#include <bits/stdc++.h>
using namespace std;

int main()
{
    int disposicao, cansativas, revigorantes;
    int atividades;
    int c[10000], aux;

    cin >> disposicao >> cansativas >> revigorantes;
    atividades = revigorantes;

    for (int i = 0; i < cansativas; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < revigorantes; i++)
    {
        cin >> aux;
        disposicao += aux;
    }

    for (int i = 0; i < cansativas; i++)
    {
        if (c[i] <= disposicao)
        {
            disposicao -= c[i];
            atividades++;
        }
        else
        {
            break;
        }
    }

    cout << atividades << endl;

    return 0;
}