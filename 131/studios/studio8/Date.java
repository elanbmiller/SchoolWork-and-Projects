package studio8;

import java.util.HashSet;
import java.util.LinkedList;

public class Date {

	private final int month;
	private final int day;
	private final int year;
	private final boolean isHoliday;


	public Date(int month, int day, int year, boolean isHoliday){
		this.month = month;
		this.day = day;
		this.year = year;
		this.isHoliday = isHoliday;
	}

	public String toString(){
		if(isHoliday){
			return this.month+"/"+this.day+"/"+this.year+" It's a holiday";
		}
		else{
			return this.month+"/"+this.day+"/"+this.year+" Not a holiday";
		}
	}


	public static void main(String[] args) {

		Date example = new Date(12, 5, 1994, true);
		Date example2 = new Date(12, 5, 1994, true);
		Date example3 = new Date(10, 5, 1994, false);
		Date example4 = new Date(12, 6, 1994, true);



		//System.out.println(example.equals(example2));

		LinkedList<Date> myList = new LinkedList<Date>();
		myList.add(example);
		myList.add(example2);
		myList.add(example3);
		myList.add(example4);

		System.out.println("LinkedList: "+myList);


		HashSet<Date> set = new HashSet<Date>();
		set.add(example);
		set.add(example2);
		set.add(example3);
		set.add(example4);



		System.out.println("HashSet: " + set);
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + day;
		result = prime * result + month;
		result = prime * result + year;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Date other = (Date) obj;
		if (day != other.day)
			return false;
		if (month != other.month)
			return false;
		if (year != other.year)
			return false;
		return true;
	}

}
