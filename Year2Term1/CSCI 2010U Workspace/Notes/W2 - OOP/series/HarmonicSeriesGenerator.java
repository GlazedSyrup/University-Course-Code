// 1 + 1/2 + 1/3 + 1/4
// 2 + 2/4 + 2/6 + 2/8
// 1 - 1/2 + 1/3 - 1/4
public class HarmonicSeriesGenerator extends SeriesGenerator {
    private double denominatorIncrement = 1.0;
    private double denominator = 1.0;
    private double numerator = 1.0;
    private boolean alternating = false;

    public HarmonicSeriesGenerator(double denominatorIncrement,
                                   double numerator,
                                   double startDenominator,
                                   boolean alternating) {
        this.denominatorIncrement = denominatorIncrement;
        this.alternating = alternating;
        this.numerator = numerator;
        this.denominator = startDenominator;
        this.sum = numerator / startDenominator;
        this.previousValue = this.sum;
    }

    public double generateCurrentValue(){
        this.denominator += this.denominatorIncrement;
        double currentValue = this.numerator / this.denominator;

        if (this.alternating && this.previousValue > 0.0){
            currentValue *= -1.0;
        }
        this.previousValue = currentValue;
        return this.previousValue;
    }

    // 1 - 1/2 + 1/3 - 1/4
    public static void main(String[] args) {
        HarmonicSeriesGenerator gen = new HarmonicSeriesGenerator(1.0, 1.0, 1.0, true);
        for (int i = 0; i < 10; i++){
            System.out.printf("%.3f (sum: %.3f)\n", gen.nextValue(), gen.getSumSoFar());
        }
    }
}