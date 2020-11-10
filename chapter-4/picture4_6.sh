:<<EOF
这个脚本用来输出目录中所有的文件名，输出格式是：深度为i的文件的名字将被i次（tab）缩进后打印出来。
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
