# 42 Cursus Projects Portfolio

## Table of Contents

- [42 Cursus Projects Portfolio](#42-cursus-projects-portfolio)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [**Projects**](#projects)
    - [Specialization Projects](#specialization-projects)
    - [Core Projects](#core-projects)
    - [Network Projects](#network-projects)
    - [Graphics Projects](#graphics-projects)
    - [C++ Projects](#c-projects)
  - [How to explore](#how-to-explore)
  - [Prerequisites](#prerequisites)
****
## Introduction
This repository showcases my completed or ongoing projects during the 42 cursus. Each project is organized in its own subdirectory, containing the source code, relevant documentation, and a brief description.

## **Projects**

### Specialization Projects
| Project Name | Description | Language |
| --------------- | ------------------------------------------------- | ---------------- |
| ft_linear_regression | Implement a program to predict car prices using a linear regression model. Train the model with a gradient descent algorithm to minimize the cost function. This project introduces fundamental machine learning concepts, focusing on linear regression, gradient descent, and model evaluation. | Python
|Datascience X Logistic Regression (DSLR) | Explore basic data science and machine learning principles by implementing a logistic regression model for binary classification. Emphasize data exploration and preprocessing before applying the model. Develop a custom machine learning toolkit to handle tasks such as data visualization, normalization, and model evaluation.| Python
Multilayer Perceptron |  Implement a multilayer perceptron (MLP), an artificial neural network, from scratch. Focus on the backpropagation algorithm, manipulating derivatives and linear algebra for training the network. Gain a deeper understanding of neural network architectures, activation functions, and gradient-based optimization methods. | Python
Total perspective vortex | Process EEG data from motor imagery experiments using machine learning algorithms. Implement dimensionality reduction techniques to transform the filtered data before classification. Integrate your algorithm within the scikit-learn framework for classification and validation, using libraries like MNE for EEG data processing. | Python
Leaffliction |  Tackle computer vision tasks by acquiring, processing, and analyzing digital images to extract meaningful information. Focus on transforming visual images into symbolic representations using geometry, physics, statistics, and learning theory. Implement image processing and computer vision algorithms to understand and interpret image data. | Python

### Core Projects

| Project Name    | Description                                       | Language         |
| --------------- | ------------------------------------------------- | ---------------- |
| [libft](./maincourse/libft)           | Creation of a custom C library, replicating standard library functions for deeper understanding. It's one of the first significant projects, Libft requires to reimplement several standard C library functions. This project emphasizes a deep understanding of C programming and memory management. | C                |
| ft_printf       | Implementation of the printf function in C, focusing on variadic functions and formatted output. In this project, you have to recreate the printf function, which involves parsing variadic arguments and formatted output. It's a substantial exercise in string manipulation and handling various data types. | C                |
| get_next_line   | Developing a function to read lines from a file descriptor, managing static variables and buffers. This project involves writing a function that reads a line from a file descriptor, a common task in systems programming. It tests ability to handle dynamic memory and file I/O in C. | C                |
| pipex           | Implementing a pipeline of processes, managing input/output redirection and process chaining. This project requires students to create a program that mimics the behavior of shell pipe commands. It involves using fork to create child processes, pipe to set up communication between these processes, and managing input/output redirection with file descriptors. The main challenge is correctly chaining multiple processes and handling all edge cases related to process synchronization and communication. This project provides deep insight into inter-process communication (IPC) and Unix process management. | C                |
| push_swap       | Develop an efficient algorithm to sort a stack of integers. The goal is to minimize the number of operations. This project demands proficiency in stack data structures, sorting algorithms (like quicksort, mergesort), and optimization techniques. | C                |
| philosophers    | Solve the Dining Philosophers problem using pthreads to manage concurrency. Implement mutexes to prevent deadlock and race conditions. The project teaches thread creation (pthread_create()), synchronization (pthread_mutex_lock()), and proper handling of shared resources. | C                |
| minishell       | Build a basic Unix shell to handle command parsing, execution, and input/output redirection. This project covers process creation, management, and inter-process communication. | C                |

### Network Projects

| Project Name   | Description                                       | Language         |
| --------------- | ------------------------------------------------- | ---------------- |
| IRC             |  Implement an IRC server that handles client connections using sockets (socket(), bind(), listen(), accept()). Manage real-time communication with select/poll for handling multiple clients. Understand and implement the IRC protocol for message formatting and routing. | C++              |
| net_practice    |  Complete exercises on setting up TCP/UDP connections, handling packet transmission, and implementing basic network services. It involves low-level socket programming, understanding of OSI model layers, and using tools like netcat and wireshark for debugging. |                |

### Graphics Projects

| Project Name   | Description                                       | Language         |
| --------------- | ------------------------------------------------- | ---------------- |
| cub3d           | Create a 3D game engine using ray-casting to render a scene from a 2D map. Implement the DDA (Digital Differential Analyzer) algorithm for ray traversal. Handle texture mapping, sprite rendering, and basic physics for player movement.  | C                |
| fractol         | Visualize fractals like the Mandelbrot and Julia sets. Implement complex number arithmetic and iterative algorithms to generate fractal images. Optimize rendering using multi-threading and explore color gradients for visual effects. | C                |

### C++ Projects

| Project Name  | Description | Language |
|---------------|-------------|----------|
| **Module 00** | In this module, I started my journey with C++, gaining a solid understanding of the basics. I covered the fundamentals such as syntax, data types, and control structures. This module was essential in learning how to declare variables, use loops, and implement conditional statements. Additionally, I explored the compilation process and basic I/O operations, which laid the foundation for more advanced concepts. | C++ |
| **Module 01** | Here, I delved into dynamic memory allocation, learning how to effectively use `new` and `delete` for managing memory in C++. I also worked with pointers and references, which are crucial for handling resources efficiently. This module introduced me to file I/O streams (`ifstream`, `ofstream`) and the RAII (Resource Acquisition Is Initialization) principle, helping me understand how to manage resources and prevent memory leaks. | C++ |
| **Module 02** | This module focused on ad-hoc polymorphism through function and operator overloading. I implemented canonical form classes, ensuring that my classes had proper constructors, destructors, copy constructors, and assignment operators. The experience helped me understand encapsulation, data hiding, and the importance of maintaining class invariants in object-oriented programming. | C++ |
| **Module 05** | In this module, I tackled exception handling in C++, learning to write robust code using `try`, `catch`, and `throw` statements. I gained experience with standard exceptions and even created custom exception classes. Additionally, I explored the powerful features of the Standard Template Library (STL), working with containers like `vector` and `map`, and utilizing algorithms such as `sort` and `find` to handle data efficiently. | C++ |
| **Module 06** | This module introduced me to type casting in C++, covering `static_cast`, `dynamic_cast`, `const_cast`, and `reinterpret_cast`. I learned to identify the appropriate casting method for different scenarios, while understanding the safety and potential pitfalls of each. I also explored Run-Time Type Information (RTTI) and its practical applications in dynamic type checking and safe downcasting. | C++ |
| **Module 07** | In this module, I mastered templates in C++, focusing on both function templates and class templates. I learned how to write generic code that can work with any data type, significantly enhancing the flexibility and reusability of my code. The module also covered template specialization and the nuances of the `typename` and `template` keywords, deepening my understanding of C++'s type system. | C++ |
| **Module 08** | This module allowed me to explore advanced C++ concepts, specifically templated containers, iterators, and algorithms using the STL. I implemented three key exercises: <br> **EasyFind:** I created a templated function that locates an integer within a container, enhancing my understanding of STL containers. <br> **Span:** I developed a class to store a collection of integers and calculate the shortest and longest spans between them, emphasizing efficient data handling and iterator usage for batch operations. <br> **MutantStack:** I extended `std::stack` to create an iterable stack, blending stack functionality with container properties, which was a great exercise in working with advanced STL features. | C++ |
| **Module 09** | In this final module, I focused on applying the STL to solve complex problems in C++98. I implemented three challenging exercises: <br> **Bitcoin Exchange:** I built a program that calculates the value of Bitcoin on specific dates using a historical price database, demonstrating my ability to handle data efficiently and manage errors using STL containers. <br> **Reverse Polish Notation (RPN):** I developed an RPN calculator that evaluates expressions with basic arithmetic operations, showcasing my skills in stack management and algorithmic parsing. <br> **PmergeMe:** I implemented the Ford-Johnson merge-insert sort algorithm, comparing its performance across different STL containers, which involved efficiently sorting large data sets and understanding the intricacies of this advanced sorting technique. | C++ |


## How to explore

1. Navigate into each project's subdirectory inside maincourse directory.
2. Read the project-specific README for detailed instructions, project goals, and challenges overcome.

## Prerequisites

- **C Compiler**: GCC or Clang
- **C++ Compiler**: GCC or Clang
- **Make**: For building projects
- **Git**: For version control
