#include <iostream> 
#include <stack> 
#include <vector> 

void solve() {
  while (true) {
    int n; 
    std::cin >> n;
    if (n == 0) {
      return; 
    }
    std::vector <int> a(n + 3, 0); 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int currentTruck = 1;
    std::stack <int> mystack;  
    for (int i = 1; i <= n; i++) {
      while (mystack.empty() == false && mystack.top() == currentTruck) {
        currentTruck++; 
        mystack.pop(); 
      }  
      if (currentTruck == a[i]) {
        currentTruck++;  
      }
      else {
        mystack.push(a[i]); 
      }
    }
    while (mystack.empty() == false && mystack.top() == currentTruck) {
      currentTruck++; 
      mystack.pop();
    }
    if (currentTruck > n) {
      std::cout << "yes" << std::endl; 
    }
    else {
      std::cout << "no" << std::endl; 
    }
  }  
}

int main () {
  solve(); 
  return 0; 
}