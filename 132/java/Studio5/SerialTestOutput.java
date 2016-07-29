package Studio5;

import java.io.OutputStream;
import java.util.Scanner;

import studio4.SerialComm;

public class SerialTestOutput {


	public static void main(String[] args){

		Scanner reader = new Scanner(System.in);
		System.out.println("Enter a string (up to 16 characters): ");
		String str = reader.nextLine();
		int endOfLine = 0x0d;
		//System.out.println("Input : " + str);


		SerialComm sc = new SerialComm();
		try {
			sc.connect("COM4");
		} catch (Exception e) {
			System.out.println("ERROR: Couldn't Connect To Port!");
			e.printStackTrace();
		}


		OutputStream OldOut = sc.getOutputStream();
		ViewOutputStream out = new ViewOutputStream(OldOut);

		//System.out.println("LENGTH: " +str.length());

		out.write(5);
		for(int i = 0; i < str.length(); i++){
			
			
			if(i == str.length() - 1){
				out.write((int)str.charAt(i));
				break;
			}
				try {
					Thread.sleep(1500);
				} catch (InterruptedException e) {

					e.printStackTrace();
				}
				

				out.write((int)str.charAt(i));		//send each char byte
				

		}
		System.out.println("Getting in EndOfLIne");
		out.write(endOfLine);			//send end of line			
	}


}
