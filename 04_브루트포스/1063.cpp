#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    string s1, s2;
    int n;
    cin >> s1 >> s2 >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp == "R")
        {
            if (s1[0] + 1 < 'I')
            {
                if (s1[0] + 1 == s2[0] && s1[1] == s2[1])
                {
                    if (s2[0] + 1 < 'I')
                        s2[0]++;
                    else
                        continue;
                }
                s1[0]++;
            }
        }
        else if (temp == "L")
        {
            if (s1[0] - 1 >= 'A')
            {
                if (s1[0] - 1 == s2[0] && s1[1] == s2[1])
                {

                    if (s2[0] - 1 >= 'A')
                        s2[0]--;
                    else
                        continue;
                }
                s1[0]--;
            }
        }
        else if (temp == "B")
        {
            if (s1[1] - 1 > '0')
            {
                if (s1[0] == s2[0] && s1[1] - 1 == s2[1])
                {
                    if (s2[1] - 1 > '0')
                        s2[1]--;
                    else
                        continue;
                }
                s1[1]--;
            }
        }
        else if (temp == "T")
        {
            if (s1[1] + 1 < '9')
            {
                if (s1[0] == s2[0] && s1[1] + 1 == s2[1])
                {
                    if (s2[1] + 1 < '9')
                        s2[1]++;
                    else
                        continue;
                }
                s1[1]++;
            }
        }
        else if (temp == "RT")
        {
            if (s1[0] + 1 < 'I' && s1[1] + 1 < '9')
            {
                if (s1[0] + 1 == s2[0] && s1[1] + 1 == s2[1])
                {
                    if (s2[0] + 1 < 'I' && s2[1] + 1 < '9')
                    {
                        s2[0]++;
                        s2[1]++;
                    }
                    else
                        continue;
                }
                s1[0]++;
                s1[1]++;
            }
        }
        else if (temp == "LT")
        {
            if (s1[0] - 1 >= 'A' && s1[1] + 1 < '9')
            {
                if (s1[0] - 1 == s2[0] && s1[1] + 1 == s2[1])
                {
                    if (s2[0] - 1 >= 'A' && s2[1] + 1 < '9')
                    {
                        s2[0]--;
                        s2[1]++;
                    }
                    else
                        continue;
                }
                s1[0]--;
                s1[1]++;
            }
        }
        else if (temp == "RB")
        {
            if (s1[0] + 1 < 'I' && s1[1] - 1 > '0')
            {
                if (s1[0] + 1 == s2[0] && s1[1] - 1 == s2[1])
                {
                    if (s2[0] + 1 < 'I' && s2[1] - 1 > '0')
                    {
                        s2[0]++;
                        s2[1]--;
                    }
                    else
                        continue;
                }
                s1[0]++;
                s1[1]--;
            }
        }
        else if (temp == "LB")
        {
            if (s1[0] - 1 >= 'A' && s1[1] - 1 > '0')
            {
                if (s1[0] - 1 == s2[0] && s1[1] - 1 == s2[1])
                {
                    if (s2[0] - 1 >= 'A' && s2[1] - 1 > '0')
                    {
                        s2[0]--;
                        s2[1]--;
                    }
                    else
                        continue;
                }
                s1[0]--;
                s1[1]--;
            }
        }
    }
    cout << s1 << endl;
    cout << s2;

    return 0;
}