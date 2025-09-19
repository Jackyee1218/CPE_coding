// P3 441: Lotto 
// https://vjudge.net/problem/UVA-441

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans[6];

void dfs(vector<int> &nums, int pre_i, int level) {
    if(level == 6) {
        cout << ans[0];
        for(int i = 1; i < 6; i++) {
            cout << " " << ans[i];
        }
        cout << '\n';
    }
    for(int i = pre_i+1; i < nums.size(); i++) {
        ans[level] = nums[i];
        dfs(nums, i, level+1);
    }
}

int main() {
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);

    int n;
    bool first_case = true;
    while(cin >> n && n) {
        if(!first_case) cout << '\n';
        first_case = false;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        dfs(nums, -1, 0);
    }
}