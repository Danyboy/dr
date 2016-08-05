function getRandomInt(min, max){
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

var iter = 100000;
var daysInYear = 356;
var probability = 0;

for (i = 0; i < iter; i++){
    var drs=0;
    var days = new Array(daysInYear);
    for (j = 0; j < 400; j++){
	var day = getRandomInt(0, daysInYear);
	days[day] = days[day]++;
	if (days[day] > 4){
	    drs++; 
	    days[day] = 0; //надо проверять что этот день ещё не учитывали
	    continue;
	}
    }
    probability += drs > 0 ? 1 : 0; //если был хоть один день с > 4 значит случилось, добавляем 1
    //console.log(i);
    //console.log("result");
    //console.log(drs);
}
