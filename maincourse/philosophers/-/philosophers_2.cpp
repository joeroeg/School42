// g++ src.cpp -std=c++11 -lpthread

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <random>
#include <ctime>

using namespace std;

int myrand(int min, int max) {
  static mt19937 rnd(time(nullptr));
  return uniform_int_distribution<>(min,max)(rnd);
}

void philosopher(int ph, mutex& ma, mutex& mb, mutex& mo) {
  for (;;) {  // prevent thread from termination
    int duration = myrand(200, 800);
    {
      // Block { } limits scope of lock
      lock_guard<mutex> gmo(mo);
      cout<<ph<<" thinks "<<duration<<"ms\n";
    }
    this_thread::sleep_for(chrono::milliseconds(duration));
    {
      lock_guard<mutex> gmo(mo);
      cout<<"\t\t"<<ph<<" is hungry\n";
    }
    lock_guard<mutex> gma(ma);
    // sleep_for() Delay before seeking second fork can be added here but should not be required.
    lock_guard<mutex> gmb(mb);
    duration = myrand(200, 800);
    {
      lock_guard<mutex> gmo(mo);
      cout<<"\t\t\t\t"<<ph<<" eats "<<duration<<"ms\n";
    }
    this_thread::sleep_for(chrono::milliseconds(duration));
  }
}

int main() {
  cout<<"dining Philosophers C++11 with Resource hierarchy\n";
  mutex m1, m2, m3, m4, m5;   // 5 forks are 5 mutexes
  mutex mo;           // for proper output
  // 5 philosophers are 5 threads
  thread t1([&] {philosopher(1, m1, m2, mo);});
  // thread t2([&] {philosopher(2, m2, m3, mo);});
  // thread t3([&] {philosopher(3, m3, m4, mo);});
  // thread t4([&] {philosopher(4, m4, m5, mo);});
  // thread t5([&] {philosopher(5, m1, m5, mo);});  // Force a resource hierarchy
  t1.join();  // prevent threads from termination
  // t2.join();
  // t3.join();
  // t4.join();
  // t5.join();
}
