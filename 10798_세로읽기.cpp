#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> vec;
    for (int i = 0; i < 5; i++) {
        string tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    for(int idx = 0; idx < 15; idx++) {
        for (int i = 0; i < 5; i++) {
            string str1 = vec.at(i);
            if(str1.size() <= idx) {
                continue;
            }
            cout << str1[idx];
        }
    }

    cout << "\n";
}