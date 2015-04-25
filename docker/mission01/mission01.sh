#!/bin/bash
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[32m-          DOCKER BUILD            -\\033[0m";
echo "\\033[32m------------------------------------\\033[0m";
docker build --tag hello/world:v42 .;
clear;
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[32m-   WELCOME TO YOUR NEW CONTAINER  -\\033[0m";
echo "\\033[32m------------------------------------\\033[0m";
echo "To access to HW page, open :";
boot2docker ip;
echo "port 4242";
echo "";
docker run -ti -p 4242:80 hello/world:v42
