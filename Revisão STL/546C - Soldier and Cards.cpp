#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
int c; // contador de jogadas

int solve(list <int> k1, list <int> k2){

    if(k1.empty()){ // se k1 fica sem cartas o 2 ganha
        return 2;
    }else if(k2.empty()){ // se k2 fica sem cartas o 1 ganha
        return 1;
    }

    if(k1.front() > k2.front()){
        k1.push_back(k2.front());
        k1.push_back(k1.front());
        k1.pop_front();
        k2.pop_front();
        c++;
        solve(k1, k2);
    }
    else if(k1.front() < k2.front()){
        k2.push_back(k1.front());
        k2.push_back(k2.front());
        k1.pop_front();
        k2.pop_front();
        c++;
        solve(k1, k2);
    }
}

int main(){
    int n; // numero de cartas
    int s1, s2; // quantidade de cartas dos jogadores
    list <int> k1; // mão do jogador 1
    list <int> k2; // mão do jogador 2

    // entrada
    cin >> n;

    // definindo a mão do jogador 1
    cin >> s1;
    rep(i, 0, s1){
        int x;
        cin >> x;
        k1.push_back(x);
    }

    // definindo a mão do jogador 2
    cin >> s2;
    rep(i, 0, s2){
        int x;
        cin >> x;
        k2.push_back(x);
    }

    c = 0;
    
    cout << c << " " << solve(k1, k2) << endl;

    return 0;
}