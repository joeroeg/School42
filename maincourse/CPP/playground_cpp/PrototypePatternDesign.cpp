#include <iostream>
#include <unordered_map>
#include <string>

/*

The prototype pattern is a creational design pattern in software development. It is used when the type of objects to create is determined by a prototypical instance, which is cloned to produce new objects. This pattern is used to:
- Avoid subclasses of an object creator in the client application, like the factory method pattern does.
- Avoid the inherent cost of creating a new object in the standard way (e.g., using the 'new' keyword) when it is prohibitively expensive for a given application.
https://en.wikipedia.org/wiki/Prototype_pattern
https://youtu.be/tv-_1er1mWI?si=wJn9JIrkR8Nsfnhe&t=144


Explanation:
Prototype Pattern: GraphicTool uses a prototype Graphic to create new objects. The clone() method is used for this purpose.
Simulating Dynamic Loading: We simulate dynamic class instantiation with the createGraphicByName function, which acts like a simple factory based on input from the user.
Run-time Flexibility: Users specify what type of graphic object they want at runtime, and the appropriate class is instantiated.
*/

// Abstract base class
class Graphic {
public:
    virtual Graphic* clone() const = 0;
    virtual void draw() const = 0;
    virtual ~Graphic() { std::cout << "Graphic: Destroying a Graphic object.\n"; }
};

// Concrete class 1
class Note : public Graphic {
public:
    Note() {
        std::cout << "Note: Creating a Note object.\n";
    }
    Note(const Note&) {
        std::cout << "Note: Cloning a Note object.\n";
    }
    Graphic* clone() const override {
        return new Note(*this);
    }
    void draw() const override {
        std::cout << "Note: Drawing a musical note.\n";
    }
};

// Concrete class 2
class Rest : public Graphic {
public:
    Rest() {
        std::cout << "Rest: Creating a Rest object.\n";
    }
    Rest(const Rest&) {
        std::cout << "Rest: Cloning a Rest object.\n";
    }
    Graphic* clone() const override {
        return new Rest(*this);
    }
    void draw() const override {
        std::cout << "Rest: Drawing a musical rest.\n";
    }
};

// GraphicTool class that uses a prototype to create new objects
class GraphicTool {
    Graphic* prototype;
public:
    GraphicTool(Graphic* proto) : prototype(proto) {
        std::cout << "GraphicTool: GraphicTool created with a prototype.\n";
    }
    ~GraphicTool() {
        std::cout << "GraphicTool: GraphicTool being destroyed, deleting prototype.\n";
        delete prototype;
    }

    Graphic* createGraphic() const {
        std::cout << "GraphicTool: Creating a graphic using the prototype.\n";
        return prototype->clone();
    }
};

// Factory for creating Graphics by type name
Graphic* createGraphicByName(const std::string& type) {
    if (type == "Note") {
        return new Note();
    } else if (type == "createGraphicByName: Rest") {
        return new Rest();
    }
    return nullptr;
}

int main() {

    Graphic* proto = new Note();  // Step 1: Create prototype
    Graphic* newGraphic = proto->clone();  // Step 2: Clone prototype

    newGraphic->draw();  // Step 3: Use the new object

    delete proto;        // Clean up memory
    delete newGraphic;   // Clean up memory


    // std::string inputType;
    // inputType = "Note";
    // // std::cout << "Enter graphic type ('Note' or 'Rest'): ";
    // // std::cin >> inputType;

    // // A prototype object is created based on user input
    // // This is done by allocating a prototype object based on the user's choice at runtime
    // Graphic* proto = createGraphicByName(inputType);
    // std::cout << "Address of proto: " << proto << "\n";
    // if (!proto) {
    //     std::cout << "Invalid graphic type!\n";
    //     return 1;
    // }

    // // Then a GraphicTool is created with the prototype
    // // The prototype object is then passed to the GraphicTool.
    // // This usually involves storing a pointer to the prototype object within the GraphicTool.\
    // // At this point, the tool just holds a reference (pointer) to the already allocated prototype object; no new memory for the prototype is allocated here.
    // GraphicTool tool(proto);
    // std::cout << "Address of proto: " << proto << "\n";
    // Graphic* myGraphic = tool.createGraphic();
    // std::cout << "Address of myGraphic: " << myGraphic << "\n";
    // myGraphic->draw();
    // delete myGraphic;

    return 0;
}

/*

1. Enter graphic type ('Note' or 'Rest'): Note
The program prompts for input and you chose "Note". This is your runtime decision influencing the prototype.
`
A Note object is instantiated as the prototype for the GraphicTool. This happens when you call createGraphicByName("Note") and it constructs a new Note.
3. GraphicTool created with a prototype.
A GraphicTool object is initialized with the Note prototype you just created. This sets up the tool for future cloning operations.
4. Creating a graphic using the prototype.
Indicates that the createGraphic() method of GraphicTool has been invoked to create a new graphic.
5. Cloning a Note object.
Shows that the clone() method of the Note prototype is called, demonstrating the Prototype pattern in action. This is the actual cloning process where a new Note object is created as a copy of the prototype.
6. Drawing a musical note.
The newly cloned Note object’s draw() method is called, confirming that the cloned object behaves as expected.
7. Destroying a Graphic object.
The first instance of this message indicates that the cloned Note object is being destroyed, likely at the end of the main() function where it goes out of scope and is deleted.
8. GraphicTool being destroyed, deleting prototype.
The GraphicTool itself is being destroyed as the program exits, signaling that it’s cleaning up its resources, specifically the prototype object it was holding.
9. Destroying a Graphic object.
The second instance of this message confirms that the original prototype Note object is destroyed as part of the GraphicTool destruction process.

Cloning vs. Creating: The core of the Prototype pattern—using a clone of a prototype instead of direct construction (using new with a constructor)—is clearly demonstrated. This confirms that new Note objects are created via cloning, not by direct instantiation during the createGraphic() call.
Resource Management: Proper construction and destruction messages confirm that resources are managed correctly without leaks, as every new is paired with a corresponding delete.
*/
