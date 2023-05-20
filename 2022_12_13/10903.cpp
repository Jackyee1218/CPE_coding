#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k;
	while((cin >> n) && n) {
		cin >> k;
		int win[n+1];
		int lose[n+1];
		memset(win, 0, sizeof(win));
		memset(lose, 0, sizeof(lose));
	
		// rock scissors paper
		for(int i = 1; i <= (k*n*(n-1))/2; i++) {
			int p1, p2;
			string s1, s2;
			cin >> p1 >> s1 >> p2 >> s2;
			if(s1 == "rock") {
				if(s2 == "scissors") {
					win[p1]++;
					lose[p2]++;
				} else if(s2 == "paper") {
					win[p2]++;
					lose[p1]++;
				}
			} else if(s1 == "scissors") {
				if(s2 == "paper") {
					win[p1]++;
					lose[p2]++;
				} else if(s2 == "rock") {
					win[p2]++;
					lose[p1]++;
				}
			} else {
				if(s2 == "rock") {
					win[p1]++;
					lose[p2]++;
				} else if(s2 == "scissors") {
					win[p2]++;
					lose[p1]++;
				}
			}
		}
		
		// output
		for(int i = 1; i <= n; i++) {
			if(win[i]+lose[i] == 0) cout << "-" << endl;
			else printf("%.3f\n", ((float)win[i])/(win[i]+lose[i])) ;
		}
		cout << endl;
		
	}
}
