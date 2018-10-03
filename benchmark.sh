#!/bin/bash

NB_GENERATING_ALGO=6
NB_SORTING_ALGO=6
start=10
end=17
#sizes=(256 512 1024 2048 4096)
tries=10

for i in $(seq 1 $NB_SORTING_ALGO)
do
    for j in $(seq 1 $NB_GENERATING_ALGO)
    do
        for s in $(seq $start $end)
        do
            result=0
            n=$(echo "2^$s" | bc)
            for t in $(seq 1 $tries)
            do  
                result=$((result + $(./all "$i" "$j" "$n")))
            done
            result=$((result/"$tries"))
            echo "$i $j $n $result" >> "./data/benchmark_${i}_${j}.dat"
        done
    done
done