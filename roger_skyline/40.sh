#!/bin/bash

# Réaliser un script qui affiche la liste des fichiers triés par taille et avec des couleurs dans le dossier mis en argument

if [ "$#" -eq 1 ];then
	ls -GS "$1"
else
	echo "error: please specify a path"
fi
