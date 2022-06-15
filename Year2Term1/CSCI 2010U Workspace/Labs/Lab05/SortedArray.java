public class SortedArray {
  Warrior [] array = new Warrior[100];
  int arrayL = 0;
  public int assignmentCount = 0;

  public void insert(Warrior warrior) {
    if(arrayL == 0){
      assignmentCount +=1;
      array[0] = warrior;
      arrayL += 1;
    }
    else{
      for(int i = 1; i <= 100; i++ ){
        if(arrayL == 100){
          break;
        }
        if(arrayL == i){
          assignmentCount +=1;
          array[i] = warrior;
          arrayL += 1;
        }
        else{
          if(array[i+1].getSpeed() < warrior.getSpeed()){
              assignmentCount +=1;
              array[i] = warrior;
              arrayL += 1;
          }
          else if(array[i+1].getSpeed() > warrior.getSpeed()){
            assignmentCount +=1;
            array[i] = warrior;
            arrayL += 1;
          }
        } 
      }
    }
  }

}