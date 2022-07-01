#!/bin/bash
current_sum=0
max_sum=0
read len
read str
for current_num in $str
do
    current_sum=$[$current_sum+$current_num]
    if [ $current_sum -gt $max_sum ]
    then
        max_sum=$current_sum
    elif [ $current_sum -lt 0 ]
    then
        current_sum=0
    fi
done
echo $max_sum
