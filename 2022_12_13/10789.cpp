#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
	if(num == 1) return false;
	for(int i = 2; i <= sqrt(num); i++) {
		if(num % i == 0) return false;
	}
	return true;
}


int main() {
	int m;
	cin >> m;
	for(int k = 1; k <= m; k++) {
		string line, ans;
		cin >> line;
		sort(line.begin(), line.end());
		for(int i = 0, j; i < line.size(); i++) {
			int size = 1;
			for(j = i+1; j < line.size(); size++, j++) {
				if(line[j] != line[i]) {
					i = j-1;
					break;
				}
			}
			if(isPrime(size)) ans += line[i];
			if(j == line.size()) break;
		}
		cout << "Case " << k << ": ";
		if(ans.size()) cout << ans << endl;
		else cout << "empty\n";
	}
}
