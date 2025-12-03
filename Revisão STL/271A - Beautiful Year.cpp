#include <bits/stdc++.h>
using namespace std;

int Vr(int x)
{
    // Transforma o ano em string
    string s = to_string(x);
    set<char> st;

    // Verifica se possui numeros repetidos
    for (char a : s)
    {
        if (st.count(a)) // se ouver repetição chama a função novamente com o proximo numero
        {
            return Vr(x + 1);
        };

        st.insert(a);
    }

    return x;
}

int main()
{
    int y;
    int res;

    cin >> y;

    res = Vr(y + 1);

    cout << res << endl;

    return 0;
}