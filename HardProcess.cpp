#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int a[n+5];
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int l = 1;
	int cntZeroes = 0;
	int ans = -1;
	int left = -1, right = -1;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			cntZeroes++;
		}
		while(cntZeroes > k){
			if(a[l] == 0){
				cntZeroes--;
			}
			l++;
		}
		if(ans < i - l + 1){
			ans = i - l + 1;
			left = l;
			right = i;
		}
	}
	if (left != -1 && right != -1) {
    	for (int i = left; i <= right; i++){
      		a[i] = 1; 
    	}
  	}
  	cout << ans << endl; 
  	for (int i = 1; i <= n; i++) {
    	cout << a[i] << ' ';
  	}
  	return 0; 
}