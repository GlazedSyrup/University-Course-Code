package expressionTree;

public class ExpressionTree{
    //Initialize variables
    private OpNode root;
    //Constructor
    public ExpressionTree(OpNode root){
        this.root = root;
    }
    //Print Function that displays the tree
    public void print(){
        root.print(0);
    }
    //Evaluates all sub nodes
    public Double evaluate(){
        return root.evaluate();
        
    }
}