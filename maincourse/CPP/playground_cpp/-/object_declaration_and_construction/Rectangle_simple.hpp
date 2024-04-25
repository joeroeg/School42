#ifndef RECTANGLE_SIMPLE_HPP
#define RECTANGLE_SIMPLE_HPP

class Rectangle_simple {
private:
    int width, height;
public:
    Rectangle_simple();
    Rectangle_simple(int, int);

    // Accessor
    int area() const { return width * height; }
};

#endif
