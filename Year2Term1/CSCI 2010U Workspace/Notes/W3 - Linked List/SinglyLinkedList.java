public class SinglyLinkedList {
    class SLLNode{
        public String value;
        public SLLNode next;

    }

    //Initial state of out linked list
    private SLLNode head = null;

    public void insertAtBeginning(String newValue){
        SLLNode newNode = new SLLNode();
        newNode.value = newValue;

        newNode.next = head;

        head = newNode;

    }

    public void insertAtEnd(String newValue){
        if(head == null){
            insertAtBeginning(newValue);
            return;
        }

        //path towards the end of the linked list
        SLLNode current = head;
        SLLNode prev = null;
        while(current != null){
            prev = current;
            current = current.next;
        }

        SLLNode newNode = new SLLNode();
        newNode.value = newValue;
        newNode.next = null;

        prev.next = newNode;
    }

    public String toString(){
        String result = "[ ";

        SLLNode current = head;
        while(current != null){
            result += current.value + " ";
            current = current.next;
        }

        return result + "]";
    }

    public static void main(String[] args){
        SinglyLinkedList myList = new SinglyLinkedList();
        myList.insertAtEnd("Micheal");  
        myList.insertAtEnd("Faisal");  
        myList.insertAtBeginning("Ken");  
        myList.insertAtEnd("Jarek");  
        myList.insertAtBeginning("Jeremey");  

        System.out.println(myList);
    }
    
}
