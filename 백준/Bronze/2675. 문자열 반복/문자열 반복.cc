#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    //const int MAXLENGHT 20;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int R, j = 0;
        cin >> R;
        int array[20] = {0};
        string inputString;
        cin >> inputString;
        for(j = 0; j < inputString.length(); j++) {
            array[j] = inputString[j];
        }
        for (int k = 0; k < j; k++) {
            for (int l = 0; l < R; l++) {
                cout << static_cast<char>(array[k]);
            }
        }
        cout << endl;
    }
 
    
    return 0;
}