#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; // lê o número de casos de teste

    while(t--) {
        int n;
        cin >> n; // lê o tamanho da string para este caso

        char s[20005];        // array para armazenar a string
        vector<int> a, b;     // vetores para guardar as posições de 'a' e 'b'

        // ---- lê a string e armazena posições ----
        for(int i = 0; i < n; i++){
            cin >> s[i];
            if(s[i] == 'a') a.push_back(i); // armazena a posição de cada 'a'
            else b.push_back(i);           // armazena a posição de cada 'b'
        }

        // ---- calcula a mediana para cada letra ----
        int meio_a = a.size() / 2; // índice do elemento mediano de 'a'
        int meio_b = b.size() / 2; // índice do elemento mediano de 'b'

        // ---- calcula custo para agrupar todos 'a' ----
        long long costA = 0;
        int sizeA = a.size();
        if(sizeA > 0){
            int medA = a[meio_a]; // posição mediana real
            for(int i = 0; i < sizeA; i++){
                // posição ideal de cada 'a' em um bloco contínuo
                int target = medA - sizeA/2 + i;
                costA += abs(a[i] - target); // soma o número de trocas necessárias
            }
        }

        // ---- calcula custo para agrupar todos 'b' ----
        long long costB = 0;
        int sizeB = b.size();
        if(sizeB > 0){
            int medB = b[meio_b]; // posição mediana real
            for(int i = 0; i < sizeB; i++){
                int target = medB - sizeB/2 + i; // posição ideal do 'b'
                costB += abs(b[i] - target);     // soma o número de trocas
            }
        }

        // ---- a resposta é o menor custo ----
        cout << min(costA, costB) << "\n";
    }

    return 0;
}
