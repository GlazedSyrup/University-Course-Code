public class BinarySearch {
    //Overloaded function
    public static boolean binarySearch(int[] data, int toFind, int startIndex, int endIndex){
        return binarySearch(data, toFind, 0, data.length - 1);
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
        //Additionally, a base case / solution when the value does not exist or list is empty.
        if (endIndex < startIndex){
            return false;
        }

        int middleIndex = (startIndex + endIndex) /2;

        // Base Case / Solution
        if (toFind == data[middleIndex]){
            return true;
        }
        else if (toFind < data[middleIndex]){
            // toFind is not in the middle, so we will look to the left half of the list
            return binarySearch(data, toFind, startIndex, middleIndex-1);
        }
        else {
            // toFind is not in the middle, so we will look to the right half of the list
            return binarySearch(data, toFind, middleIndex+1, endIndex);
        }
    }

    public static void main(String[] args) {
        int[] myList = {2,6,10,12,19,22,31,44,63};
        System.out.println("Is 10 in the list? " + binarySearch(myList, 10));
        System.out.println("Is 6 in the list? " + binarySearch(myList, 6));
        System.out.println("Is 30 in the list? " + binarySearch(myList, 30));
        System.out.println("Is 31 in the list? " + binarySearch(myList, 31));
    }
}