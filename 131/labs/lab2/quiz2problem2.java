package lab2;

import cse131.ArgsProcessor;

public class quiz2problem2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArgsProcessor ap = new ArgsProcessor(args);
		//Given four integers a, b, c, and d, write a program that determines if no two of the 4 integers have the same value.
			int a = ap.nextInt("What is number a?");
			int b = ap.nextInt("What is number b?");
			int c = ap.nextInt("What is number c?");
			int d = ap.nextInt("What is number d?");
			
			
			if (((a == b || a == c)||(a == d)||(b == c || b == d)||(c == d))){
				System.out.println("Two integers have the same value");
				
			}
			else{
				System.out.println("No two integers have the same value");
			}
	}
}
