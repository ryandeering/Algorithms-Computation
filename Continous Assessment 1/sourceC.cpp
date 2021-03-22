//Ryan Deering

//Algorithms and Computation - CA1

//sources
//The first two labs

#include <iostream>

class Shape {
public:
	virtual void draw() const = 0; //pure virtual function, can't create from base class
};

class Triangle : public Shape {
public:
    void draw() const;
};

class Square : public Shape {
public:
    void draw() const;
};

class Circle : public Shape {
public:
    void draw() const;
};

void Shape::draw() const
{
    std::cout << "Shape:" << std::endl;
}

void Circle::draw() const
{
    Shape::draw();
	std::cout << "Circle" << std::endl;
}

void Square::draw() const
{
    Shape::draw();
	std::cout << "Square" << std::endl;
}

void Triangle::draw() const
{
    Shape::draw();
    std::cout << "Triangle" << std::endl;
}


int main()
{
    Shape* shapes[] = { new Triangle(), new Circle(), new Square()};

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->draw();
    }
}