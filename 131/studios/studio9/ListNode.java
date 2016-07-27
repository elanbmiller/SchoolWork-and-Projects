package studio9;

public class ListNode {
	int value;
	ListNode next;
	ListNode previous;
	
	public ListNode(){
		
	}
	
	public ListNode(int value){
		this.value = value;
	}
	
	public ListNode(int value, ListNode next){
		this.value = value;
		this.next = next;
	}
	
	public ListNode(int value, ListNode next, ListNode previous){
		this.value = value;
		this.next = next;
		this.previous = previous;
	}
}
