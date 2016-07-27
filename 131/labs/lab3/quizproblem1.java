package lab3;

import cse131.ArgsProcessor;

public class quizproblem1 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArgsProcessor ap = new ArgsProcessor(args);

		//DNA bases are usually denoted as A, T, C, or G. Declare and initialize a String array that contains those bases.
	//	Write code that populates an array of N elements with a random base for each element.
	
		//String [] dna1 = new String {"A", "G", "C", "T"};
		//System.out.print(dna1[0]); 
		
		
		int list = 10;
		String[] dna = new String [list];
		for (int i = 0; i < list; i++){

			double a = Math.random();
			if (a < .25){
				dna[i] = "A";
			}
			else if (a < .5){
				dna[i] = "T";
			}
			else if (a < .75){
				dna[i] = "C";
			}
			else{
				dna[i] = "G";
			}
			System.out.print(dna[i] + " ");
		}
		System.out.println();
	}
}

