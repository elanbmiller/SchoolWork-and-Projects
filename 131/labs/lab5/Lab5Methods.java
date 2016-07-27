package lab5;

/** TA: brianc
 * Grade: 100/100
 * good job
 */

public class Lab5Methods {


	/**summation of j, k times
	 * @param j
	 * @param k
	 * @return j + j + j ...(k times)
	 */
	public static int multPos(int j, int k){

		int sum = 0;

		for(int i = 0; i < k; i++){
			sum += j;

		}
		return sum;
	}

	/**multiplication of j and k
	 * @param j
	 * @param k
	 * @return j * k
	 */
	public static int mult(int j, int k){

		int a = Math.abs(j);
		int b = Math.abs(k);
		multPos(a, b);
		int sign = 1;
		if((j > 0) && (k > 0)){
			sign = 1;
		}
		else if ((j < 0) && (k < 0)){
			sign = 1;
		}
		else if((j == 0)|| (k == 0)){
			sign = 0;
		}
		else{
			sign = -1;
		}
		return multPos(a, b)*sign;
	}

	/** exponents: n to the k power solved through repeated multiplication
	 * @param n
	 * @param k
	 * @return n ^ k  or  n * n * n ...(k times)
	 */
	public static int expt(int n, int k){
		int totalpower = 1;
		for (int i = 0; i < k; i++){
			totalpower *= n;

		}
		return totalpower;
	}

	/** Asks for a string and determines if string is a palindrome
	 * @param s
	 * @return true if palindrome and false if not
	 */

	public static boolean isPalindrome(String s){
		int length = s.length();

		String Sbackwards = "";

		for(int i = 0; i <= length; i++){
			if (i==0)
				Sbackwards = Sbackwards + s.substring(length);
			else
				Sbackwards = Sbackwards + s.substring(length - i, length - i + 1);
		}

		if(s.equals(Sbackwards)){
			return true;
		}
		else{
			return false;
		}
	}


	/**Tests method fibonacci to give the first n numbers in the fibonacci sequence
	 * @param int n
	 * @return first n integers of the fibonacci sequence
	 */

	public static int[] fibonacci(int n){

		int [] a = new int [n];

		for(int i = 0; i < n; i++){
			if(i == 1 || i == 0){		//sets the first two digits of the fibonacci sequence to 1 and 1 respectively
				a[i] = 1;
			}
			else{
				a[i] = a[i - 2] + a[i - 1]; //gives the rest of the fibonacci sequence to the nth number

			}
		}
		return a;
	}

		public static String computeGrade(double[] labs, double[] quizzes, double[] exams, boolean studios, int extensions){
			
			double totallabpoints = 0;
			for(int i = 0; i < labs.length; i++){
				totallabpoints += labs[i];
			}
			
			double totalquizpoints = 0;
			double lowestquizgrade = 1000;		//set variable to 100 to help us determine what the lowest quiz grade is
			for(int i = 0; i < quizzes.length; i++){
				totalquizpoints += quizzes[i];
				if (quizzes[i] < lowestquizgrade){
					lowestquizgrade = quizzes[i];
				}
			}
			
			totalquizpoints = totalquizpoints - lowestquizgrade;
			
			
			double totalexampoints = 0;
			for(int i = 0; i < exams.length; i++){
				totalexampoints += exams[i];
			}
			
			double totalavglabpoints = (totallabpoints / labs.length) * .15;	//weighted lab points
			double totalavgquizpoints = (totalquizpoints / (quizzes.length - 1)) * .1; //weighted quiz points (subtract one from quizzes.length to show that 1 quiz was dropped)
			double totalavgexampoints = (totalexampoints / exams.length) * .45; //weighted exam points
			
			double totalavglabquiztestpoints = totalavglabpoints + totalavgquizpoints + totalavgexampoints; //total weighted lab, quiz and test points
			
			
			//this determines if boolean studios is true and if it is, studioScore is 10 points, which will be added to the overall grade
			int studioScore = 0;
			if(studios){
				studioScore = 10;
			}
			
			
			
			
			double extensionpoints = extensions * .2; 	//weighted extension points
			
			
			double totalgradepoints = extensionpoints + studioScore + totalavglabquiztestpoints; //total grade in points
			String grade = "";	//use grade to assign letter value to grade
			
			
			//letter grade based on totalgradepoints
			if (totalgradepoints >= 97){
				grade = "A+";
			}
			else if(totalgradepoints >= 93){
				grade = "A";
			}
			else if(totalgradepoints >= 90){
				grade = "A-";
			}
			else if(totalgradepoints >= 87){
				grade = "B+";
			}
			else if(totalgradepoints >= 83){
				grade = "B";
			}
			else if(totalgradepoints >= 80){
				grade = "B-";
			}
			else if(totalgradepoints >= 77){
				grade = "C+";
			}
			else if(totalgradepoints >= 73){
				grade = "C";
			}
			else if(totalgradepoints >= 70){
				grade = "C-";
			}
			else if(totalgradepoints >= 60){
				grade = "D";
			}
			else{
				grade = "F";
			}
			
			return grade;
			
		}
}

