package studio9;

import java.util.Iterator;

public class DoublyLinkedListOfInts implements List<Integer> {

	
	public ListNode head;
	public ListNode tail;
	public int size;
	
	public DoublyLinkedListOfInts (){
		head = new ListNode(0,null,null); 
		tail = new ListNode(0,null,head);
		head.next = tail; 
		size = 0; 
	}
	
	public void addFirst(Integer x) {
		addAfter(head, x);
	}
	
	public void addLast(Integer x) {
		addAfter(tail.previous, x);
	}
	
	 void addAfter(ListNode pred, int x) {
		ListNode item = new ListNode(x, pred.next, pred);
		item.previous.next = item;
		item.next.previous = item;
		size++;
	}
	
	
	
	

	

	 @Override
		public boolean remove(Integer x) {
			ListNode p = head.next;
			while (p.next != null) {
				if (p.value == x) {
					p.next.previous = p.previous;
					p.previous.next = p.next;
					this.size--; 
					return true;
				}
				else
					p = p.next; 
			}
			return false;
		}

		@Override
		public Integer get(int i) throws IndexOutOfBoundsException {
			ListNode p = head.next;
			while (p != null) {
				if (i == p.value) {
					return p.value;
				} else {
					p = p.next;
				}
			}
			throw new IndexOutOfBoundsException(String.valueOf(i));
		}

		@Override
		public int size() {
			return size;
		}

		@Override
		public boolean isEmpty() {
			// TODO Auto-generated method stub
			return this.size == 0;
		}

		@Override
		public String toString() {
		       StringBuilder s = new StringBuilder();
		       ListNode p = head.next;
		        for (int i = 0; i<size;i++) {
		            s.append(p.value+ " ");
		            p = p.next; 
		        }
		        return s.toString();
		}

		@Override
		public Iterator<Integer> iterator() {
			// TODO Auto-generated method stub
			return null;
		}

		
		public static void main(String args){
			List<Integer> test = new DoublyLinkedListOfInts();
			System.out.println(test.toString());
		}

		@Override
		public int indexOf(Integer i) {
			ListNode p = head.next;
			int index = 0; 
			while (p != null) {
				if (i == p.value) 
					return index;
				else {
					p = p.next;
					index++;
				}
			}
			return -1; 
		
		}

		


	}


