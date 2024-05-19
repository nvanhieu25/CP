#include <iostream>
#include <stack> 
#include <math.h> 
std::stack <int> st;
int n; 
int a[200005]; 
int prePos[200005], sufPos[200005]; 
 
int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  st.push(0); 
  for (int i = 1; i <= n; i++) {
    while (a[st.top()] >= a[i]) {
      st.pop(); 
    }    
    prePos[i] = st.top(); 
    st.push(i); 
  }
  while (!st.empty()) {
    st.pop(); 
  }
  st.push(n + 1);
  for (int i = n; i >= 1; i--) {
    while (a[st.top()] >= a[i]) {
      st.pop(); 
    }
    sufPos[i] = st.top(); 
    st.push(i);  
  }
  long long ans = -1; 
  for (int i = 1; i <= n; i++) {
    ans = std::max(ans, 1LL * a[i] * (sufPos[i] - prePos[i] - 1)); 
  }
  std::cout << ans; 
  return 0;
}