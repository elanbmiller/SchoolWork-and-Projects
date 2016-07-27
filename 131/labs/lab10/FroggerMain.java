package lab10;
/*
 * Grader: Doug Shook
 * Result: Nice animations!
 * 			(+10 for animations)
 * 			(-10) for interface not being implemented properly (returns null)
 * 			(-5) for improper/missing javadoc comments
 * Total: 95 / 100
 */
import lab10.ControlDemo;

/**
 * 
 * @author Elan Miller
 * 431484
 * CSE 131
 * Lab 10: Frogger
 * frogger main method

 */

public class FroggerMain {
	public static void main(String[] args) {
		FroggerGame g = new Frogger();
		
		System.out.println(g.getGameName());
		System.out.println(g.getTeamMembers());
		g.playGame();
		
		System.exit(0);
	}
}
