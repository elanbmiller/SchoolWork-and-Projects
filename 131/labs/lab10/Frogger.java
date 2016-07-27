package lab10;

import sedgewick.StdDraw;

/**
 * 
 * @author Elan Miller
 * 431484
 * CSE 131
 * Lab 10: Frogger
 * Creates a frogger game 
 *
 */

public class Frogger implements FroggerGame {


	private Brick[] traffic;	
	private int score;
	private int life;

	
	public void playGame() {


		StdDraw.setPenColor(StdDraw.YELLOW);		//intro screen
		StdDraw.filledSquare(.5, .5, .9);



		StdDraw.setPenColor(StdDraw.MAGENTA);
		StdDraw.filledSquare(.5, .5, .3);

		StdDraw.setPenRadius(.05);
		StdDraw.setPenColor(StdDraw.RED);
		StdDraw.square(.5, .5, .3);

		StdDraw.setPenColor(StdDraw.GREEN);

		StdDraw.filledSquare(.25, .25, .025);
		StdDraw.pause(500);

		StdDraw.filledSquare(.5, .25, .025);
		StdDraw.pause(500);

		StdDraw.filledSquare(.75, .25, .025);
		StdDraw.pause(500);

		StdDraw.filledSquare(.75, .5, .025);
		StdDraw.pause(500);

		StdDraw.filledSquare(.75, .75, .025);
		StdDraw.pause(500);

		StdDraw.filledSquare(.5, .75, .025);
		StdDraw.pause(500);

		StdDraw.filledSquare(.25, .75, .025);
		StdDraw.pause(500);

		StdDraw.filledSquare(.25, .5, .025);
		StdDraw.pause(500);

		StdDraw.setPenRadius(1);
		StdDraw.setPenColor(StdDraw.BLUE);
		StdDraw.text(.5, .5, "Frogger");



		StdDraw.pause(2000);					//end of intro screen


		traffic = new Brick[3];

		traffic [0] = new Brick (0, .2, .05, .15, StdDraw.RED, .001);		//Create the brick
		traffic [1] = new Brick(0, .4, .05, .15, StdDraw.RED, .001);
		traffic [2] = new Brick(.5, .6, .05, .15, StdDraw.RED, -.001);



		TheFrog frog = new TheFrog(.5, .0001, 3);	//Creates the frog

		frog.drawFrog();


		Pod p  = new Pod(.5, .95, .12, .12, StdDraw.BLACK, true);	//Create first pod


		Pod p2 = new Pod(.2, .95, .12, .12, StdDraw.BLACK, true);	//Create second pod


		Pod p3 = new Pod(.8, .95, .12, .12, StdDraw.BLACK, true);	//Create third pod

		score = 0;			//start off initial score at 0
		life = 3;			//start off amount of lives at 3


		while(true){

			StdDraw.show(1);

			StdDraw.clear();

			traffic[0].drawBrick();		//draw brick

			traffic[1].drawBrick();

			traffic[2].drawBrick();


			p.drawPod();		//draw the pods

			p2.drawPod();

			p3.drawPod();

			frog.drawFrog();						//Draw frog


			traffic[0].move();			//keep bricks moving
			traffic[1].move();
			traffic[2].move();


			StdDraw.setPenColor(StdDraw.MAGENTA);			//print score and lives in upper right corner
			StdDraw.text(.95, .98, "SCORE: " + score);
			StdDraw.text(.93, .94, "LIVES: " + life);




			if(ArcadeKeys.isKeyPressed(0, 0)){	//if w is pressed

				frog.moveUp();	//move up


			}

			else if(ArcadeKeys.isKeyPressed(0, 2)){	//if s is pressed

				frog.moveDown();	//move down 


			}

			else if(ArcadeKeys.isKeyPressed(0, 3)){	//if d is pressed

				frog.moveRight();	//move right 


			}

			else if(ArcadeKeys.isKeyPressed(0, 1)){	//if a is pressed

				frog.moveLeft();	//move left


			}
			//if the frog reaches the pod and it hasn't reached it on this round add points and deactivate pod
			if ((frog.getX() >= .14 && frog.getX() <= .26) && (frog.getY() <= 1.01 && frog.getY() >= .89) && p2.isActive()){

				p2.deactivate();

				p2.drawPod();

				score += 1;

				
				int rand =  (int) Math.round((Math.random()*2));
				
				
				traffic[rand].increaseSpeed();			//increase speed of bricks each time you get points
				//traffic[1].increaseSpeed();
				//traffic[2].increaseSpeed();

				frog.setCoordinates();	//reset frog to beginning

				frog.drawFrog();
				

			}

			if((frog.getX() >= .44 && frog.getX() <= .56) && (frog.getY() <= 1.01 && frog.getY() >= .89) && p.isActive()){

				p.deactivate();

				p.drawPod();

				score += 1;

				traffic[0].increaseSpeed();
				traffic[1].increaseSpeed();
				traffic[2].increaseSpeed();

				frog.setCoordinates();	//reset frog to beginning

				frog.drawFrog();

			}

			if((frog.getX() >= .74 && frog.getX() <= .86) && (frog.getY() <= 1.01 && frog.getY() >= .89) && p3.isActive()){

				p3.deactivate();

				p3.drawPod();

				score += 1;

				traffic[0].increaseSpeed();
				traffic[1].increaseSpeed();
				traffic[2].increaseSpeed();

				frog.setCoordinates();	//reset frog to beginning

				frog.drawFrog();

			}

			if(traffic[0].isCollidingWith(frog)){		//test if there's a collision
				frog.setCoordinates();					//reset coordinates
				life -= 1;								//decrement life

			}

			if(traffic[1].isCollidingWith(frog)){		

				frog.setCoordinates();		
				life -= 1;					

			}

			if(traffic[2].isCollidingWith(frog)){

				frog.setCoordinates();
				life -= 1;

			}

			if(score % 3 == 0 && score != 0){		//this makes all three of the pods reactivate after they've all been deactivated	

				p.activate();
				p2.activate();
				p3.activate();

			}


			//if player runs out of lives
			if(life == 0){

				StdDraw.setPenColor(StdDraw.YELLOW);		//closing screen
				StdDraw.filledSquare(.5, .5, .9);

				StdDraw.setPenColor(StdDraw.WHITE);
				StdDraw.filledSquare(.5, .5, .3);

				StdDraw.setPenRadius(.05);
				StdDraw.setPenColor(StdDraw.RED);
				StdDraw.square(.5, .5, .3);

				StdDraw.setPenColor(StdDraw.GREEN);

				StdDraw.show(1);


				StdDraw.filledSquare(.25, .25, .025);
				StdDraw.pause(500);
				StdDraw.show(1);


				StdDraw.filledSquare(.5, .25, .025);
				StdDraw.pause(500);
				StdDraw.show(1);


				StdDraw.filledSquare(.75, .25, .025);
				StdDraw.pause(500);
				StdDraw.show(1);


				StdDraw.filledSquare(.75, .5, .025);
				StdDraw.pause(500);
				StdDraw.show(1);


				StdDraw.filledSquare(.75, .75, .025);
				StdDraw.pause(500);
				StdDraw.show(1);


				StdDraw.filledSquare(.5, .75, .025);
				StdDraw.pause(500);
				StdDraw.show(1);


				StdDraw.filledSquare(.25, .75, .025);
				StdDraw.pause(500);
				StdDraw.show(1);


				StdDraw.filledSquare(.25, .5, .025);
				StdDraw.pause(500);
				StdDraw.show(1);
				StdDraw.pause(750);


				StdDraw.setPenRadius(1);
				StdDraw.setPenColor(StdDraw.BLUE);
				StdDraw.text(.5, .5, "Game Over");
				StdDraw.show(1);
				StdDraw.pause(2000);	//end of closing screen

				// Reset game parameters
				life = 3;
				score = 0;

				p.activate();		//reset pods
				p2.activate();
				p3.activate();

				traffic = new Brick[3];

				traffic [0] = new Brick (0, .2, .05, .15, StdDraw.RED, .001);		//Reset the brick speeds
				traffic [1] = new Brick(0, .4, .05, .15, StdDraw.RED, .001);
				traffic [2] = new Brick(.5, .6, .05, .15, StdDraw.RED, -.001);

			}

		}

	}

	@Override
	public String getGameName() {
		return "Frogger";
	}

	@Override
	public String[] getTeamMembers() {
		return new String[] {"Elan Miller"};
	}

}
