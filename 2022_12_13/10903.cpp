#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	while((cin >> num) && num) {
		string ans;
		int cnt = 0;
		while(num) {
			cnt += num % 2;
			ans += '0'+(num%2); 
			num >>= 1;
		}
		reverse(ans.begin(), ans.end());
		cout << "The parity of " << ans << " is " << cnt << " (mod 2).\n";
	}
}
