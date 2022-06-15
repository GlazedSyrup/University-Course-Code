package sorting;

public abstract class Sorter {
  private long opCount = 0L;

  public long getOpCount() {
    return this.opCount;
  }

  protected void resetOpCount() {
    this.opCount = 0L;
  }

  protected void countOp() {
    this.opCount++;
  }

  public abstract void sort(double[] list);

  public abstract void sort(double[] list, int n1, int n2);
}