public class TaylorSeries {

    public static double approXp(int x, int n){
        double approxp = 0;

        TaylorSeries TSinst = new TaylorSeries();

        for(int i = 0; i <= n; i++){
            approxp += TSinst.pow(x, i)/TSinst.factorial(i);
        }

        return approxp;
    }
    
    public double factorial(int n){
        if(n <= 1){
            return 1;
        }

        return n*factorial(n-1);
    }

    public double pow(int x, int n){
        if(n == 0){
            return 1;
        }

        return x*pow(x, n-1);
    }
}
