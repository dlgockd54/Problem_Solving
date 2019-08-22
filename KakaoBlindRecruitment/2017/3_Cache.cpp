#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

deque<string> deq;

int solution(vector<string> &cities, int cacheSize) {
    int size = cities.size();
    int answer = 0;
    deque<string>::iterator iter;

    while (!deq.empty()) {
        deq.pop_front();
    }

    for (int i = 0; i < size; i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        iter = find(deq.begin(), deq.end(), cities[i]);

        if (iter == deq.end()) {
            answer += 5;

            if (deq.size() == cacheSize) {
                deq.pop_front();
            }
        } else {
            deq.erase(iter);
            answer++;
        }

        deq.push_back(cities[i]);
    }

    return answer;
}

int main() {
    int cacheSize = 3;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};

    cout << solution(cities, cacheSize) << endl;

    cacheSize = 3;
    cities = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
    cout << solution(cities, cacheSize) << endl;

    cacheSize = 2;
    cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
    cout << solution(cities, cacheSize) << endl;

    cacheSize = 5;
    cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
    cout << solution(cities, cacheSize) << endl;

    cacheSize = 2;
    cities = {"Jeju", "Pangyo", "NewYork", "newyork"};
    cout << solution(cities, cacheSize) << endl;

    cacheSize = 0;
    cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    cout << solution(cities, cacheSize) << endl;

    return 0;
}