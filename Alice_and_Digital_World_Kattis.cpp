#include <iostream>
#include <math.h>
int numTest;
int n, m;
int a[100005];

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    int ans = -1; 
    for (int i = 1; i <= n; i++) {
      if (a[i] == m) {
        int sum = m; 
        for (int j = i - 1; j >= 1; j--) {
          if (a[j] > m) {
            sum += a[j];
          }
          else {
            break;
          }
        }
        for (int j = i + 1; j <= n; j++) {
          if (a[j] > m) {
            sum += a[j];
          }
          else {
            break; 
          }
        }
        ans = std::max(ans, sum); 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}