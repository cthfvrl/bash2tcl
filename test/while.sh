#!/usr/bin/bash
SUM=0; 
I=0; 
N=5;
while ((I<=N)); 
do SUM=$((SUM+I)); I=$((I+1)); 
done
echo $SUM