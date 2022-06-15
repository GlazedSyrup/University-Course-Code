public class BinarySearch {
    //overloaded function
    public static boolean binarySearch(int[] data, int toFind){
        return binarySearch( data, toFind, data.length - 1);
    }
    
    
    
    
    // [1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39]    (n = 20)
    // [1,3,5,7,9,11,13,15,17,19] toFind=14  (n = 10)
    // [11,13,15,17,19]                      (n = 5)
    // [11,13]                               (n = 2)
    // [13]                                  (n = 1)
    // []                                    (n = 0)
    // 
    // T(n) = O(log n)  (but how do I know this?)
    // T(n) = T(n/2) + O(1)  (recurrence - T is defined in terms of T)

    public static boolean binarySearch(int[] data, int toFind, int startIndex, int endIndex){
        if(endIndex < startIndex){
            return false;
        }
        
        int middleIndex = (startIndex + endIndex)/2;

        if (toFind == data[middleIndex]){
            return true;
        } else if(toFind < data[middleIndex]){
            return binarySearch(data, toFind, startIndex, middleIndex-1);
        } else{
            return binarySearch(data, toFind, middleIndex+1, endIndex);
        }
    }

    public static void main(String[] args) {
        int[] myList =  {2,6,10,12,19,22,31,44,63};
        System.out.println("is 19" + binarySearch(myList, 19));
    }



}
