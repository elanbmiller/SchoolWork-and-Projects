import java.awt.Color;

import cse131.ArgsProcessor;
import sedgewick.StdDraw;


public class MagicEightBall {

	public static void main(String[] args) {
		ArgsProcessor ap = new ArgsProcessor(args);
		String Question = ap.nextString("What is your question?");
		double b = 0.0;
		for(int i = 0; i < 1; i++){
			b = Math.random();
		}

		StdDraw.filledCircle(.5, .5, .5);


		double[] xValues = new double[] {.2, .5, .8};
		double[] yValues = new double[] {.88, 0.0, .88};


		for(int i = 0; i < 255; i++){
			Color B1 = new Color(0, 0, i);
			Color R1 = new Color(i, 0, 0);

			
			StdDraw.setPenColor(B1);
			StdDraw.filledPolygon(xValues, yValues);
			StdDraw.setPenColor(R1);
			if(b > .5){
				StdDraw.text(.5, .5, "Yes");
			}
			else{
				StdDraw.text(.5, .5, "No");
			}
		}
	}
}
