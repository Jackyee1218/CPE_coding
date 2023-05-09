#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b;
	while((cin >> a >> b) && (a+b > 0)) {
		// makes a > b
		if(a < b) swap(a, b);
		
		int cnt = 0, t = 0;
		
		while(b) {
			int sa = a%10;
			int sb = b%10;
			a /= 10;
			b /= 10;
			if(sa+sb+t >= 10) {
				t = 1;
				cnt++;
			} else 
				t = 0;
		}
		while(a) {
			int sa = a%10;
			a /= 10;
			if(sa+t >= 10) {
				t = 1;
				cnt++;
			} else 
				break;
		}
		if(cnt == 0) cout << "No carry operation.\n";
		else if(cnt == 1) cout << "1 carry operation.\n";
		else cout << cnt << " carry operations.\n";
	}
} 
