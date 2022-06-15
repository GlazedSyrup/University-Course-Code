package sorting;

public class MergeSorter extends Sorter{

    public void merge(double[] list, int l, int m, int r){
        //Initialize Variables
        int c1 = 0;
        countOp();
        int c2 = 0;
        countOp();
        int temp = l;
        countOp();
        int n1 = m - l + 1;
        countOp();
        int n2 = r - m;
        countOp();
        double left[] = new double[n1];
        countOp();
        double right[] = new double[n2];
        countOp();

        for (int i = 0; i < n1; i++)
            left[i] = list[l + i];
            countOp();
        for (int i = 0; i < n2; i++)
            right[i] = list[m + i + 1];
            countOp();

        while(c1 < n1 && c2 < n2){
            if (left[c1] <= right[c2]){
                list[temp] = left[c1];
                countOp();
                c1++;
                countOp();
            }
            else{
                list[temp] = right[c2];
                countOp();
                c2++;
                countOp();
            }
            temp++;
            countOp();
        }
        while(c1 < n1){
            list[temp] = left[c1];
            countOp();
            c1++;
            countOp();
            temp++;
            countOp();
        }
        while(c2 < n2){
            list[temp] = right[c2];
            countOp();
            c2++;
            countOp();
            temp++;
            countOp();
        }
    }
    //Override Abstract Functions
    @Override
    public void sort(double[] list, int n1, int n2){
        if (n1 < n2){
            int mid = (n1 + n2)/2;
            countOp();
            this.sort(list, n1, mid);
            this.sort(list, mid+1, n2);

            this.merge(list, n1, mid, n2);
        }
    }
    
    //Adding Additional Sort method for the sake of overriding all functions
    //Do nothing with it though
    public void sort(double[] list){

    }

}
