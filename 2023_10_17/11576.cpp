#include <iostream> 
using namespace std;

int main() {
	int m;
	int k, w;
	cin >> m;
	while(m--) {
		cin >> k >> w;
		string ans;
		cin >> ans;
		for(int i = 1; i < w; i++) {
			string tmp;
			cin >> tmp;
			int p = 0;
			for(int len = k; len >= 1; len--) {
				bool valid = true;
				for(int j = 0; j < len; j++) {
					if(ans[ans.size()-len+j] != tmp[j]) valid = false;
				}
				if(valid) {
					p = len;
					break;
				}
			}
			for(int j = p; j < k; j++) ans += tmp[j];
		}
		cout << ans.size() << endl;
	}
} 
