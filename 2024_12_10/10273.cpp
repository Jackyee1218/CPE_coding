#include <iostream>
#include <vector>
#include <map>
using namespace std;

int gcd(int a, int b) {
    if(a % b == 0) return b;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

int main() {
    int cases; 
    cin >> cases;
    while(cases--) {
        int n;
        cin >> n;
        vector<int> milks[1005];
        int L = 1;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            L = lcm(L, tmp);
            for(int j = 0; j < tmp; j++) {
                int milk;
                cin >> milk;
                milks[i].push_back(milk);
            }
        }
        map<int, int> mp;
        vector<bool> dead(n, true);
        int D = 0, preD = 0, live = n;
        while(L--) {
            if(live == 0) break;
            int idx = -1;
            bool same=  false;
            for(int i = 0; i < n; i++) {
                if(!dead[i]) {
                    mp[i] += milks[i][D%milks[i].size()];
                    if(idx == -1 || mp[i] <= mp[idx]) {
                        if(idx == -1) {
                            idx=i;
                        } else if(mp[i] == mp[idx]) {
                            same = true;
                        } else {
                            idx = i;
                            same = false;
                        }
                    }
                }
            }
            D++;
            if(idx != -1 && !same) {
                preD = D;
                dead[idx] = true;
                live--;
            }
            printf(">> %d %d\n", idx, mp[idx]);
        }
        if(live == n) {cout << "0\n";}
        else {cout << live << " " << preD << '\n';}
    }
}