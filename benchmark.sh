#!/bin/bash

NB_GENERATING_ALGO=6
NB_SORTING_ALGO=6
sizes=(256 512 1024 2048 4096)
tries=10

for i in $(seq 1 $NB_SORTING_ALGO)
do
    for j in $(seq 1 $NB_GENERATING_ALGO)
    do
        for s in ${sizes[*]}
        do
            result=0
            for t in $(seq 1 $tries)
            do
                result=$((result + $(./all "$i" "$j" "$s")))
            done
            result=$((result/"$tries"))
            echo "$i $j $s $result" >> "data/benchmark_`$i`_`$j`.dat"
        done
    done
done