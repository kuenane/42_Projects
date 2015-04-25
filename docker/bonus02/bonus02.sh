#!/bin/bash
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[32m-          DOCKER BUILD            -\\033[0m";
echo "\\033[32m------------------------------------\\033[0m";
docker build --tag my_img:v42 .;
clear;
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[32m-   WELCOME TO YOUR NEW CONTAINER  -\\033[0m";
echo "\\033[32m------------------------------------\\033[0m";
echo "This is my own image (emacs + dotemacs + git + gitclone my project + gcc)";
echo "";
docker run -ti my_img:v42
