- functions inside classes called methods
- we can assign a reference only during declaration.
- It's a good idea to visually separate different variables in your class.
    public could use camelcase
    private could use underscore m_Variable and
    regular variables with no formatting
- a static member variable of a class is shared across all instances of that class.
    It exists independently of any class objects you might create, which means there's only one copy of that variable, no matter how many objects of the class exist. This makes static variables ideal for storing class-wide information — data that is shared by all objects of the class.
- rule of Three/Five/Zero:
    Rule of Three (C++03 and earlier): If you define a custom constructor, copy constructor, or destructor, you should likely explicitly define all three to ensure correct copy semantics and resource management.

    Rule of Five (C++11 and later): Includes the previous three plus the move constructor and move assignment operator. If your class manages resources that require deep copying or has unique ownership semantics, you should define these five special member functions to handle copies and moves safely and efficiently.

    Rule of Zero: Suggests that classes should not manage resources directly but use existing classes that handle resource management, like smart pointers (std::unique_ptr, std::shared_ptr). Following this rule, you often don't need to define any special member functions explicitly.

## Constructor
Using constructors in C++ is not obligatory, but they are highly recommended for initializing objects in a clean, predictable way. Here's how to use them correctly along with best practices:

### When and How to Use Constructors
- **Declaration and Initialization**: A constructor in C++ is declared within a class and does not have a return type. It can be used to initialize the class's attributes, set up necessary resources, or perform any startup procedures required by the object.

  ```cpp
  class Contact {
  public:
      Contact(std::string fName, std::string lName); // Constructor declaration
  };

  Contact::Contact(std::string fName, std::string lName)
      : firstName(fName), lastName(lName) {} // Constructor initialization using an initializer list
  ```

### Best Practices
- **Use Initializer Lists**: Prefer initializing members through initializer lists rather than assignment within the constructor body. This is more efficient as it avoids an extra copy operation for non-primitive types.

  ```cpp
  class Example {
  private:
      std::string name;
      int value;
  public:
      Example(std::string n, int v) : name(n), value(v) {}
  };
  ```

- **Default Constructors**: If your class has members that will be initialized to a consistent or default state and no resources need dynamic allocation, define a default constructor.

  ```cpp
  class Example {
  private:
      std::string name;
      int value;
  public:
      Example() : name("Default"), value(0) {}
  };
  ```

- **Explicit Constructors**: For constructors that take a single argument, consider using the `explicit` keyword to prevent automatic type conversions, which can lead to unexpected bugs.

  ```cpp
  class Example {
  public:
      explicit Example(int val) : value(val) {}
  };
  ```

- **Delegating Constructors**: Use delegating constructors to reduce code duplication across multiple constructors that perform similar initializations.

  ```cpp
  class Example {
  private:
      int x, y;
  public:
      Example() : Example(0, 0) {}  // Delegates to main constructor
      Example(int val) : Example(val, val) {}
      Example(int x, int y) : x(x), y(y) {}
  };
  ```

### What Can Be Omitted?
- **Constructors Are Optional**: If a class has no specific initialization needs and holds only fundamental data types or objects that manage their own initialization, you might not need to explicitly define a constructor.
- **Avoiding Constructors for PODs**: Plain Old Data (POD) types that don’t require any special initialization logic or resource management can sometimes do without custom constructors, relying instead on default initialization.

Constructors are a fundamental part of C++ that provide control over how objects are initialized and managed. Proper use of constructors can greatly enhance the reliability and performance of your applications.

## Destructor
- typically you don't call destructor function. It's called automatically when the program leave the scope.


## Inheritance
- inheritance is the key featury of C++ as this allows us to avoid duplications.
- class Player : Entity

## Virtual functions
- Virtual functions let us override methdods in subclasses
- Virtual functions use dynamic dispatch utilizing v-table to keep track of.
- if you want to override a function you have to mark the base function in the base class as virtual.
- in C++11 you could mark your overdiden function with a keyword override.
- virtual function could be costly but in most cases it's negligible only if you have limited resources.

## Pure virtual functions (Interface)
- a pure virtual function allows us to define a function in a base class that does not have an implementation and then for subclasses to actually implement that function.
- quite common is to create a class that consists only of unimplemented methods and then force a subclass to actually implement them.

## Visibility
- There are only 3  private, protected and public
- Public means anyone could access these entities.
- Private - only the class where private members were declared could be accessed
- Protected means that the base class and all subclasses could access protected entities

## Arrays
- A lot of stuff that I know but also some stuff that i need to rewatch

## Strings
- when we use a pointer *string it's readonly memory when we use an array string[ ] it's read/write
-





## Q
I didn't understand:
- What is virtual function?
- What is purely virtual?
- How to use static
- How to find a size of a heap allocated array?



- How to define a header?
-
