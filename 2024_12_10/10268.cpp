#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

#define pb push_back

int main()
{
    int x;
    while (cin >> x)
    {
        stringstream ss;
        vector<int> v;
        string s;
        cin.ignore();
        getline(cin, s);
        ss << s;
        int tmp, n = -1;
        while (ss >> tmp)
        {
            n++;
            v.pb(tmp);
        }
        int res = 0;
        for (int i = n; i >= 2; i--)
        {
            res += i * pow(x, i - 1) * v[v.size() - i - 1];
        }
        if (n >= 1)
            res += v[v.size() - 2];
        cout << res << "\n";
    }
}