import java.util.*;
/** @author Thomas Chiarello
*/
public class HumanPlayer extends Player{
    /**
    * This is the constructor which takes and defines a monster
    * @param monster - CPU Players Monster
    */
    public HumanPlayer(Monster monster){
        super(monster);
    }

    /**
     * This method takes an input from the user, confirms that it is a valid input, then returns the choice.
     * @return choice
     */
    Scanner sc= new Scanner(System.in);
    public int chooseMove() {
        while(true){
            System.out.print("1. Vine Whip\n2. Tackle\n3. Take Down\n4. Razor Leaf\nWhich move? ");  
            if(sc.hasNextInt()){          
                int choice= sc.nextInt();
                if(1 <= choice && choice <= 4){
                        return choice;
                } else{
                    System.out.println("Invalid choice, please enter a number from 1 to 4");
                }
            } else{
                System.out.println("Invalid Option, please enter an integer.");
                sc.next();
            }
        }
    }


    public boolean isFasterThan(CPUPlayer enemy) {
        return (this.monster.getSpd()) > (enemy.getMonster().getSpd());
    }
    
}
