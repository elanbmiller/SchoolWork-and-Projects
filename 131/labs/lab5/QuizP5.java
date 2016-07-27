package lab5;

public class QuizP5 {
//
	public static void main(String[] args) {
		// TODO Auto-generated method stub


		double a = 1.0;
		double b = 5.0;
		double c = 3.0;
		System.out.println(isFirstLessThan(a, b, c));
		System.out.println(areEachLessThan(a, b, c));

	}

	public static boolean isFirstLessThan(double a, double b, double c){
		if(a < (b + c)){
			return true;
		}
		return false;
	}

	public static boolean areEachLessThan(double a, double b, double c){
		if (isFirstLessThan(a, b, c) && isFirstLessThan(c, a, b) && isFirstLessThan(b, a, c)){
			return true;
		}
		else{
			return false;
		}
	}

}

