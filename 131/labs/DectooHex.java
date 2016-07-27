import java.io.FileNotFoundException;
import java.io.PrintStream;


public class DectooHex {

	public static void main(String[] args) throws FileNotFoundException {
		//System.out.println("0X" +(myReverse(decToHex(105))));
		int val = 108;
		String hex = Integer.toHexString(val);
		
		System.out.println(hex);
		
	}

	public static String decToHex(int dec){
		String temp = "";
		String parsedNum = "";
		int intDivOne = 0;
		double doubDivOne = 0;

		int toParse = 0;

		while(dec > 16){
			intDivOne = dec / 16;
			doubDivOne = (double)dec/16.0;

			toParse = (int) (((double)(doubDivOne - intDivOne))*16.0);
			parsedNum = Integer.toString(toParse);
			
			temp+= parsedNum;
			
			dec = intDivOne;
		}
		if(dec <= 16){
			intDivOne = dec / 16;
			doubDivOne = (double)dec/16.0;

			toParse = (int) (((double)(doubDivOne - intDivOne))*16.0);

			parsedNum = Integer.toString(toParse);

			temp+= parsedNum;
			
			
			dec = intDivOne;

			
			
			return temp;
		}

		return temp;
	}
	
	public static String myReverse(String str) {
	    String reverse = "";
	    int length = str.length();
	    for( int i = length - 1 ; i >= 0 ; i--)
	       reverse = reverse + str.charAt(i);
	    return reverse;
	}
}
