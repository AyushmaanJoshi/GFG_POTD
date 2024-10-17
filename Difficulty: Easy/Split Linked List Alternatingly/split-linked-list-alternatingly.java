//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class Main {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = sc.nextLine();
            Scanner ss = new Scanner(input);

            while (ss.hasNextInt()) {
                arr.add(ss.nextInt());
            }

            Node head = new Node(arr.get(0));
            Node tail = head;

            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }

            Solution ob = new Solution();
            Node[] result = ob.alternatingSplitList(head);
            printList(result[0]);
            printList(result[1]);
        }

        sc.close();
    }
}

// } Driver Code Ends


// User function Template for Java
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    // Function to split the linked list into two alternate linked lists.
    Node[] alternatingSplitList(Node head) {
        // Initialize two dummy nodes to start the two new lists
        Node list1Dummy = new Node(0); // Dummy node for list 1
        Node list2Dummy = new Node(0); // Dummy node for list 2
        
        // Pointers for traversing the new lists
        Node list1 = list1Dummy;
        Node list2 = list2Dummy;
        
        // Pointer to traverse the original list
        Node current = head;
        
        // Boolean flag to alternate between list1 and list2
        boolean addToList1 = true;
        
        // Traverse the original linked list
        while (current != null) {
            if (addToList1) {
                list1.next = current;  // Add current node to list 1
                list1 = list1.next;    // Move the list1 pointer forward
            } else {
                list2.next = current;  // Add current node to list 2
                list2 = list2.next;    // Move the list2 pointer forward
            }
            
            // Move to the next node in the original list
            current = current.next;
            
            // Toggle the flag to switch between lists
            addToList1 = !addToList1;
        }
        
        // End both lists by making the last node's next as null
        list1.next = null;
        list2.next = null;
        
        // Return the heads of the two new lists (skipping the dummy nodes)
        return new Node[] { list1Dummy.next, list2Dummy.next };
    }
}
