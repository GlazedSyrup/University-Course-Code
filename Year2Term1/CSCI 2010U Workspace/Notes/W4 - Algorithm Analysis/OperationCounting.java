public class OperationCounting {
    // worst case analysis
    public static int linearSearch(int[] values, int toFind) { //  Assume n => values.length
        for (int i = 0; i < values.length; i++) {              // 2n + 2 = O(n) -> linear
           if (values[i] == toFind) {                          // 2      = O(1) -> constant
               return i;                                       // 1      = O(1) -> constant (base)
           }
        }
        return -1;                                             // 1      = O(1) -> constant (base)
     }                                                  // TOTAL: 2n + 2 + 2n + 1 = 4n + 3 = O(n)
                                                                        // ^ we add n to our condition as
                                                                        // check it each time.
                                                                        // only 1 base condition will execute.

     public static double[] prefixAverage1(double[] elements) {
        double[] averages = new double[elements.length];                    // 3 = O(1)
        for (int avgIndex = 0; avgIndex < elements.length; avgIndex++) {    // 2n + 2
            double total = 0.0;                                             // 2
            for (int sumIndex = 0; sumIndex <= avgIndex; sumIndex++) {      // 2(n / 2) + 2
                total += elements[sumIndex];                                // 3 = O(1)
            }
            averages[avgIndex] = total / (avgIndex + 1);                    // 4 = O(1)
        }
        return averages;                                                    // 1 = O(1)
    }            // TOTAL: 3 + 2n + 2 + 2n + 2n^2/2 + 2n + n(3(n/2)) + 4n + 1 = O(n^2)

    public static double[] prefixAverage2(double[] elements) {
        double[] averages = new double[elements.length];                    // 4 = O(1)
        double total = 0.0;                                                 // 2 = O(1)
        for (int avgIndex = 0; avgIndex < elements.length; avgIndex++) {    // 2 + 2n = O(n)
            total += elements[avgIndex];                                    // 3 = O(1)
            averages[avgIndex] = total / (avgIndex + 1);                    // 4 = O(1)
        }
        return averages;                                                    // 1 = O(1)
    }                                                                // TOTAL: 4 + 2 + 2n + 2 + 3n + 4n = O(n)
}