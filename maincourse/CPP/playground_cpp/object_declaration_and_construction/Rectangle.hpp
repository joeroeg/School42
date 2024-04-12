#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
private:
    int width, height;

public:
    // Default Constructor
    Rectangle() : width(0), height(0) {}

    // Parameterized Constructor
    Rectangle(int w, int h) : width(w), height(h) {}

    // Copy Constructor
    Rectangle(const Rectangle& other) : width(other.width), height(other.height) {}

    // Accessor
    int area() const { return width * height; }
};

#endif
