#!/bin/bash

# Réaliser un script qui affiche seulement le login, le UID et le Path du fichier /etc/passwd

cut -d ":" -f1,3,6 /etc/passwd | tr ":" " " | grep -v "#"
