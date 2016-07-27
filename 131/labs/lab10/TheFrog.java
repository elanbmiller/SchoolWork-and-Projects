package lab10;

import java.awt.Color;

import sedgewick.StdDraw;

/**
 * 
 * @author Elan Miller
 * 431484
 * CSE 131
 * Lab 10: Frogger
 * Creates a frog class 
 *
 */

public class TheFrog {
	private double x;
	private double y;
	private int lives;

	public TheFrog(double x, double y, int lives){
		this.x = x;
		this.y = y;
		this.lives = lives;
	}

	/**
	 * Draws frog
	 */

	public void drawFrog(){

		StdDraw.setPenColor(StdDraw.GREEN);

		StdDraw.filledSquare(x, y, 0.025);

	}


	/**
	 * Moves frog up
	 */

	public void moveUp(){

		if(this.y < 1.009){

			this.y += .002;

		}

		drawFrog();

	}

	/**
	 * moves frog down
	 */

	public void moveDown(){

		if(this.y > .009){

			this.y += -.002;

		}

		drawFrog();

	}

	/**
	 * moves frog to the right
	 */

	public void moveRight(){

		if(this.x < 1.009){

			this.x += .002;

		}

		drawFrog();

	}

	/**
	 * moves frog to the left
	 */

	public void moveLeft(){

		if(this.x >.009){

			this.x += -.002;

		}

		drawFrog();

	}


	/**
	 * returns x value of frog
	 */

	public double getX(){

		return this.x;

	}

	/**
	 * returns y value of frog
	 */

	public double getY(){

		return this.y;

	}

	/**
	 * resets frogs coordinates to starting position (used when frog reaches a pod or hits a brick)
	 */

	public void setCoordinates(){		//reset frog coordinates

		this.x = .5;

		this.y = .0001;

	}

}





