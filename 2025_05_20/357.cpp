// P5 357: Let Me Count The Ways
// https://vjudge.net/problem/UVA-357
#include <iostream>
#include <vector>
using namespace std;

#define SIZE 30005

int cents[] = {-1, 1, 5, 10, 25, 50};


int main() {
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);

    vector<long long> dp(SIZE, 1);
    for(int i = 2; i <= 5; i++) {
        int c = cents[i];
        for(int j = c; j < SIZE; j++) {
            dp[j] += dp[j-c];
        }
    }
    int n;
    while(cin >> n ) {
        long long res = dp[n];
        if(res == 1) printf("There is only 1 way to produce %d cents change.\n", n);
        else printf("There are %lld ways to produce %d cents change.\n", res, n);
    }

}