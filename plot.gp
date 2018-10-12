set ylabel "Temps en nanoseconde"
set logscale x 2
set xlabel "Taille des données n"

gen = "sortedArray reverseSortedArray constantArray randomizedArrayRangeN randomizedArrayRangeLogN randomizedArrayRangeNSquare"
tris = "Insertion Fusion Tas QuickSortArbitrary QuickSortRandom SortC QuickSortIterMed3 Smooth QuickSortIterMed3Threshold"

set title "Evaluation du temps de tri ".word(gen, gen_algo)
set key top left

# plot "benchmark.dat" using 3:4
plot for [i=1:8] 'data/benchmark_'.i.'_'.gen_algo.'.dat' using 3:4 with linespoints title word(tris, i)

set term pdfcairo size 10in,5in;
set output 'output/benchmark_'.gen_algo.'.pdf'
replot