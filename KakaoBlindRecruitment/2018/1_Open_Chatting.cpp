#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;

string getUidFromRecord(string record) {
    char *recordArr = new char[record.length() + 1];
    char *uid = nullptr;

    strcpy(recordArr, record.c_str());

    strtok(recordArr, " ");
    uid = strtok(NULL, " ");

    delete[] recordArr;

    return string(uid);
}

string getNickNameFromRecord(string record) {
    char *recordArr = new char[record.length() + 1];
    char *nickname = nullptr;

    strcpy(recordArr, record.c_str());

    strtok(recordArr, " ");
    strtok(NULL, " ");
    nickname = strtok(NULL, " ");

    delete[] recordArr;

    return string(nickname);
}

string getActionFromRecord(string record) {
    char *recordArr = new char[record.length() + 1];
    char *action = nullptr;

    strcpy(recordArr, record.c_str());

    action = strtok(recordArr, " ");

    delete[] (recordArr);

    return string(action);
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> actionUidArr;
    map<string, string> userNicknameMap;
    int size = record.size();

    for (int i = 0; i < size; i++) {
        string action = getActionFromRecord(record[i]);
        string uid = getUidFromRecord(record[i]);

        if (strcmp(action.c_str(), "Enter") == 0 || strcmp(action.c_str(), "Change") == 0) {
            string nickname = getNickNameFromRecord(record[i]);
            userNicknameMap[uid] = nickname;
        }

        actionUidArr.push_back(make_pair(action, uid));
    }

    for (int i = 0; i < size; i++) {
        string action = actionUidArr[i].first;
        string nickname = userNicknameMap[actionUidArr[i].second];
        string resultStr = nickname + "님이 ";

        switch (action[0]) {
            case 'E':
                resultStr += "들어왔습니다.";
                answer.push_back(resultStr);
                break;
            case 'L':
                resultStr += "나갔습니다.";
                answer.push_back(resultStr);
        }

        resultStr = "";
    }

    return answer;
}

int main() {
    vector<string> record = {
            "Enter uid1234 Muzi",
            "Enter uid4567 Prodo",
            "Leave uid1234",
            "Enter uid1234 Prodo",
            "Change uid4567 Ryan"
    };
    vector<string> result = solution(record);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}