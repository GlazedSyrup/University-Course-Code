public class ArrayBinaryTree {
    private int[] values;
    public ArrayBinaryTree(int[] initialValues){
        this.values = initialValues;
    }
    public int get(int index){
        return this.values[index];
    }

    public int getRootIndex(){
        return 0;
    }

    public int getLeftChild(int index){
        return index * 2 + 1;
    }

    public int getRightChild(int index){
        return index * 2 + 2;
    }

    public int getParent(int index){
        return (index - 1)/2;
    }

    public void printInOrder(){
        printNode(getRootIndex(), 0);
    }

    public void printNode(int index, int depth){
        //Bad input check, base case
        if (index < 0 || index >= this.values.length){
            return;
        }

        printNode(getRightChild(index), depth + 1);

        for (int i = 0; i < depth; i++){
            System.out.print("\t");
        }
        System.out.println("" + get(index));
        printNode(getLeftChild(index), depth + 1);
    }

    public static void main(String[] args) {
        /*
                         7
                   3            12
              1        5    10      15
         */
        int[] startValues = new int[] {7, 3, 12, 1, 5, 10, 15};
        ArrayBinaryTree tree = new ArrayBinaryTree(startValues);
        System.out.printf("%d's parent is %d\n", tree.get(6), tree.get(tree.getParent(6)));

        tree.printInOrder();
    }
}