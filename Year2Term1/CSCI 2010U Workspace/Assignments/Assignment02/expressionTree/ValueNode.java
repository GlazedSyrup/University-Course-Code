package expressionTree;

public class ValueNode implements TreeNode{
    //Initialize Variables
    public double value;
    //Constructor
    public ValueNode(double value){
        this.value = value;
    }
    //Override Abstract functions
    @Override
    public void print(int depth) {
        for(int i = 0; i < depth; i++){
            System.out.print("\t");
        }
        System.out.println("" + value);
    }

    @Override
    public Double evaluate() {
        return value;
    }
}
