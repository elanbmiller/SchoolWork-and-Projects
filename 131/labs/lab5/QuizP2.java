package lab5;

public class QuizP2 {
	public static int signum(int N){
		if(N < 0){
			return -1;
		}
		else if (N == 0){
			return 0;
		}
		else{
			return 1;
		}
		
	}

	public static void main(String[] args) {
		int result = signum(2);
		System.out.println(result);
	}
}


