package lab3;

import cse131.ArgsProcessor;

public class MineSweeper {

	public static void main (String[] args) {

		//
		// Do not change anything between here ...
		//
		ArgsProcessor ap = new ArgsProcessor(args);
		int rows = ap.nextInt("How many rows?");
		int cols = ap.nextInt("How many columns?");
		double percent = ap.nextDouble("What is the probability of a bomb?");
		//
		// ... and here
		//
		//  
		//
		rows = rows + 2;
		cols = cols + 2;
		String[][] a = new String [rows][cols];
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				double random = Math.random();

				if ((random < percent) && ((i != 0 && i != (rows-1)) && ((j != 0 && j != (cols-1))))){
					a [i][j] = "*";
					
				}
				else{
					a [i][j] = ".";
					
				}
				if ((i != 0 && i != (rows-1)) && ((j != 0 && j != (cols-1)))){
				System.out.print(a[i][j]);
				}
			}
			System.out.println();
		}

		System.out.println();
		String[][] b = new String [rows][cols];
		for (int i = 1; i < rows-1; i++){
			for (int j = 1; j <cols-1; j++){
				int counter = 0;
				if ((a[i][j].equals("*"))){
					b [i][j] = "*";
				}
				else{
					if (a[i-1][j-1].equals ("*")){
						counter = counter + 1; 
					}
					if (a[i-1][j].equals("*")){
						counter = counter + 1;
					}
					if (a[i-1][j+1].equals("*")){
						counter = counter + 1;
					}
					if (a[i][j-1].equals("*")){
						counter = counter + 1;
					}
					if (a[i][j+1].equals("*")){
						counter = counter + 1;
					}
					if (a[i+1][j-1].equals("*")){
						counter = counter + 1;
					}
					if (a[i+1][j].equals("*")){
						counter = counter + 1;
					}
					if (a[i+1][j+1].equals("*")){
						counter = counter + 1;
					}
					b [i][j] = "" + counter;	
				}
				System.out.print(b[i][j]);
			}
			System.out.println();
		}
	}
}
