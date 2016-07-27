package studio6;

public class Methods {

	// Your methods go below this line


	/**	Factorial of n
	 * @param n
	 * @return factorial of n
	 */

	public static int fact(int n) {
		if (n <= 0)
			return 1;
		else 
			return n * fact(n-1);
	}

	public static void main(String[] args) {
		System.out.println(fact(5));
	}

	/** Gives the nth fibonacci digit
	 * @param n
	 * @return nth fibnacci digit
	 */

	public static int fib(int n){
		if (n > 1)
			return fib(n - 1) + fib(n - 2);
		else
			return n;
	}

	/** Determines whether the nth digit is odd
	 * @param n
	 * @return true--n is odd or false--n is not odd
	 */

	public static boolean isOdd(int n){
		if (n > 0)
			return !isOdd(n - 1);
		else
			return false;

	}

	/** Adds a and b
	 * @param a and b
	 * @return a + b
	 */

	public static int sum(int a, int b){
		if (b > 0)
			return sum(a + 1, b - 1);
		else
			return a;
	}

	public static int harmonicSum(int n){
		if (n > 1)
			return ((int) (1.0 / n)) + harmonicSum(n - 1);
		else 
			return 1;
	}
	public static int sumDownBy2(int n){
		if (n == 1)
			return 1;
		else if (n  == 0)
			return 0;
		else
			return n + sumDownBy2(n - 2);
					
	}
}
