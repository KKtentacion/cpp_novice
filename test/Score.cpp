#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;
class Person {
 public:
  Person(string name, int score) {
    this->m_name  = name;
    this->m_score = score;
  }
  void Getscore() {
    cout << "The score of " << this->m_name << " is " << this->m_score << endl;
  }
  void Getname() {
    cout << this->m_name << endl;
  }
  void Changescore(int score) {
    this->m_score = score;
  }

 private:
  string m_name;
  int m_score;
};
void CreatePerson(vector<Person>& P, int const n) {
  string nameSeed = "ABCDE";
  for (int i = 0; i < 5; i++) {
    string name  = "Player";
    name        += nameSeed[i];
    int score    = 0;
    Person p(name, score);
    P.push_back(p);
  }
  cout << "Alreay created " << n << " Person" << endl;
}
void setScore(vector<Person>& P) {
  for (auto it = P.begin(); it != P.end(); it++) {
    deque<int> score;
    for (int i = 0; i < 10; i++) {
      random_device rd;
      mt19937 gen(rd());
      uniform_int_distribution<> dis(60, 100);
      int tmp_score = dis(gen);
      score.push_back(tmp_score);
    }
    sort(score.begin(), score.end());
    score.pop_back();
    score.pop_front();
    int sum_score = 0;
    for (auto it = score.begin(); it != score.end(); it++) {
      sum_score += *it;
    }
    int avg = sum_score / score.size();
    it->Changescore(avg);
  }
}
void outlineScore(vector<Person> P) {
  for (auto it = P.begin(); it != P.end(); it++) {
    it->Getscore();
  }
}
int main() {
  int const n = 5;
  vector<Person> P;
  CreatePerson(P, n);
  setScore(P);
  outlineScore(P);
  return 0;
}