#!/bin/bash
declare -ia array=(4371 1323 6173 4199 4344 9679 1989)
declare -i result
for((i=0;i<${#array[@]};i++))
do
	let result=${array[i]}%10
	echo ${array[i]}	$result
done
