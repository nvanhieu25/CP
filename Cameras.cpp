#include<bits/stdc++.h>

using namespace std;
int n, k, r;
int checkCam[100005];
int main(){
	cin >> n >> k >> r;
	for(int i = 1; i <= k; i++){
		int house;
		cin >> house;
		checkCam[house] = 1;
	}
	int left = 1;
	int right = r;
	int cntCameras = 0;
	for(int i = left; i <= right; i++){
		if(checkCam[i] == 1){
			cntCameras++;
		}
	} 
	int ans = 0;
	if(cntCameras < 2){
		for(int j = 1; j <= 2 - cntCameras; j++){
			for(int i = right; i >= left; i--){
				if(checkCam[i] == 0){
					checkCam[i] = 1;
					ans++;
					break;
				}
			}
		}
		cntCameras = 2;
	}
	for(int i = right + 1; i <= n; i++){
		if(checkCam[i] == 1){
			cntCameras++;
		}
		if(checkCam[left] == 1){
			cntCameras--;
		}
		left++;
		if(cntCameras < 2){
			checkCam[i] = 1;
			ans++;
			cntCameras = 2;
		}
	}
	cout << ans;
	return 0;
}