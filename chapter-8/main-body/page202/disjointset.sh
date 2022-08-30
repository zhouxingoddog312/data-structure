#!/bin/bash
#usage Disjset=(`Initialize 10`)
#Disjset=(`Union "${Disjset[*]}" 1 3`)
#Find "${Disjset[*]}" 2
declare -a DisjSet
function Initialize()
{
	local str
	for((i=0;i<$1;i++))
	do
		str="0 "$str
	done
	echo $str
}
function Union()
{
	local Root1
	local Root2
	local str=($1)
	Root1=$(Find "${str[*]}" $2)
	Root2=$(Find "${str[*]}" $3)
	if [ $Root1 -ne $Root2 ]
	then
		str[$Root2]=$Root1
	fi
	echo ${str[*]}
}
function Find()
{
	local tmp
	local pos=$2
	local str=($1)

	while [ ${str[$pos]} -gt 0 ]
	do
		tmp=${str[$pos]}
		pos=$tmp
	done
	echo $pos
}
