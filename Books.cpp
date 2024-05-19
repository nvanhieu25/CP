#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, t;
	cin >> n >> t;
	int arr[n+5];
	int l = 1, ans = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= n; i++){
		sum += arr[i];
		while(sum>t){
			sum -= arr[l];
			l += 1;
		}
		if(ans < i - l + 1){
			ans = i - l + 1;
		}
	}
	cout << ans;
	return 0;
}