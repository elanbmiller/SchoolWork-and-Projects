import cse131.ArgsProcessor;


public class Probabilityextension {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArgsProcessor ap = new ArgsProcessor(args);
		
		Double p = ap.nextDouble("What is the probability of success?");
		
		//Double randp = Math.random();
		
		Double startupexpvalue = (((p * 190000) + ((1 - p) * 5000)));
		
		Double a = 110000 + Math.random() * 50000;
		
		Double prgrmsalary = a;
		
		System.out.println("The gamer makes: " + "$ " + startupexpvalue);
		System.out.println("The programmer makes: " + "$ " + prgrmsalary);
		
		if (startupexpvalue > prgrmsalary){
			System.out.println("You should be a gamer? " + "True");
		}
		else{
			System.out.println("You should be a gamer? " + "False");
		}
	}

}
