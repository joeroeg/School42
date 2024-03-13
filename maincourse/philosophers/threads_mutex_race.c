#include <pthread.h>
#include <stdio.h>

int counter = 0;
pthread_mutex_t lock;

/*
2 threads with mutex
	Final counter value: 200000000
	./a.out  6.44s user 7.36s system 163% cpu 8.423 total

	Two Threads with Mutex: The most concurrent version, with two threads sharing the workload.
	The system CPU utilization (>100%) indicates parallel execution across CPU cores.
	However, the mutex significantly increases execution time due to the overhead of locking and unlocking, plus the contention between threads.

2 threads no mutex
	Final counter value: 103087166
	./a.out  0.74s user 0.00s system 191% cpu 0.389 total
	This is an example of race condition resulting from concurrent access to a shared resource without proper synchronization.
	The key takeaway from this scenario is that while the absence of mutexes significantly improves execution time, making it nearly as fast as the single-threaded case without mutexes, it leads to incorrect results due to concurrent modifications of the shared counter variable by both threads.

1 thread with mutex
	Final counter value: 200000000
	./a.out  3.46s user 0.00s system 99% cpu 3.463 total

	One Thread with Mutex: Removes the parallel execution, reducing CPU utilization to ~100%, indicating that now only one core is fully utilized.
	The execution time decreases compared to two threads because there's no contention, but mutex overhead remains.

1 thread with not mutex
	Final counter value: 200000000
	./a.out  0.32s user 0.00s system 98% cpu 0.325 total
	One Thread without Mutex: Demonstrates the overhead introduced by mutexes.
	Without the need for synchronization (since there's only one thread), execution is significantly faster, approaching the theoretical minimum time for incrementing the counter.

no threads and mutexes
	Final counter value: 200000000
	./a.out  0.32s user 0.00s system 99% cpu 0.325 total
	No Threads and Mutexes: Essentially a single-threaded program without any synchronization overhead, serving as a control scenario.
	It matches the performance of a single thread without mutexes, confirming that the primary cost in the multithreaded scenarios is due to synchronization.

Key Takeaways:
	Mutex Overhead: Even in single-threaded contexts, mutexes introduce non-negligible overhead. In multithreaded scenarios, this overhead is exacerbated by contention, where threads compete for locks.
	Concurrency vs. Parallelism: These results clearly differentiate between concurrency (multiple threads making progress) and parallelism (multiple threads executing simultaneously). While parallelism can speed up processing, its benefits can be negated by synchronization costs.
	Optimization Strategies: For optimal performance, minimize locking and unlocking operations, especially in tight loops. Consider finer-grained locking, lock-free programming techniques, or redesigning the algorithm to reduce the need for shared mutable state.

*/

void* countToABillion(void* arg) {
    for(int i = 0; i < 100000000; ++i) {
        // pthread_mutex_lock(&lock); // Locking the mutex
        counter++;
        // pthread_mutex_unlock(&lock); // Unlocking the mutex
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL); // Initializing the mutex

    pthread_create(&thread1, NULL, countToABillion, NULL);
    pthread_create(&thread2, NULL, countToABillion, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final counter value: %d\n", counter);
    pthread_mutex_destroy(&lock); // Destroying the mutex

    return 0;
}
