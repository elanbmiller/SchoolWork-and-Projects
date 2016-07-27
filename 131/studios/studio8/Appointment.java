package studio8;

import java.util.LinkedList;

public class Appointment {

	public Date date;
	public Time time;

	public Appointment(Date date, Time time){

		this.date = date;
		this.time = time;

	}

	public String toString(){
		return date.toString() + " " + time.toString();
	}


	public static void main(String[] args) {

		
		
		Appointment practice = new Appointment(new Date(11, 5, 1994, true), new Time(5, 7, true));
		System.out.println(practice);

	}




	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((date == null) ? 0 : date.hashCode());
		result = prime * result + ((time == null) ? 0 : time.hashCode());
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
		Appointment other = (Appointment) obj;
		if (date == null) {
			if (other.date != null)
				return false;
		} else if (!date.equals(other.date))
			return false;
		if (time == null) {
			if (other.time != null)
				return false;
		} else if (!time.equals(other.time))
			return false;
		return true;
	}

}
