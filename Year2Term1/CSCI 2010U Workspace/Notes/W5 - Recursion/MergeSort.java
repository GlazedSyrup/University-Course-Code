public class MergeSort {

    public void merge(int[] myList, int left, int mid, int right){
        int sub1 = mid - left + 1;
        int sub2 = right - mid;

        int L[] = new int[sub1];
        int R[] = new int[sub2];

        for (int i = 0; i < sub1; i++){
            L[i] = myList[left + i];
        }
        for (int i = 0; i < sub2; i++){
            R[i] = myList[mid + i + 1];
        }

        //Initial index for merging
        int i = 0;
        int j = 0;

        //This will represent i + j
        int k = left;

        while(i < sub1 && j < sub2){
            if (L[i] <= R[j]){
                myList[k] = L[i];
                i++;
            }
            else{
                myList[k] = R[j];
                j++;
            }
            k++;
        }
        //May not execute, security if i or j do not reach sub1
        while(i < sub1){
            myList[k] = L[i];
            i++;
            k++;
        }
        while(j < sub2){
            myList[k] = R[j];
            j++;
            k++;
        }
    }

    public void sort(int[] myList, int left, int right){
        if (left < right){
            int mid = (left + right)/2;

            this.sort(myList, left, mid);           // T(n/2)
            this.sort(myList, mid+1, right);        // T(n/2)
                                                    //
            this.merge(myList, left, mid, right);   // O(n)
                                                    // 2T(n/2) + O(n)
        }
    }

    public void printArray(int[] myList){
        for (int i = 0; i < myList.length; i++){
            System.out.print(myList[i] + " ");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        int[] currentList = {4,10,21,19,3432,2,5,8,3,66,33,44,55,1};

        MergeSort mS = new MergeSort();
        mS.printArray(currentList);

        mS.sort(currentList, 0, currentList.length -1);

        mS.printArray(currentList);
    }
}