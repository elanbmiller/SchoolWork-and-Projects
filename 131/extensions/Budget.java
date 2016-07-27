import cse131.ArgsProcessor;


public class Budget {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArgsProcessor ap = new ArgsProcessor(args);
		int age = ap.nextInt("How old are you?");
		double worth = ap.nextInt("What is your net worth rounded to the nearest dollar?");
		double DaysLeft = (90-age)*365;
		double moneyPerDay = (Math.round(worth/DaysLeft*100.0))/100.0;

		if(DaysLeft>0){
			System.out.println("Assuming you live until age 90, you can live on: ");
			System.out.println();
			System.out.println(moneyPerDay + " dollars per day");
			System.out.println();
			System.out.println(Math.round((moneyPerDay*30.0)*100.0)/100.0 + " dollars per month");
			System.out.println();
			System.out.println(Math.round((moneyPerDay*365.0)*100.0)/100.0 + " dollars per year");
		}
		else{
			System.out.println("You made it this far, you don't need me helping you");
		}
	}
}

