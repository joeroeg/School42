#include <iostream>
#include <string>

class Graphic {
public:
    virtual void draw() const = 0;
    virtual ~Graphic() {}
};

class Note : public Graphic {
public:
    void draw() const override {
        std::cout << "Drawing a musical note.\n";
    }
};

class Rest : public Graphic {
public:
    void draw() const override {
        std::cout << "Drawing a musical rest.\n";
    }
};

class GraphicTool {
    std::string type;

public:
    GraphicTool(const std::string& type) : type(type) {}

    Graphic* createGraphic() const {
        if (type == "Note") {
            return new Note();
        } else if (type == "Rest") {
            return new Rest();
        }
        return nullptr;
    }
};

int main() {
    std::string inputType;
    inputType = "Note";
    // std::cout << "Enter graphic type ('Note' or 'Rest'): ";
    // std::cin >> inputType;

    GraphicTool tool(inputType);
    Graphic* myGraphic = tool.createGraphic();
    if (myGraphic) {
        myGraphic->draw();
        delete myGraphic;
    } else {
        std::cout << "Invalid graphic type provided!\n";
    }

    return 0;
}
