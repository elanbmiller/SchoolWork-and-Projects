package lab4;

import java.awt.Color;

import sedgewick.StdDraw;
import cse131.ArgsProcessor;

class ListItem {
	public int number;
	public ListItem next;

	ListItem(int number, ListItem next) {
		this.number = number;
		this.next = next;
	}

	public String toString() {
		if (next == null)
			return "" + number;
		else
			return number + " " + next;
	}



	public static void main(String[] args){

		ListItem a, b, c, d;
		a = new ListItem(1,null);
		b = new ListItem(2,null);
		b.next = a;
		c = new ListItem(3,b);
		d = new ListItem(4, new ListItem(5, new ListItem(6, b)));
		c = c.next;

		System.out.println("a = (" + a + ")");
		System.out.println("b = (" + b + ")");
		System.out.println("c = (" + c + ")");
		System.out.println("d = (" + d + ")");
		
		
	}
}
