#include <iostream>
#include <vector>
#include <map>
using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    // freopen("infile.txt", "r", stdin);
    // freopen("outfile.txt", "w", stdout);
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        vector<int> milks[1005];
        int L = 1;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            L = lcm(L, tmp);
            for (int j = 0; j < tmp; j++)
            {
                int milk;
                cin >> milk;
                milks[i].push_back(milk);
            }
        }
        vector<bool> dead(n, false);
        int D = 0, preD = 0, live = n;
        // cout << "L : " << L << '\n';
        while (1)
        {
            bool killed = false;
            for (int d = 1; d <= L; d++)
            {
                if (live == 0)
                    break;
                int idx = -1;
                int now_small = 0x3fffffff;
                bool same = false;
                for (int i = 0; i < n; i++)
                {
                    if (!dead[i])
                    {
                        int now = milks[i][D % milks[i].size()];
                        if (idx == -1)
                        {
                            idx = i;
                            now_small = now;
                        }
                        else if (now < now_small)
                        {
                            idx = i;
                            now_small = now;
                            same = false;
                        }
                        else if (now == now_small)
                        {
                            same = true;
                        }
                    }
                }
                D++;
                if (idx != -1 && !same)
                {
                    killed = true;
                    preD = D;
                    dead[idx] = true;
                    live--;
                    // printf("D: %d, idx: %d %d\n", D, idx, now_small);
                }
            }
            if (!killed)
                break;
        }
        cout << live << " " << preD << '\n';
    }
}