import java.util.Random;

public class Lab05 {
	public static void main(String[] args) {
		SortedDoublyLinkedList list = new SortedDoublyLinkedList();
		SortedArray array = new SortedArray();

		// insert 100 elements into both lists (randomly generated)
		for (int i = 0; i < 100; i++) {
			Warrior newWarrior = new Warrior("Generic", genStat(50), genStat(50), genStat(200));
			list.insert(newWarrior);
			array.insert(newWarrior);
		}

		// compare the number of assignment operations:
		System.out.println("SortedDoublyLinkedList.assignmentCount: " + list.assignmentCount);
		System.out.println("SortedArray.assignmentCount:            " + array.assignmentCount);
	}

	public static int genStat(int max) {
		// randomly choose an integer between 1 and max
		Random rand = new Random();
		return rand.nextInt(max) + 1;
	}
}