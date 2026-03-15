#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    Node* children[10];
    bool isEnd;

    Node() {
        for (int i = 0; i < 10; i++) children[i] = nullptr;
        isEnd = false;
    }
};


bool compare(const string& a, const string& b) {
    return a.length() < b.length();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // 테스트케이스 수
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n; // 전화번호 수
        cin >> n;
        vector<string> phone(n);
        for (int j = 0; j < n; j++) cin >> phone[j];

        //길이순으로 정렬 
        sort(phone.begin(), phone.end(), compare);

        Node* root = new Node();
        bool flag = true;
        
        // 메모리 해제를 위해 생성된 모든 노드를 추적하는 벡터
        vector<Node*> nodeList;
        nodeList.push_back(root);

        // 각 번호를 순회하며 직접 삽입 및 검사 
        for (string s : phone) {
            if (!flag) break; // 이미 일관성이 깨졌다면 중단

            Node* curr = root;
            for (char c : s) {
                int idx = c - '0';

                // 내려가는 도중에 이미 끝인 노드를 만난다면?
                // 나보다 짧은 번호가 내 앞에 이미 존재한다
                if (curr->isEnd) {
                    flag = false;
                    break;
                }

                if (curr->children[idx] == nullptr) {
                    Node* newNode = new Node();
                    curr->children[idx] = newNode;
                    nodeList.push_back(newNode); // 나중에 지우기 위해 저장
                }
                curr = curr->children[idx];
            }
            curr->isEnd = true; // 현재 번호의 끝 표시
        }

        // 3. 결과 출력
        if (flag) cout << "YES\n";
        else cout << "NO\n";

        // 4. 메모리 해제 (nodeList에 담긴 노드들을 순서대로 지움)
        for (Node* node : nodeList) {
            delete node;
        }
    }

    return 0;
}