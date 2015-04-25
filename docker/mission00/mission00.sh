#!/bin/bash
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[32m-          STARTING DOCKER         -\\033[0m";
echo "\\033[32m------------------------------------\\033[0m";
boot2docker init;
boot2docker start;
$(boot2docker shellinit);
boot2docker status;
echo"";
echo "\\033[32m------------------------------------\\033[0m";
echo "\\033[32m-            DOCKER INFO           -\\033[0m";
echo "\\033[32m------------------------------------\\033[0m";
docker info
