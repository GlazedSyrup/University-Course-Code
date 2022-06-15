public class SavingsCalculator {
    public static void main(String[] args){
        double principle = 1000.0;
        //float principle2 = 1000.0f;
        double interestRate = 0.035;
        int numYears = 10;

        for (int year = 0; year < numYears; year++){
            principle += interestRate * principle;
        }

        System.out.println("Interest Rate: " + interestRate + "\nPrinciple: $" + principle);

        principle = 0.0;
        numYears = 0;
        double annualContribution = 5000.0;

        while (principle < 1000000.0){
            principle += interestRate * principle + annualContribution;
            numYears++;
        }
        System.out.printf("It took %d years to save up ONE MILLION DOLLARS", numYears);
    }
}