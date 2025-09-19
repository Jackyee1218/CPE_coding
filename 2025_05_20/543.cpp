// P4 543: Goldbach’s Conjecture
// https://vjudge.net/problem/UVA-543


#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

#define SIZE 1000005

int main() {
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);

    vector<int> v(SIZE, true);
    for(int i = 2; i*i < SIZE; i++) {
        if(v[i]) {
            for(int j = i*i; j < SIZE; j+=i) {
                v[j] = false;
            }
        }
    }

    int n = 0;
    while(cin >> n && n) {
        for(int i = 3; i <= n/2; i+=2) {
            if(v[i] && v[n-i]) {
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
    }
}