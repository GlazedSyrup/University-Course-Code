public class SortedDoublyLinkedList implements LinkedList {
    private DLLNode head = null;
    public int assignmentCount = 0;

    class DLLNode{
        public Warrior warrior;
        public DLLNode next;
        public DLLNode prev;
    }

    @Override
    public void insert(Warrior warrior) {
    // if the head is empty or if the head has a greater speed that the warrior(the parameter
    // then insert at beginning
            assignmentCount +=1;
        DLLNode newNode = new DLLNode();
        if(head == null || (warrior.getSpeed() >= head.warrior.getSpeed())){
                assignmentCount +=1;
            newNode.warrior = warrior;
    
                assignmentCount +=1;
            newNode.next = head;
                assignmentCount +=1;
            newNode.prev = null;
                assignmentCount +=1;
            head = newNode;
            return;

        } else{
            // by this point we already know that the head is a smaller value
            // compared to the warrior we are inserting.
                assignmentCount +=1;
            DLLNode currentNode = head;
                assignmentCount +=1;
            DLLNode nextNode = head.next;
            
            //Once nextNode has a warrior with a greater speed than our parameter warrior
            //Then currentNode will be smaller than warrior and nextNode will be larger
            while(nextNode != null){
                if(warrior.getSpeed() > nextNode.warrior.getSpeed()){
                        assignmentCount +=1;
                    newNode.warrior = warrior;
                        assignmentCount +=1;
                    newNode.next = nextNode;
                        assignmentCount +=1;
                    newNode.prev = currentNode;


                        assignmentCount +=1;
                    currentNode.next = newNode;
                        assignmentCount +=1;
                    nextNode.prev = newNode;
                    return;
                }

                    assignmentCount +=1;
                currentNode = currentNode.next;
                    assignmentCount +=1;
                nextNode = nextNode.next;
            }
            //nextNode is null; We are at the end of the list
                assignmentCount +=1;
            newNode.warrior = warrior;
                assignmentCount +=1;
            newNode.next = null;
                assignmentCount +=1;
            newNode.prev = currentNode;
                assignmentCount +=1;
            currentNode.next = newNode;
            return;
        }

    }

    public String toString(){
            assignmentCount +=1;
        String result = "[ ";

            assignmentCount +=1;
        DLLNode current = head;
        while(current != null){
                assignmentCount +=1;
            result += current.warrior + " ";
                assignmentCount +=1;
            current = current.next;
        }

        return result + "]";    }

}