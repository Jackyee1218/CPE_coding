#include <iostream>
#include <cstring>
#include <map>
using namespace std;

/*
1 <= C <= 150
0 <= n1  <= 500
0 <= n5  <= 100
0 <= n10 <= 50
*/
int dp[1000][200][100];
int min(int a, int b)
{
    return a < b ? a : b;
}

int find_min_coke(int nc, int n1, int n5, int n10)
{
    if (nc == 0)
        return 0;
    if (dp[n1][n5][n10] != 0)
        return dp[n1][n5][n10];

    dp[n1][n5][n10] = 0x3fffffff;

    /*
    1. A coke at a time
    2. the combination of changes should have chance to use less coins

    -  1*n10           -> 2*n1        (cost 1) # 10
    -  2*n5            -> 2*n1        (cost 2) # 10
    -  1*n5 + 3*n1     -> 0           (cost 4) # 8
    -  1*n10 + 3*n1    -> 1*n5        (cost 4) # 13
    -  8*n1            -> 0           (cost 8) # 8
    */
    if (n10 >= 1)
        dp[n1][n5][n10] = min(dp[n1][n5][n10], find_min_coke(nc - 1, n1 + 2, n5, n10 - 1) + 1);
    if (n5 >= 2)
        dp[n1][n5][n10] = min(dp[n1][n5][n10], find_min_coke(nc - 1, n1 + 2, n5 - 2, n10) + 2);
    if (n5 >= 1 && n1 >= 3)
        dp[n1][n5][n10] = min(dp[n1][n5][n10], find_min_coke(nc - 1, n1 - 3, n5 - 1, n10) + 4);
    if (n10 >= 1 && n1 >= 3)
        dp[n1][n5][n10] = min(dp[n1][n5][n10], find_min_coke(nc - 1, n1 - 3, n5 + 1, n10 - 1) + 4);
    if (n1 >= 8)
        dp[n1][n5][n10] = min(dp[n1][n5][n10], find_min_coke(nc - 1, n1 - 8, n5, n10) + 8);
    return dp[n1][n5][n10];
}

int main()
{
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        memset(dp, 0, sizeof(dp));
        int nc, n1, n5, n10;
        cin >> nc >> n1 >> n5 >> n10;
        cout << find_min_coke(nc, n1, n5, n10) << '\n';
    }
}