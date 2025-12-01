#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, r, c = 0;
    vector <int> a;

    cin >> n >> k;

    for (int i = 0, x; i < n; i++){
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end()); // fazemos uma ordenação para podermos comparar a partir dos menores numeros

    while(c < k){ // como o numero tem que ser <= podemos definir a r = a[c]
        r = a[c];
        c++;
    }

    if(k == 0){ // caso k = 0, a resposta é a[0] - 1
        r = a[0] - 1;
    }

    if((a[c - 1] == a[c]) || r < 1){ // se houver numeros repetidos ou a resposta estiver abaixo do escopo r = -1
        r = -1;
    }

    cout << r << endl;
    
    return 0;
}