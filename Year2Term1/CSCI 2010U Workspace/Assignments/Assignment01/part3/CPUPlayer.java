import java.util.Random;
/** @author Thomas Chiarello
*/
public class CPUPlayer extends Player {
    /**
    * This is the constructor which takes and defines a monster
    * @param monster - CPU Players Monster
    */
    public CPUPlayer(Monster monster){
        super(monster);
    }

    /**
     * This method randomly generates a number from 1 to 4
     */
    public int chooseMove() { 
        Random rand = new Random();
        int choice = rand.nextInt(3);
        return choice+1; 
    }  
    

}
