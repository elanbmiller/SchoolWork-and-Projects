package lab7;

public class Course {

	private String Name;
	private double Credits;
	private int Seats;
	private Student[] roster;

	/**public constructor that takes three parameters and initializes
	 * @param NameofCourse
	 * @param CreditsAmount
	 * @param TotalSeats
	 */
	public Course(String NameofCourse, double CreditsAmount, int TotalSeats){
		this.Name = NameofCourse;
		this.Credits = CreditsAmount;
		this.Seats = TotalSeats;
		this.roster = new Student[TotalSeats];
	}

	//returns Name
	public String getName(){
		return this.Name;
	}

	//returns remaing seats
	public int getRemainingSeats(){
		int counter = 0;
		for(int i = 0; i < this.roster.length; i++){
			if(this.roster[i] != null)
				counter += 1;
		}
		return this.roster.length - counter;
	}

	//returns course name and course credits
	public String toString(){
		return this.Name + this.Credits;
	}

	/**
	 * @param Stud
	 * @return true if Stud is successfully added to the course, false otherwise
	 */
	public boolean addStudent(Student Stud){
		if((this.roster.length - this.getRemainingSeats()) < this.roster.length){
			this.roster[this.Seats - this.getRemainingSeats()] = Stud;
			return true;
		}
		else{
			return false;
		}
	}

	//prints names and student ID for all students in course
	public void printRoster(){
		for(int i = 0; i < roster.length; i++){
			System.out.println(this.roster[i].getName() + " ID:" + this.roster[i].getStudentID());	
		}
	}
	//computes average GPA of all students in the course
	public double averageGPA(){
		int TotalAmountOfStudents = 0;
		double GPAtotal = 0.0;
		for(int i = 0; i < this.roster.length; i++){
			if (this.roster[i] != null){
				GPAtotal += this.roster[i].getGPA();
				TotalAmountOfStudents += 1;
			}
		}
		return GPAtotal/TotalAmountOfStudents;
	}



}

