#!/bin/bash
declare -a array
array[0]=1
array[1]=2
for((i=2;i<16;i++))
do
	let array[i]=array[i-1]+array[i-2]+1
done
echo ${array[*]}
