#include <iostream> 
#include <string> 
#include <set> 
#include <vector>
#include <math.h> 
struct hint {
  std::string s; 
  std::vector <int> pos; 
};
int numHints; 
std::vector <hint> listHints; 
std::string ans = ""; 
int maxLength = 0; 
std::set <int> S; 

int main () {
  std::ios::sync_with_stdio(false);
  std::cin >> numHints; 
  for (int i = 1; i <= numHints; i++) {
    std::string s;
    std::cin >> s;
    std::vector <int> pos; 
    int cnt;
    std::cin >> cnt; 
    for (int j = 1; j <= cnt; j++) {
      int p;
      std::cin >> p;
      maxLength = std::max(maxLength, p + (int) s.size() - 1); 
      pos.push_back(p - 1);  
    }
    listHints.push_back((hint) {s, pos}); 
  }
  for (int i = 1; i <= maxLength; i++) {
    ans = ans + 'a';
    S.insert(i - 1);  
  }
  for (int i = 0; i < (int) listHints.size(); i++) {
    hint element = listHints[i]; 
    std::string &s = element.s; 
    std::vector <int> &pos = element.pos; 
    for (int j = 0; j < (int) pos.size(); j++) {
      int curPos = pos[j];             
      while (true) {
        std::set <int>::iterator it = S.lower_bound(curPos);
        if (it != S.end()) {
          int nextPos = *it;                                    
          if (nextPos - curPos < (int) s.size()) {
            ans[nextPos] = s[nextPos - curPos]; 
            S.erase(it); 
          }
          else {
            break;
          }
        }
        else {
          break; 
        }
      }  
    }
  }
  std::cout << ans; 
  return 0; 
}