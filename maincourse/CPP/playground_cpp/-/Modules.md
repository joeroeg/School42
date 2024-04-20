## Module 04
The exercises in Module 04 of your C++ course are designed to deepen your understanding of several advanced concepts in object-oriented programming (OOP). Here's a breakdown of what each exercise aims to teach and why these are valuable skills:

### Exercise 00: Polymorphism
- **Purpose:** Learn how to use subtype polymorphism effectively. This is a fundamental OOP concept where a base class reference is used to refer to an object of any derived class. This allows for flexible and reusable code.
- **Skills Gained:**
  - **Implementing Inheritance:** Understanding how classes can inherit properties and behaviors from a base class.
  - **Method Overriding:** Modifying how derived classes perform specific actions differently than the base class.
  - **Dynamic Binding:** Seeing polymorphism in action as the program decides which method to invoke at runtime based on the object's class.

### Exercise 01: I Don't Want to Set the World on Fire
- **Purpose:** Understand complex object composition and memory management, which are critical when dealing with dynamic memory allocation in C++.
- **Skills Gained:**
  - **Memory Management:** Learn to manage memory manually to avoid leaks, a common issue in languages like C++ that don't have automatic garbage collection.
  - **Deep Copying:** Ensure that copies of objects correctly duplicate all resources, not just pointers, to prevent data corruption and runtime errors.
  - **Composition Over Inheritance:** This exercise also subtly introduces the benefits of composition—having objects as members of other objects—over inheritance.

### Exercise 02: Abstract Class
- **Purpose:** Grasp the concept of abstract classes, which are used to define interfaces in C++ that cannot be instantiated but can be subclassed by other classes.
- **Skills Gained:**
  - **Designing Abstract Classes:** Learn to design classes that outline methods but leave the implementation to derived classes.
  - **Preventing Instantiation:** Understand how to make a class abstract to ensure that only meaningful instances of subclasses are created, which is a critical design principle.

### Exercise 03: Interface & Recap
- **Purpose:** While C++ does not have interfaces like some other languages (e.g., Java), this exercise teaches you to simulate them using abstract classes. This helps in designing highly decoupled and testable code.
- **Skills Gained:**
  - **Implementing Interfaces:** Learn to define and use interfaces through abstract classes to ensure that different classes conform to a particular contract.
  - **Polymorphism and Interface Design:** Deepen your understanding of polymorphism through interface design, improving your ability to manage and use objects interchangeably through their common interface.
