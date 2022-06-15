public class Lab06 {

    public static int operationCount = 0;

    public static int fibonacciRec(int n){
        operationCount = 0;
        if(n <= 1){
            operationCount += 1;
            return n;
        }
        operationCount += 1;
        return fibonacciRec(n-1) + fibonacciIter(n-2);
    }

    public static int fibonacciIter(int n){
        operationCount = 0;
        operationCount += 1;
        int curr = 1;
        operationCount += 1;
        int prev = 0;
        operationCount += 1;
        int prevp = 0;
        for(int i = 0; i < n; i++){
            operationCount += 1;
            prevp = prev;
            operationCount += 1;
            prev = curr;
            operationCount += 1;
            curr = prev + prevp;
        }
        operationCount += 1;
        return curr;
    }

    public static int getCallCount(){
        return operationCount;
    }

	/* Towers of Hanoi */
	public static String move1(int source, int dest) {
		return "Move top ring from peg " + source + " to peg " + dest + ".\n";
	}

    public static String solveHanoi(int start, int end, int temp, int numRings){
        String solution = "";
        if(numRings == 1){
            solution = solution + move1(start, end);
        }else{
            solution = solution + solveHanoi(start, temp, end, numRings-1);
            solution = solution + move1(start, end);
            solution = solution + solveHanoi(temp, end, start, numRings-1);
        }
        return solution;
    }

	public static void main(String[] args) {
		System.out.println("Fibonacci:");
		int n = 15;

		//resetCallCount();
		int recursiveResult = fibonacciRec(n);
		int recursiveCalls = getCallCount();
        System.out.printf("Recursive result: %d (%d recursive calls)\n", recursiveResult, recursiveCalls);

        
		//resetCallCount();
		int iterativeResult = fibonacciIter(n);
		int iterations = getCallCount();
        System.out.printf("Iterative result: %d (%d iterations)\n", iterativeResult, iterations);

		System.out.println("Towers of Hanoi:");
		String solution = solveHanoi(1, 3, 2, 3);
		System.out.print(solution);
	}
}




