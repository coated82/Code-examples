#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int x;
        map<int, pair<int, int>> u;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (!u.count(x))
            {
                u[x].first = i;
                u[x].second = i;
            }
            else
            {
                u[x].second = i;
            }
        }

        while (k--)
        {
            int a, b;
            cin >> a >> b;

            if (!u.count(a) || !u.count(b) || u[a].first > u[b].second)
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
        u.clear();
    }

    return 0;
}