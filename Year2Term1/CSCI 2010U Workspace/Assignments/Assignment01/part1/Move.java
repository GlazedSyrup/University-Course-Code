/**@author Thomas Chiarello
*/
public class Move {
    private String name;
    private String type;
    private int pwr;
    private float acc;

    /** This is the constructor which takes the stats of a move and defines them
    */
    public Move(String name, String type, int pwr, float acc){
        this.name = name;
        this.type = type;
        this.pwr = pwr;
        this.acc = acc;
    }

    public String getName(){
        return this.name;
    }

    public String getType(){
        return this.type;
    }

    public int getPwr(){
        return this.pwr;
    }

    public float getAcc(){
        return this.acc;
    }
}
