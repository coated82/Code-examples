#include <bits/stdc++.h>
using namespace std;

int main() {
    set <int> s;
    s.insert(10);
    s.insert(3);
    s.insert(7);
    s.insert(7);

    for (int x : s) {
        cout << x << " ";
    }

    cout << endl;

    auto x = s.find(3);
    cout << *x << endl;

   

}
