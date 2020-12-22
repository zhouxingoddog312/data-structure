#!/bin/bash
declare -i TableSize=$2
declare -i val
declare -i sum
string="$1"
for((i=0;i<3;i++))
do
	let val=`printf "%d" "'${string:i:1}"`
	let val*=$((27**i))
	let sum+=val
done
let sum%=TableSize
echo $sum
