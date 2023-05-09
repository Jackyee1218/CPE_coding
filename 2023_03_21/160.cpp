#include <bits/stdc++.h>
using namespace std;

bool isPrime(int);

void sol(int n) {

	printf("%3d! =", n);
	// i for finding the prime number
	for(int i = 2, num = 0; i <= n; i++) {
		if(isPrime(i)) {
			num++;
			int cnt = 0;
			// calculate the total of elements for the primen number
			for(int j = i; j <= n; j+= i) {
				int t = j;
				while(t%i == 0) {
					cnt++;
					t /= i;
				}
			}
			printf("%3d", cnt);
			if(num >= 15) {
				num = 0;
				cout << endl;
			}
		}
	}
	cout << endl;
}

bool isPrime(int n) {
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) return false;
	}
	return true;
}


int main() {
	int n;
	while((cin >> n) && n != 0) {
		sol(n);
	}
}
