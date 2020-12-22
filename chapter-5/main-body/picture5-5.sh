#!/bin/bash
declare -i sum=0
declare -i val
declare -i len
string="$1"
TableSize="$2"
len=`expr length "${string}"`
for((i=1;i<=len;i++))
do
	val=`printf "%d" "'${string:0-i:1}"`
	let val=val*$((32**(i-1)))
	let sum+=val
done
let sum%=TableSize
echo $sum
