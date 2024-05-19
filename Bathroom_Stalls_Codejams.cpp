#include <iostream> 
#include <queue> 
#include <map> 
int numTest; 
long long n, k; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> k; 
    std::priority_queue <long long> pq; 
    std::map <long long, long long> cnt; 
    pq.push(n); 
    cnt[n] = 1; 
    while (!pq.empty()) {
      long long maxLength = pq.top(); 
      pq.pop(); 
      long long half1 = (maxLength - 1) / 2; 
      if (cnt.find(half1) == cnt.end()) {
        pq.push(half1); 
      }
      cnt[half1] += cnt[maxLength];
      long long half2 = maxLength - half1 - 1;
      if (cnt.find(half2) == cnt.end()) {
        pq.push(half2); 
      } 
      cnt[half2] += cnt[maxLength];
      if (k <= cnt[maxLength]) {
        std::cout << std::max(half1, half2) << ' ' << std::min(half1, half2) << std::endl; 
        break; 
      }
      else {
        k -= cnt[maxLength]; 
      }
    }
  }
  return 0; 
}