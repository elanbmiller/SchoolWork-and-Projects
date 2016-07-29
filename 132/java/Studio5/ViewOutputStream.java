package Studio5;

import java.io.*;

import javax.swing.JFrame;

import studio4.PrintStreamPanel;

public class ViewOutputStream extends FilterOutputStream {

	final private PrintStreamPanel psp;
	final private PrintStream ps;

	 public ViewOutputStream(OutputStream out) {
	        super(out);
	        JFrame f = new JFrame("ViewOutputStream");
			f.setBounds(100,100,225,300);
	        psp = new PrintStreamPanel();
			f.getContentPane().add(psp);
			f.setVisible(true);
	        ps = psp.getPrintStream(); 
	    }
	 
	public void write(int b) {
		ps.println(" 0x" + Integer.toHexString(b));
		try {
			super.write(b);
		} catch (IOException e) {
			System.out.println("Couldn't write hexNum to outputStream");
			e.printStackTrace();
		}
		
	
	}
}
