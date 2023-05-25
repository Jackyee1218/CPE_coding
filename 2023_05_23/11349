#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool judge(const vector<vector<long long> > &num) {
	for(int i = 0; i < num.size(); i++) {
		for(int j = i; j < num.size(); j++) {
			if(num[i][j] != num[num.size()-i-1][num.size()-j-1] || num[i][j] < 0) return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	for(int k = 1; k <= t; k++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int n;
		while(ss) {
			string a, b;
			ss >> a;
			ss >> b;
			ss >> n;
		}
		vector<vector<long long> > num(n, vector<long long>(n));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> num[i][j];
		cout << "Test #" << k << ": ";
		if(judge(num)) cout << "Symmetric.\n";
		else cout << "Non-symmetric.\n";
		cin.ignore();
	}
} 
