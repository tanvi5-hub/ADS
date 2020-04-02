import java.util.*;

public class A13	{
	
	Scanner obj = new Scanner(System.in);
	
	void main_func()	{
		int op, flag = 0;
		
		while(flag != 1)
		{
			System.out.println("1. Linked List\n 2. Stack\n 3. Priority Queue\n 4. Dequeue\n 5. Hash Set\n 6. Exit");
			op = obj.nextInt();
			
			switch(op)	{
				
				case 1:
					Linked();
					break;
					
				case 2:
					Stack();
					break;
					
				case 3:
					Queue();
					break;
					
				case 4:
					Dequeue();
					break;
					
				case 5:
					HashSet();
					break;
					
				case 6:
					flag = 1;
					return;
					
				default:
					System.out.println("Enter Valid Choice : \n");
					break;
			}
		}
	}
	
	public void Linked()	{
		LinkedList<Integer> l = new LinkedList<Integer>();
		int op, flag = 0, data;
		
		while(flag != 1)	{
			System.out.println("1. Add First\n 2. Add Last\n 3. Remove First\n 4. Remove Last\n 5. Display\n 6. Exit");
			op = obj.nextInt();
			
			switch(op)	{
				
				case 1:
					System.out.println("Enter Data to be Added First :");
					data = obj.nextInt();
					l.addFirst(data);
					break;
					
				case 2:
					System.out.println("Enter Data to be Added Last :");
					data = obj.nextInt();
					l.addLast(data);
					break;
					
				case 3:
					l.removeFirst();
					break;
					
				case 4:
					l.removeLast();
					break;
					
				case 5:
					System.out.println("Contents of Linked List are : " + l);
					break;
					
				case 6:
					flag = 1;
					break;
					
				default:
					System.out.println("Enter Valid Choice : ");
					break;
			}
		}
	}
	
	public void Stack()	{
		Stack<Integer> st = new Stack<Integer>();
		int op, flag = 0, data;
		
		while(flag != 1)	{
			System.out.println("1. Push\n 2. Pop\n 3. Display Top\n 4. Is Empty\n 5. Exit\n");
			op = obj.nextInt();
			
			switch(op)	{
				
				case 1:
					System.out.println("Enter Data to be Added in List : ");
					data = obj.nextInt();
					st.push(data);
					break;
					
				case 2:
					System.out.println("Data Popped fromStack is : " + st.pop());
					break;
					
				case 3:
					System.out.println("Data at Top of the Stack is : " + st.peek());
					break;
					
				case 4:
					if(st.isEmpty())	{
						System.out.println("Stack is Empty!");
					}	
					
					else	{
						System.out.println("Stack is Not Empty!");
					}
					break;
					
				case 5:
					flag = 1;
					break;
					
				default:
					System.out.println("Enter Valid Choice : ");
					break;
			}
		}
	}
	
	public void Queue()	{
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		int op, flag = 0, data;
		
		while(flag != 1)	{
			System.out.println("1. Add Data\n 2. Pop\n 3. Display Head\n 4. Size\n 5. Exit\n");
			op = obj.nextInt();
			
			switch(op)	{
				
				case 1:
					System.out.println("Enter Data to be Added : ");
					data = obj.nextInt();
					pq.add(data);
					break;
					
				case 2:
					System.out.println("Data Popped from Priority Queue : " + pq.poll());
					break;
					
				case 3:
					System.out.println("Data at Top of the Queue is : " + pq.peek());
					break;
					
				case 4:
					System.out.println("Size of Priority Queue is : " + pq.size());
					break;
					
				case 5:
					flag = 1;
					break;
					
				default :
					System.out.println("Enter Valid Choice : ");
					break;
			}
		}
	}
	
	public void Dequeue()	{
		ArrayDeque<Integer> dq = new ArrayDeque<Integer>();
		int op, flag = 0, data;
		
		while(flag != 1)	{
			System.out.println("1. Add First\n 2. Add Last\n 3. Display Head\n 4. Display Tail\n 5. Remove First\n 6. Remove Last\n 7. Exit\n");
			op = obj.nextInt();
			
			switch(op)	{
			
				case 1:
					System.out.println("Enter Data to be Added In Queue : ");
					data = obj.nextInt();
					dq.addFirst(data);
					break;	
					
				case 2:
					System.out.println("Enter Data to be Added In Queue : ");
					data = obj.nextInt();
					dq.addLast(data);
					break;
					
				case 3:
					System.out.println("First Element of Dequeue : " + dq.peekFirst());
					break;
					
				case 4:
					System.out.println("Last Element of Dequeue : " + dq.peekLast());
					break;
					
				case 5:
					System.out.println("Data removed from front : " + dq.pollFirst());
					break;
					
				case 6:
					System.out.println("Data removed from end : " + dq.pollLast());
					break;
					
				case 7:
					flag = 1;
					break;
					
				default:
					System.out.println("Enter Valid Choice : ");
					break; 
			}			
		}
	}
	
	public void HashSet()	{
		HashSet<Integer> hs = new HashSet<Integer>();
		int op, flag = 0, data;
		
		while(flag != 1)	{
			System.out.println("1. Add Element\n 2. Remove Element\n 3. Display Whole\n 4. Size\n 5. Exit\n");
			op = obj.nextInt();
			
			switch(op)	{
				
				case 1:
					System.out.println("Enter Data to be Added In Hash Set : ");
					data = obj.nextInt();
					hs.add(data);
					break;
					
				case 2:
					System.out.println("Enter Data to be Removed from Hash Set : ");
					data = obj.nextInt();
					hs.remove(data);
					break;
					
				case 3:
					System.out.println("Elements in whole HashSet are : " + hs);
					break;
					
				case 4:
					System.out.println("Size Of HashSet : " + hs.size());
					break;
					
				case 5:
					flag = 1;
					break;
					
				default:
					System.out.println("Enter Valid Choice : ");
					break;	
			}
		}	
	}
	
	public static void main(String[] args)	{
		A13 d = new A13();
		d.main_func();
	}
}
