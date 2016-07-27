package recursion;

import sedgewick.StdDraw;

public class Dragon {

	public static void main(String[] args) {
		boolean[] turns = { true, true, true, true};
		drawTurns(turns, 1);//FIXME: Replace with a call to your method
	}

	public static boolean[] invertOpposite(boolean[] turns){
		boolean[] turns1 = new boolean[turns.length];
		for(int i = 0; i < turns.length; i++){
			turns1[i] = !turns[turns.length - i - 1];
		}
		return turns1;
	}

	public static boolean[] add(boolean turns, boolean turnLeft){
		for(int i = 0; i <= turns.length; i++){
			when(turns[i] = turns.length){
				turns[i] = turnLeft;
			}
		}
	}


	public static boolean[] turns(int n){

		boolean[] turnLeft = new boolean[]{true};

		if(n == 1){
			return new boolean[]{false};
		}
		else if(n > 1){

			return turns(n - 1) + turnLeft 
		}
	}

	public static void drawTurns(boolean[] turns, int depth) {
		double x0 = 0.5, y0 = 0.5, angle = 0;

		double length = 0.35 / Math.pow(2, depth / 2);

		for (int i = 0; i < turns.length; i++) {

			double x1 = x0 + length * Math.cos(angle);
			double y1 = y0 + length * Math.sin(angle);

			StdDraw.line(x0, y0, x1, y1);
			x0 = x1;
			y0 = y1;
			if (turns[i])
				angle += Math.PI / 2;
			else
				angle -= Math.PI / 2;
			StdDraw.pause((int)(length*1000));

		}

		double x1 = x0 + length * Math.cos(angle);
		double y1 = y0 + length * Math.sin(angle);

		StdDraw.line(x0, y0, x1, y1);

	}

}
