package studio3;
//Laura Roettges & 

import cse131.ArgsProcessor;

public class Dice {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArgsProcessor ap = new ArgsProcessor(args);
		int D = ap.nextInt("how many dice?");
		int T = ap.nextInt("how many throws?");

		//double a = Math.random();
		//int v = (int)(a * 6) + 1;

		//int [] h =new int[T];
		//for (int j = 0; j < T; j++){
		//	int roll = j;


		int[][] diceThrown = new int[D][T];
		
		for (int j = 0; j < T; j++){

			for (int i = 0; i < D; i++){
				double a = Math.random();
				int v = (int)(a * 6) + 1;
				diceThrown[i][j] = v;	
			System.out.print(diceThrown[i][j] + " ");
			}
			System.out.println();
		}
		
		int t = diceThrown[0][0]
				if int t == diceThrown
		
	}
}
