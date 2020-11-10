#!/bin/bash
function fullpath(){
	cd $1
	local pre_path=$(pwd)
	cd ->/dev/null
	for name in $(ls $1)
	do
		echo $pre_path"/"$name
	done
}
function SizeDirectory(){
	local declare -i filesize=0
	local declare -i TotalSize=0
	if [ -f $1 ] || [ -d $1 ]
	then
		filesize=`ls -ld $1|cut -d ' ' -f 5`
		let TotalSize=filesize
		if [ -d $1 ]
		then
			for child in $(fullpath $1)
			do
				let TotalSize+=$(SizeDirectory $child)
			done
		fi
	fi
	return $TotalSize
}
result=`SizeDirectory $1`
echo $result
