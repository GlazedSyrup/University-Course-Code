package sorting;
public class InsertionSorter extends Sorter{
//Override Abstract Functions
    @Override
    public void sort(double[] list) {
        for(int i = 0; i < list.length; i++){
            int temp = i-1;
            countOp();
            double currntElmnt = list[i];
            countOp();
            while((temp > -1) && (list[temp] > currntElmnt)){
                list[temp+1] = list[temp];
                countOp();
                temp--;
                countOp();
            }
            list[temp+1] = currntElmnt;
            countOp();
        }
        
    }

    //Adding Additional Sort method for the sake of overriding all functions
    //Do nothing with it though
    public void sort(double[] list, int n1, int n2){
    
    }
}
