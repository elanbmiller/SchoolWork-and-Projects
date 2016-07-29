package studio4;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.*;

public class SerialTestInput {

	public static void main(String[] args){
		SerialComm sc = new SerialComm();
		try {
			sc.connect("COM4");
		} catch (Exception e) {
			System.out.println("Couldn't Connect to Port");
			e.printStackTrace();
		}

		InputStream is = sc.getInputStream();
		int count = 0;

		ViewInputStream vis = new ViewInputStream(new BufferedInputStream(is));


				while(true){
					try {
						if(vis.available() > 0){
							System.out.print(vis.read());
							//System.out.println(" HEXREAD IS:" + vis.Hexread());
						}
					} catch (IOException e) {
						System.out.println("ViewInputStream failed");
						e.printStackTrace();
					}
				}
				

		//InputStream is = sc.getInputStream();
		//int count = 0;

		//		while(true){
		//			try {
		//				if(is.available() > 0){
		//					if((count % 11) == 0){
		//					System.out.print((int)is.read() + "	");
		//					System.out.println();
		//					count++;
		//					}
		//					else{
		//						System.out.print((int)is.read() + "	");
		//						count++;	
		//					}
		//			}
		//			} catch (IOException e) {
		//				System.out.println("Isstream failed");
		//				e.printStackTrace();
		//			}
		//		}


	}

}
