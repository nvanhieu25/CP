#include <iostream> 
#include <vector>
#include <algorithm> 
int n; 
int a[2005]; 
std::vector <int> listID[2005]; 
int result[2005]; 

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
    listID[a[i]].push_back(i); 
  }
  std::sort(a + 1, a + n + 1); 
  int higherScore = 2005; 
  int curRank = -1; 
  for (int i = n; i >= 1; i--) {
    if (higherScore != a[i]) {
      higherScore = a[i]; 
      curRank = n - i + 1; 
    }  
    int lastid = listID[a[i]].back(); 
    listID[a[i]].pop_back(); 
    result[lastid] = curRank;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << result[i] << ' '; 
  }
  return 0; 
}