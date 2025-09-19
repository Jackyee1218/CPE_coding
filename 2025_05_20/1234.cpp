// P7 1234: RACING
// https://vjudge.net/problem/UVA-1234
// Disjoint Set & Minimum Feedback Edge Set

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


vector<int> UF;

int FIND(int x) {
    if(UF[x] == x) return x;
    return UF[x] = FIND(UF[x]);
}

void UNION(int a, int b) {
    if(FIND(a) != FIND(b)) {
        UF[FIND(a)] = FIND(b);
    }
}

int main() {
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);

    int cases;
    cin >> cases;
    while(cases--) {
        int n, m;
        cin >> n >> m; // #junctions & #roads t 0 < n < 10000 and 0 < m < 100000
        UF.resize(n);
        for(int i=0;i<n;i++)UF[i] = i;
        priority_queue<pair<int, int>> pq;
        vector<pair<int, int>> edges;
        int sum = 0;
        for(int i = 0; i < m; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            sum += d;
            edges.push_back({u-1, v-1});
            pq.push({d, i});
        }
        while(pq.size()) {
            int d, idx;
            tie(d, idx) = pq.top();
            pq.pop();
            if(FIND(edges[idx].first) != FIND(edges[idx].second)) {
                sum -= d;
                UNION(edges[idx].first, edges[idx].second);
            } 
        }
        cout << sum << '\n';
    }
}