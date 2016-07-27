import java.util.Arrays;


public class EmployeeSort {

	private Employee[] employees;

	public EmployeeSort(){
	}
	
	
	public EmployeeSort(int size){
		this.employees = new Employee[size];
	}

	public void Sort(){

		for(int i = 0; i < employees.length; i ++){

			Employee current = employees[i];
			int j = i - 1;

			while (j >=0 && employees[j].employeeNumber >= current.employeeNumber){

				employees[j+1] = employees[j];
				j--;
			}
			employees[j+1] = current;

		}

	}


	public static void main(String[] args) {

		EmployeeSort sort = new EmployeeSort(3);
		
		Employee emp1 = new Employee(100000009, "John","Doe", "john.doe@dsnalgos.com");
		Employee emp2 = new Employee(100000002, "Patrick","Dwight", "patrick.dwight@dsnalgos.com");
		Employee emp3 = new Employee(100000011, "Marlo","Thomas", "marlo.thomas@dsnalgos.com");
		
		sort.employees[0] = emp1;
		sort.employees[1] = emp2;
		sort.employees[3] = emp3;
		
		sort.Sort();

		System.out.println(Arrays.deepToString(sort.employees));

	}

	class Employee {
		public int employeeNumber;
		public String firstName;
		public String lastName;
		public String email;

		public Employee(int employeeNumber, String firstName, String lastName, String email) {
			this.employeeNumber = employeeNumber;
			this.firstName = firstName;
			this.lastName = lastName;
			this.email = email;
		}

		public String toString() {
			return this.employeeNumber + " : " + this.email;
		}

	}

}


