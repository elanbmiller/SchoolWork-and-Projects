package recursivepatterns;

import java.awt.Color;

import sedgewick.*;

public class PersianRug {

	/**
	 * 
	 * @param palette an array of Colors to choose from
	 * @param llx lower left x coordinate of this rug square
	 * @param lly lower left y coordinate of this rug square
	 * @param size width (and therefore also height) of this rug square
	 * @param north color index of the north side of this rug square
	 * @param east color index of the east side of this rug square
	 * @param south color index of the south side of this rug square
	 * @param west color index of the west side of this rug square
	 */

	private static void persianRug(
			Color[] palette, 
			double llx, double lly,
			double size, 
			int north, int east, int south, int west) {

		if (size < .0035) { // base case, size ridiculously small
			return;
		}	


		int Color = (int) (north + east + west +south + 435) / 6;
		
		Color = Color % 11;

		StdDraw.setPenColor(palette[Color]);


		StdDraw.line(llx+size/2, lly, llx+size/2, lly+size);

		StdDraw.line(llx, lly+size/2, llx+size, lly+size/2);

		persianRug(palette,llx, lly+size/2, size/2, north, Color, Color, west); // top left

		persianRug(palette, llx+size/2, lly+size/2, size/2, north, east, Color, Color); // top right

		persianRug(palette, llx, lly, size/2, Color, Color, south, west); // bottom left

		persianRug(palette, llx+size/2, lly, size/2, Color, east, south, Color); // bottom right


	}

	public static void main(String args[]) {

		//palette of colors

		Color[] palette = { StdDraw.BLUE, StdDraw.CYAN, StdDraw.DARK_GRAY,
				StdDraw.GRAY, StdDraw.GREEN, StdDraw.LIGHT_GRAY,
				StdDraw.MAGENTA, StdDraw.ORANGE, StdDraw.PINK, StdDraw.RED,
				StdDraw.WHITE, StdDraw.YELLOW };
		
		StdDraw.setPenColor(palette[0]);
		StdDraw.line(0, 0, 1, 0);
		StdDraw.line(1, 0, 1, 1);
		StdDraw.line(1, 1, 0, 1);
		StdDraw.line(0, 1, 0, 0);

		// Lower left is point (0,0)
		// Size of the square is 1
		// The color index of each surrounding side is 0

		StdDraw.show(0);
		persianRug(palette, 0.0, 0.0, 1, 0, 0, 0, 0);
		StdDraw.show(0);
	}
}

