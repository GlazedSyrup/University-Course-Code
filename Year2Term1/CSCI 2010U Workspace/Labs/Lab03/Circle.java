public class Circle extends Shape {
    private float radius;
    float pi = 3.14159265359f;

    public Circle(String color, float radius){
        this.color = color;
        this.radius = radius;
    }
    
    public float getArea(){
        return pi*radius*radius;
    }
    
    public float getPerimeter(){
        return 2*pi*radius;
    }

    public String toString(){
        return (color + " circle with radius " + radius);
    }

}