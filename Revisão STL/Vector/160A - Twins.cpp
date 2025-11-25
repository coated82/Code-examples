#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, r;
    vector<int> a, s;

    cin >> n;

    for (int i = 0, x; i < n; i++) // entrada de dados
    {
        cin >> x;
        a.push_back(x);
    }

    // ordenar o vetor de forma decrecente
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    s.push_back(a.front());
    for (int i = 1; i < n; i++) // fazendo um vetor de soma de prefixos
    {
        s.push_back(a[i] + s.back());
    }

    for (int i = 0; i < n; i++)
    {
        if (s.back() - s[i] < s[i]) // assim que a quantidade do meu irmão for menor que a minha 
        {                           // será a quantidade minima de moedas necessarias que eu devo pegar
            r = i + 1;              
            break;
        }
    }

    cout << r << endl;

    return 0;
}