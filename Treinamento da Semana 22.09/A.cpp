#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool s;
    int p;
    int r = 0;

    cin >> n;

    while (n--)
    {
        p = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> s;
            if (s)
            {
                p++;
            }
        }
        if (p >= 2)
        {
            r++;
        }
    }

    cout << r << endl;

    return 0;
}