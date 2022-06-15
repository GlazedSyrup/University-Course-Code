import java.util.Random;
/** @author Thomas Chiarello
*/
public class CPUPlayer {
    private Monster monster;
    private Move move;

    /**
    * This is the constructor which takes and defines a monster
    * @param monster - CPU Players Monster
    */
    public CPUPlayer(Monster monster){
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
     * This method randomly generates a number from 1 to 4
     */
    public int chooseMove() { 
        Random rand = new Random();
        int choice = rand.nextInt(3);
        return choice+1; 
    }  
    
    /**
    * This method calculates damage and decreases a monsters health.
    * This is done with the following formula:
    * damageDealt = attacking monster's attack stat + attacking monster move's power - defending monster's defense stat
    */
    public void attack(HumanPlayer player, int enemyMove) {
        int dmgDealt;
        if(enemyMove == 1){
            move = this.monster.getMove1();
            dmgDealt = (monster.getAtk() + move.getPwr()) - (player.getMonster().getDef());
            player.getMonster().takeDmg(dmgDealt);
        } else if(enemyMove == 2){
            move = this.monster.getMove2();
            dmgDealt = (monster.getAtk() + move.getPwr()) - (player.getMonster().getDef());
            player.getMonster().takeDmg(dmgDealt);
        } else if(enemyMove == 3){
            move = this.monster.getMove3();
            dmgDealt = (monster.getAtk() + move.getPwr()) - (player.getMonster().getDef());
            player.getMonster().takeDmg(dmgDealt);
        } else{ 
            move = this.monster.getMove4();
            dmgDealt = (monster.getAtk() + move.getPwr()) - (player.getMonster().getDef());
            player.getMonster().takeDmg(dmgDealt);
        }

        System.out.println(this.monster.getName() + " uses " + move.getName() + ".");
        System.out.println(this.monster.getName() + " hit for " + dmgDealt + " points of damage.");
    }

}
