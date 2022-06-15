public class GenericArrayList<T> {
    private Object[] elements;
    private int numElements;
    
    /***
     * This is the constructor which takes a capacity and defines the array and its length parameter
     * this is an example of using javadoc
     * @param initialSize - capacity integer, setting the initial array size
     */

    public GenericArrayList(int initialSize){
        this.elements = new Object[initialSize];
        numElements = 0;
    }

    public void resizeIfRequired(){
        if(this.numElements+1 >= this.elements.length){
            Object[] newArray = new Object[elements.length*2];
            
            for(int i = 0; i < this.elements.length; i++){
                newArray[i] = this.elements[i];
            }
            //Replace elements with the new larger array
            this.elements = newArray;
        }
    }

    public void InsertAtEnd(T newElement){
        resizeIfRequired();

        this.elements[this.numElements] = newElement;
        this.numElements++;
    }

    public void InsertAtBeginning(T newElement){
        resizeIfRequired();

        for(int i = this.numElements - 1; i >= 0; i--){
            this.elements[i + 1] = this.elements[i];
        }

        this.elements[0] = newElement;
        this.numElements++;
    }

    public void InsertAtIndex(int index, T newElement){
        if(index >= this.numElements){
            throw new ArrayIndexOutOfBoundsException("No such index: " + index);
        }

        resizeIfRequired();

        for(int i = this.numElements - 1; i >= index; i--){
            this.elements[i + 1] = this.elements[i];
        }

        this.elements[index] = newElement;
        this.numElements++;
    }

    public String toString(){
        String result = "[";
        for(int i = 0; i < this.numElements; i++){
            result += this.elements + " ";
        }
        result += "]";
        return result;
    }

    public static void main(String[] args){
        GenericArrayList<String> myList = new GenericArrayList<String>(5);
        myList.InsertAtEnd("Bob");
        myList.InsertAtEnd("John");
        myList.InsertAtEnd("Rick");
        myList.InsertAtEnd("Tom");
        myList.InsertAtBeginning("Brim");
        myList.InsertAtBeginning("Jett");
        myList.InsertAtIndex(3, "UrMom");
    
        System.out.println(myList);
    }

}
