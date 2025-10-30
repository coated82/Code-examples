#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int n, t, a[100000], i;
    int p = 1;       // p representa a posição atual (começa na célula 1)
    bool r = false; 

    cin >> n >> t;

    // leitura dos "saltos" de cada célula
    // para cada posição i (de 1 até n-1), a[i] indica quantas células você pula a partir dali
    for (i = 1; i < n; i++)
    {
        cin >> a[i];
    }

    i = 1; // começa na primeira célula
    // enquanto a posição atual (p) for menor que o destino (t)
    while (p < t)
    {
        p += a[i]; // avança p posições conforme o valor em a[i]
        i = p;     // atualiza o índice para a nova posição

        // se a posição atual for igual ao destino
        if (p == t)
        {
            r = true;
            break;
        }
    }

    // após o loop, verifica se chegou ou não ao destino
    if (r)
    {
        cout << "YES" << endl; 
    }
    else
    {
        cout << "NO" << endl; 
    }

    return 0;
}
