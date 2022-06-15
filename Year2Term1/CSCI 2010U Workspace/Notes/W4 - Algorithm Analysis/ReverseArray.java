// [1,2,3,4,5]
//  |       |
//  i       j
//
// 1. Swap elements at i and j
// [5,2,3,4,1]
//  |       |
//  i       j
// 2. recursively solve for i + 1 to j - 1
// [5,2,3,4,1]
//    |   |
//    i   j


// [5,4,3,2,1]
//      |
//     i,j

// [1,2,3,4]
// [4,2,3,1]
// [4,3,2,1]


// f(n) = n^2 is O(g(n) = n^3)      n^3 is OMEGA(n^2)
// big-oh O(): f grows the same or slower than g
// big-theta : f grows exactly the same as g
// big-omega : f grows the same or faster than g
public class ReverseArray {
    //rail recursion, linear recursion

    //iterative version of reversing the array, outside to inside
    public static void reverseArrayLoop(int[] array) {
        int i = 0;
        int j = 0;

        while(i<j){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }    

    public static void reverseArray(int[] array, int i, int j) {
        if(i < j){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            
            //recursively call with increments
            reverseArray(array, i+1, j-1);
        }
    }

    //convienience function to avoid initial values for start and end
    public static void reverseArray(int[] array) {
        reverseArray(array, 0, array.length-1);
    }

    

    public static void main(String[] args) {
        int[] myList =  {2,6,10,12,19,22,31,44,63};
        reverseArray(myList);
        for(int element : myList){
            System.out.printf("%d ", element);
        }
        System.out.println("");
    }



}
