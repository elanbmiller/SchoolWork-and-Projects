package studio8;

import java.util.LinkedList;

public class Calendar {

	public LinkedList<Appointment> appointments;


	public Calendar(LinkedList<Appointment> appointments){

		this.appointments = appointments;

	}

	public void addAppointment(Appointment a){
		appointments.add(a);
	}

	public String toString(){
		return appointments + " ";
	}

	



	public static void main(String[] args) {

		
		//System.out.println(example);
		
	}

}
