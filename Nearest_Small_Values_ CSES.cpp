#include <iostream> 
#include <stack> 
int n; 
int a[200005]; 
std::stack <int> candidate; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  candidate.push(0); 
  for (int i = 1; i <= n; i++) {
    while (!candidate.empty()) {
      int position = candidate.top(); 
      if (a[position] >= a[i]) {
        candidate.pop(); 
      }
      else {
        std::cout << position << ' '; 
        break; 
      }
    }
    candidate.push(i);
  }
  return 0; 
}