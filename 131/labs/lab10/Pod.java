package lab10;

import java.awt.Color;

import sedgewick.StdDraw;

/**
 * 
 * @author Elan Miller
 * 431484
 * CSE 131
 * Lab 10: Frogger
 * Creates a pod class  
 *
 */


public class Pod {

	private double x; // center x
	private double y; // center y
	private double height;
	private double width;

	private Color c;
	private int score;
	private boolean isActive;

	public Pod(double x, double y, double height, double width, Color c, boolean isActive){
		this.x = x;
		this.y = y;
		this.height = height;
		this.width = width;
		this.c = c;
		this.isActive = isActive;
	}

	/*
	 * creates pod
	 */

	public void drawPod(){

		double[] xs = new double[]{(x - .5 * width), (x + .5 * width), (x + .5 * width), (x - .5 * width)};	//Creates x values of the logs
		double[] ys = new double[]{(y + .5 * height), (y + .5 * height), (y - .5 * height), (y - .5 * height)};	//Creates y values of the logs

		if(isActive){
			StdDraw.setPenColor(c);
		}
		else{
			StdDraw.setPenColor(StdDraw.GRAY);
		}
		StdDraw.filledPolygon(xs, ys);
	}

	/*
	 * deactivates pod (used when frog hits pod--it turns gray and can't be reached again until the others have been reached)
	 */

	public void deactivate(){

		isActive = false;

	}

	/*
	 * activates pod (makes pods black and not gray so they can be reached by the frog and receive points)
	 */

	public void activate(){

		isActive = true;

	}

	/*
	 * boolean that returns if the pod is active or not
	 */

	public boolean isActive(){

		if(isActive){

			return true;

		}

		else{

			return false;
		}

	}

	/*
	 * returns pod color
	 */

	public Color getColor(){
		return this.c;
	}

	/*
	 * returns pod width
	 */

	
	public double getWidth(){
		return this.width;
	}

	/*
	 * returns pod height
	 */

	public double getHeight(){
		return this.height;
	}
}
