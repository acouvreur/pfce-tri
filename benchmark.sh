#!/bin/bash

NB_GENERATING_ALGO=6
NB_SORTING_ALGO=8
start=10
end=17
#sizes=(256 512 1024 2048 4096)
tries=10
gen=("sortedArray" "reverseSortedArray" "constantArray" "randomizedArrayRangeN" "randomizedArrayRangeLogN" "randomizedArrayRangeNSquare")
tris=("triInsertion" "triFusion" "triParTas" "triRapidePivotArbitraire" "triRapidePivotAleatoire" "sortBuiltIn" "quickSortIterativeMed3" "smoothSort")

for i in $(seq 1 $NB_SORTING_ALGO)
do
    for j in $(seq 1 $NB_GENERATING_ALGO)
    do
    echo > "./data/benchmark_${i}_${j}.dat"
    echo "Processing sorting algorithm \"${tris[i-1]}\" with input data generator \"${gen[j-1]}\""
        for s in $(seq $start $end)
        do
            echo "Computing 2^${s} array length..."
            result=0
            n=$(echo "2^$s" | bc)
            for _ in $(seq 1 $tries)
            do  
                result=$((result + $(./all "$i" "$j" "$n")))
            done
            result=$((result/"$tries"))
            echo "$i $j $n $result" >> "./data/benchmark_${i}_${j}.dat"
            echo "Computed in ${result} ns..."
        done
    echo "Done."
    done
done