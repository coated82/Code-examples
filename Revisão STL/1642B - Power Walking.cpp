#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while(t--){
        int k, n;
        set <int> a;

        cin >> k;

        for(int i = 0; i < k; i++){
            cin >> n;
            a.insert(n);
        }

        for (int i = 0; i < k; i++){
            if(i < a.size()){
                cout << a.size() << " ";
            }else{
                cout << i + 1 << " ";
            }
        }
        cout << endl;

        a.clear();
    }

    return 0;
}