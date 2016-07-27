package lab10;

import java.awt.Color;

import sedgewick.StdDraw;

/**
 * 
 * @author Elan Miller
 * 431484
 * CSE 131
 * Lab 10: Frogger
 * Creates a brick class 
 *
 */

public class Brick {
	private double x;
	private double y;
	private double height;
	private double width;
	private Color c;
	private double speed;

	public Brick(double x, double y, double height, double width, Color c, double speed){
		this.x = x;
		this.y = y;
		this.height = height;
		this.width = width;
		this.c = c;
		this.speed = speed;
	}

	/**
	 * returns x value of brick
	 */

	public double getBrickX(){

		return this.x;

	}

	/*
	 * returns y value of brick
	 */

	public double getBrickY(){

		return this.y;

	}

	/*
	 * returns a boolean that tells if frog has collided with brick
	 * parameter: TheFrog f
	 */

	public boolean isCollidingWith(TheFrog f)		//determines if brick collides with frog f
	{

		if(((f.getX() > (this.x - this.width/2)) && (f.getX() < (this.x + this.width/2)) 
				&& (f.getY() > (this.y - this.height/2)) && (f.getY() < this.y + this.height/2)))
		{
			return true;
		}
		else{
			return false;
		}

	}


	/*
	 * draws brick
	 */

	public void drawBrick(){

		StdDraw.setPenColor(c);

		StdDraw.filledRectangle(x, y, width / 2, height / 2);

	}


	/*
	 * moves brick
	 */

	public void move(){		//move bricks 

		this.x = this.x + speed;

		if(this.x > 1.3){

			this.x = 0;

		}

		if(this.x < -.3){

			this.x = 1;
		}

	}

	/*
	 * increases brick speed (used when frog reaches a pod)
	 */

	public void increaseSpeed(){		//increase brick speed

		if(speed > 0){

			speed += .001;

		}

		else{

			speed -= .001;

		}

	}
}


