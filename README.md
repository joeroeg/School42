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
| libft           | Creation of a custom C library, replicating standard library functions for deeper understanding. It's one of the first significant projects, Libft requires to reimplement several standard C library functions. This project emphasizes a deep understanding of C programming and memory management. | C                |
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

| Project Name   | Description                                       | Language         |
| --------------- | ------------------------------------------------- | ---------------- |
| Module 00  |  Introduction to C++ basics, covering syntax, data types, and control structures. Learn variable declarations, loops, and conditional statements. Focus on understanding the compilation process and basic I/O operations. | C++              |
| Module 01  |  Dive into dynamic memory allocation with new and delete, pointers, and references. Learn to manage resources, avoid memory leaks, and handle file I/O streams (ifstream, ofstream). Explore RAII (Resource Acquisition Is Initialization) principle. | C++              |
| Module 02  | Understand ad-hoc polymorphism through function and operator overloading. Implement canonical form classes with proper constructors, destructors, copy constructors, and assignment operators. Explore encapsulation and data hiding. | C++              |
| Module 03  | Implement inheritance hierarchies, abstract classes, and interfaces. Study virtual functions and pure virtual functions for achieving runtime polymorphism. Understand the use of base and derived class pointers and object slicing issues. | C++              |
| Module 04  | Focus on subtyping polymorphism and OOP principles like encapsulation, inheritance, and polymorphism. Implement design patterns such as Singleton, Factory, and Observer. Use polymorphic base classes to design flexible and reusable code. | C++              |
| Module 05  |  Learn exception handling with try, catch, and throw statements. Understand standard exceptions and custom exception classes. Utilize the Standard Template Library (STL) for containers (vector, map) and algorithms (sort, find). | C++              |
| Module 06  | Introduction to type casting in C++: static_cast, dynamic_cast, const_cast, and reinterpret_cast. Understand the use cases, safety, and pitfalls of each casting method. Study RTTI (Run-Time Type Information) and its applications. | C++              |
| Module 07  |  Master templates in C++, including function templates and class templates. Implement generic functions and classes for type-independent code. Explore template specialization and the use of typename and template keywords. | C++              |
| Module 08  | Work with advanced STL features like templated containers (deque, set), iterators, and algorithms. Understand functors, lambda expressions, and their use in algorithm customization. Optimize code using efficient data structures and algorithms. | C++              |
| Module 09 | This repository contains my implementations for Module 09 of the C++ curriculum, focused on utilizing the Standard Template Library (STL). Each exercise is designed to demonstrate proficiency in managing complex data structures and algorithms using C++98. **Bitcoin Exchange:** A program that calculates the value of Bitcoin on specific dates using a historical price database. It demonstrates efficient data handling and error management using STL containers.
**Reverse Polish Notation (RPN):** An RPN calculator that evaluates expressions with basic arithmetic operations. This project showcases stack management and algorithmic parsing in C++. 
**PmergeMe:** A sorting program implementing the Ford-Johnson merge-insert sort algorithm. It compares performance across different STL containers, efficiently handling large data sets. |

## How to explore

1. Navigate into each project's subdirectory inside maincourse directory.
2. Read the project-specific README for detailed instructions, project goals, and challenges overcome.

## Prerequisites

- **C Compiler**: GCC or Clang
- **C++ Compiler**: GCC or Clang
- **Make**: For building projects
- **Git**: For version control
