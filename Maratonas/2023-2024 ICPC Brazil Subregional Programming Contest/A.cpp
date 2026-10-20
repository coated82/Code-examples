#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, h, aux;
    int c = 0;

    cin >> n >> h;

    for (int i = 0; i < n; i++){
        cin >> aux;
        if(aux <= h) c++;
    }

    cout << c << endl;

    return 0;
}