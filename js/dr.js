function getRandomInt(min, max){
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function getDrProbability(){

var friendsQuantity = 400;
var birtdaysInOneDay = 5;
var iter = 100;
var daysInYear = 365;
var probability = 0;

var start = Date.now();

for (i = 0; i < iter; i++){
    var drs = 0;
    var days = Array.apply(null, Array(daysInYear)).map(Number.prototype.valueOf,0);
    for (j = 1; j < friendsQuantity; j++){
	var day = getRandomInt(1, daysInYear);
	days[day] = days[day] + 1;
	if (days[day] >= birtdaysInOneDay){
	    drs++; 
	    continue;
	}
    }
    probability += drs > 0 ? 1 : 0; //если был хоть один день с > 4 значит случилось, добавляем 1
}

var end = Date.now();
var p = probability / iter;
var time = end - start;
var result = "Final result: " + p + " time: " + time;
console.log(result);
alert(result);
}

getDrProbability();