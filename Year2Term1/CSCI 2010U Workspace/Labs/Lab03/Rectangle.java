public class Rectangle extends Shape {
    private float length;
    private float width;

    public Rectangle(String color, float length, float width){
        this.color = color;
        this.length = length;
        this.width = width;
    }
    
    public float getArea(){
        return length*width;
    }
    
    public float getPerimeter(){
        return 2*width + 2*length;
    }

    public String toString(){
        return (color + " rectangle with length " + length + " and width " + width);
    }

}
