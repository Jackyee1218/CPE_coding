#include <bits/stdc++.h>
using namespace std;

#define MAX 5000000

int main() {
	
	int m;
	cin >> m;
	
	while(m--) {
		
		int tcost;
		vector<int> land_cost;
		
		while((cin >> tcost) && tcost != 0) 
			land_cost.push_back(tcost);
		
		// sort to ascending array
		sort(land_cost.begin(), land_cost.end(), greater<int>());
	
		int sum = 0;
		bool valid = true;
		
		for(int i = 0; i < land_cost.size(); i++) {
			sum += 2*pow(land_cost[i], i+1);
			if(sum > MAX) {
				valid = false;
				break;
			}
		}
		if(!valid) cout << "Too expensive\n";
		else cout << sum << endl; 
	}
} 
