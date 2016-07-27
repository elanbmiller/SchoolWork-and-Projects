import java.util.Scanner;


public class Calculator {

	public Calculator() {
	}
	double add(double a, double b){
		return a + b;
	}
	double subtract(double a, double b){
		return a - b;
	}
	double multiply(double a, double b){
		return a * b;
	}
	double divide(double a, double b){
		//if((b % a) == 0){
		return b/a;
		//}
		//		else{
		//			return b/a + " with remainder: " + b % a;
		//		}
	}
	double exponent(double a, double b){

		double answer = 1;

		for(int i = 0; i < b; i++){

			answer *= a;

		}
		return answer;
	}

	public static void main(String[] args) {
		//		System.out.println(add(2,3));
		//		System.out.println(subtract(2,3));
		//		System.out.println(multiply(2,3));
		//		System.out.println(divide(2,3));

		Scanner input = new Scanner(System.in);

		Calculator calc = new Calculator();

		double answer = 0;
		double inputA, inputB;
		char operator;
		boolean done = false;

		while (!done) {
			System.out.print("Please enter your an operation: ");

			inputA = input.nextDouble();
			operator = input.next().charAt(0);
			inputB = input.nextDouble();        

			switch (operator) {
			case '+': answer = calc.add(inputA, inputB);
			break;
			case '-': answer = calc.subtract(inputA, inputB);
			break;
			case '*': answer = calc.multiply(inputA, inputB);
			break;
			case '/': answer = calc.divide(inputA, inputB);
			break;
			case '^': answer = calc.exponent(inputA, inputB);
			break;
			}
			System.out.println(answer);             
		}       
		input.close();
	}	
}
