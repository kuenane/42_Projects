#!/bin/bash

for i in ./ex*; do cd $i && cat *.ml && echo $i && echo "" ; echo "------------------------------------------------------" ; cd ..; done
