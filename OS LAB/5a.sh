#!/bin/bash
# Program to generate prime numbers in a given range

echo "Enter the lower bound:"
read m

echo "Enter the upper bound:"
read n

for ((i=m; i<=n; i++))
do
    flag=0
    for ((j=2; j<=i/2; j++))
    do
        if [ $((i % j)) -eq 0 ]
        then
            flag=1
            break
        fi
    done

    if [ $flag -eq 0 ]
    then
        echo -n "$i "
    fi
done
echo
