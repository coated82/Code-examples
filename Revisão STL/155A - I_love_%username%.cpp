#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[1005];
    int c = 0;
    int ma, me;

    cin >> n;
    cin >> a[0];

    ma = a[0];
    me = a[0];

    for (int i = 1; i < n; i++) // as partidas só são boas se ele bater o recorde ou seja
    {                           // tanto possitivamente quanto negativamente
        cin >> a[i];
        if (a[i] > ma)
        {
            c++;
            ma = a[i];
        }
        else if (a[i] < me)
        {
            c++;
            me = a[i];
        }
    }

    cout << c << endl;

    /*
        Não senti a necessicade de usar nenhuma extrutura pois era completamente opcional
    */

    return 0;
}