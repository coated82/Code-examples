#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;        // número de problemas que o time vai avaliar
    int p, c = 0; // p: variável temporária para ler 0 ou 1 (confiança em resolver)
                  // c: contador de quantos problemas o time vai resolver
    int s;        // s: soma das opiniões (quantos membros acham que sabem resolver)

    cin >> n; 

    // o loop será executado n vezes (um para cada problema)
    while (n--)
    {
        s = 0; // zera a soma para o problema atual

        // lê as opiniões dos 3 membros da equipe
        for (int i = 0; i < 3; i++)
        {
            cin >> p; // cada membro responde 1 (sim) ou 0 (não)
            s += p;   // soma as respostas para ver quantos estão confiantes
        }

        // se pelo menos dois membros têm certeza (s >= 2)
        // o time decide resolver o problema
        if (s >= 2)
        {
            c++; // incrementa o contador de problemas que serão resolvidos
        }
    }

    // ao final, imprime quantos problemas o time vai resolver
    cout << c << endl;

    return 0;
}
