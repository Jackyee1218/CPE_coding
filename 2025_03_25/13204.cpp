// 13204: Count these Permutations
// Unsolved
// https://vjudge.net/problem/UVA-13204

/*

# goal
1. at least half the capacity of the pool
2. close to the target degree
3. never more than 5 degree hotter

*/

#include <iostream>
#include <vector>
using namespace std;


int main() {
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);
    int pros;
    cin >> pros;
    while (pros--) {
        long long max_c, target_temp;
        cin >> max_c >> target_temp;
        int n;
        cin >> n;
        vector<long long> c(n + 1), temp(n + 1);
        vector<long long> pre_c(n + 1, 0), pre_mix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> c[i] >> temp[i];
            pre_c[i] = pre_c[i - 1] + c[i];
            pre_mix[i] = pre_mix[i - 1] + c[i] * temp[i];
        }
        bool find_answer = false;
        int best_l = -1, best_r = -1;
        long long best_diff = -1, best_c = -1;
        for(int l  = 1; l <= n; l++) {
            for(int r = l; r <= n; r++) {
                long long now_c = pre_c[r] - pre_c[l-1];
                long long now_mix = pre_mix[r] - pre_mix[l-1];
                if(now_c > max_c) break;
                if(now_c < (max_c+1)/2) continue;
                long long diff = abs(now_mix - now_c*target_temp);
                if(diff > 5*now_c) continue;
                if(!find_answer){
                    best_l = l;
                    best_r = r;
                    best_diff = diff;
                    best_c = now_c;
                    find_answer = true;
                } else if(best_diff*now_c > best_c*diff) {
                    best_l = l;
                    best_r = r;
                    best_diff = diff;
                    best_c = now_c;
                }
            }
        }
        
        if(!find_answer) printf("Not possible\n");
        else printf("%d %d\n", best_l-1, best_r-1);
    }
}