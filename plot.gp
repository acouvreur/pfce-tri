set ylabel "Temps en nanoseconde"
set logscale y 10
set logscale x 2
set xlabel "Taille des donnees n"

gen = "sortedArray reverseSortedArray constantArray randomizedArrayRangeN randomizedArrayRangeNSquare randomizedArrayRangeNSquare"
tris = "triInsertion triFusion triParTas triRapidePivotArbitraire triRapidePivotAleatoire sortBuiltIn"

set title "Evaluation du temps de tri ".word(gen, gen_algo)

# plot "benchmark.dat" using 3:4
plot for [i=1:6] 'data/benchmark_'.i.'_'.gen_algo.'.dat' using 3:4 smooth unique title word(tris, i)

pause -1 "Hit any key to continue"