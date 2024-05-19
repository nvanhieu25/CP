#include <iostream> 
#include <vector>
#include <functional>
#include <queue> 

int main () {
  while (true) {
    int n;
    std::cin >> n; 
    if (n == 0) {
      break; 
    }
    std::priority_queue <int, std::vector <int>, std::greater <int> > pq; 
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x; 
      pq.push(x); 
    }
    long long ans = 0; 
    while ((int) pq.size() > 1) {
      int top1 = pq.top();
      pq.pop();
      int top2 = pq.top();
      pq.pop(); 
      ans += top1 + top2; 
      pq.push(top1 + top2); 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}