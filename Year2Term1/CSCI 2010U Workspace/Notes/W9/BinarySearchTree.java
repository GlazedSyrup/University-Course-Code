public class BinarySearchTree{
    private BSTNode root = null;

    public void printInOrder(){
        if(this.root == null){
            System.out.println("Nothing in the Tree yet");
        }else{
            System.out.printf("Height: %d\n", root.getHeight());
            System.out.printf("Balance: %d\n", root.getBalance());
            this.root.print(0);
        }
    }


    public void insert(int newValue){
        if(this.root == null){
            BSTNode newNode = new BSTNode();
            newNode.value = newValue;
            newNode.left = null;
            newNode.right = null;
            newNode.parent = null;

            this.root = newNode;
        }else{
            this.root.insert(newValue);
        }
    }





    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        tree.insert(2);
        tree.insert(7);
        tree.insert(12);
        tree.insert(20);
        tree.insert(6);
        tree.insert(11);
        
        tree.printInOrder();
    }
}