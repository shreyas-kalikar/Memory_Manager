#!/bin/bash
#Run this with ./run_N_Times.sh "$#"

if [ "$#" -ne 1 ]; then
	echo "Enter number of times you want to run this program."
	exit 1;
fi

make

let count=0
while [ $count -lt "$1" ]; do
	./bench
	let count=$count+1
done

make clean
