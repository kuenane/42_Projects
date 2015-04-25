#!/bin/bash
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[32m-          DOCKER BUILD            -\\033[0m";
echo "\\033[32m------------------------------------\\033[0m";
docker build --tag java_img:v42 .;
clear;
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[32m-   WELCOME TO YOUR NEW CONTAINER  -\\033[0m";
echo "\\033[32m------------------------------------\\033[0m";
echo "Essential, vim, emacs, git, openjdk, python and associated packages are installed by default";
echo "";
docker run -ti java_img:v42
