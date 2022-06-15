import sorting.*;
import expressionTree.*;

public class Assignment2Driver {
	public static double[] generateRandomArray(int size) {
		double[] array = new double[size];
	
		for (int i = 0; i < array.length; i++) {
			array[i] = Math.random() * 100.0;
		}
	
		return array;
	}

	public static void main(String[] args) {
		// part 1

		double[] array1 = generateRandomArray(1);
		double[] array2 = array1.clone();

		// algorithm #1
		Sorter iSorter = new InsertionSorter();
		iSorter.sort(array1);
		System.out.println("Operations: " + iSorter.getOpCount());

		// algorithm #2
		Sorter mSorter = new MergeSorter();
		mSorter.sort(array2, 0, array2.length-1);
		System.out.println("Operations: " + mSorter.getOpCount());

		// part 3

		// 2 + (8 * 3)
		ValueNode two = new ValueNode(2);
		ValueNode three = new ValueNode(3);
		ValueNode eight = new ValueNode(8);
		OpNode eightTimes3 = new OpNode(eight, "*", three);
		OpNode twoPlusEightTimesThree = new OpNode(two, "+", eightTimes3);
		ExpressionTree tree = new ExpressionTree(twoPlusEightTimesThree);
		System.out.println("print():");
		tree.print();
		System.out.println("evaluate():");
		System.out.println("" + tree.evaluate());

		System.out.println("");

		// (13 / 4) + (2 + (8 * 3))
		ValueNode thirteen = new ValueNode(13);
		ValueNode four = new ValueNode(4);
		OpNode thirteenOverFour = new OpNode(thirteen, "/", four);
		OpNode bigExpression = new OpNode(thirteenOverFour, "+", twoPlusEightTimesThree);
		ExpressionTree tree2 = new ExpressionTree(bigExpression);
		System.out.println("print():");
		tree2.print();
		System.out.println("evaluate():");
		System.out.println("" + tree2.evaluate());

	}
}