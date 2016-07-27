package lab7;

/*
 * Grader: Doug Shook
 * Result: Missing javadoc for the class (-2). Used inline comments instead of javadoc for some methods (-2)
 * 		Because this was not committed on time you have used one of your late coupons on this lab.
 * Grade: 96 / 100
 */

public class Student {
	private String FirstName;
	private String LastName;
	private int StudentID;
	private int Credits;
	private double GPA;

	/**public constructor that takes three parameters and initializes
	 * @param NameofCourse
	 * @param CreditsAmount
	 * @param TotalSeats
	 */

	public Student(String FirstName, String LastName, int StudentID){
		this.FirstName = FirstName;
		this.LastName = LastName;
		this.StudentID = StudentID;
		this.Credits = 0;
		this.GPA = 0.0;
	}


	/**
	 * Returns full name and ID
	 */

	public String toString(){
		return this.FirstName + " " + this.LastName + " ID:"  + this.StudentID + " GPA:" + this.getGPA();
	}

	//return full name
	public String getName(){
		return this.FirstName + " " + this.LastName;
	}

	//return ID number
	public int getStudentID(){
		return this.StudentID;
	}
	//return GPA total
	public double getGPA(){
		return this.GPA;
	}
	//return amount of credits
	public int getCredits(){
		return this.Credits;
	}
	//returns students class based on credit amount
	public String getClassStanding(){
		if (this.Credits < 30){
			return "Freshman";
		}
		else if (this.Credits < 60){
			return "Sophomore";
		}
		else if (this.Credits < 90){
			return "Junior";
		}
		else{
			return "Senior";
		}
	}

	/** 
	 * @param amount of credits
	 * @return true if graduated, false if not
	 */
	public boolean isGraduated(){
		if (this.Credits >= 120){
			return true;
		}
		else{
			return false;
		}
	}

	/**
	 * @param stud
	 * @return true if Student's GPA is > stud GPA
	 */

	public boolean hasHigherAverage(Student stud){
		if (this.GPA > stud.getGPA()){
			return true;
		}
		else{
			return false;
		}
	}

	/**Updates Student's GPA
	 * @param CourseGrade
	 * @param CourseCredits
	 */

	public void submitGrade(double CourseGrade, int CourseCredits){

		double TotalCurrentPoints = (this.GPA * this.Credits) + (CourseGrade * CourseCredits);

		this.Credits += CourseCredits;

		double UpdatedGPA = TotalCurrentPoints/this.Credits;

		this.GPA = (Math.round(UpdatedGPA * 1000))/1000.0;


	}

	//determines amount of tuition that has been paid
	public double computeTuition(){
		int Semesters = 0;
		if(this.Credits <= 18){
			Semesters = 1;
		}
		else if(this.Credits % 18 < 9){
			Semesters = this.Credits / 18;
		}
		else{
			Semesters = (this.Credits / 18) + 1;
		}
		return Semesters * 22850.0;
	}


	//Creates new baby
	public Student createBaby(Student BabyStudent){
		String BabyFirstName = this.FirstName + " " + this.LastName;
		String BabyLastName = BabyStudent.getName();
		int BabyID = (int) Math.random() * 900000 + 100000;
		Student Baby = new Student(BabyFirstName, BabyLastName, BabyID);
		Baby.GPA = (BabyStudent.getGPA() + this.getGPA()) / 2;
		Baby.Credits = Math.max(BabyStudent.getCredits(), this.getCredits());
		return Baby;
	}
	
	public static void main(String[] args){
		Student example = new Student("Elan", "Miller", 431484);
		example.submitGrade(4.0, 3);	//calculus
		example.submitGrade(3.7, 3);	//philosophy
		System.out.println(example.toString());
	}
	
}


















