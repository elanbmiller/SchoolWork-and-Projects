package lab4;

import java.awt.Color;

import sedgewick.StdDraw;

public class Quiz4p2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Color c = StdDraw.RED;

		StdDraw.setPenColor(c);
		StdDraw.filledSquare(.5, .5, .5);
		//StdDraw.clear(color);
		int t = 50;
		StdDraw.show(t);

		while (true){
			StdDraw.setPenColor(c);
			if (c == StdDraw.RED){
				
				c = StdDraw.YELLOW;

			}
			else if (c == StdDraw.YELLOW){
				c = StdDraw.GREEN;

			}
			else if (c == StdDraw.GREEN){
				c = StdDraw.RED;

			}
			StdDraw.filledSquare(.5, .5, .5);
			StdDraw.show(t);
		}

	}

}
