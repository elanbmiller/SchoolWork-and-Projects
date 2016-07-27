package lab2;
import cse131.ArgsProcessor;


public class Practicelab2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
ArgsProcessor ap = new ArgsProcessor(args);
		
		
		double rounds = ap.nextInt("how many rounds do you want to play?");
			String random = "";
			String player1 = "";
			
			int tie = 0;
			int player1wins = 0;
			int randomwins = 0;
		
		for (int i=0; i<rounds; i++){
		
			

			double a = Math.random();
			boolean r = ((0.0<a) && (a<=0.33));
			boolean p = ((0.33<a) && (a<=0.66));
			boolean s = ((0.66<a) && (a<=1.0));
			
			String r1 = "rock";
			String p1 = "paper";
			String s1 = "scissors";
			
			if (i % 3 == 0){
				player1 = r1;
			}
			if (i % 3 == 1){
				player1 = p1;
			}
			if (i % 3 == 2){
				player1 = s1;
			}

			
			
			if (r){
				random = r1;
			}
			if (p){
				random = p1;
			}
			if (s){
				random = s1;
				}

			
			if (player1.equals(random)){
				tie = tie + 1;
			}
			
			
			if (player1.equals (r1)  && random.equals (s1)){
				player1wins = player1wins + 1;
			}
			
			if (player1.equals(p1)  && random.equals (r1)){
				player1wins = player1wins + 1;
			}
			if (player1.equals (s1)  && random.equals (p1)){
				player1wins = player1wins + 1;
			}
			
			if (random.equals (r1)  && player1.equals (s1)){
				randomwins = randomwins + 1;
			}
			if (random.equals (p1)  && player1.equals (r1)){
				randomwins = randomwins + 1;
			}
			if (random.equals (s1)  && player1.equals(p1)){
				randomwins = randomwins + 1;
			}
			
			
		
		}
			double player1totalwins = player1wins/rounds;
			double randomtotalwins = randomwins/rounds;
			System.out.println("Percentage of player1 wins: "+ Math.round((player1totalwins*100)*10.0)/10.0 + "%");
			System.out.println("Percentage of random wins: " + Math.round((randomtotalwins*100)*10.0)/10.0 + "%");
}
}