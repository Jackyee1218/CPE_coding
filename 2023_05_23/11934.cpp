#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, L;
	while((cin >> a >> b >> c >> d >> L) && !(a == 0 && b == 0 && c == 0 && d == 0 && L == 0)) {
		int cnt = 0;
		for(int i = 0; i <= L; i++) {
			if((i*i*a+i*b+c)%d == 0) cnt++;
		}
		cout << cnt << endl;
	}
} 
