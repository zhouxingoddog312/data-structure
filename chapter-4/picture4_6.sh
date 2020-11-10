#!/bin/bash
function fullpath(){
	cd $1
	local pre_path=$(pwd)
	cd -
	for name in $(ls $1)
	do
		echo $pre_path"/"$name
	done
}
function PrintName(){
	for((i=$2;i>0;i--))
	do
		printf "	"
	done
	printf "$1\n"
}
function ListDir(){
	if [ -d $1 ] || [ -f $1 ]
	then
		PrintName $1 $2
		if [ -d $1 ]
		then
			local Dirname
			local Depth
			let Depth=$[$2+1]
			for Dirname in $(fullpath $1)
			#for Dirname in $(ls -R $1|sed '1d;/^$/d;s/\(.*\):/\1/g')
			do
				ListDir $Dirname $Depth
			done
		fi
	fi
}
declare -i Depth_i=0
ListDir $1 $Depth_i
