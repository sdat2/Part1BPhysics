f(N) = 1.0/N
set xrange [1:500]
plot pi+f(x) with lines linetype 4, pi-f(x) with lines linetype 5, 'tmpfile2' u 5:6 with linespoints
