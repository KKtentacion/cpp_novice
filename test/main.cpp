#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
void printSet(set<int> const& s) {
  for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}
void test() {
  set<int> s1;
  s1.insert(10);
  s1.insert(20);
  s1.insert(30);
  s1.insert(40);
  s1.insert(50);
  s1.insert(60);
  if (s1.empty()) {
    cout << "set is empty now" << endl;
  } else {
    cout << s1.size() << endl;
  }
  printSet(s1);

  set<int> s2;
  s2.insert(100);
  s2.insert(200);
  s2.insert(300);
  s2.insert(400);
  s2.insert(500);
  s2.insert(600);
  printSet(s2);

  s1.swap(s2);
  printSet(s1);
  printSet(s2);
}
int main() {
  test();
  return 0;
}