## Resolve birthday problem by monte carlo algorithm on cpp js java.

Cpp give 0.867 on 1000 000 iteration, js 0.849 on 1000 itaration.

## Comparsion of language speed:

```
time node dr.js
final result
862527
0.862527
67.77user 1.21system 1:09.14elapsed 99%CPU (0avgtext+0avgdata 51608maxresident)k
344inputs+0outputs (2major+10194minor)pagefaults 0swaps

g++  -std=gnu++11 -o main main.cpp
time ./main 1000000
0.866328
real    0m29.642s
user    0m28.875s
sys     0m0.746s

javac BirthdayProblem.java
time java BirthdayProblem 400 5 1000000
0.868484

real    0m17.861s
user    0m17.432s
sys     0m0.556s

```