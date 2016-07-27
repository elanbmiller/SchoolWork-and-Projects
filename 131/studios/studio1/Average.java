package studio1;

import cse131.ArgsProcessor;

public class Average {
	public static void main(String[] args) {
		ArgsProcessor ap = new ArgsProcessor(args);//allows you to save following arguments (how old are you...) and use them
		int n1 = ap.nextInt("How old are you?");
		int n2 = ap.nextInt("What year were you born?");
		System.out.println((n1+n2)/2.0);
	}
}


