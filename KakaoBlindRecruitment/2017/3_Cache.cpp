#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <list>

using namespace std;

list<string> pageFrame;

int solution(int cacheSize, vector<string> cities) {
    int size = cities.size();
    int answer = 0;
    list<string>::iterator iter;

    pageFrame.clear();

    for (int i = 0; i < size; i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        iter = find(pageFrame.begin(), pageFrame.end(), cities[i]);

        if (iter == pageFrame.end()) {
            answer += 5;

            if (pageFrame.size() == cacheSize) {
                if(pageFrame.size() > 0) {
                    pageFrame.pop_front();
                }
            }
        } else {
            pageFrame.remove(*iter);
            answer++;
        }

        pageFrame.push_back(cities[i]);
    }

    return answer;
}

int main() {
    int cacheSize = 3;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};

    cout << solution(cacheSize, cities) << endl;

    cacheSize = 3;
    cities = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
    cout << solution(cacheSize, cities) << endl;

    cacheSize = 2;
    cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork",
              "Rome"};
    cout << solution(cacheSize, cities) << endl;

    cacheSize = 5;
    cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork",
              "Rome"};
    cout << solution(cacheSize, cities) << endl;

    cacheSize = 2;
    cities = {"Jeju", "Pangyo", "NewYork", "newyork"};
    cout << solution(cacheSize, cities) << endl;

    cacheSize = 0;
    cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    cout << solution(cacheSize, cities) << endl;

    return 0;
}