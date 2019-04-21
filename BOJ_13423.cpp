/**
 * https://www.acmicpc.net/problem/13423
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> dots;

void bubbleSort() {
    int size = dots.size();

    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(dots[j] > dots[j + 1]) {
                int temp = dots[j];
                dots[j] = dots[j + 1];
                dots[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int begin, int end, int target) {
    int ret = -1;

    if(begin <= end) {
        int middle = (end + begin) / 2;

        if(target < dots[middle]) {
            ret = binarySearch(begin, middle - 1, target);
        }
        else if(target > dots[middle]) {
            ret = binarySearch(middle + 1, end, target);
        }
        else {
            ret = middle;
        }
    }

    return ret;
}

int main() {
    int T = 0;

    scanf("%d", &T);

    while(T--) {
        int N = 0;
        int size = -1;
        int result = 0;

        dots.clear();

        scanf("%d", &N);

        while(N--) {
            int dot = 0;

            scanf("%d", &dot);

            dots.push_back(dot);
        }

        bubbleSort();

        size = dots.size();

        for(int i = 1; i < size - 1; i++) {
            for(int j = i + 1; j < size; j++) {
                int distance = dots[j] - dots[i];
                int target = dots[i] - distance;

                if(binarySearch(0, i - 1, target) > -1) {
                    result++;
                }
            }
        }

        printf("%d\n", result);
    }

    return 0;
}
