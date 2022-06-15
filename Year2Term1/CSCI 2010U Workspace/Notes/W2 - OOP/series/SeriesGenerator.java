// 1, 2, 3, 4, 5, ...
// 1, 2, 4, 8, 16, ...
public abstract class SeriesGenerator {
    private int index = 0;
    protected double sum = 0.0;
    protected double previousValue = 0.0;

    abstract double generateCurrentValue();

    public double nextValue(){
        this.index++;

        double currentValue = generateCurrentValue();

        this.sum += currentValue;

        return currentValue;
    }

    public double getSumSoFar() {
        return sum;
    }
}
