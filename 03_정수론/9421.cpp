#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isSang(int num) {
    set<int> visit;
    int temp = num;

    while (true) {
        int answer = 0;
        while (temp) {
            answer += (temp % 10) * (temp % 10);
            temp /= 10;
        }
        if (answer == 1) return true;
        if (visit.count(answer) == 0) visit.insert(answer);
        else return false;

        temp = answer;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        if (isPrime(i) && isSang(i)) {
            cout << i << '\n';
        }
    }

    return 0;
}
