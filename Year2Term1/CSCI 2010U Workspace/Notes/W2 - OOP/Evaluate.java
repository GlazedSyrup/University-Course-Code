package java2;

import java2.animals.Animal;
import java2.animals.Giraffe;
import java2.animals.Cricket;
import java.util.Date;

public class Evaluate {
    public static void main(String[] args){
        Animal giraffe = new Giraffe(300.0f, "Leaves", "Giraffe", new Date());
        System.out.println(giraffe);
        giraffe.speak();

        Animal cricket = new Cricket(0.005f, "Insects", "Cricket", new Date());
        System.out.println(cricket);
        cricket.speak();
    }
}
