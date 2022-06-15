package java2.animals;

import java.util.Date;

public class Giraffe extends Animal {
    public Giraffe(float mass, String foodSource, String species, Date dateOfBirth){
        super(mass, foodSource, species, dateOfBirth);
    }
    @Override
    public void speak() {
        System.out.println("blaaaaghhh?");        
    }


}