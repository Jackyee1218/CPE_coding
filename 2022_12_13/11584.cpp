#include <bits/stdc++.h>
using namespace std;

/*
加了 dp : AC 13 ms, 1.3MB
沒加 dp : AC 20 ms, 320KB
*/

string line;
bool dp[1005][1005];
int len[1005];

bool isPalidrome(int l, int r) {
	int ll = l, rr = r;
	while(l < r) {
		if(line[l] != line[r]) return false;
		l++;
		r--;
		if(dp[l][r]) return true;
	}
	dp[ll][rr] = true;
	return true;
}


int main() {
	int m;
	cin >> m;
	while(m--) {
		cin >> line;
		memset(dp, false, sizeof(dp));
		memset(len, 0x7f, sizeof(len));
		for(int i = 0; i < line.size(); i++) {
			for(int j = 0; j <= i; j++) {
				if(isPalidrome(j, i)) {
					if(len[i] > len[j-1]+1)	len[i] = len[j-1]+1;
				}
			}
		}
		cout << len[line.size()-1] << endl;
	} 
}
