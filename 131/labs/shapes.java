import java.awt.Color;

import sedgewick.StdDraw;
import cse131.ArgsProcessor;


public class shapes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		ArgsProcessor ap = new ArgsProcessor(args);
		int n = ap.nextInt("How many shapes?");
		//StdDraw.setXscale();
		//StdDraw.setYscale();
		StdDraw.setCanvasSize(1200, 900);

		double r = .001;

		//		for (int i = 0; i < 256; i++) {
		//		    StdDraw.setPenColor(Color.getHSBColor(i / 256.0f, 1.0f, 1.0f));
		//		    StdDraw.square(.5, .5, r);
		//		    r+=.01;
		//		}

//						for(int i = 1; i < n; i++){
//								
//							StdDraw.setPenColor(Color.getHSBColor((float) Math.random(), .8f, .8f));
//							//StdDraw.setPenColor();
//							StdDraw.circle(.5, .5, r);
//							r+=.001;
//							StdDraw.show();
//							
//						}



		for(int i = 1; i < n; i++){
			double x = Math.random();
			double y = Math.random();
			double radius = Math.random();
			double r1 = Math.random();

			if(i % 2 == 0){
//				StdDraw.setPenColor(StdDraw.RED);
//				StdDraw.circle(x, y, radius/10);

							StdDraw.setPenColor(Color.getHSBColor((float) Math.random(), .8f, .8f));
							StdDraw.filledCircle(x, y, radius/50.0);
							StdDraw.setPenColor(Color.getHSBColor((float) Math.random(), .8f, .8f));
							double x1 = Math.random();
							double y1 = Math.random();
							StdDraw.filledSquare(x1, y1, radius/50.0);
			}
			else{
//				StdDraw.setPenColor(StdDraw.BLUE);
//				StdDraw.square(x, y, radius/10);
			}
		}
	}

}
