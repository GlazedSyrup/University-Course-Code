public class SortedDoublyLinkedList implements LinkedList {
    private DLLNode head = null;

    class DLLNode{
        public Warrior warrior;
        public DLLNode next;
        public DLLNode prev;
    }

    @Override
    public void insert(Warrior warrior) {
    // if the head is empty or if the head has a greater speed that the warrior(the parameter
    // then insert at beginning 
        DLLNode newNode = new DLLNode();
        if(head == null || (warrior.getSpeed() >= head.warrior.getSpeed())){
            newNode.warrior = warrior;
    
            newNode.next = head;
            newNode.prev = null;
            head = newNode;
            return;

        } else{
            // by this point we already know that the head is a smaller value
            // compared to the warrior we are inserting.
            DLLNode currentNode = head;
            DLLNode nextNode = head.next;
            
            //Once nextNode has a warrior with a greater speed than our parameter warrior
            //Then currentNode will be smaller than warrior and nextNode will be larger
            while(nextNode != null){
                if(warrior.getSpeed() > nextNode.warrior.getSpeed()){
                    newNode.warrior = warrior;
                    newNode.next = nextNode;
                    newNode.prev = currentNode;

                    
                    currentNode.next = newNode;
                    nextNode.prev = newNode;
                    return;
                }

                currentNode = currentNode.next;
                nextNode = nextNode.next;
            }
            //nextNode is null; We are at the end of the list
            newNode.warrior = warrior;
            newNode.next = null;
            newNode.prev = currentNode;
            currentNode.next = newNode;
            return;
        }

    }

    public String toString(){
        String result = "[ ";

        DLLNode current = head;
        while(current != null){
            result += current.warrior + " ";
            current = current.next;
        }

        return result + "]";    }

}