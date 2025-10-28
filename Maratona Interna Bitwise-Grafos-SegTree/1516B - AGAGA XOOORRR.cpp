#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        int a[2005]; // vetor para armazenar os prefixos de XOR
        a[0] = 0;    // prefixo inicial (nenhum elemento ainda)

        cin >> n; // lê o tamanho do array

        // Calcula o prefix XOR
        // a[i] vai guardar o XOR de todos os elementos de 1 até i
        // Exemplo: a[i] = a[1] ^ a[2] ^ ... ^ a[i]
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            a[i] = a[i - 1] ^ x; // acumula o XOR até o índice i
        }

        // Se o XOR total (a[n]) for 0,
        // já é possível dividir o array em 3 partes iguais,
        // pois 0 ^ 0 ^ 0 = 0 → sempre igual.
        bool r = !a[n];

        // Testa todas as combinações de cortes (i, j)
        // para dividir o array em 3 partes:
        // [1..i], [i+1..j], [j+1..n]
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                // Calcula o XOR de cada parte usando os prefixos:
                // Parte 1: XOR(1..i)   = a[i]
                // Parte 2: XOR(i+1..j) = a[j] ^ a[i]
                // Parte 3: XOR(j+1..n) = a[n] ^ a[j]
                // Se todos forem iguais → possível
                if (a[i] == (a[j] ^ a[i]) && a[i] == (a[n] ^ a[j]))
                {
                    r = true;
                }
            }
        }

        if (r)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
