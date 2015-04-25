#!/bin/bash
rm -f ~/.ssh/id_rsa.pub;
rm -f ~/.ssh/id_rsa;
ssh-keygen -t rsa -q -N '' -f ~/.ssh/id_rsa;
mv ~/.ssh/id_rsa.pub .
echo "New keys generated and added to current directory."
