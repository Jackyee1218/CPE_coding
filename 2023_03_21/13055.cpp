#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	stack<string> name;
	
	while(n--) {
		
		string condition;
		cin >> condition;
	
		if(condition == "Sleep") {
			
			string tname;
			cin >> tname;
			name.push(tname);
			
		} else if(condition == "Test") {
			if(!name.size())
				cout << "Not in a dream\n";
			else 
				cout << name.top() << endl;
		} else { // Kick
			if(name.size()) name.pop(); 
		}
	}
} 
