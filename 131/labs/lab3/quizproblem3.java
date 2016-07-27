package lab3;

import cse131.ArgsProcessor;

public class quizproblem3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//Take an array of int values and create a copy of that array, with all of the elements reversed in terms of their 
		//position.
		
		ArgsProcessor ap = new ArgsProcessor(args);

		int N = ap.nextInt("How many integers?");



		int[]arr  = new int [N];
		for (int i = 0; i < N; i++){
			arr[i] = i;
			System.out.print(arr[0] + " ");
		}
	//	int[]copy = new int [N];
	//	for (int i = 0; i < N; i++){
	//		copy [i] = arr[N - i - 1];
	//	System.out.print((copy[i]) + " ");
	//	}

	}

}
