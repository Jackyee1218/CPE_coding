// P6 10740: Not the Best
// https://vjudge.net/problem/UVA-10740

#include <iostream>
#include <queue>
using namespace std;

struct T{
    int node;
    long long dis;
    bool operator<(const T& other) const {
        return dis > other.dis; 
    }
};

int main() {
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);

    int n, m;
    while(cin >> n >> m && n+m) { // vertices and edges
        int x, y, k;
        cin >> x >> y >> k;
        priority_queue<T> pq;
        vector<int> cnt(n+1, 0);
        vector<vector<T>> con(n+1, vector<T>());
        for(int i = 0; i < m; i++) {
            int u, v;
            long long d;
            cin >> u >> v >> d;
            con[u].push_back(T{v, d});
        }

        pq.emplace(T{x, 0LL});
        long long answer = -1;
        while(!pq.empty()) {
            T now = pq.top();
            pq.pop();
            long long dis = now.dis;
            int v = now.node;
            cnt[v]++;
            if(v == y && cnt[v] == k) {
                answer = dis;
                break;
            }
            if(cnt[v] > k) continue;
            for(int i = 0; i < con[v].size(); i++) {
                T tmp = con[v][i];
                pq.emplace(T{tmp.node, tmp.dis+dis});
            }
        }
        cout << answer << '\n';
    }
}