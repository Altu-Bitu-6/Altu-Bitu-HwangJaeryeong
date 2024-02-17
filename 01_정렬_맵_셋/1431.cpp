// 1. 길이 짧은 것이 먼저
// 2. A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저
// 3. 사전순으로 (숫자가 알파벳보다 사전순으로 작다)

#include <iostream>
#include <algorithm>
#include <string>

// sort(정렬 시작부분, 정렬 끝내는 부분, 정렬하는 조건);

using namespace std;

int compare(string a, string b){
    int size_a = a.size();
    int size_b = b.size();
    int sum_a = 0, sum_b = 0;

    //1번조건
    if (size_a != size_b) {
        return size_a < size_b;
    }

    //2번조건
    for(int i = 0; i < a.size(); i++){
        if(a[i] >= '0' && a[i] <= '9')
            sum_a += int(a[i]) - 48;

        if (b[i] >= '0' && b[i] <= '9')
            sum_b += int(b[i]) - 48;
    }

    if(sum_a != sum_b){
        return sum_a < sum_b;
    }

    //3번조건
    return a < b;
}

int main(){
    int n;
    cin >> n;
    
    string str[100];
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }

    sort(str, str + n, compare);
    for(int i = 0; i < n; i++){
        cout << str[i] << "\n";
    }
}