/**@author Thomas Chiarello
*/
public class Monster {
    private String name;
    private String type;
    private int hp;
    private int spd;
    private int atk;
    private int def;
    private Move move1;
    private Move move2;
    private Move move3;
    private Move move4;

    /** This is the constructor which takes all the stats of a monster and defines them
    */
    public Monster(String name, String type, int hp, int spd, int atk, int def, Move move1, Move move2, Move move3, Move move4){
        this.name = name;
        this.type = type;
        this.hp = hp;
        this.spd = spd;
        this.atk = atk;
        this.def = def;
        this.move1 = move1;
        this.move2 = move2;
        this.move3 = move3;
        this.move4 = move4;
    }

    public void takeDmg(int dmg){
        this.hp -= dmg;
    }

    public String getName(){
        return this.name;
    }

    public String getType(){
        return this.type;
    }

    public int getHP(){
        return this.hp;
    }

    public int getSpd(){
        return this.spd;
    }

    public int getAtk(){
        return this.atk;
    }

    public int getDef(){
        return this.def;
    }

    public Move getMove1(){
        return this.move1;
    }

    public Move getMove2(){
        return this.move2;
    }

    public Move getMove3(){
        return this.move3;
    }

    public Move getMove4(){
        return this.move4;
    }

}
