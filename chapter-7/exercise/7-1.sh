#!/bin/bash
#形如7-1.sh 3 1 4 1 5 9 2 6 5的输入即可排序
array=(`echo $@`)
length=${#array[@]}
for((i=0;i<$length;i++))
do
	Tmp=${array[i]}
	j=$i
	while [ $j -gt 0 ]&&[ ${array[$j-1]} -gt $Tmp ]
	do
		array[$j]=${array[$j-1]}
		j=$[j-1]
	done
	array[$j]=$Tmp
done
echo ${array[@]}
