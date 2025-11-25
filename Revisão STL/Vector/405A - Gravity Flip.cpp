#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    vector<int> a;

    cin >> n;

    while (n--)
    {
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    /*
        Caso simples onde ao observar a logica da questão só temos que
        ordenar o array de forma crescente
    */

    return 0;
}