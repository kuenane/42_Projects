#!/bin/bash
underline=`tput smul`;
stopunderline=`tput rmul`;
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[32m-          DOCKER BUILD            -\\033[0m";
echo "\\033[32m------------------------------------\\033[0m";
docker build --tag ssh_img:v42 .;
clear;
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[32m-   WELCOME TO YOUR NEW CONTAINER  -\\033[0m";
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[34m\\033[34m${underline}SSH COMMAND:${stopunderline}\\033[0m\\033[0m";
echo "ssh wide-aze@IP -p PORT";
echo "";
echo "\\033[34m${underline}IP:${stopunderline}\\033[0m";
boot2docker ip;
echo "";
echo "\\033[34m${underline}DOCKER PS:${stopunderline}\\033[0m";
docker run -d -P ssh_img:v42
echo "";
docker ps;
