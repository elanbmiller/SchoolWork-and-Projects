package studio8;

import java.util.HashSet;
import java.util.LinkedList;

public class Time {

	private final int minute;
	private final int hour;
	private final boolean isArmyTime;

	public Time(int min, int hr, boolean isArmy){
		this.minute = min;
		this.hour = hr;
		this.isArmyTime = isArmy;
	}


	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + hour;
		result = prime * result + (isArmyTime ? 1231 : 1237);
		result = prime * result + minute;
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
		Time other = (Time) obj;
		if (hour != other.hour)
			return false;
		if (isArmyTime != other.isArmyTime)
			return false;
		if (minute != other.minute)
			return false;
		return true;
	}


	public String toString(){
		if(this.isArmyTime){
			return this.hour + ":" + this.minute;
		}
		else if(this.hour >= 12){
			return this.hour - 12 + ":" + this.minute + "PM";
		}
		else if(this.hour < 12){
			if (this.hour == 0) { return "12:" + this.minute + "AM"; }
			return this.hour + ":" + this.minute + "AM";
		}
		return "";
	}

	public static void main(String[] args) {
		Time example = new Time(5, 7, true);
		Time example2 = new Time(6, 6, false);
		Time example3 = new Time(5, 7, false);
		Time example4 = new Time(18, 6, false);

		//			System.out.println(example == (example3));
		//			System.out.println(example2.equals(example4));

		LinkedList<Time> list = new LinkedList<Time>();
		list.add(example);
		list.add(example2);
		list.add(example3);

		System.out.println(list);


		HashSet<Time> set = new HashSet<Time>();
		set.add(example);
		set.add(example2);
		set.add(example3);

		System.out.println(set);



		//abstract data type: model of a data structure that specifies the characteristics of the
		//collection of data, and the operations that can be performed on the collection (doesn't say)
		//how the adt will be implemented

		// interface: group of related methods with empty bodies

		//			In Java, we can use an interface to specify an ADT:
		//				public interface Bag {
		//				boolean add(Object item);
		//				boolean remove(Object item);
		//				boolean contains(Object item);
		//				int numItems();
		//				Object grab();
		//				Object[] toArray();
		//				} (see ~cscie119/examples/bag/Bag.java)
		//				• An interface specifies a set of methods. 
		//				• includes only the method headers 
		//				• cannot include the actual method definitions

		//			When a class header includes an implements clause, 
		//			the class must define all of the methods in the interface



	}

}
