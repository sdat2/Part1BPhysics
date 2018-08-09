f(N) = 1.0/N
set xrange [1:1000]
plot 0.693147+f(x) with lines linetype 4, 0.693147 - f(x) with lines linetype 5, 'tmpfileln' u 4:5 with linespoints
