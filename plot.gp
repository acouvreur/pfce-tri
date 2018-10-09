set ylabel "Temps en nanoseconde"
set logscale y 10
set logscale x 2
set xlabel "Taille des donnees n"

gen = "sortedArray reverseSortedArray constantArray randomizedArrayRangeN randomizedArrayRangeLogN randomizedArrayRangeNSquare"
tris = "triInsertion triFusion triParTas triRapidePivotArbitraire triRapidePivotAleatoire sortBuiltIn quickSortIterativeMed3 smoothSort"

set title "Evaluation du temps de tri ".word(gen, gen_algo)

# plot "benchmark.dat" using 3:4
plot for [i=1:8] 'data/benchmark_'.i.'_'.gen_algo.'.dat' using 3:4 with linespoints title word(tris, i)

pause -1 "Hit any key to continue"

set term pdf
set output 'output/benchmark_'.gen_algo.'.pdf'
replot