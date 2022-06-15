package expressionTree;

public class OpNode implements TreeNode{
    //Initializing Variables
    public String operation;
    public TreeNode left = null;
    public TreeNode right = null;
    //Constructor
    public OpNode(TreeNode left, String operation, TreeNode right){
        this.left = left;
        this.operation = operation;
        this.right = right;
    }
    //Override Abstract Functions
    @Override
    public void print(int depth) {
        if(this.right != null){
            this.right.print(depth + 1);
        }

        for(int i = 0; i < depth; i++){
            System.out.print("\t");
        }
        System.out.println("" + operation);

        if(this.left != null){
            this.left.print(depth + 1);
        }
    }

    @Override
    public Double evaluate() {
        double result;
        //Determine which operation is used and perform that operation
        switch(this.operation){
            case "+":
                result = this.left.evaluate() + this.right.evaluate();
                break;
            case "-":
                result = this.left.evaluate() - this.right.evaluate();
                break;
            case "*":
                result = this.left.evaluate() * this.right.evaluate();
                break;
            default:
                result = this.left.evaluate() / this.right.evaluate();
                break;
        }
        return result;
    }
    
}
