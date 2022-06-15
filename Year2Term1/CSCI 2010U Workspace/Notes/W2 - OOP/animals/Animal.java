package java2.animals;

import java.util.Date;

public abstract class Animal {
    public float mass;
    private String foodSource;
    private String species;
    private Date dateOfBirth;
 
    public Animal(){

    }

    public Animal(float mass, String foodSource, String species, Date dateOfBirth){
        this.mass = mass;
        this.foodSource = foodSource;
        this.species = species;
        this.dateOfBirth = dateOfBirth;
    }

    public int getAgeInYears(){
        //we will need to chance within Giraffe and Cricket
        return -1;
    }

    public String getSpecies(){
        return this.species;
    }

    public String toString(){
        return this.species + ", born: " + this.dateOfBirth.toString() + ", mass:" + this.mass + "kg.";
    }

    public abstract void speak();
}
