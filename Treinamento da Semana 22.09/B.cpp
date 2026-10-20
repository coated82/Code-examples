#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    int pa = -1, pa2 = -1, pb = -1, pb2 = -1;
    bool f = false, f2 = false;

    cin >> a;

    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] == 'A' && a[i + 1] == 'B' && !f && i != pa2)
        {
            pa = i;
            pb = i + 1;
            f = true;
        }

        if (a[i] == 'B' && a[i + 1] == 'A' && !f2 && i != pb)
        {
            pb2 = i;
            pa2 = i + 1;
            f2 = true;
        }
    }

    if (pa != pa2 && pb != pb2 && pa != -1 && pa2 != -1 && pb != -1 && pb2 != -1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}