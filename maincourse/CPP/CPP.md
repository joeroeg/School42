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

## Q
- What is virtual?
- What is purely virtual?
- How to use static
