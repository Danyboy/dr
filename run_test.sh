#!/bin/bash

LOG="./result.log"
ITERATION="1000000"

run_language(){
    cd $1 && $2
    result=$((time -f %E $3) 2>&1)
    echo "| $1 | $( echo $result | tr "\n" " " | sed "s\ \ | \g")"
    cd ..
}

my_run(){
    echo "| Language      | Result        | Time           |"
    echo "| ------------- |:-------------:| :-------------:|"

    run_language cpp "g++ main.cpp" "./a.out $ITERATION" 
    run_language go " " "go run birthday.go $ITERATION"
    run_language java "javac BirthdayProblem.java" "java BirthdayProblem 400 5 $ITERATION"
    run_language js " " "node dr.js"
    run_language php " " "php dr.php"
}

my_run >> $0-$(date +%d%m%y-%H:%M:%S).log 2>&1
