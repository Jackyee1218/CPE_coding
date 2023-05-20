#include <bits/stdc++.h>
using namespace std;

int suma[505][505], sumb[505][505], dp[505][505][2];

int main() {
	
	int n, m;
	while((cin >> n >> m) && n+m) {
		memset(suma, 0, sizeof(suma));
		memset(sumb, 0, sizeof(sumb));
		memset( dp , 0, sizeof( dp ));
		// left
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> suma[i][j];
				suma[i][j] += suma[i][j-1];
			}
		}
		
		// up
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> sumb[i][j];
				sumb[i][j] += sumb[i-1][j];
			}
		}
		
		// build dp
	
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				// dp[i][j][0]  from previous dp + suma[i][j];
				// dp[i][j][1] from previous dp + sumb[i][j];
				dp[i][j][0] = max(dp[i-1][j][0] , dp[i-1][j][1]) + suma[i][j];
				dp[i][j][1] = max(dp[i][j-1][1] , dp[i][j-1][0]) + sumb[i][j];
			}
		}
		
		// output 
		
		cout << max(dp[n][m][0], dp[n][m][1]) << endl;
	}
} 
