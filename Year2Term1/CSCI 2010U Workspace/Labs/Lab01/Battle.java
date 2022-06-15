public class Battle {

    //Monster Data
    String M1Name;
    Float M1HP;
    Float M1Atk;
    Float M1Def;

    String M2Name;
    Float M2HP;
    Float M2Atk;
    Float M2Def;

    int round = 0;

    public Battle(String M1Name, Float M1HP, Float M1Atk, Float M1Def, String M2Name, Float M2HP, Float M2Atk, Float M2Def){
        ///Monster Initialization
        this.M1Name = M1Name;
        this.M1HP = M1HP;
        this.M1Atk = M1Atk;
        this.M1Def = M1Def;
    
        this.M2Name = M2Name;
        this.M2HP = M2HP;
        this.M2Atk = M2Atk;
        this.M2Def = M2Def;
    }

    //Get Functions
    public boolean isM1Dead(){
        return M1HP <= 0;
    }
    public String getM1Name(){
        return M1Name;
    }
    public float getM1HP(){
        return M1HP;
    }
    public float getM1Atk(){
        return M1Atk;
    }
    public float getM1Def(){
        return M1Def;
    }
    
    public boolean isM2Dead(){
        return M2HP <= 0;
    }
    public String getM2Name(){
        return M2Name;
    }
    public float getM2HP(){
        return M2HP;
    }
    public float getM2Atk(){
        return M2Atk;
    }
    public float getM2Def(){
        return M2Def;
    }

    public void simulateRound(){
        float dmg;
        while(!isM1Dead() && !isM2Dead()){
            round++;
            System.out.println("Round " + round);

            if(getM2Def() - getM1Atk() < 0){
                this.M2HP -= getM1Atk() - getM2Def();
                dmg =  getM1Atk() - getM2Def();
            }
            else{
                dmg =  getM2Def() - getM1Atk();
            }
            System.out.println(getM1Name() + " does " + dmg + " points of damage to " + getM2Name());
            if(getM1Def() - getM2Atk() < 0){
                this.M1HP -= getM2Atk() - getM1Def();
                dmg =  getM2Atk() - getM1Def();
            }
            else{
                dmg =  getM1Def() - getM2Atk();
            }
            System.out.println(getM2Name() + " does " + dmg + " points of damage to " + getM1Name());

            System.out.println(getM1Name() + ": " + getM1HP());
            System.out.println(getM2Name() + ": " + getM2HP());


        }
    }

}