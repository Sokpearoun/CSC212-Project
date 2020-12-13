// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <ctime>

void foo(int end)
{
  unsigned long start, stop;

  start = std::clock();
  int total = 0;
  for (int i = 0; i < end; i++) {
      total += i;
  }
  end = std::clock();
  // std::cout << "Total from Thread 1: " << total << "\n";
  std::cout << "\nInside the Function Stats:\n";
  std::cout << "Start: " << start << "\nEnd: " << end << "\n";
  std::cout << "Run Time: " << 1.0 * (end - start)/CLOCKS_PER_SEC << "\n";


}

void bar(int end)
{
  unsigned long start, stop;

  start = std::clock();
  int total = 0;
  for (int i = 0; i < end; i++) {
      total += i;
  }
  end = std::clock();

  // std::cout << "Total from Thread 2: " << total << "\n";
  std::cout << "\nInside the Function Stats:\n";
  std::cout << "Start: " << start << "\nEnd: " << end << "\n";
  std::cout << "Run Time: " << 1.0 * (end - start)/CLOCKS_PER_SEC << "\n\n";
}


int main() {

  unsigned long c_start, c_end, start, stop;
  long double end = 1000 * 1000 * 1000;

  c_start = std::clock();
  std::thread first (foo, end);     // spawn new thread that calls foo()
  std::thread second (bar, end);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes
  c_end = std::clock();

  std::cout << "\nOutside the Function Stats:\n";
  std::cout << "Run Time: " << 1.0 * (c_end - c_start)/CLOCKS_PER_SEC << "\n\n";
  std::cout << "Start: " << c_start << "\nEnd: " << c_end << "\n";
  std::cout << "foo and bar completed.\n";

  std::cout << "\nWithout multithreading: " << "\n";
  start = std::clock();
  foo(end);
  bar(end);
  end = std::clock();
  std::cout << "\nOutside the Function Stats:\n";
  std::cout << "Run Time: " << 1.0 * (end - start)/CLOCKS_PER_SEC << "\n";
  std::cout << "Start: " << start << "\nEnd: " << end << "\n";

  return 0;
}