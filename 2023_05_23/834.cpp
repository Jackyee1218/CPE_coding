#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int n, m;
	while(cin >> n >> m) {
		vector<int> num;
		while(1) {
			num.push_back(n/m);
			n -= m*(n/m);
			if(n == 0) break;
			swap(n, m);
		}
		cout << "[" << num[0] << ";" << num[1];
		for(int i = 2; i < num.size(); i++) cout << "," << num[i];
		cout << "]\n";  
	}
}
