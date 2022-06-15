public class Lab02 {
        private double[] elements;
        private int numElements;

    public double[] map(double[] dArray, UnaryFunction func){
        int size = dArray.length;
        
        this.elements = new double[size];
        numElements = 0;

        for(int i = 0; i < size; i++){
            this.elements[i] = dArray[i];
        }
        return this.elements;
    }
    
    public String toString(){
        String result = "[";
        for(double element : this.elements){
            result += element + " ";
        }
        result += "]";
        return result;
    }
    public static void main(String[] args) {
    
    }
}
