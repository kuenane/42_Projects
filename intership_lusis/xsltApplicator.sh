#!/bin/bash

###################
#    FUNCTIONS    #
###################

function ft_exit()
{
	exit 1
}

function print_usage_and_exit()
{
	echo "usage: xsltApplicator.sh -xslt file.xslt -xml file.xml [-o outfile]"	
	ft_exit
}

function check_argc()
{
if [ $# -ne 4 ] && [ $# -ne 6 ]; then
	if [ $# -ne 0 ]; then
		echo "error: bad number of parameters"
	fi
	print_usage_and_exit
fi	
}

function too_many_xml()
{
	echo "error: too many definition for xmlfile"
	ft_exit
}

function too_many_xslt()
{
	echo "error: too many definition for xsltfile"		
	ft_exit
}

function too_many_outfile()
{
	echo "error: too many definition for outfile"	
	ft_exit
}

function missing_xml()
{
	echo "error: missing xml file..."
	ft_exit
}

function missing_xslt()
{
	echo "error: missing xslt file..."
	ft_exit
}

##############
#    MAIN    #
##############

XSLTFILE=""
XMLFILE=""
OUTFILE=""

if [ $# -ne 4 ] && [ $# -ne 6 ]; then
	if [ $# -ne 0 ]; then
		echo "error: bad number of parameters"
	fi
	print_usage_and_exit
fi
if [ "$1" == "-xml" ]; then
	if [ -z "$2" ]; then
		echo "error: invalid value for option ${1}: ${2}"
		ft_exit
	else
		XMLFILE="$2"
	fi
elif [ "$1" == "-xslt" ]; then
	if [ -z "$2" ]; then
		echo "error: invalid value for option ${1}: ${2}"
		ft_exit
	else
		XSLTFILE="$2"
	fi
elif [ "$1" == "-o" ]; then
	if [ -z "$2" ]; then
		echo "error: invalid value for option ${1}: ${2}"
		ft_exit
	else
		OUTFILE="$2"
	fi
else
	echo "error: invalid option ${1}"
	print_usage_and_exit
fi

if [ "$3" == "-xml" ]; then
	if [ -z "$4" ]; then
		echo "error: invalid value for option ${3}: ${4}"
		ft_exit
	elif [ -n "$XMLFILE" ]; then
		too_many_xml
	else
		XMLFILE="$4"
	fi
elif [ "$3" == "-xslt" ]; then
	if [ -z "$4" ]; then
		echo "error: invalid value for option ${3}: ${4}"
		ft_exit
	elif [ -n "$XSLTFILE" ]; then
		too_many_xslt
	else
		XSLTFILE="$4"
	fi
elif [ "$3" == "-o" ]; then
	if [ -z "$4" ]; then
		echo "error: invalid value for option ${3}: ${4}"
		ft_exit
	elif [ -n "$OUTFILE" ]; then
		too_many_outfile
	else
		OUTFILE="$4"
	fi
else
	echo "error: invalid option ${3}"
	print_usage_and_exit
fi

if [ $# -eq 6 ]; then
	if [ "$5" == "-xml" ]; then
		if [ -z "$6" ]; then
			echo "error: invalid value for option ${5}: ${6}"
			ft_exit
		elif [ -n "$XMLFILE" ]; then
			too_many_xml
		else
			XMLFILE="$6"
		fi
	elif [ "$5" == "-xslt" ]; then
		if [ -z "$6" ]; then
			echo "error: invalid value for option ${5}: ${6}"
			ft_exit
		elif [ -n "$XSLTFILE" ]; then
			too_many_xslt
		else
			XSLTFILE="$6"
		fi
	elif [ "$5" == "-o" ]; then
		if [ -z "$6" ]; then
			echo "error: invalid value for option ${5}: ${6}"
			ft_exit
		elif [ -n "$OUTFILE" ]; then
			too_many_outfile
		else
			OUTFILE="$6"
		fi
	else
		echo "error: invalid option ${5}"
		print_usage_and_exit
	fi
elif [ -z "$XSLTFILE" ]; then
	missing_xslt
elif [ -z "$XMLFILE" ]; then
	missing_xml
fi

if [ -n "$OUTFILE" ]; then
	xsltproc ${XSLTFILE} ${XMLFILE} | xmllint --format - | perl -0pe 's/( more .*\n.*)bus="1">/\1occ="1">/g' | perl -0pe 's/( more .*\n.*)\/>/\1 bus="1"\/>/g' > ${OUTFILE}
else
	xsltproc ${XSLTFILE} ${XMLFILE} | xmllint --format - | perl -0pe 's/( more .*\n.*)bus="1">/\1occ="1">/g' | perl -0pe 's/( more .*\n.*)\/>/\1 bus="1"\/>/g'
fi
