#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int n, x, m = INF;
        vector<int> s;

        cin >> n;

        for (int i = 0; i < n; i++) // entrada no vector
        {
            cin >> x;
            s.push_back(x);
        }

        sort(s.begin(), s.end()); // sort() para organizar o vector

        // comparação para pegar a menor diferença entre o melhor da primeira equipe e o pior da segunda
        for (int i = 1; i < n; i++)
        {
            if (s[i] - s[i - 1] < m)
            {
                m = s[i] - s[i - 1];
            }
        }

        cout << m << endl;
        s.clear();
    }

    /*
        Para a resolução eu pensei que se eu ordenasse o vector
        sempre que eu fizer a conta entre os adjacentes eu já estaria 
        comparando o maior da equipe A e o menor da equipe B
    */

    return 0;
}