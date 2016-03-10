#!/bin/bash

# Réaliser un script qui met à jour l’ensemble des sources de package, puis de vos packages et qui log l’ensemble dans un fichier nommé update_script.log

LOGFILE="update_script.log"

if [ `uname -s` = "Darwin" ];then
	brew update > "$LOGFILE"
	brew upgrade >> "$LOGFILE"
else
	sudo apt-get update > "$LOGFILE"
	sudo apt-get upgrade >> "$LOGFILE"
fi
