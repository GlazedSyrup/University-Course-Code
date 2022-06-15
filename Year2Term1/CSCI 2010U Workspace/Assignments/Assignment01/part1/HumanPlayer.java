import java.util.*;
/** @author Thomas Chiarello
*/
public class HumanPlayer {
    private Monster monster;
    private Move move;

    /**
    * This is the constructor which takes and defines a monster
    * @param monster - CPU Players Monster
    */
    public HumanPlayer(Monster monster){
        this.monster = monster;
    }

    public Monster getMonster(){
        return this.monster;
    }

    /**
     * This method determines if a monsters hp has run out
     */
    public boolean hasLost() {
        if(this.monster.getHP() <= 0){
            return true;
        } else{
            return false;
        }
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


    /**
    * This method calculates damage and decreases a monsters health.
    * This is done with the following formula:
    * damageDealt = attacking monster's attack stat + attacking monster move's power - defending monster's defense stat
    */
    public void attack(CPUPlayer enemy, int playerMove) {
        int dmgDealt;
        if(playerMove == 1){
            move = this.monster.getMove1();
            dmgDealt = (monster.getAtk() + move.getPwr()) - (enemy.getMonster().getDef());
            enemy.getMonster().takeDmg(dmgDealt);
        } else if(playerMove == 2){
            move = this.monster.getMove2();
            dmgDealt = (monster.getAtk() + move.getPwr()) - (enemy.getMonster().getDef());
            enemy.getMonster().takeDmg(dmgDealt);
        } else if(playerMove == 3){
            move = this.monster.getMove3();
            dmgDealt = (monster.getAtk() + move.getPwr()) - (enemy.getMonster().getDef());
            enemy.getMonster().takeDmg(dmgDealt);
        } else{ //no need to test for move==4 since we already know it cant be anything other than 4 in the chooseMove method.
            move = this.monster.getMove4();
            dmgDealt = (monster.getAtk() + move.getPwr()) - (enemy.getMonster().getDef());
            enemy.getMonster().takeDmg(dmgDealt);
        }

        System.out.println(this.monster.getName() + " uses " + move.getName() + ".");
        System.out.println(this.monster.getName() + " hit for " + dmgDealt + " points of damage.");

    }

    public boolean isFasterThan(CPUPlayer enemy) {
        return (this.monster.getSpd()) > (enemy.getMonster().getSpd());
    }
    
}
