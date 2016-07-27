package lab4;

import sedgewick.StdDraw;
import cse131.ArgsProcessor;

public class BumpingBalls {

	public static void main(String[] args) {
		ArgsProcessor ap = new ArgsProcessor(args);
		int number = ap.nextInt("How many balls?");
		int time = ap.nextInt("How long?");


		double [][] positions = new double [number][4];

		for (int i = 0; i < number; i++){

			positions[i][0] = Math.random();		//setting a random x
			positions[i][1] = Math.random();		//setting a random y
			positions[i][2] = Math.random()/50.0;	//setting a random x velocity
			positions[i][3] = Math.random()/50.0;	//setting a random y velocity
		}

		double nextx; //next position for x
		double nexty; //next position for y

		for (int j = 0; j < time; j++){

			StdDraw.show(40);
			StdDraw.clear();		

			for (int i = 0; i < number; i++){

				nextx = positions[i][0] + positions[i][2]; //add x and x velocity
				if (nextx >= 0.95){ 
					positions[i][2] = -positions[i][2];

				}
				else if (nextx <= 0.05){
					positions[i][2] = -positions[i][2];
				}
				nexty = positions[i][1] + positions[i][3];
				if (nexty >= .95){ 
					positions[i][3] = -positions[i][3];
				}
				else if (nexty <= 0.05){
					positions[i][3] = -positions[i][3];
				}
				positions [i][0] = positions [i][0] + positions [i][2];
				positions [i][1] = positions [i][1] + positions [i][3];


				

				for (int d = 0; d < number; d++){
					if (Math.sqrt((positions [i][0]-positions [d][0])*(positions [i][0]-positions [d][0])+ (positions [i][1]-positions [d][1])*(positions [i][1]-positions [d][1])) <= .1){
						positions[i][2] = -positions[i][2];
						positions[i][3] = -positions[i][3];
						positions[d][2] = -positions[d][2];
						positions[d][3] = -positions[d][3];
//						System.out.println(Math.sqrt((positions [i][0]-positions [d][0])*(positions [i][0]-positions [d][0])+ (positions [i][1]-positions [d][1])*(positions [i][1]-positions [d][1])));
					
					}
					StdDraw.filledCircle(positions[i][0], positions[i][1], .05);
				}
			}

		}
	}

}
