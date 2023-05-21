// LIS
// status : AC 0.7s
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int k = 1; k <= t; k++) {
		
		int n, np, nq;
		cin >> n >> np >> nq;
		
		vector<int> seq, lis;
		
		// build p array
		vector<int> p(np+1);
		for(int i = 0; i < np+1; i++)
			cin >> p[i];
		
		
		// build map q  val -> index
		map<int, int> mp;
		for(int i = 0; i < nq+1; i++) {
			int tmp;
			cin >> tmp;
			mp[tmp] = i+1;
		}
		
		// build seq for doing LIS
		for(int i = 0; i < p.size(); i++) {
			if(mp[p[i]])
				seq.push_back(mp[p[i]]);
		}
		
		// doing LIS
		for(int i = 0; i < seq.size(); i++) {
			vector<int>::iterator it = upper_bound(lis.begin(), lis.end(), seq[i]);
			if(it != lis.end()) {
				*it = seq[i];
			} else {
				lis.push_back(seq[i]);
			}
		}
		cout << "Case " << k << ": " << lis.size() << endl;
	}
}




/*
TIME : n^2
status : TLE

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int k = 1; k <= t; k++) {
		
		int n, np, nq;
		cin >> n >> np >> nq;
		
		vector<int> p(np+2);
		vector<int> q(nq+2);
		vector<vector<int> > dp(2, vector<int>(nq+2, 0));
		
		for(int i = 1; i <= np+1; i++)
			cin >> p[i];
		for(int i = 1; i <= nq+1; i++)
		 	cin >> q[i];
		
		for(int i = 1; i <= np+1; i++) {
			for(int j = 1; j <= nq+1; j++) {
				if(p[i] == q[j]) {
					dp[i%2][j] = dp[(i+1)%2][j-1]+1;
				} else {
					dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1]);
				}
			}
		}
		cout << "Case " << k << ": " << dp[(np+1)%2][nq+1] << endl;
		
	}
}
*/
