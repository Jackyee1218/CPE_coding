// 13204: Count these Permutations
// Unsolved
// https://vjudge.net/problem/UVA-13204


#include <iostream>
#include <vector>
#include <bitset>
#include <climits>
using namespace std;
/*
# Math & dp  !!Failed!! TLE

n+m < 51 [-50, 50]

令 S 為 (n+m) 數之總和，則題目求 F(T) 之最大、最小 ， 假設其中一邊和為 T

F(T) = T*(S-T) = - T^2 + ST = (- T^2 + ST - S^2/4 ) + S^2/4 = -(T - S/2)^2 + S^2/4

T 之範圍
求最大:
將其中一邊逼近S/2

求最小:
將其中一邊遠離S/2

若有兩個都很接近S/2，diff皆一樣，要選較大的。
ex. S = 15 , S/2= 7.5，但為了方便會記錄成 S/2=7
4、10 和 7都差3 ，但實際上10更好。
如果S為偶數可整除，則都沒差。

# using bitset without math but same dp !!correct!!

*/

// i j k  前 i 個數字挑 j 個是否可達 k


int main() {
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);
    int n, m;
    while(cin >> n >> m) {
        int total = n+m;
        vector<int> nums(total+1);
        int S = 0;
        for(int i = 1; i <= total; i++) {
            cin >> nums[i];
            S += nums[i];
        }
        if(n > m) swap(n, m);
        vector<bitset<10005>> dp(n+1); // 因為是對稱的，算其中一邊即可，總數(-2500~2500)，將數值位移，則需要5001，又n+m最多100，每個都需要位移50，因此需要10001
        dp[0][0] = true;
        for(int i = 1; i <= total; i++) {
            int val = nums[i];
            for(int j = n; j >= 1; j--) {
                dp[j] |= dp[j-1]<<(nums[i]+50); // 抵銷負值，會重複累加
            }
        }
        bitset<10005> k = dp[n];  
        int MIN_ans = INT_MAX, MAX_ans = INT_MIN;
        for(int i = 0; i < 10005; i++) {
            if(k[i]) {
                int tmp = i-50*n;  // 因為有累加要減回去
                int re = S-tmp; 
                MIN_ans = min(MIN_ans, tmp*re);
                MAX_ans = max(MAX_ans, tmp*re);
            }
        }
        cout << MAX_ans << " " << MIN_ans << '\n';
    }
}