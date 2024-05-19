#include <iostream> 
#include <queue>
#include <vector>
#include <functional> 

int main () {
  int numQuery;
  std::cin >> numQuery; 
  std::priority_queue <int, std::vector <int>, std::greater <int> > pq, pq2; 
  for (int query = 1; query <= numQuery; query++) {
    int type; 
    std::cin >> type; 
    if (type == 1) {
      int value;
      std::cin >> value; 
      pq.push(value); 
    }
    else if (type == 2) {
      int value;
      std::cin >> value; 
      pq2.push(value); 
    }
    else {
      while (!pq2.empty() && pq2.top() == pq.top()) {
        pq.pop();
        pq2.pop(); 
      }
      std::cout << pq.top() << std::endl; 
    }
  }
  return 0; 
}