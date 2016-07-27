package lab1;

import cse131.ArgsProcessor;

public class Nutrition {

	public static double fCarbs(double carbs) {
		return ((4*carbs)*(10.0))/10.0;
	}
	public static double fFat(double fat) {
		return ((9*fat)*(10.0))/10.0;
	}
	public static double fProt(double protein) {
		return (4*protein)*(10.0)/10.0;
	}
	public static double fTotalCarb(double carbs, double fat, double prot) {
		return 4*carbs+9*fat+4*prot;
	}
	public static double fUnavCal(double totalCarb, double statedCals) {
		return totalCarb-statedCals;
	}
	public static double fcaloriesofcarb(double carbs) {
		return 4*carbs;
	}
	public static double fcaloriesoffat(double fat) {
		return 9*fat;
	}
	public static double fcaloriesofprotein(double protein) {
		return 4*protein;
	}
	public static double fdivision(double x, double y) {
		return x / y;
	}
	public static double frounding(double z) {
		return (Math.round((z*100)*10.0)/10.0);
	}
	public static double fmultiply(double a) {
		return a * 100;
	}

	public static void main(String[] args) {
		ArgsProcessor ap = new ArgsProcessor(args);
		String name = ap.nextString("What is the name of the food?");
		double carbs = ap.nextDouble("How many grams of carbs?");
		double fat = ap.nextDouble("How many grams of fat?");
		double protein = ap.nextDouble("How many grams of protein?");
		double statedCals = ap.nextDouble("How many calories on the label?");

		System.out.println(name + " has ");
		System.out.println(carbs + " grams of carbohydrates= "+ (fCarbs(carbs) +" Calories"));
		System.out.println(fat + " grams of fat= " + (fFat(fat)+" Calories"));
		System.out.println(protein+" grams of protein= "+(fProt(protein)+" Calories"));

		System.out.println("This food is said to have "+ (statedCals +" (available) calories"));
		double totalCarb=fTotalCarb(carbs, fat, protein);
		double UnavCal=fUnavCal(totalCarb, statedCals);
		System.out.println("with "+ Math.round((UnavCal*10.0))/10.0 + " unavailable Calories, this food has " + Math.round((UnavCal/4*10.0))/10.0 + " grams of fiber");

		double caloriesofcarb=fcaloriesofcarb(carbs);
		double caloriesoffat=fcaloriesoffat(fat);
		double caloriesofprotein=fcaloriesofprotein(protein);

		double CarbPercent=fdivision(caloriesofcarb, statedCals);
		double FatPercent=fdivision(caloriesoffat, statedCals);
		double ProteinPercent=fdivision(caloriesofprotein, statedCals);

		System.out.println("Approximately");
		System.out.println (frounding(CarbPercent)+"% "+"of your food is carbohydrates");
		System.out.println (frounding(FatPercent)+"% "+ "of your food is fat");
		System.out.println (frounding(ProteinPercent)+"% "+ "of your food is protein");

		double carbamount=fmultiply(CarbPercent);
		System.out.print("This food is acceptable for a low-carb diet? ");
		System.out.println(carbamount<=25);

		double fatamount=fmultiply(FatPercent);
		System.out.print("This food is acceptable for a low-fat diet? ");
		System.out.println(fatamount<=15);


		boolean x = Math.random() <= .5;
		System.out.println("By coin flip you should eat this food? "+ x);





	}

}
