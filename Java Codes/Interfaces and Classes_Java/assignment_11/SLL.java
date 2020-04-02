package Definition;
import Declaration.Interface;
import java.util.Scanner;

class Node	{
	public int data;
	public Node next;
	
	Node()	{
		data = 0;
	}
	
	Node(int d)	{
		data = d;
		next = null;
	}
}

public class SLL implements Interface	{
	Node head;
	Node tail;
	int size;
	
	SLL()	{
		head = null;
		tail = null;
		size = 0;
	}
	
	public void insert(int x)	{
		Node temp = new Node(x);
		size++;
		
		if(head == null)	{
			head = temp;
			tail = temp;
		}
		
		else	{
			tail.next = temp;
			tail = temp;
		}
	}
	
	public int count_size()	{
		return size;
	}
	
	public int isEmpty()	{
		if(head == NULL)	{
			return 0;
		}
		
		else	{
			return 1;
		}
	}
	
	public void Display()	{
		if(head == null)	{
			System.out.println("Linked List is Empty!");
		}
		
		node temp = head;
		while(temp != null)	{
			System.out.print(+ temp.data + "->");
			temp = temp.next;
		}
	}
	
	public void delete(int x)	{
		int flag = 0;
		if(head.data == x)	{
			Node temp = head;
			head = head.next;
			temp = null;
			System.gc();
		}
		
		else	{
			Node p = head;
			Node q = head;
			
			while(p.data != x)	{
				q = p;
				p = p.next;
				
				if(p == null)	{
					flag = 1;
					break;
				}
			}
			
			if(flag = 1)	{
				System.out.println("Data Not Present!");
			}
			
			else	{
				size--;
				q.next = p.next;
				p = null;
				System.gc();
			}
		}
	}
	
	public static void main(String[] args)	{
		SLL s = new SLL();
		int op, flag = 0, data;
		
		Scanner obj = new Scanner(System.in);
		while(flag != 1)	{
			System.out.println("1. Insert\n 2. IsEmpty\n 3. Display\n 4. Delete\n 5. Size\n 6. Exit\n Enter your choice :\n");
			op = obj.nextInt();
			
			switch(op)	{
				case 1:
					System.out.println("Enter Data to be inserted :");
					data = obj.nextInt();
					s.insert(data);
					break;
					
				case 2:
					data = s.isEmpty();
					if(data == 0)	{
						System.out.println("Linked List is Empty!");
					}
					
					else	{
						System.out.println("Linked List is not Empty!"); 
					}
					
					break;
					
				case 3:
					s.display();
					break;
					
				case 4:
					System.out.println("Enter data to be deleted :");
					data = obj.nextInt();
					s.delete(data);
					break;
					
				case 5:
					data = s.count_size();
					System.out.println("Size of Linked List is : " + data);
					break;
					
				case 6:
					flag = 1;
					break;
					
				default:
					System.out.println("Enter Valid Choice :");
					break;
			}
		}
	}
}
