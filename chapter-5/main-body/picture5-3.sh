#!/bin/bash
declare -i  sum=0
declare -i val=0
string="$1"
len=`expr length "${string}"`
for((i=0;i<len;i++))
do
	let val=`printf "%d" "'${string:i:1}"`
	let sum+=val
done
let sum=sum%$2
echo $sum
