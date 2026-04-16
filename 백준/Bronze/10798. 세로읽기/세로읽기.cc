#include <iostream>
#include <string>

using namespace std;

int main() {
    string words[5];

    for (int i = 0; i < 5; i++) {
        cin >> words[i];
    }

    
    int maxLength = 0;
    for (int i = 0; i < 5; i++) {
        if (words[i].size() > maxLength) {
            maxLength = words[i].size();
        }
    }

    string finalword;
    for (int j = 0; j < maxLength; j++) {
        for (int i = 0; i < 5; i++) {
            if (j < words[i].size()) {
                finalword += words[i][j];
            }
        }
    }

    cout << finalword << endl;

    return 0;
}
