#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    int remain = number.size() - k; // 남은 숫자의 개수
    int start = 0; // 현재 선택할 수 있는 범위의 시작 인덱스

    for (int i = 0; i < remain; i++) {
        char maxDigit = number[start];
        int maxIndex = start;

        // 현재 선택할 수 있는 범위 내에서 가장 큰 숫자 찾기
        for (int j = start; j <= k + i; j++) {
            if (maxDigit < number[j]) {
                maxDigit = number[j];
                maxIndex = j;
            }
        }

        // 선택된 가장 큰 숫자를 정답에 추가하고, 다음 선택할 수 있는 범위를 갱신
        answer += maxDigit;
        start = maxIndex + 1;
    }

    return answer;
}