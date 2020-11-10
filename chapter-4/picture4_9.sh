:<<EOF
后序遍历计算目录大小
EOF
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
	local filesize=0
	local TotalSize=0
	if [ -f $1 ] || [ -d $1 ]
	then
		filesize=`ls -ld $1|cut -d ' ' -f 5`
		let TotalSize=filesize
		if [ -d $1 ]
		then
			for child in $(fullpath $1)
			do
				filesize=$(SizeDirectory $child)
				let TotalSize+=filesize
			done
		fi
	fi
	echo $TotalSize
}
result=`SizeDirectory $1`
echo $result
