## Resolve birthday problem by monte carlo algorithm on different languages.

### Подробное описание

https://ru.wikipedia.org/wiki/Парадокс_дней_рождения
https://en.wikipedia.org/wiki/Birthday_problem

В данном коде решается немного иная задача:

Какова вероятность что у 5 из 400 людей будет день рождение в один день.

Ответ на всех языках примерно такой: 0,86.

То есть имея 400 друзей в вк очень вероятно что пятеро из них родились в один день.

### Table of result and language speed on 1 000 000 iteraion
| Language      | Result        | Time           |
| ------------- |:-------------:| :-------------:|
| cpp           | 0.867784 | 0:08.86   |
| java           | 0.869173 | 0:17.87   |
| js           | 0.862871 | 1:10.54   |
| php           | 0.863919 | 2:30.30   |
| Haskell	| -		| Soon	    |
| Asm		| -		| Soon	    |
| Go		| -		| Soon	    |

### Run
```
run_test.sh
```

### Comparsion of language speed:

```
cpp
0.867784
8.18user 0.03system 0:08.25elapsed 99%CPU (0avgtext+0avgdata 3188maxresident)k
16inputs+0outputs (1major+123minor)pagefaults 0swaps

java
0.868967
17.42user 0.48system 0:18.03elapsed 99%CPU (0avgtext+0avgdata 82772maxresident)k
272inputs+8outputs (2major+17213minor)pagefaults 0swaps

js
Final result: 0.862129 time: 69031
68.30user 0.66system 1:09.49elapsed 99%CPU (0avgtext+0avgdata 51056maxresident)k
14784inputs+8outputs (67major+10077minor)pagefaults 0swaps

php
Final result: 0.863872150.69user 0.76system 2:31.77elapsed 99%CPU (0avgtext+0avgdata 47176maxresident)k
1344inputs+8outputs (28major+9951minor)pagefaults 0swaps

```