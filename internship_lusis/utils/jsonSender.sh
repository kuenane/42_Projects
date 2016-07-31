#!/bin/bash

#######################################
#########       DEFINES       #########
#######################################

IP=localhost

PORT=WDA_CONPORT

FORMATIN="5"

FORMATOUT="5"

DEBUG=true

TRIM_SPACES_ENDL=false





#######################################
#########      FUNCTIONS      #########
#######################################

function print_usage_and_exit()
{
  echo "usage: injSQL.sh filename [-formatIn value] [-formatOut value] [-port value] [-ip value]" 
  exit 1
};

function check_nb_params()
{
  if [ "$1" -ne 1 ] && [ "$1" -ne 3 ] && [ "$1" -ne 5 ] && [ "$1" -ne 7 ] && [ "$1" -ne 9 ]; then
    print_usage_and_exit
  fi
};

function check_if_filename_exist()
{
  if [ ! -f "$1" ]; then
    echo "error: $1 don't exist"
    exit 1
  fi

  if [ "$TRIM_SPACES_ENDL" = true ]; then
    FILECONTENT=`cat "$1" | tr -d " " | tr -d "\n"`
  else
    FILECONTENT=`cat "$1"`
  fi
};

function apply_option()
{
  if [ "$1" = "-formatIn" ]; then
    FORMATIN="$2"
  elif [ "$1" = "-formatOut" ]; then
    FORMATOUT="$2"
  elif [ "$1" = "-port" ]; then
    PORT="$2"
  elif [ "$1" = "-ip" ]; then
    IP="$2"
  else
    print_usage_and_exit
  fi
};

function build_sku()
{
  SKU=`grep -o 'sku\":\".................' $1 | awk -F\" '{print $3}'`
};

function build_tcp_protocol_layer()
{
  #protocol id
  TCP_PROTOCOL_LAYER="02070703"

  #action
  TCP_PROTOCOL_LAYER+=$(printf "%08x" `expr 32 + $"${#FILECONTENT}"`)
};

function build_session_protocol_layer()
{
  #version
  SESSION_PROTOCOL_LAYER="0100"

  #action
  SESSION_PROTOCOL_LAYER+="0009"

  #formatIn (with padding)
  SESSION_PROTOCOL_LAYER+=$(printf "%04x" $FORMATIN)

  #formatOut (with padding)
  SESSION_PROTOCOL_LAYER+=$(printf "%04x" $FORMATOUT)

  #uniqueReference
  SESSION_PROTOCOL_LAYER+="12345678901234567890123456789011"

  #destination
  SESSION_PROTOCOL_LAYER+="0000"

  #resultCode
  SESSION_PROTOCOL_LAYER+="0000"

  #len
  SESSION_PROTOCOL_LAYER+=$(printf "%08x" ${#FILECONTENT})
};

function  set_connection()
{
  if [ "$DEBUG" = true ]; then
    printf "\n"
    printf "%-25s" "Request for SKU:" "$SKU"
    printf "\n\n"
    printf "%-25s" "Tcp Protocol Layer:" "$TCP_PROTOCOL_LAYER"
    printf "\n\n"
    printf "%-25s" "Session Protocol Layer:" "$SESSION_PROTOCOL_LAYER"
    printf "\n\n"
    printf "%-25s" "File content:" "$FILECONTENT"
    printf "\n\n"
    printf "%-25s" "File size:" "${#FILECONTENT} (+ 32 header = `expr 32 + $"${#FILECONTENT}"`)"
    printf "\n\n"
  fi

  exec 3<>/dev/tcp/${IP}/${PORT}
};

function  send_request()
{
  # SESSION_PROTOCOL_LAYER="000100090000000012345678901234561111111111111111000000000000"
  # printf "$SESSION_PROTOCOL_LAYER$FILECONTENT\n\n" >&1
  # printf "$SESSION_PROTOCOL_LAYER$FILECONTENT" >&3
  # printf "$TCP_PROTOCOL_LAYER$SESSION_PROTOCOL_LAYER$FILECONTENT\n\n" >&1

  # printf "xxd'"
  printf "$TCP_PROTOCOL_LAYER" | xxd -p -r >&3
  printf "$SESSION_PROTOCOL_LAYER" | xxd -p -r >&3
  printf "$FILECONTENT" >&3
  # echo "'"

  # printf "$TCP_PROTOCOL_LAYER$SESSION_PROTOCOL_LAYER$FILECONTENT" >&3

  if [ "$DEBUG" = true ]; then
    printf "REQUEST SENT, WAITING FOR RESPONSE...\n\n"
  fi
};

function read_the_response()
{
  READRESP_RET=`timeout 1 cat <&3`
  # READRESP_RET=`cat <&3`

  if [ -z "${READRESP_RET:8:8}" ] || [ "${READRESP_RET:8:8}" -lt 30 ]; then
    echo "error: received incomplete response"
    exit 1
  fi

  RESULTCODE=${READRESP_RET:36:2}

  if [ "$RESULTCODE" -eq 0 ]; then
    if [ "$DEBUG" = true ]; then
      printf "RESPONSE RECEIVED, RESULTCODE=$RESULTCODE\n\n"
    fi
    RESULTJSON=${READRESP_RET:64}
  fi
};

function print_result()
{
  if [ "$RESULTCODE" -ne 0 ]; then
    echo "error: resultCode = $RESULTCODE"
    exit 1
  fi

  if [ "$DEBUG" = true ]; then
    printf "########################################################\n\n"
  fi

  echo "$RESULTJSON"
};





#######################################
#########         MAIN        #########
#######################################

  check_nb_params "$#"

  check_if_filename_exist "$1"

  if [ "$#" -ge 3 ]; then
    apply_option "$2" "$3"
    if [ "$#" -ge 5 ]; then
      apply_option "$4" "$5"
      if [ "$#" -ge 7 ]; then
        apply_option "$6" "$7"
        if [ "$#" -ge 7 ]; then
          apply_option "$6" "$7"
        fi
      fi
    fi
  fi

  build_sku "$1"

  build_tcp_protocol_layer

  build_session_protocol_layer

  set_connection

  send_request

## RM THE TIMEOUT (OR INCREASE IT)
  # read_the_response
##

  # print_result

  timeout 5 cat <&3 ; echo ""

  exit 0
