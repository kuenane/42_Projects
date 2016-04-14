#!/bin/bash

for i in ./ex*; do cd $i && ocamlopt *.ml && echo $i && echo "" && ./a.out && rm -rf *.cmi *.cmx *.o a.out ; echo "------------------------------------------------------" ; cd ..; done
