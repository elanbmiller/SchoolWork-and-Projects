import java.util.Random;

import cse131.ArgsProcessor;


public class PrimeNums {

	public static void main(String[] args) {

		ArgsProcessor ap = new ArgsProcessor(args);

		int nth = ap.nextInt("What prime integer would you like?");
		int num, count, i;{
			num=1;
			count=0;
			while (count < nth){
				//System.out.println("back to basics");
				num++; //find the next prime number 

				for (i = 2; i <= num; i++){
					//System.out.println("This is i after loop starts: " + i);
					if (num % i == 0) {
						//System.out.println("This is num: " + num + " And This is i: " + i);
						break; //prime not found
					}
				}
				if ( i == num){
					//System.out.println("This is num: " + num + " And This is i: " + i);
					count++; //prime found
				}
			}
			System.out.println(num);
		}
	}
}
