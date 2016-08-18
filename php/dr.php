<?php
function getDrProbability(){

$friendsQuantity = 400;
$birtdaysInOneDay = 5;
$iter = 1000000;
$daysInYear = 365;
$probability = 0;

for ($i = 0; $i < $iter; $i++){
    $drs = 0;
    $days = array_fill(1, $daysInYear, 0);
    for ($j = 1; $j < $friendsQuantity; $j++){
	$day = rand(1, $daysInYear);
	$days[$day] = $days[$day] + 1;
	if ($days[$day] >= $birtdaysInOneDay){
	    $drs++; 
	    break;
	}
    }
    $probability += $drs > 0 ? 1 : 0; //если был хоть один день с 5 др значит случилось, добавляем 1
}

$p = $probability / $iter;
echo($p . " ");
}

getDrProbability();
?>