#include <bits/stdc++.h>
using namespace std;

/*
# wall
. passable square
J Joe's initial position
F a square that is on fire
*/

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};


struct coor{
	int i;
	int j;
	int cnt;
};

bool judge(int i, int j, int row, int col) {
	return i >= 0 && i < row && j >= 0 && j < col;
}

int main() {
	int m;
	cin >> m;
	while(m--) {
		
		queue<coor> joe;
		queue<coor> fire;
		
		
		int row, col;
		cin >> row >> col;
		
		bool valid_joe[row][col];
		bool valid_fire[row][col];
		memset(valid_joe, true, sizeof(valid_joe));
		memset(valid_fire, true, sizeof(valid_fire));
		
		string maze[row];
		for(int i = 0; i < row; i++) cin >> maze[i];
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(maze[i][j] == 'J') {
					joe.push((coor){i,j,0});
					valid_joe[i][j] = false;
					maze[i][j] = '.';
				} else if(maze[i][j] == 'F') {
					fire.push((coor){i,j,0});
					valid_fire[i][j] = false; 
				}
			}
		}
		
		int ans = 0;
		if(joe.back().i == 0 || joe.back().i == row-1 || joe.back().j == 0 || joe.back().j == col-1) {
			cout << 1 << endl;
			continue;
		}
		while(1) {
			queue<coor> new_fire;
			queue<coor> new_joe;
			
			// fire
			while(fire.size()) {
				coor now = fire.front();
				fire.pop();
				for(int k = 0; k < 4; k++) {
					int newi = now.i+di[k];
					int newj = now.j+dj[k];
					if(judge(newi, newj, row, col) && valid_fire[newi][newj] && maze[newi][newj] == '.') {
						maze[newi][newj] = 'F';
						valid_fire[newi][newj] = false;
						new_fire.push((coor){newi, newj, now.cnt+1});
					}
				}
			}
			fire = new_fire;
			// joe
			bool pass = false;
			if(joe.size() == 0) {
				cout << "IMPOSSIBLE\n";
				break;
			}
			while(joe.size()) {
				coor now = joe.front();
				joe.pop();
				for(int k = 0; k < 4; k++) {
					int newi = now.i+di[k];
					int newj = now.j+dj[k];
					if(judge(newi, newj, row, col) && valid_joe[newi][newj] && maze[newi][newj] == '.') {
						valid_joe[newi][newj] = false;
						new_joe.push((coor){newi, newj, now.cnt+1});
						if(newi == 0 || newi == row-1 || newj == 0 || newj == col-1) {
							joe = queue<coor>();
							ans = now.cnt+1; 
							pass = true;
							break;
						}
					}
				}
			}
			if(pass) {
				cout << ans+1 << endl;
				break;
			}
			joe = new_joe;	
			
		}
	}
}
