#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int T;
	cin >> T;
	
	while(T--) {
		int n;
		cin >> n;
		
		int arr[n], dpmax[n], dpmin[n];
		for(int i = 0; i < n; i++) cin >> arr[i];
		memset(dpmax, 0, sizeof(dpmax));
		memset(dpmin, 0, sizeof(dpmin));
		
		int sum = 0, p = 1;
		for(int i = 1; i < n; i++) {
			if(arr[i-1] > arr[i]) {
				sum++;
				p = i+1;
				break;
			}
		}
		for(int i = p; i < n; i++) {
			if(sum % 2) {
				if(arr[i-1] < arr[i]) 
					sum++;
			} else {
				if(arr[i-1] > arr[i])
					sum++;
			}
		}
		cout << 1+sum << endl; 
		
	}
}
