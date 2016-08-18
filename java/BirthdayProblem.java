class BirthdayProblem {

    public static double birthdayProblem (int friends, int birthdaysInOneDay , int iteration){
	int daysInYear = 365;
	int result = 0;

	for (int i = 0; i < iteration; i++){
	    int [] days = new int [daysInYear];
	    for (int j = 0; j < friends; j++){
		if (++days[myRandomInt(0, daysInYear - 1)] >= birthdaysInOneDay){
		    result++;
		    break;
		}
	    }
	}
	
	return ((double) result / (double) iteration);
    }
    
    public static int myRandomInt(int min, int max){
	return (int) (min + Math.random() * (max - min));
    }

    public static void main(String args[]){
	System.out.println(birthdayProblem(Integer.parseInt(args[0]), Integer.parseInt(args[1]), Integer.parseInt(args[2])));
    } 
}