#include<bits/stdc++.h>

using namespace std;

int mex = 0;
int cnt[400005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q, x;
	cin >> q >> x;
	for(int i = 1; i <= q; i++){
		int v;
		cin >> v;
		cnt[v % x]++;
		while(true){
			if(cnt[mex % x] > 0){
				cnt[mex % x]--;
				mex++;
			}
			else break;
		}
		cout << mex << "\n";
	}
	return 0;
}