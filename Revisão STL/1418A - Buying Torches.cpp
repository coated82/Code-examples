#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long int t; // quantidade de casos de teste
    unsigned long long int x; // em 1 troca, 1 graveto vira x gravetos
    unsigned long long int y; // y gravetos são necessários para 1 carvão
    unsigned long long int k; // quantidade de tochas necessárias

    // leitura da quantidade de casos
    cin >> t;
    while(t--){
        // entrada dos valores
        cin >> x >> y >> k;

        unsigned long long int s; // quantidade total de gravetos necessários
        unsigned long long int q; // quantidade total de trocas

        // (y + 1) * k -> y gravetos para o carvão + 1 graveto para a tocha
        // -1 pois o último graveto já está disponível
        s = (y + 1) * k - 1;

        // cada troca gera (x - 1) gravetos líquidos
        // + (x - 2) para garantir divisão inteira com arredondamento para cima
        q = (s + x - 2) / (x - 1);

        // + k trocas necessárias para fabricar as k tochas
        q += k;

        // saída
        cout << q << endl;
    }

    return 0;
}
