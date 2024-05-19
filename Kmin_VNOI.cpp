#include <iostream> 
#include <deque> 

int numTest; 
int n, k; 
int a[17005];

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    std::deque <int> dq;
    for (int i = 1; i <= k; i++) {
      while (!dq.empty() && a[i] < dq.back()) {
        dq.pop_back();
      }
      dq.push_back(a[i]);
    }
    std::cout << dq.front() << ' '; 
    for (int i = k + 1; i <= n; i++) {
      if (dq.front() == a[i - k]) {
        dq.pop_front(); 
      }
      while (!dq.empty() && a[i] < dq.back()) {
        dq.pop_back();
      }
      dq.push_back(a[i]); 
      std::cout << dq.front() << ' ';
    }
    std::cout << std::endl; 
  }
  return 0; 
}
