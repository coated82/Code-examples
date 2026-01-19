#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; // quantidade de casos
    int x; // 1 graveto por x gravetos
    int y; // y gravetos por 1 carvão
    int k; // quantidade de tochas necessarias

    // loop de casos de teste
    cin >> t;
    while(t--){
        // entrada
        cin >> x >> y >> k;

        unsigned long long int q; // quantidade de trocas
        unsigned long long int s; // quantidade de gravetos

        // y * k é igual a quantidade de gravetos para pegar o carvão
        // + k - 1 para pegar os gravetos faaltantes para fazer as tochas
        s = y*k + k - 1;

        // cada troca de gravetos dá x - 1 com isso a solução se da por
        q = (s / (x - 1)) + k;

        // saida
        cout << q << endl;
    }

    return 0;
}