// Rubric Last section says:
//The subjective evaluation of your enhancement/additions
// I think they are reffering to the player class,
// which does jack shit. I probably need to remove it from
// the github files.

// THAT ORRRRR

//Im actually supposed to use inheritance for the humanPlayer and CPUPlayer
//which honestly sounds like more work but realistic

//ALSO for part 3 a status(burn) effect might be worth a try
//or type advantage, that sounds much easier to implement,
//can also ask nick for help with formulas needed.

//aight gn
import java.util.Random;

public abstract class Player {
    protected Monster monster;
    protected Move move;
    public abstract int chooseMove();
    //Type Advantage Table
    protected String[] Tags = {"Normal", "Fire", "Water", "Grass", "Flying"};
    protected float[] Def0 = {        1,      1,       1,       1,        1};
    protected float[] Def1 = {        1,   0.5f,    0.5f,       2,        1};
    protected float[] Def2 = {        1,      2,    0.5f,    0.5f,        1};
    protected float[] Def3 = {        1,   0.5f,       2,    0.5f,     0.5f};
    protected float[] Def4 = {        1,      1,       1,       2,        1};
    protected float[][] Atk = {    Def0,   Def1,    Def2,    Def3,     Def4}; 

    public String[] getTags(){
        return this.Tags;
    }

    public float[][] getAtk(){
        return this.Atk;
    }

    public Player(Monster monster){
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
     * This method determines what the type advantage/disadvantage is through the types of the attack and defense and using the table above.
     */
    public float typeAdvantage(Monster enemy, Move move){
        int AtkI = -1;
        int DefI = -1;
        for(int i = 0; i < 4; i++ ){
            if(move.getType() == getTags()[i]){
                DefI = i;
            }
            if(enemy.getType() == getTags()[i]){
                AtkI = i;
            }
            if(AtkI != -1 && DefI != -1){
                return getAtk()[DefI][AtkI];
            }
        }

        return 1;
    }



    /**
    * This method calculates damage and decreases a monsters health.
    * This is done with the following formula:
    * damageDealt = attacking monster's attack stat + attacking monster move's power - defending monster's defense stat.
    * There is the possibility for an attack to miss based on the moves acc variable.
    */
    public void attack(Player enemy, int attack) {
        int dmgDealt;
        boolean missed = false;
        Random rand = new Random();
        float chance = rand.nextFloat();
        if(attack == 1){
            move = this.monster.getMove1();
        } else if(attack == 2){
            move = this.monster.getMove2();
        } else if(attack == 3){
            move = this.monster.getMove3();
        } else{ //no need to test for move==4 since we already know it cant be anything other than 4 in the chooseMove method.
            move = this.monster.getMove4();
        }

        if(chance <= move.getAcc()){
            //This mess of math is the the damage dealt using the formula above, then right here---->\/ we multiply the typeadvantage, or sometimes type disadvantage.
            dmgDealt = Math.round(((monster.getAtk() + move.getPwr()) - (enemy.getMonster().getDef()))*typeAdvantage(enemy.getMonster(), move));
            enemy.getMonster().takeDmg(dmgDealt);
        } else{
            dmgDealt = 0;
            missed = true;
        }

        System.out.println(this.monster.getName() + " uses " + move.getName() + ".");
        if(missed){
            System.out.println(this.monster.getName() + " missed!");
        } else{
            System.out.println(this.monster.getName() + " hit for " + dmgDealt + " points of damage.");
        }
    }    
}
