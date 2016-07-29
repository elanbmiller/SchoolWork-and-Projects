package Studio9;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class CountSteps {

	public static void main(String[] args){
		
		FileReader fr = null;
		try {
			fr = new FileReader("data/studio9/Data.csv");
		} catch (FileNotFoundException e){
			e.printStackTrace();
		}
		BufferedReader br = new BufferedReader(fr);
		
		String line = "";
		String xLine = "";
		String yLine = "";
		String zLine = "";
		String[] allVals = new String[1000];
		String[] xs = new String[1000];
		String[] ys = new String[1000];
		String[] zs = new String[1000];
		int i = 0;
		try {
			while((line = br.readLine()) != null){
				allVals = line.split(",");
				xs[i] = allVals[0];
				ys[i] = allVals[1];
				zs[i] = allVals[2];
				i++;
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		for(int j = 0; j < xs.length; j++)
			System.out.print(xs[j] + " ");
		System.out.println();
		for(int k = 0; k < ys.length; k++)
			System.out.print(ys[k] + " ");
		System.out.println();
		for(int l = 0; l < zs.length; l++)
			System.out.print(zs[l] + " ");
	}
	
}
