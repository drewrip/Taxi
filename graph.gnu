set yrange [0.1:0.3]
set title "Frequency of Winning Drawings (1000000 Trials)"
show title
set xlabel "Number of Trials"
set ylabel "Frequency of Winning Trials"
show xlabel
show ylabel
plot "data/graph.dat" using 1:2 with lines