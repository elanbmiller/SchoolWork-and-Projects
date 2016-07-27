import cse131.ArgsProcessor;


public class Primenumspython {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArgsProcessor ap = new ArgsProcessor(args);

		int n = ap.nextInt("What prime integer would you like to test?");


		for(int x = 2; x <((n/2))+1;x++){

			if(n%x == 0)
				System.out.println(n + " is divisible by: "+ x);
			else
				System.out.println(n + " is not divisible by: " + x);
		}	
	}
}


