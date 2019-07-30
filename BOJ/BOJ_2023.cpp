/**
 * https://www.acmicpc.net/problem/2023
 */

#include <iostream>

using namespace std;

bool isPrimeNumber(int num) {
    bool ret = true;

    for(int i = 2; i < num; i++) {
        if((num % i) == 0) {
            ret = false;

            break;
        }
    }

    return ret;
}

void printPrimeNumber(int N, int num) {
    int length = 0;

    for(int tempNum = num; tempNum > 0; tempNum /= 10) {
        length++;
    }

    if(length == N) {
        if(isPrimeNumber(num)) {
            printf("%d\n", num);
        }
    }
    else {
        if(isPrimeNumber(num)) {
            for(int i = 1; i < 10; i++) {
                int newNum = num * 10 + i;

                printPrimeNumber(N, newNum);
            }
        }
    }
}

void solution(int N) {
    int arr[4] = { 2, 3, 5, 7 };

    for(int i = 0; i < 4; i++) {
        if(N < 2) {
            printf("%d\n", arr[i]);
        }
        else {
            printPrimeNumber(N, arr[i]);
        }
    }
}

int main() {
    int N = 0;

    scanf("%d", &N);

    solution(N);

    return 0;
}
