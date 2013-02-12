#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include <iostream>
using namespace std;

void func() {
  boost::posix_time::seconds time(3);
  cout << "worker: running" << endl;
  boost::this_thread::sleep(time);
  cout << "worker: finished" << endl;
}

int main() {
  cout << "main: startup" << endl;
  boost::thread worker(func);
  cout << "main: waiting" << endl;
  worker.join();
  cout << "main: done" << endl;
  return 0;
}
