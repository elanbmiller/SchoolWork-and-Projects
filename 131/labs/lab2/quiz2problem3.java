//Sedgewick 1.3.32 Ramanujan's taxi: 1729 is the smallest integer that can be expressed as the sum of two cubes in two different ways.
//In other words, there are four distinct positive integers a, b, c, and d such that a3 + b3 = c3 + d3

package lab2;

import cse131.ArgsProcessor;

public class quiz2problem3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArgsProcessor ap = new ArgsProcessor(args);
//Sedgewick 1.3.32 Ramanujan's taxi: 1729 is the smallest integer that can be expressed as the sum of two cubes in two different ways.
		//In other words, there are four distinct positive integers a, b, c, and d such that a3 + b3 = c3 + d3
		boolean torf = true;
		int a = ap.nextInt("What is the number?");
		for (int i = 0;i < a; i++){
			
			for (int j = i; j < a; j++){
				
				for (int k = j; k < a; k++){
					
					for (int l = k; l < a; l++){
				
						
					if(((i*i*i)+(j*j*j) == (k*k*k) + (l*l*l)) && ((i*i*i)+(j*j*j) ==a))  {
						if ((i != j) && (i != k) && (i != l) && (j != k) && (j != l) && (k != l)){
							System.out.println(i +" "+ j + " "+ k + " " + l);
							torf = false;
						}
						
					}
					}
			}
		}
	}
		if (torf) {
			System.out.println("no solution");
		}

}
}