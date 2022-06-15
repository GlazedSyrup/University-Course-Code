public class BSTNode {
    public int value;
    public BSTNode left;
    public BSTNode right;
    public BSTNode parent;

    public void print(int depth){
        if(this.right != null){
            this.right.print(depth + 1);
        }

        for(int i = 0; i < depth; i++){
            System.out.print("\t");
        }
        System.out.println("" + value);

        if(this.left != null){
            this.left.print(depth + 1);
        }
    }

    //insert or push or put or add
    public void insert(int newValue){
        if(newValue < this.value){
            if(this.left == null){
                BSTNode newNode = new BSTNode();
                newNode.value = newValue;
                newNode.left = null;
                newNode.right = null;
                newNode.parent = null;
                this.left = newNode;
            } else{
                this.left.insert(newValue);
            }
        }
        //
        else{
            if(this.right == null){
                BSTNode newNode = new BSTNode();
                newNode.value = newValue;
                newNode.left = null;
                newNode.right = null;
                newNode.parent = null;
                this.right = newNode;
            } else{
                this.right.insert(newValue);
            }
        }
    }

    public int getHeight(){
        int leftHeight = 0;
        int rightHeight = 0;
        if(this.left != null){
            leftHeight = this.left.getHeight();
        }
        if(this.right != null){
            rightHeight = this.right.getHeight();
        }
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }

    public int getBalance(){
        int leftHeight = 0;
        int rightHeight = 0;

        if(this.left != null){
            leftHeight = this.left.getHeight();
        }
        if(this.right != null){
            rightHeight = this.right.getHeight();
        }

        return leftHeight - rightHeight;

    }
}
