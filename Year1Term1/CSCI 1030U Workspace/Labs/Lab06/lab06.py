class Shape:
    def __init__(self, shape, object):
        self.shape = shape
        self.object = object



class Rectangle(Shape):
    def __init__(self, length, height):
        Shape.__init__(self, 'Rectangle', Rectangle)
        self.length = length
        self.height = height
        self.area = length*height
        self.perimeter = 2*length + 2*height

    def set_area(self):
        self.area = length*height

    def get_area(self):
        return self.area
    
    def set_perimeter(self):
        self.perimeter = 2*length + 2*height

    def get_perimeter(self):
        return self.perimeter




class Circle(Shape):
    def __init__(self, radius):
        Shape.__init__(self, 'Circle', Circle)
        self.radius = radius
        self.area = 3.141592653589793*radius**2
        self.perimeter = 2*3.141592653589793*radius

    def set_area(self):
        self.area = 3.141592653589793*radius**2

    def get_area(self):
        return self.area
    
    def set_perimeter(self):
        self.perimeter = 2*3.141592653589793*radius

    def get_perimeter(self):
        return self.perimeter








r1 = Rectangle(4, 5)
r2 = Rectangle(3, 5)
c1 = Circle(4)
c2 = Circle(3)

print(r1.get_area())
print(r2.get_area())
print(r1.get_perimeter())
print(r2.get_perimeter())


print(c1.get_area())
print(c2.get_area())
print(c1.get_perimeter())
print(c2.get_perimeter())



shapes = [
    Rectangle(3, 5),
    Circle(4)
]

assert r1.get_area() == 20
assert r2.get_area() == 15

assert c1.get_area() > 50.26 and c1.get_area() < 50.27
assert c2.get_area() > 28.27 and c2.get_area() < 28.28

assert c1.get_perimeter() > 25.13 and c1.get_perimeter() < 25.14
assert c2.get_perimeter() > 18.84 and c2.get_perimeter() < 18.85

assert shapes[0].get_area() == 15
assert shapes[0].get_perimeter() == 16
assert shapes[1].get_area() > 50.26 and shapes[1].get_area() < 50.27
assert shapes[1].get_perimeter() > 25.13 and shapes[1].get_perimeter() < 25.14
