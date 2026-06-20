#!/bin/bash
echo "Enter the number of Fibonacci numbers to be printed:"
read n

f1=0
f2=1

echo "The first $n Fibonacci numbers are:"

for ((i=1; i<=n; i++))
do
    echo "$f1"
    f3=$((f1 + f2))
    f1=$f2
    f2=$f3
done