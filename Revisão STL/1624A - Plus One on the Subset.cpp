#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    int t, n;
    set<int> a;

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0, x; i < n; i++)
        {
            cin >> x;
            a.insert(x);
        }

        int me = INF, ma = 0;

        for (int num : a) // logica pra pegar o menor e maior numero
        {
            if (num > ma) 
            {
                ma = num;
            }
            if (num < me)
            {
                me = num;
            }
        }

        cout << ma - me << endl;
        a.clear(); // limpar o set para o proximo caso de teste
    }

    return 0;
}