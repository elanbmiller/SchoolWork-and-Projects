import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;


public class ButterworthFilter2 {

	public static void main(String[] args) {
		FileReader fr = null;
		try {
			fr = new FileReader("data/studio10/Studio10Data.xlsx");
		} catch (FileNotFoundException e){
			e.printStackTrace();
		}
		BufferedReader br = new BufferedReader(fr);

		int count = 0;
		long y = 0;
		long y2 = 0;
		String line = "";
		while((line = br.readLine()) != null){
			if(count == 0){
				y += 0.01036382*((int)line);
				count++;
			}
			else if(count == 1){
				y += 0;
				count++;
			}
			else if(count == 2){
				y += −0.01036382*((int)line);
				y2 = y;
				count++;
			}
			else if(count == 3){
				y += 1.9789467705*y;
				count++;
			}
			else{
				y = y - 0.97927235*(y2);
				count = 0;
			}

		}

		System.out.println("Y: " + y);
	}

}
