package lab8;

/**
 * Elan Miller
 * 431484
 * CSE 131
 * Lab 8: Polynomial
 * Creates a list and edits
 * @author Elan Miller
 *
 */

import java.util.Iterator;
import java.util.LinkedList;

/** Grade: 96/100
 * TA: brianc
 * good job, but be sure to do the following:
 * -delete FIXME comments
 * -add header javadoc
 * -delete commented out code
 * -your helper method should have a javadoc
 *
 */

public class Polynomial {

	public LinkedList<Double> list;
	

	/**
	 * Constructs a Polynomial with no terms yet.
	 */
	public Polynomial() {
		// Set the instance variable (list) to be a new linked list of Double type
		list = new LinkedList<Double>();
	}
	/**
	 * returns String representation of the polynomial (takes no parameters) 
	 */
	public String toString() {
		String result = "";	// String the represents polynomial
		int pow = 0;		// int to keep track of what power polynomial is at
		for(Double d : this.list)
			// for (int d = 0; d<list.size();d++)
			//result += list.get(d) + "x" + "^" + d +" ";
		{
			result = d + "x" + "^" + pow;
			pow++;
		}
		return result ; // FIXME
	}

	/**
	 * @param a double coefficient
	 * @return adds higher order term with the coefficient to Polynomial
	 */
	public Polynomial addTerm(double coeff) {
		this.list.addLast(coeff);	//modify Polynomial
		return this;  // required by lab spec
	}

	/**
	 * @param double x
	 * @return value of Polynomial at value x
	 */

	public double evaluate(double x) {

		return evaluateHelper(list.iterator(), x);	//helper method
	}

	//helper method using iterator
	private double evaluateHelper(Iterator<Double> numIter, double x){
		if(!numIter.hasNext()){		//if there's no upcoming value
			return 0.0;
		}
		return numIter.next() + x*evaluateHelper(numIter, x);
	}

	/**
	 * @return new Polynomial that is the first derivative of this polynomial
	 */
	
	public Polynomial derivative() {
		Polynomial result = new Polynomial();
		int pow = 0;
		for(Double d : this.list)
			//(int i = 1; i < this.list <i++)
			//result.addterm(i*list.get(i))
		{
			if(pow != 0){
				result.addTerm(pow * d);
			}
			pow++;
		}
		return result;
		// FIXME
	}

	/**
	 * @param Polynomial another
	 * @return new Polynomial that is result of adding together the two polynomials
	 */
	
	public Polynomial sum(Polynomial another) {

		Polynomial result = new Polynomial();

		int i = 0;
		while(i < another.list.size() || i < this.list.size()){		//while either polynomial has elements
		
			if(i < another.list.size() && i < this.list.size()){	//if they're both > i
				result.addTerm(another.list.get(i) + this.list.get(i)); 	//add terms at the i-th point
			}
			else if(i < another.list.size()){	//if only one is greater than i	
				result.addTerm(another.list.get(i));	//add that term to the new polynomial
			}
			else if(i < this.list.size()){		//if only the other one is greater than i	
				result.addTerm(this.list.get(i));		//add that term to the new polynomial
			}

			i++;
		}

		// for (int i = 0; i < list.size(); i++) {}

		// int i = 0;
		// while (i < list.size()) {
		//		i++;
		// }

		return result;   // FIXME
	}

	/**
	 * This is the "equals" method that is called by
	 *    assertEquals(...) from your JUnit test code.
	 *    It must be prepared to compare this Polynomial
	 *    with any other kind of Object (obj).  Eclipse
	 *    automatically generated the code for this method,
	 *    after I told it to use the contained list as the basis
	 *    of equality testing.  I have annotated the code to show
	 *    what is going on.
	 */

	public boolean equals(Object obj) {
		// If the two objects are exactly the same object,
		//    we are required to return true.  The == operator
		//    tests whether they are exactly the same object.
		if (this == obj)
			return true;
		// "this" object cannot be null (or we would have
		//    experienced a null-pointer exception by now), but
		//    obj can be null.  We are required to say the two
		//    objects are not the same if obj is null.
		if (obj == null)
			return false;

		//  The two objects must be Polynomials (or better) to
		//     allow meaningful comparison.
		if (!(obj instanceof Polynomial))
			return false;

		// View the obj reference now as the Polynomial we know
		//   it to be.  This works even if obj is a BetterPolynomial.
		Polynomial other = (Polynomial) obj;

		//
		// If we get here, we have two Polynomial objects,
		//   this and other,
		//   and neither is null.  Eclipse generated code
		//   to make sure that the Polynomial's list references
		//   are non-null, but we can prove they are not null
		//   because the constructor sets them to some object.
		//   I cleaned up that code to make this read better.


		// A LinkedList object is programmed to compare itself
		//   against any other LinkedList object by checking
		//   that the elements in each list agree.

		return this.list.equals(other.list);
	}

}
