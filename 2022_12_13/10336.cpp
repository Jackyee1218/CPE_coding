#include <bits/stdc++.h>
using namespace std;

int n, m;

struct T{
	char c;
	int cnt;
};

bool operator<(const T& a, const T& b) {
	if(a.cnt > b.cnt) return true;
	if(a.cnt == b.cnt) return a.c < b.c;
	return false;
}


void bfs(int i, int j, vector<vector<bool> >& v, const vector<vector<char> >& mp) {
	v[i][j] = true;
	if(mp[i-1][j] == mp[i][j] && !v[i-1][j]) bfs(i-1, j, v, mp);
	if(mp[i+1][j] == mp[i][j] && !v[i+1][j]) bfs(i+1, j, v, mp);
	if(mp[i][j-1] == mp[i][j] && !v[i][j-1]) bfs(i, j-1, v, mp);
	if(mp[i][j+1] == mp[i][j] && !v[i][j+1]) bfs(i, j+1, v, mp);
}

int main() {
	int t;
	cin >> t;
	for(int k = 1; k <= t; k++) {
		
		cin >> n >> m;
		
		vector<int> ans(26, 0);
		vector<T> output;
		vector<vector<char> > mp(n+2, vector<char>(m+2, 0));
		vector<vector<bool> > v(n+2, vector<bool>(m+2, false));
		
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= m; j++)
				cin >> mp[i][j];
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(!v[i][j]) {
					ans[mp[i][j]-'a']++;
					bfs(i, j, v, mp);
				}
			}
		}
		
		for(int i = 0; i < 26; i++) {
			if(ans[i]) output.push_back((T){(char)((int)'a'+i), ans[i]});
		}
		sort(output.begin(), output.end());
		cout << "World #" << k << endl;
		for(int i = 0; i < output.size(); i++) {
			cout << output[i].c << ": " << output[i].cnt << endl;
		}
		
	}
} 
