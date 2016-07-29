package assignment4;

import java.io.*;

import javax.swing.JFrame;

import studio4.PrintStreamPanel;

public class ViewInputStream extends FilterInputStream {

    final private PrintStreamPanel psp;
    final private PrintStream ps;

    public ViewInputStream(InputStream in) {
        super(in);
        JFrame f = new JFrame("ViewInputStream");
		f.setBounds(100,100,225,300);
        psp = new PrintStreamPanel();
		f.getContentPane().add(psp);
		f.setVisible(true);
        ps = psp.getPrintStream(); 
    }

    public int read() {
        // TODO
        // use super.read() to access the next byte from the InputStream
        // also, you can use ps like System.out to print to the new window
    	int readValue = 0;
		try {
			readValue = super.read();
		} catch (IOException e) {
			System.out.println("Couldn't Read Anything");
			e.printStackTrace();
		}
    	
    	String hex = Integer.toHexString(readValue);
		ps.println("0x"+ hex);
		
		String finalHex = " " + hex;
		
		return readValue;

    }
    
}
