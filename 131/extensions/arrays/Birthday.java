package arrays;
import cse131.ArgsProcessor;

public class Birthday {

	public static void main(String[] args) {

		ArgsProcessor ap = new ArgsProcessor(args);	


		int n = ap.nextInt("How many people in room?");

		//array with months as rows and days as columns
		int[][] bdays = new int [13][32]; 

		//fill array with 0's	
		for(int i = 0; i < 12; i++){
			for(int j = 0; j < 31; j++){
				bdays[i][j] = 0;
			}
		}

		//set arrays to count how many bdays in a specific month or day
		int[] monthbday = new int [12];
		int[] daybday = new int [31];

		//fill bday array with values
		for(int i = 0; i < n; i++){
			int a = (int) (Math.random()*12);
			int b = (int) (Math.random()*31);
			bdays[a][b] = bdays[a][b] + 1;

			//adds 1 to each slot for months and days
			monthbday[a]++;
			daybday[b]++;
		}

		System.out.println("MONTHS");
		for(int i = 0; i < 12; i++){
			double samemonth = ((double)monthbday[i]/n);	//assign variable to average of same month bdays
			System.out.println("Month"+ (i + 1)+ ":" + Math.round((samemonth*100.0)*10.0)/10.0 + "%");
		}
		double monthavg = 0.0;	//assign variable to count all avgs for each month
		for(int i = 0; i < 12; i++){
			monthavg += monthbday[i];

		}
		double monthavg1 = monthavg / n; 	//fraction of total bdays in all the months divided by the number of people
		System.out.println("Average Bdays Per Month " + (monthavg1 / 12)*100.0 + " %"); //prints out average # of bdays per month
		System.out.println("DAYS");
		for(int j = 0; j < 31; j++){
			double sameday = ((double)daybday[j]/n);	//assign variable to average of same day bdays
			System.out.println("Day"+ (j + 1)+ ":" +Math.round((sameday*100.0)*10.0)/10.0 + "%");
		}
		double dayavg = 0.0;	//assign variable to count all avgs for each day
		for(int j = 0; j < 31; j++){
			dayavg += daybday[j];
		}
		double dayavg1 = dayavg / n;	//fraction of total bdays on all days divided by the number of people
		System.out.println("Average Bdays per day " + (dayavg1 / 31)*100.0 + " %"); //prints out average # of bdays per day


		//determine the amount of bdays that overlap with another bday
		int samebdays = 0;

		for(int i = 0; i < 12; i++){
			for(int j = 0; j < 31; j++){

				if (bdays[i][j] > 1){
					samebdays = samebdays + bdays[i][j];
				}


			}
		}
		//Print out the percentage of bdays that overlap with another one
		float totalsamebdays = Math.round(((double)samebdays/n)*100);
		System.out.println("total number of bdays that overlap " + totalsamebdays + "%");

	}

}
