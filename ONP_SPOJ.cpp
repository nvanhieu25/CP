#include <iostream> 
#include <stack> 
#include <string> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string formula;
    std::cin >> formula; 
    std::stack <char> st; 
    for (int i = 0; i < (int) formula.size(); i++) {
      if ('a' <= formula[i] && formula[i] <= 'z') {
        std::cout << formula[i];
      }
      else if (formula[i] == ')') {
        std::cout << st.top(); 
        st.pop(); 
      }
      else if (formula[i] == '(') {
        continue; 
      }
      else {
        st.push(formula[i]); 
      }
    }
    std::cout << std::endl; 
  }
  return 0; 
}