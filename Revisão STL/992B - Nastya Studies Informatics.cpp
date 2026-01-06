#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, r, x, y;
    cin >> l >> r >> x >> y;

    // Se y não for múltiplo de x, impossível
    if (y % x != 0) {
        cout << 0 << '\n';
        return 0;
    }

    long long k = y / x;
    long long ans = 0;

    // percorre divisores de k
    for (long long a = 1; a * a <= k; a++) {
        if (k % a == 0) {
            long long b = k / a;

            // precisam ser coprimos
            if (gcd(a, b) == 1) {
                // verifica se os valores reais estão no intervalo
                if (x * a >= l && x * a <= r &&
                    x * b >= l && x * b <= r) {

                    if (a == b)
                        ans += 1; // (a, a)
                    else
                        ans += 2; // (a, b) e (b, a)
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
