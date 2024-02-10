// CS1410 - Assignment 03
#include <iostream>
#include <iomanip> 
#include <cmath>
 
using namespace std;

//TODO 1: ShapeKind Enumeration goes here
enum ShapeKind {
  Circle, Square, Rectangle
};
//TODO 2: Shape Structure goes here
struct Shape{
  ShapeKind kind;
  double length;
  double width;
};

// Function prototypes and definitions
double area(Shape s);
//TODO 3: area() definition goes here
double area(Shape s){
  switch(s.kind){
    case ShapeKind::Circle:
      return pow((s.length/2.0),2) * 3.14;
    case ShapeKind::Square:
    return s.length * s.width;
    default: 
     return s.length * s.width;
    
  };
  return 0;
};
double perimeter(Shape s);
//TODO 4: perimeter( definition goes here
double perimeter(Shape s){
switch(s.kind){
    case ShapeKind::Circle:
      return s.length * 3.14;
    case ShapeKind::Square:
    return (s.length + s.width)*2;
    default: 
    return (s.length + s.width)*2;
  };
  return 0;
};
string nameOf(Shape);
//TODO 5: nameOf() definition goes here
string nameOf(Shape s){
  switch(s.kind){
    case ShapeKind::Circle:
      return "Circle";
    case ShapeKind::Square:
    return "Square";
    default: 
    return "Rectangle";
  };
  return 0;
};
void promptAndReadInputFor(Shape& );
//TODO 6: promptAndReadInputFor() definition goes here
void promptAndReadInputFor(Shape& s){
  switch(s.kind){
    case ShapeKind::Circle:
      cout << "Enter diameter of circle: ";
      cin >> s.length;
      s.width = s.length;
      //area(s.length)
      break;
    default:
      cout << "Enter Length and Width: ";
      cin >> s.length >> s.width;
      if (s.length == s.width){
        s.kind = ShapeKind::Square;
      } else if (s.length != s.width) {
        s.kind = ShapeKind::Rectangle;
      }
      break;
  };
  //return 0;
}
// The main function
int main() {
  // Shape objects
Shape Circle = { ShapeKind::Circle, 0, 0 };
  //TODO 7: define two more shape objects: a Square and and a Rectangle 
Shape Square = { ShapeKind::Square, 0, 0 };
Shape Rectangle = { ShapeKind::Rectangle, 0, 0 };
  //TODO 8: Call the promptAndReadInputFor() function on each of the above three shapes
promptAndReadInputFor(Circle);
promptAndReadInputFor(Square);
promptAndReadInputFor(Rectangle);
  //TODO 9: Print a out a report of these shapes in a table-like format
    cout << "Shape" << setw(12) << "width" << setw(12)<< "height" << setw(12) << "Perimeter" << setw(12) << "Area" << endl;
    cout << nameOf(Circle) << setw(11) << Circle.width << setw(8) << Circle.length<<setw(12) <<perimeter(Circle) << setw(13) << area(Circle) << endl;
    cout << nameOf(Square) << setw(11) << Square.width << setw(8) << Square.length <<setw(12) << perimeter(Square) << setw(13) << area(Square) << endl;
    cout << nameOf(Rectangle) << setw(8)<< Rectangle.width << setw(8) << Rectangle.length<< setw(12)<< perimeter(Rectangle) << setw(13) << area(Rectangle) << endl;
  return 0;
}