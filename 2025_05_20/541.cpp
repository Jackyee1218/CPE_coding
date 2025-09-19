// P2 541: Error Correction
// https://vjudge.net/problem/UVA-541

#include <iostream>
#include <cstring>
using namespace std;

int grid[105][105];

int main() {
    // freopen("infile.txt", "r", stdin);
    int n;
    while(cin >> n && n) {
        bool row[n];
        bool col[n];
        memset(row, true, sizeof(row));
        memset(col, true, sizeof(col));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> grid[i][j];
                if(grid[i][j] == 1) {
                    row[i] = !row[i];
                    col[j] = !col[j];
                }
            }
        }
        int cnt_row = 0, cnt_col = 0;
        int row_idx = -1, col_idx = -1;
        for(int i = 0; i < n; i++) {
            if(!row[i]) {
                cnt_row++;
                row_idx = i;
            }
        }
        for(int i = 0; i < n; i++) {
            if(!col[i]) {
                cnt_col++;
                col_idx = i;
            }
        }
        if(cnt_row + cnt_col == 0) cout << "OK\n";
        else if(cnt_row == 1 && cnt_col == 1) printf("Change bit (%d,%d)\n", row_idx+1, col_idx+1);
        else cout << "Corrupt\n";
    }
}