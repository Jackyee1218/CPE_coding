// 12442: Forwarding Emails vjudge
// Unsolved
// https://vjudge.net/problem/UVA-12442

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
T <= 20
2 <= N <= 50000

# 以下情境都建立在此提的設定下 "單一節點單一邊" 
此題困難的點在於，done、v 的設計，當從一個點往下 dfs 所有經過的點都應該被應該被標做 done，
因為從別的地方進入，意味著從自己的地方開始，因此不需要再花費時間去做 dfs。

假設有一條 path 已經走過，若外面有點可以連進來那就應該讓其進來做 dfs，因為可能會更佳，
v 在此只是單純用於判斷 loop的情況

*/
#define SIZE 50005
bool done[SIZE];
bool v[SIZE];
int to[SIZE]; // Since only one edge for one node
int cnt;

void dfs(int node) {
    v[node] = true;
    done[node] = true; 
    if(!v[to[node]]) 
        dfs(to[node]);
    v[node] = false;
    cnt++;
}

int main() {
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);

    int cases;
    cin >> cases;
    for(int t = 1; t <= cases; t++) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            to[u] = v;
        }
        // dfs
        int best_cnt = -1, idx = -1;
        memset(done, false, sizeof(done));
        memset(v, false, sizeof(v));
        for(int i = 1; i <= n; i++) {
            if(!done[i]) {
                cnt = 0;
                dfs(i);
                if(cnt > best_cnt) {
                    idx = i;
                    best_cnt = cnt;
                }
            }
        }
        printf("Case %d: %d\n", t, idx);
    }
}