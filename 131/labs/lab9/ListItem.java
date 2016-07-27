//Graded By: Andrew Gorman
//Grade: 100/100

package lab9;


/**
 * Elan Miller
 * 431484
 * CSE 131
 * Lab 9: ListItem
 * Creates and edits a list
 * @author Elan Miller and jon gross
 *
 */

public class ListItem {
	//
	// Important:  Do NOT make these instance variables private
	// Our testing needs to be able to access them, so leave their
	//   declarations as you see them below.
	//
	final int number;
	ListItem next;

	/**
	 * Creates a single list item.
	 * @param number the value to be held in the item
	 * @param next a reference to the next item in the list
	 */
	ListItem(int number, ListItem next) {
		this.number = number;
		this.next   = next;
	}

	/**
	 * Return a copy of this list using recursion.  No
	 * credit if you use any iteration!  All existing lists should remain
	 * intact -- this method must not mutate anything.
	 * @return
	 */
	public ListItem duplicate() {

		if(this.next != null){

			return new ListItem(number, this.next.duplicate());

		}

		else{

			return new ListItem(number, null);

		}

	}

	/**
	 * Recursively compute the number of elements in the list. No
	 * credit if you use any iteration!  All existing lists should remain
	 * intact.
	 * @return
	 */
	public int length() {



		if(this.next != null){

			return 1 + this.next.length();

		}

		else{

			return 1;
		}

	}

	/**
	 * Return a new list, like duplicate(), but every element
	 * appears n times instead of once.  See the web page for details.
	 * You must do this method iteratively.  No credit
	 * if you use any recursion!
	 * @param n a positive (never 0) number specifying how many times to copy each element
	 * @return
	 */

	public ListItem stretch(int n) {
		ListItem repeat = this;
		ListItem firstpoint = null;
		ListItem update = null;
		while(repeat != null){
			for(int i = 0; i < n; i++){		//iterate n times
				ListItem copy = new ListItem(repeat.number, null);	//create n number of copies
				if(firstpoint == null){		//create first value
					firstpoint = copy;
				}
				if(update != null){
					update.next = copy;
				}
				update = copy;		//set update to the starting value in the new List
			}
			repeat = repeat.next;
		}
		return firstpoint; 
	}

	/**
	 * Return the first ListItem, looking from "this" forward,
	 * that contains the specified number.  No lists should be
	 * modified as a result of this call.  You may do this recursively
	 * or iteratively, as you like.
	 * @param n
	 * @return
	 */

	public ListItem find(int target) {

		ListItem place = this;

		while(place!=null){

			if(place.number == target){
		
				return place;

			}

			place = place.next;		//update place to place.next to then check if place.next equals target

		}

		return null;
	}

	/**
	 * Return the maximum number contained in the list
	 * from this point forward.  No lists should be modified
	 * as a result of this call.  You may do this method recursively
	 * or iteratively,as you like.
	 * @return
	 */

	public int max() {

		ListItem LargestNum = this;

		int TheNum = Integer.MIN_VALUE;		//set TheNum to very negative number to account for negative #'s

		while(LargestNum != null){

			if(LargestNum.number > TheNum){

				TheNum = LargestNum.number;

			}

			LargestNum = LargestNum.next;		//update LargestNum to then check again
		}




		return TheNum; // FIXME

	}

	/**
	 * Returns a copy of the list beginning at ls, but containing
	 * only elements that are even.
	 * @param ls
	 * @return
	 */
	public static ListItem evenElements(ListItem ls) {

		if(ls == null){		//base case!

			return null;

		}

		else if(ls.number % 2 == 0){		//determines if number is even

			return new ListItem(ls.number, evenElements(ls.next));

		}

		else{

			return evenElements(ls.next);		//skip over odd number

		}

	}


	/**
	 * Returns a string representation of the values reachable from
	 * this list item.  Values appear in the same order as the occur in
	 * the linked structure.  Leave this method alone so our testing will work
	 * properly.
	 */
	public String toString() {
		if (next == null)
			return ("" + number);
		else
			return (number + " " + next); // calls next.toString() implicitly
	}

}
