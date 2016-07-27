package lab2;

import cse131.ArgsProcessor;

public class quiz2montyhall {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArgsProcessor ap = new ArgsProcessor(args);

			
		//System.out.println("happy!");
		
		int rounds = ap.nextInt("how many rounds do you want to play?");

		double change = 0;
		double stay = 0;

		double switchwins = 0;
		double staywins = 0;

		for (int i=0; i<rounds; i++){


			double a = Math.random();
			boolean one = ((0.0<a) && (a<=0.33));
			boolean two = ((0.33<a) && (a<=0.66));
			boolean three = ((0.66<a) && (a<=1.0));

			if (one){
				staywins = staywins + 1;
				//stay = one;
				//change = two ;
			}
			if (two){
				switchwins = switchwins + 1;
				//stay = one;
				//change = two;
			}
			if (three){
				switchwins = switchwins + 1;
				//stay = one;
				//change = three;


			}

		}	
		double totalswitchwins = (switchwins / rounds)*100;
		double totalstaywins = (staywins / rounds)*100;
		System.out.println("switch: " +totalswitchwins + "%");
		System.out.println("stay: " +totalstaywins + "%");
	}
}