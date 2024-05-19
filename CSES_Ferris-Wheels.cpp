#include <iostream> 
#include <algorithm> 
int n, x; 
int a[200005]; 

int main () {
  std::cin >> n >> x; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  std::sort(a + 1, a + n + 1); 
  int l = 1, r = n; 
  int ans = 0; 
  while (l <= r) {
    ans++; 
    if (a[l] + a[r] <= x) {
      l++; 
    }
    r--; 
  }
  std::cout << ans;
  return 0; 
}