package lines;

import java.awt.Color;

import sedgewick.StdDraw;

public class Lines {

	/**
	 * 
	 * @param x1 x coordinate of starting point
	 * @param y1 y coordinate of starting point
	 * @param x2 x coordinate of ending point
	 * @param y2 y coordinate of ending point
	 */
	public static void drawLine(double x1, double y1, double x2, double y2) {
		// FIXME -- fill in this method according to the instructions
		if(Math.abs(x1 - x2) < .01 && Math.abs(y1 - y2) < .01){
			return;
		}
		if ((x1 < x2) && (y1 < y2)){
			StdDraw.setPenRadius(.01);
			StdDraw.point(x1, y1);
			drawLine(x1 + .001, y1 + .001, x2 , y2);
		}
		if((x1 < x2) && (y1 > y2)){
			StdDraw.setPenRadius(.01);
			StdDraw.point(x1, y1);
			drawLine(x1 + .001, y1 - .001, x2 , y2);
		}
		if((x1 > x2) && (y1 > y2)){
			StdDraw.setPenRadius(.01);
			StdDraw.point(x1, y1);
			drawLine(x1 - .001, y1 - .001, x2 , y2);
		}
		if((x1 > x2) && (y1 < y2)){
			StdDraw.setPenRadius(.01);
			StdDraw.point(x1, y1);
			drawLine(x1 - .001, y1 + .001, x2 , y2);
		}
		if((x1 == x2) && (y1 < y2)){
			StdDraw.setPenRadius(.01);
			StdDraw.point(x1, y1);
			drawLine(x1, y1 + .001, x2 , y2);
		}
		if((y1 == y2) && (x1 < x2)){
			StdDraw.setPenRadius(.01);
			StdDraw.point(x1, y1);
			drawLine(x1 + .001, y1, x2 , y2);
		}
		if((y1 == y2) && (x1 > x2)){
			StdDraw.setPenRadius(.01);
			StdDraw.point(x1, y1);
			drawLine(x1 -.001, y1, x2 , y2);
		}
		if((x1 == x2) && (y1 > y2)){
			StdDraw.setPenRadius(.01);
			StdDraw.point(x1, y1);
			drawLine(x1, y1 - .001, x2 , y2);
		}
	}
	/**
	 * Code to test the drawLine method visually
	 */
	public static void main(String[] args) {

		//
		// Test the drawing program
		//
		drawLine(0,0,1,1); // lower left to upper right
		drawLine(0,1,1,0); // upper left to lower right
//		drawLine(.2, 0, .2, .9);
//		drawLine(0, .5, .7, .5);
//		drawLine(.5, .3, .1, .3);
//		drawLine(.5, .7, .5, .3);

		
		// Draw rectangles of decreasing width and height
		
				for (double r = 0.25; r < 0.5; r = r+.005) {
					double s = 1-r;
					drawLine(r,r, r, s);
					drawLine(r, s, s, s);
					drawLine(s, s, s, r);
					drawLine(s, r, r, r);
				}
		System.out.println("done drawing");
	}

}
