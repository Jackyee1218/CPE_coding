// P1 11063: B2-sequence 
// https://vjudge.net/problem/UVA-11063

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);
    int n , cnt = 1;
    while(cin >> n) {
        vector<int> nums(n);
        int pre = 0;
        map<int, bool> v;
        bool failed = false;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            if(pre >= nums[i]) failed= true;
            pre = nums[i];
        }
            
        
        
        for(int i = 0; i < n && !failed; i++) {
            for(int j = i; j < n && !failed; j++) {
                int sum = nums[i] + nums[j];
                if(v[sum]) {
                    failed = true;
                    break;
                }
                v[sum] = true;
            }
        }
        printf("Case #%d: ", cnt++);
        if(failed) cout << "It is not a B2-Sequence.\n\n";
        else cout << "It is a B2-Sequence.\n\n";
    }
}