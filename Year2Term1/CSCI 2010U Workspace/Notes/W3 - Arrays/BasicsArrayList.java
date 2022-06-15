public class BasicsArrayList {
    private String[] elements;
    private int numElements;
    
    /***
     * This is the constructor which takes a capacity and defines the array and its length parameter
     * this is an example of using javadoc
     * @param initialSize - capacity integer, setting the initial array size
     */

    public BasicsArrayList(int initialSize){
        this.elements = new String[initialSize];
        numElements = 0;
    }

    public void resizeIfRequired(){
        if(this.numElements+1 >= this.elements.length){
            String[] newArray = new String[elements.length*2];
            
            for(int i = 0; i < this.elements.length; i++){
                newArray[i] = this.elements[i];
            }
            //Replace elements with the new larger array
            this.elements = newArray;
        }
    }

    public void InsertAtEnd(String newElement){
        resizeIfRequired();

        this.elements[this.numElements] = newElement;
        this.numElements++;
    }

    public void InsertAtBeginning(String newElement){
        resizeIfRequired();

        for(int i = this.numElements - 1; i >= 0; i--){
            this.elements[i + 1] = this.elements[i];
        }

        this.elements[0] = newElement;
        this.numElements++;
    }

    public void InsertAtIndex(int index, String newElement){
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
        for(String element : this.elements){
            result += element + " ";
        }
        result += "]";
        return result;
    }

    public static void main(String[] args){
        BasicsArrayList myList = new BasicsArrayList(5);
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
