package expressionTree;

public interface TreeNode {
    //Initialize Variables
    int value = 0;
    //Initialize Abstract Functions
    public abstract void print(int depth);    
    public abstract Double evaluate();
}
    