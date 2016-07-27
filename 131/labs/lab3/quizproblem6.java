package lab3;

import cse131.ArgsProcessor;

public class quizproblem6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArgsProcessor ap = new ArgsProcessor(args);

		int a = 10;

		int[] values = new int [a];
		for (int i = 0; i < a; i++){
			values [i] = (int) (Math.random() * 100);

			System.out.print(values[i] + " ");
		}

		for (int i = 0; i < a; i++){
			values [i] = i ++;
			System.out.println();
		
		
		}




	}
}
