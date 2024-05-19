#include <iostream>
#include <queue>
#include <math.h> 

int P, C;
std::queue <int> Q; 
int testCase = 0; 

int main () {
  while (true) {
    testCase++; 
    while (!Q.empty()) {
      Q.pop(); 
    }
    std::cin >> P >> C; 
    if (P == 0 && C == 0) {
      break; 
    }
    std::cout << "Case " << testCase << ":" << std::endl; 
    for (int i = 1; i <= std::min(P, C); i++) {
      Q.push(i);
    }
    for (int command = 1; command <= C; command++) {
      char type;
      std::cin >> type;
      if (type == 'N') {
        int firstPerson = Q.front();
        std::cout << firstPerson << std::endl;
        Q.pop();
        Q.push(firstPerson); 
      }
      else {
        int priorityPerson;
        std::cin >> priorityPerson;
        std::queue <int> Q1; 
        while (!Q.empty()) {
          Q1.push(Q.front()); 
          Q.pop(); 
        }
        Q.push(priorityPerson);
        while (!Q1.empty()) {
          int person = Q1.front();
          Q1.pop();
          if (person != priorityPerson) {
            Q.push(person); 
          }
        }
      }
    }
  }
  return 0; 
}