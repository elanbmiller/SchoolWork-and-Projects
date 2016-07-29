package assignment10;

import java.io.InputStream;

import studio4.SerialComm;
import assignment4.MsgReceiver;
import assignment4.ViewInputStream;
import assignment4.MsgReceiver.State;

public class Health {

	final private ViewInputStream vis;

	public Health(InputStream in) {
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
				state = State.readingRawValue;

				inputVal = vis.read();
				String inputStringVal = "";
				switch(inputVal){

				case 0x30:
					inputStringVal = "Step Count";
					state = State.readingSteps;
					break;
				case 0x34:
					inputStringVal = "Pulse";
					state = State.readingPulse;
					break;
				}
				System.out.println("input value = " + inputStringVal);
				break;
			case readingSteps:
				state = state.waitingForMagicNumber;
			
				int mSec4 = vis.read();
				int mSec3 = vis.read();
				int mSec2 = vis.read();
				int mSec = vis.read();

				mSec4 = mSec4 << 24;
				mSec3 = mSec3 << 16;
				mSec2 = mSec2 << 8;

				double total = mSec4 + mSec3 + mSec2 + mSec;

				System.out.println("Steps: " + total);
				state = state.waitingForMagicNumber;
				break;
			case readingPulse:
				state = state.waitingForMagicNumber;
				
				int bmSec4 = vis.read();
				int bmSec3 = vis.read();
				int bmSec2 = vis.read();
				int bmSec = vis.read();

				bmSec4 = bmSec4 << 24;
				bmSec3 = bmSec3 << 16;
				bmSec2 = bmSec2 << 8;

				double btotal = bmSec4 + bmSec3 + bmSec2 + bmSec;

				System.out.println("Pulse: " + btotal);
				state = state.waitingForMagicNumber;
				break;
			default:
				state = State.waitingForMagicNumber;
				break;
			}
		}
	}

	public enum State{
		waitingForMagicNumber,
		waitingForInputType,
		readingRawValue,
		readingSteps,
		readingPulse
	};

	public static void main(String[] args) {
		try
		{        	
			SerialComm s = new SerialComm();
			s.connect("COM4"); // Adjust this to be the right port for your machine
			InputStream in = s.getInputStream();
			Health msgr = new Health(in);
			msgr.run();
		}
		catch ( Exception e )
		{
			e.printStackTrace();
			System.out.println("Failed to connect");
		}

	}
}







