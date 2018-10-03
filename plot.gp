set ylabel "Temps en nanoseconde"
set logscale y 2
set xlabel "Taille des donnees n"
set title "Evaluation du temps de tri"

plot "benchmark.dat" using 3:4
pause -1 "Hit any key to continue"