package assignment4;

import studio4.SerialComm;

import java.io.*;

public class MsgReceiver {

	final private ViewInputStream vis;

	public MsgReceiver(InputStream in) {
		vis = new ViewInputStream(in);
	}

	public void run() {
		// insert code here
		// read from vis and write to console
		State state = State.waitingForMagicNumber;
		int inputVal = 0;
		int rawTemp = 0;

		while(true){

			switch(state){

			case waitingForMagicNumber:
				if(vis.read() == 0x21)
					state = State.waitingForInputType;
				break;
			case waitingForInputType:							//read input?
				state = State.readingRawTemperature;

				inputVal = vis.read();
				String inputStringVal = "";
				switch(inputVal){

				case 0x30:
					inputStringVal = "Debug String";
					state = State.readingDebugString;
					break;
				case 0x31:
					inputStringVal = "Error String";
					state = State.readingErrorMessage;
					break;
				case 0x32:
					inputStringVal = "Time Stamp";
					state = State.readingTimeStamp;
					break;
				case 0x33:
					inputStringVal = "Potentiometer Value";
					state = State.readingPotentVal;
					break;
				case 0x34:
					inputStringVal = "Raw Temperature";
					state = State.readingRawTemperature;
					break;
				case 0x35:
					inputStringVal = "Converted Temperature";
					state = State.readingConvertedTemperature;
					break;
				case 0x36:
					inputStringVal = "Filtered Temperature";
					state = State.readingFilteredTemperature;
					break;
				default:
					inputStringVal = "Lower Potentiometer!!";
					state = State.waitingForMagicNumber;
					break;
				}
				System.out.println("input value = " + inputStringVal);
				break;
			case readingDebugString:	//or readingErrorMessage
				String debugStr = "";
				char c =' ';
				int visReadVal = vis.read();
				while(((visReadVal < 123)&&(visReadVal > 97)) || ((visReadVal < 91) && (visReadVal > 64))
						|| (visReadVal == 32)){
					c = (char)visReadVal;
					debugStr += c;
					visReadVal = vis.read();
				}
				state = State.waitingForInputType;		//last vis.read() == "!", so go directly to next case
				System.out.println("Debug String: " + debugStr);
				break;
			case readingErrorMessage:	//or readingErrorMessage
				String errStr = "";
				char ch =' ';
				int visVal = vis.read();
				while(((visVal < 123)&&(visVal > 97)) || ((visVal < 91) && (visVal > 64))
						|| (visVal == 32)){
					ch = (char)visVal;
					errStr += ch;
					visVal = vis.read();
				}
				state = State.waitingForInputType;		//last vis.read() == "!", so go directly to next case
				System.out.println("Error Message: " + errStr);
				break;
			case readingTimeStamp:
				state = state.waitingForMagicNumber;
				int mSec4 = vis.read();
				int mSec3 = vis.read();
				int mSec2 = vis.read();
				int mSec = vis.read();

				mSec4 = mSec4 << 24;
				mSec3 = mSec3 << 16;
				mSec2 = mSec2 << 8;

				int total = mSec4 + mSec3 + mSec2 + mSec;

				System.out.println("total sec: " + total);
				break;
			case readingPotentVal:
				state = state.waitingForMagicNumber;
				int firstByte = vis.read();
				int secondByte = vis.read();

				firstByte = firstByte << 8;

				int totalByteVal = firstByte + secondByte;

				System.out.println("Potentiometer Value: " + totalByteVal);
				break;
			case readingRawTemperature:					//read raw temp?
				state = state.waitingForMagicNumber;
				int first = vis.read();
				int second = vis.read();

				first = first << 8;

				int totVal = first + second;

				System.out.println("Raw Temperature: " + totVal);
				break;
			case readingConvertedTemperature:					//read raw temp?
				state = state.waitingForMagicNumber;
				int fourth = vis.read();
				int third = vis.read();
				int secondVal = vis.read();
				int firstVal = vis.read();

				fourth = fourth << 24;
				third = third << 16;
				secondVal = secondVal << 8;

				int totalConvertedTemp = fourth + third + secondVal + firstVal;


				System.out.println("Converted Temperature: " + totalConvertedTemp);
				break;
			case readingFilteredTemperature:					//read raw temp?
				state = state.waitingForMagicNumber;
				int four = vis.read();
				int three = vis.read();
				int two = vis.read();
				int one = vis.read();

				four = four << 24;
				three = three << 16;
				two = two << 8;

				int convertTemp = four + three + two + one;


				System.out.println("Filtered Temperature: " + convertTemp);
				break;	
			default:
				state = State.waitingForMagicNumber;
				//System.out.println("Error!!!!!!!!");
				break;
			}
		}
	}

	public enum State{
		waitingForMagicNumber,
		waitingForInputType,
		readingRawTemperature,
		readingConvertedTemperature,
		readingFilteredTemperature,
		readingTimeStamp,
		readingDebugString,
		readingErrorMessage,
		readingPotentVal
	};
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try
		{        	
			SerialComm s = new SerialComm();
			s.connect("COM4"); // Adjust this to be the right port for your machine
			InputStream in = s.getInputStream();
			MsgReceiver msgr = new MsgReceiver(in);
			msgr.run();
		}
		catch ( Exception e )
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}


/*	print out hex value being read in
	while(true){
		try {
			if(vis.available() > 0){
				vis.read();
				System.out.println(vis.read());
			}
		} catch (IOException e) {
			// FIXME Auto-generated catch block
			e.printStackTrace();
		}
	}
}
 */
