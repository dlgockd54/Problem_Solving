/**
 * https://programmers.co.kr/learn/courses/30/lessons/42577
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> phoneBookMap;

bool isContainPhoneNumber(vector<string>& phone_book) {
    bool ret = false;
    int size = phone_book.size();
    
    for(int i = 0; i < size; i++) {
        string element = phone_book[i];
        int length = element.length();

        for(int j = 1; j < length; j++) {
            string subStr = element.substr(0, j);

            if(phoneBookMap[subStr] > 0) {
                return true;
            }
        }
    }

    return ret;
}

bool solution(vector<string>& phone_book) {
    int size = phone_book.size();
    
    for(int i = 0; i < size; i++) {
        string element = phone_book[i];

        phoneBookMap[element] = 1;
    }

    return !isContainPhoneNumber(phone_book);
}

int main() {
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    // vector<string> phone_book = { "123", "456", "789" };
    // vector<string> phone_book = { "12", "123", "1235", "567", "88" };
    bool result = solution(phone_book);

    if(!result) {
        cout << "contains" << endl;
    }
    else {
        cout << "not contains" << endl;
    }

    return 0;
}