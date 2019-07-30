/**
 * https://www.acmicpc.net/problem/9375
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, int> clothesMap;

int main() {
    int T = 0;

    scanf("%d", &T);

    while(T--) {
        int n = 0;
        int numOfType = 0;
        int result = 0;

        scanf("%d", &n);

        if(n > 0) {
            map<string, int>::iterator iter;

            result = 1;
            clothesMap.clear();

            for(int i = 0; i < n; i++) {
                string clothes;
                string type;

                cin >> clothes;
                cin >> type;

                clothesMap[type] = clothesMap[type] + 1;
            }

            numOfType = clothesMap.size();
            iter = clothesMap.begin();

            for(int i = 0; i < numOfType; i++, iter++) {
                result = result * ((*iter).second + 1);
            }

            result = result - 1;
        }

        printf("%d\n", result);
    }

    return 0;
}
