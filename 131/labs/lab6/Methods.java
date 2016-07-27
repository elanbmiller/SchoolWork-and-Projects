package lab6;

import cse131.ArgsProcessor;

/*	TA: RohanB
* 	Grade: 94/100
* 	Missing javadoc for f(int x): -2
* 	Missing javadoc with author at the start of class: -2
* 	Missing javadoc for drawTrinagles in Triangles.java: -2
* 	Generate javadoc outside method. Not inside main() in Triangles.java.: 0
*/

public class Methods {

	//
	// In this class, implement the f and g functions described on the lab page
	//


	public static int f(int x){
		if (x > 100){
			return x - 10;
		}
		else{
			return f(f(x+11));
		}


	}

	/**Main method that prints out the results of f, expt, and isPalindrome
	 * @param args
	 */
	public static void main(String[] args) {

		int a = f(87);
		System.out.println(a);

		System.out.println(expt(2, 3));
		System.out.println(isPalindrome("racecar"));
		//
		// from here, call f or g with the appropriate parameters
		//

	}
	/**
	 * Finds x^y recursively
	 * @param x
	 * @param y
	 * @return x^y
	 */

	public static int expt(int x, int y){
		if(y == 0){		//base case
			return 1;
		}
		else{
			return(x * (expt(x, (y-1))));
		}
	}

	/**
	 * Determines if string is a palindrome
	 * @param string
	 * @return true or false
	 */

	public static boolean isPalindrome(String string){
		if(string.length() == 1 || string.length() == 0){
			return true;
		}
		else if(string.charAt(0) == string.charAt(string.length() - 1)){
			return isPalindrome(string.substring(1, string.length()-1));

		}
		else 
			return false;
	}






}
