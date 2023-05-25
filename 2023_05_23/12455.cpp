#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int len, n;
		cin >> len >> n;
		vector<int> num(n);
		map<int, bool> mp;
		mp[0] = true;
		for(int i = 0; i < n; i++)
			cin >> num[i];
		
		bool valid = false;
		for(int i = 0; i < n && !valid; i++) {
			for(int k = len-num[i]; k >= 0; k--) {
				if(mp[k]) mp[k+num[i]] = true;
				if(mp[len]) {
					valid = true;
					break;
				}
			}
		}
		if(mp[len]) cout << "YES\n";
		else cout << "NO\n";
	}
}
