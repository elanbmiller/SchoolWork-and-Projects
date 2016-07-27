package arrays;
import cse131.ArgsProcessor;

public class PascalsTriangle {

	public static void main(String[] args) {
		ArgsProcessor ap = new ArgsProcessor(args);	

		int N = ap.nextInt("How many rows?");


		int[][] pascal = new int [N][N];

		for(int r = 0; r < pascal.length; r++){
			for(int c = 0; c < N; c++){


				if(c == 0){
					pascal[r][c] = 1;
				}

				else if(r == c){
					pascal[r][c] = 1;
				}
				else if(c > r){
					break;
				}
				else{
					pascal[r][c] = pascal[r-1][c] + pascal[r-1][c-1];
				}
				System.out.print(pascal[r][c]+ " ");

			}
			System.out.println();

		}
	}
}


