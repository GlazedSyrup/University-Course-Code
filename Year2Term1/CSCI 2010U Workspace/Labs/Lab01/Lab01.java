public class Lab01 {
	public static void main(String[] args) {
		// part 1
		System.out.println("*** Part 1 ***");
		String chikapuName = "Chikapu";
		float chikapuAttack = 38.5f;
		float chikapuDefense = 20.0f;
		float chikapuHP = 200f;

		String zarichardName = "Zarichard";
		float zarichardAttack = 25f;
		float zarichardDefense = 12.5f;
		float zarichardHP = 200f;

		Battle battle = new Battle(chikapuName, chikapuHP, chikapuAttack, chikapuDefense, zarichardName, zarichardHP, zarichardAttack, zarichardDefense);
		
		while (!battle.isM1Dead() && !battle.isM2Dead()) {
			battle.simulateRound();
		}

		if (battle.isM1Dead()) {
			System.out.printf("\n%s has fainted!\n", battle.getM1Name());
		} else {
			System.out.printf("\n%s has fainted!\n", battle.getM2Name());
		}
		

		// part 2
		System.out.println("\n*** Part 2 ***");
		int iterations = 10;
		System.out.printf("e^1 = %.8f\n", TaylorSeries.approXp(1, iterations));
		System.out.printf("e^2 = %.8f\n", TaylorSeries.approXp(2, iterations));
	}
}