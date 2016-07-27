package lab6;

import java.awt.Color;
import java.util.Set;

import cse131.ArgsProcessor;
import sedgewick.StdDraw;

public class Triangles {

	public static void main(String[] args) {
		ArgsProcessor ap = new ArgsProcessor(args);

		/**
		 * Creates Values for initial Black Triangle
		 * @param x values and y values
		 * @return triangle with x and y values
		 */


		
		double[] xvalues = new double[]{0, .5, 1};
		double[] yvalues = new double[]{0, 1, 0};
		

		StdDraw.setPenColor(StdDraw.BLACK);
		
		
		StdDraw.filledPolygon(xvalues, yvalues);
		
		
		double[] xvalues1 = new double[]{0, .5, 1};
		double[] yvalues1 = new double[]{1, 0, 1};

				StdDraw.setPenColor(StdDraw.GREEN);
				StdDraw.filledPolygon(xvalues1, yvalues1);

		//three points for initial white triangle
		double x = .25;
		double y = .5;
		double x1 = .5;
		double y1 = 0.0;
		double x2 = .75;
		double y2 = .5;

		int n = ap.nextInt("How many triangles?");	//integer determining the number of rounds of triangles to be created
		
		
		triangles(x, y, x1, y1, x2, y2, n);
		
	}

	//method to create new triangles based on initial triangle

	public static void triangles(double x, double y, double x1, double y1, double x2, double y2, int n){


		if(n == 0){			//base case
			return;
		}
		else{
			double[] xvalues = new double[]{x, x1, x2};
			double[] yvalues = new double[]{y, y1, y2};

			for(int i = 0; i < n; i++){
				if(i == 0){
					StdDraw.setPenColor(StdDraw.GREEN);
				}
				else if(i % 2 == 0){
					StdDraw.setPenColor(StdDraw.RED);
				}
				if(i % 3 == 1){
					StdDraw.setPenColor(StdDraw.BOOK_BLUE);
				}
				if(i % 3 == 2){
					StdDraw.setPenColor(StdDraw.GREEN);
				}
				if(i % 4 == 3){
					StdDraw.setPenColor(StdDraw.RED);
				}
				if(i % 4 == 4){
					StdDraw.setPenColor(StdDraw.BOOK_BLUE);
				}
			}

				StdDraw.show(0);
				StdDraw.filledPolygon(xvalues, yvalues);		//draw triangle based on xvalues and yvalues
				
				

				//equations to determine the new points on the three new triangles to be created !!
				triangles((x - (x2 - x1)/2), (y + y1)/2, x, y1, (x + x1)/2, (y + y1)/2, n - 1);
				triangles((x + x1)/2, 2*y2-(y + y1)/2, x1, y, (x1 + x2)/2, 2*y2-(y + y1)/2, n -1);
				triangles((x1 + x2)/2, (y1 + y2)/2, x2, y1, x2 + (x1 + x2)/2 - x1, (y1 + y2)/2, n - 1);
				
			}
		}
	}
