package recursivepatterns;


import java.awt.Color;

import sedgewick.StdDraw;


public class Flower {
	
	/**
	 * 
	 * @param x x coordinate of the center of this ellipse
	 * @param y y coordinate of the center of this ellipse
	 * @param halfWidth half the width of this ellipse
	 * @param halfHeight half the height of this ellipse
	 * @param count depth of the recursion, initial call passes 0
	 */
	private static void flower(Color[] palette, double x, double y, double halfWidth, double halfHeight, int count){
		if(count == 6)
			return;
		
		else{
			Color color = (palette[(int) (Math.random() * 12)]);
			StdDraw.setPenColor(color);
			StdDraw.filledEllipse(x, y , halfWidth, halfHeight);


			flower(palette, x + halfWidth / 2, y, halfWidth / 2, halfHeight / 2, count + 1);
			flower(palette, x - halfWidth / 2, y, halfWidth / 2, halfHeight / 2, count + 1);

			flower(palette, x, y - (halfWidth / 1.21) , halfWidth / 2, halfHeight / 2, count + 1);
			flower(palette, x, y + (halfWidth / 1.21) , halfWidth / 2, halfHeight / 2, count + 1);
		}
	}


	public static void main(String args[]) {
		
		//palette of colors
		Color[] palette = { StdDraw.BLACK, StdDraw.BLUE, StdDraw.CYAN,
				StdDraw.DARK_GRAY, StdDraw.GRAY, StdDraw.GREEN,
				StdDraw.LIGHT_GRAY, StdDraw.MAGENTA, StdDraw.ORANGE,
				StdDraw.PINK, StdDraw.RED, StdDraw.WHITE, StdDraw.YELLOW };
	



		for (int i=0; i < palette.length; ++i) {
			palette[i] = TransparentColor.transparentColor(palette[i], 70);
		}

		
		// Center is at (0.5, 0.5), half-width .3, half-height .5, depth is 0
		
		flower(palette, .5, .5, .35, .5, 0);
		
	}

}
