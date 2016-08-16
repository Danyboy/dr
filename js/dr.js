function getRandomInt(min, max){
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function getDrProbability(){

var iter = 1000;
var daysInYear = 365;
var probability = 0;

for (i = 0; i < iter; i++){
    var drs=0;
    var days = Array.apply(null, Array(daysInYear)).map(Number.prototype.valueOf,0);
    for (j = 1; j < 400; j++){
	var day = getRandomInt(1, daysInYear);
	//console.log(day);
	days[day] = days[day] + 1;
	if (days[day] > 4){
	    drs++; 
	    days[day] = 0; //надо проверять что этот день ещё не учитывали
	    continue;
	}
        //console.log(days);
    }
    probability += drs > 0 ? 1 : 0; //если был хоть один день с > 4 значит случилось, добавляем 1
    //console.log(i);
    //console.log("result");
    //console.log(drs);
}

console.log("final result");
console.log(probability);
console.log(probability / iter);
}