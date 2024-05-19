#include <iostream> 
#include <set> 
std::set <long long> myset;
long long p[200005];
int n;  

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i]; 
  }
  long long ans = 10000000000000007LL; 
  for (int i = 1; i <= n; i++) {
    std::set <long long>::iterator it = myset.upper_bound(p[i]);
    if (it != myset.end()) {
      long long lastPrice = *it;
      if (lastPrice > p[i]) {
        ans = std::min(ans, lastPrice - p[i]);   
      }
    } 
    myset.insert(p[i]);
  }
  std::cout << ans; 
  return 0; 
}