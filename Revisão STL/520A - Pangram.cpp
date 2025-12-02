#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<char> s;
    char a;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        a = toupper(a); // define o padrão geral como letras maiusculas
        s.insert(a);
    }

    if ((int)s.size() != 26) // verifica se a quantidade de letras é igual a do alfabeto
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}