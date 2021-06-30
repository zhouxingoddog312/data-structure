#!/bin/bash
read -p "enter two integer,return the sum!" a b
echo $a $b
c=$((a^b))
b=$(((a&b)<<1))
while [ $b -ne 0 ]
do
	a=$c
	c=$((a^b))
	b=$(((a&b)<<1))
done
echo $c
