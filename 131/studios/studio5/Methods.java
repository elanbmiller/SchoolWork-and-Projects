package studio5;

public class Methods {

	/**
	 * Implemented correctly
	 * @param x one thing to add
	 * @param y the other thing to add
	 * @return the sum
	 */
	public static int sum(int x, int y) {
		return x+y;
	}

	/**
	 * 
	 * @param x one factor
	 * @param y another factor
	 * @return the product of the factors
	 */
	public static int mpy(int x, int y) {
		return x * y;  // FIXME
	}
	/**
	 * takes three integers and returns their average as a double
	 */
	public static double avg3(int x, int y, int z){
		return ((x + y + z) / 3);
	}
	public static double sumArray(double [] n ){
		double sum = 0;
		for (int i = 0; i < n.length; i++){
			sum = sum + n[i];

		}
		return sum;
	}
	public static double average(double [] n){
		double avg = 0;
		for (int i = 0; i < n.length; i++){
			avg = (avg + n[i]) / n.length;
		}
		return avg;
	}
	public static double Max(double a, double b){
		double c = Math.max(a, b);
		return  c;	
	}
	public static String pig(String x){
		x = x.substring (1)  + x.substring(0,1) + "ay";
		return x;
	}
}
