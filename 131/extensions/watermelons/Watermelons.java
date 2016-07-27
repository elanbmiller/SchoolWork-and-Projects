package watermelons;

import java.util.Arrays;

public class Watermelons {

	/**
	 * Computes the sum of each distinct pair of entries in the incoming array.
	 * A given pair of entries has its sum computed only once.  So if you
	 * compute the sum for entries 2 and 4, and that sum appears in your answer
	 * array, then you do not also compute the sum of entries 4 and 2.
	 * Depending on the input, the same sum value may appear multiple times in the result.
	 * For example, if all of the incoming values are 0, then so are all of the returned values.
	 * @param nums an array of integers, possibly containing duplicates
	 * @return an array containing the sums of pairs as described above
	 */
	public static int[] allPairSums(int[] nums) {
		int[] ans = new int[(nums.length * (nums.length - 1))/2];  // FIXME compute ans as the result you want

		int c = 0;

		for(int j = 0; j < nums.length - 1; j++){

			for(int i = j + 1; i < nums.length; i++){

				ans[c] = nums[j] + nums[i];
				c++;
			}
		}
		return ans;
	}

	/**
	 * The method below must COMPUTE and return a solution to the puzzle posted
	 * on the page that describes this extension.  You must compute the solution by trying
	 * lots of possibilities, and finding the one that yields the right answer.
	 * You can run the unit test testPuzzleSolution to see if you are right.
	 * @return
	 */
	public static int[] getSolution() {

		int[] Weights = {20, 22, 23, 24, 25, 26, 27, 28, 30, 31};

		int[] Temp = new int[5];

		for(int i = 0; i <= 31; i++){
			Temp[0] = i;
			for(int j = 0; j <= 31; j++){
				Temp[1] = j;
				for(int k = 0; k <= 31; k++){
					Temp[2] = k;
					for(int l = 0; l <= 31; l++){
						Temp[3] = l;
						for(int m = 0; m <= 31; m++){
							Temp[4] = m;

							int[] determine = allPairSums(Temp);
							Arrays.sort(determine);

							if(Arrays.equals(determine, Weights)){
								return Temp;
							}
						}
					}
				}
			}
		}

		return new int[] { 0 };
	}

}
