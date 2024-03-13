# Dining Philosophers Problem

## Introduction
This project simulates the classic **Dining Philosophers Problem** using threads and mutexes to manage philosopher actions and their access to resources (forks). The goal is to implement a system where philosophers alternate between eating, thinking, and sleeping without encountering deadlocks or starving any philosopher.

## Global Rules
- Global variables are forbidden!
- Your(s) program(s) should take the following arguments:
`number_of_philosophers`
`time_to_die`
`time_to_eat`
`time_to_sleep`
`number_of_times_each_philosopher_must_eat`

---
- `number_of_philosophers`: The number of philosophers and also the number of forks.
- `time_to_die` (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the  simulation, they die.
- `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
- `time_to_sleep` (in milliseconds): The time a philosopher will spend sleeping.
- `number_of_times_each_philosopher_must_eat` (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the  simulation stops. If not specified, the simulation stops when a philosopher dies.

### Program Arguments
Your program, named `philo`, must accept the following arguments:

1. `number_of_philosophers`: The number of philosophers and also the number of forks.
2. `time_to_die` (milliseconds): Maximum time a philosopher can spend without eating before dying.
3. `time_to_eat` (milliseconds): Time a philosopher spends eating. Requires holding two forks.
4. `time_to_sleep` (milliseconds): Time a philosopher spends sleeping.
5. `number_of_times_each_philosopher_must_eat` (optional): Simulation stops if all philosophers eat at least this many times. Otherwise, it stops when a philosopher dies.

### Philosophers and Forks

- Each philosopher is assigned a unique number from 1 to `number_of_philosophers`.
- Philosopher 1 sits next to philosopher `number_of_philosophers`. Each other philosopher, N, sits between N-1 and N+1.
- There is one fork between each pair of philosophers. Each philosopher has a fork on their left and right side, except in the case of a single philosopher, who has only one fork.

### State Changes and Output Format

State changes of a philosopher must be formatted and displayed as follows:

- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

Replace `timestamp_in_ms` with the current timestamp in milliseconds and `X` with the philosopher number.

### Additional Requirements

- State change messages must not overlap with each other.
- A death announcement must occur no more than 10 ms after a philosopher's death.
- The program must be free of data races.
- Implement each philosopher as a separate thread.

## Implementation Details

- **Program Name:** `philo`
- **Turn-in Files:** `Makefile`, `*.h`, `*.c`, in directory `philo/`
- **Makefile Targets:** `NAME`, `all`, `clean`, `fclean`, `re`
- **Arguments:** `number_of_philosophers`, `time_to_die`, `time_to_eat`, `time_to_sleep`, `[number_of_times_each_philosopher_must_eat]`
- **External Functions:**
`memset`
`printf`
`malloc`
`free`
`write`
`usleep`
`gettimeofday`
`pthread_create`
`pthread_detach`
`pthread_join`
`pthread_mutex_init`
`pthread_mutex_destroy`
`pthread_mutex_lock`
`pthread_mutex_unlock`

- **Libft Authorized:** No
- **Description:** Implement the Dining Philosophers problem using threads and mutexes.

### Time Management

- **`usleep`**: Suspends execution of the calling thread for (at least) a specified number of microseconds.
- **`gettimeofday`**: Gets the current time, as well as the time elapsed since the Epoch. Useful for measuring time intervals.

### Thread Management

- **`pthread_create`**: Creates a new thread, starting with execution of a specified function. Returns 0 on success.

- **`pthread_detach`**: Marks a thread for detachment. Once a detached thread terminates, its resources are automatically released back to the system.

- **`pthread_join`**: is a function used in POSIX threads programming, which allows one thread to wait for the completion of another thread. When you're dealing with multiple threads in a program, pthread_join helps you synchronize the termination of these threads.

`int pthread_join(pthread_t thread, void **retval);`
- `pthread_t thread`: This is the identifier of the thread you're waiting on.

- `void **retval`: This is a pointer to a pointer where the exit status of the joined thread will be stored. If the thread was set up to return a value upon exit, retval points to that value once pthread_join completes. If you're not interested in the return value, you can just pass NULL.


### Mutex Operations

- **`pthread_mutex_init`**: Initializes a mutex, optionally specifying attributes. If attributes are NULL, default mutex attributes are used.
- **`pthread_mutex_destroy`**: Destroys a mutex, freeing its resources. A mutex must be unlocked before it can be destroyed.
- **`pthread_mutex_lock`**: Acquires a lock on a mutex. If the mutex is already locked, the calling thread is blocked until the mutex becomes available.
- **`pthread_mutex_unlock`**: Releases a lock on a mutex. If other threads are blocked waiting for this mutex, one of them becomes unblocked.


## Key Concepts for the Dining Philosophers Project

### Overview

The Dining Philosophers problem is a classic synchronization issue in computer science, illustrating the challenges of allocating limited resources (forks) among processes (philosophers) to avoid deadlocks and ensure fair resource usage. Understanding the following key concepts is crucial for solving the problem effectively.

### Threads

- **Definition**: Threads are the smallest sequence of programmed instructions that can be managed independently by a scheduler. In the context of this project, each philosopher is represented as a thread.
- **Importance**: Using threads allows simultaneous operations, mimicking real-life scenarios where philosophers can eat, think, or sleep at the same time.

### Mutexes (Mutual Exclusion Objects)

- **Definition**: A mutex is a synchronization primitive that grants exclusive access to a resource or critical section to only one thread at a time.
- **Importance**: Mutexes prevent data races and ensure that no two philosophers can use the same fork simultaneously.

### Synchronization

- **Definition**: Synchronization involves coordinating the execution of threads to ensure a predictable execution order or to prevent race conditions.
- **Importance**: Proper synchronization is essential for avoiding deadlocks and ensuring that all philosophers get a chance to eat without starving.

### Deadlocks

- **Definition**: A deadlock occurs when a set of processes are blocked because each process is holding a resource and waiting for another resource acquired by some other process.
- **Importance**: Understanding deadlocks is crucial for this project as it directly relates to the problem of philosophers waiting indefinitely for forks.

### Avoiding Deadlocks

- **Resource Hierarchy Solution**: Assign an order to resources (forks) and require that each philosopher picks up the forks in a specific global order (e.g., always pick up the lower-numbered fork first).
- **Philosopher States**: Implementing different states (thinking, hungry, eating) for philosophers can help manage when they attempt to acquire forks.
- **Timeouts**: Introducing timeouts can prevent philosophers from holding onto forks indefinitely if they can't acquire both forks within a certain timeframe.

### Fairness and Avoiding Starvation

- **Definition**: Fairness ensures that each philosopher gets an equal opportunity to eat. Starvation occurs when one or more philosophers are prevented from eating indefinitely.
- **Importance**: Solutions must ensure that no philosopher starves by designing a scheduling mechanism that allows each philosopher an equal chance to eat.


## Resources

- [Dining Philosophers Problem on Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Dijkstra's Algorithm Implementation in C](https://rosettacode.org/wiki/Dijkstra%27s_algorithm#C)
- [Philosophers Visualizer](https://nafuka11.github.io/philosophers-visualizer/)

## Q&A

### What is the difference between threads and processes?
`Threads` are components of a process that can run concurrently, sharing the process's resources like memory and file descriptors. They are lightweight, have a shared memory space, and can communicate with each other more efficiently due to this shared space. However, because they share resources, they require synchronization to avoid conflicts, such as race conditions.

`Processes` are instances of programs that run independently from each other, each with its own memory space. This isolation prevents processes from directly accessing each other's resources, leading to higher stability and security but at the cost of slower communication through inter-process communication (IPC) mechanisms.


#### When use processes and when to use threads?
Use Processes when:
- `Isolation` is a priority. Since each process operates in its own memory space, the failure of one process won't directly affect the memory or resources of another process.
- `Security` concerns dictate that separate tasks must not interfere with each other's resources or memory space.
- `Stability` is crucial. The crash of one process does not affect the execution of another, maintaining system robustness.

Use Threads when:
- `Efficiency` in communication and memory usage is necessary. Threads within the same process can share memory and resources directly, making data exchange and communication faster and more resource-efficient.
- `Speed` is a concern. Creating and managing threads is faster than doing so for processes because threads share resources and the operating system does not have to allocate separate memory spaces or perform complex context switches.
- `Shared` State is required. Tasks that need to work on the same data set or maintain shared state for efficiency reasons are well-suited for threading, as threads inherently have access to the process's shared memory.

## Additional Resources

- **POSIX Threads Programming**: An excellent guide to understanding and working with pthreads, which are crucial for managing threads in your project.
  - [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)

- **Mutexes and Synchronization**: A detailed explanation of mutexes and how they are used to prevent data races and ensure synchronization between threads.
  - [Mutexes in C](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)

- **Concurrency in C++**: Even though your project is in C, understanding concurrency principles in C++ can also provide valuable insights since the concepts are broadly applicable.
  - [Concurrency in C++](https://www.cplusplus.com/reference/thread/thread/)

- **Modern Operating Systems by Andrew S. Tanenbaum**: This book provides a deep dive into operating systems' principles, including process synchronization and deadlocks, which are relevant to solving the Dining Philosophers problem.
  - [Modern Operating Systems, 4th Edition](https://www.pearson.com/store/p/modern-operating-systems/P100000648244)

- **Deadlocks and Dining Philosophers**: For a deeper understanding of deadlocks and strategies to avoid them in the context of the Dining Philosophers problem.
  - [Deadlock and Dining Philosophers](https://www.baeldung.com/cs/dining-philosophers-deadlock)

- **VisualGo - Visualization of Algorithms and Data Structures**: To better understand algorithms and data structures that might be helpful in implementing your solution, including synchronization algorithms.
  - [VisualGo](https://visualgo.net/en)

- **Operating Systems: Three Easy Pieces**: A free online book that covers essential topics in operating systems, including concurrency and synchronization.
  - [Operating Systems: Three Easy Pieces](http://pages.cs.wisc.edu/~remzi/OSTEP/)

