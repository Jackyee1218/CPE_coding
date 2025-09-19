// 10690: Expression Again
// Unsolved
// https://vjudge.net/problem/UVA-10690

#include <iostream>

using namespace std;

const long long P = 1000000007;
long long permutation[500005];
long long record[1000005];


/*
# Math

|a1-1| + |a2-2| + ... + |an-n| = [n^2/2]
此為最大值，可以簡單帶幾個 n 進去就知道了。

因此最簡單的想法為 a1...an = n...1
然而從簡單的式子(n=4, n=5)可以發現，

當 n = even:
切成左右兩邊，而左右兩邊的任意組合皆可達成
= (n/2)!^2 

當 n = odd:
中間可以是任一個數，而左右一樣大的放左邊，小的放右邊，且左右兩邊一樣可以各自做排列而不影響結果。
= n*[n/2]!^2
*/

int main() {
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);
    permutation[1] = 1;
    record[1] = 1;
    record[2] = 1;
    for(int i = 3; i <= 1000000; i++) {
        int half = i/2;
        if(i % 2) {
            record[i] = (((permutation[half]*permutation[half])%P)*i)%P;
        } else {
            permutation[half] = (half*permutation[half-1])%P;
            record[i] = (permutation[half]*permutation[half])%P;
        }
    }
    int n;
    while(cin >> n) {
        cout << record[n] << "\n";
    }
}