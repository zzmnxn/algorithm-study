#include <iostream>
#include <string>

using namespace std;

typedef int Data;
#define stack_len 10000

class Stack {
public:
    Data stackArr[stack_len];
    int topindex;
};


void StackInit(Stack* pstack) {
    pstack->topindex = -1;
}

void Push(Stack* pstack,Data data) {
    pstack->topindex++;
    pstack->stackArr[pstack->topindex] = data;
}

Data Pop(Stack* pstack) {
    if (pstack->topindex == -1) {
        return -1;
    }

    int ridx = pstack->topindex;
    pstack->topindex--;
    return pstack->stackArr[ridx];
}

int Size(Stack* pstack) {
    return (pstack->topindex) + 1;
}

int Empty(Stack* pstack) {
    if (pstack->topindex == -1) {
        return 1;
    }
    else return 0;
}

Data Top(Stack* pstack) {
    if (pstack->topindex == -1) {
        return -1;
    }
    return pstack->stackArr[pstack->topindex];
}


int main() {
    int n;
    cin >> n;
    Stack stack;
    StackInit(&stack);

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "push"){
            int num;
            cin >> num;
            Push(&stack, num);
        }
        else if (command == "pop") {
            cout << Pop(&stack)<<"\n";
        }
        else if (command == "top") {
            cout << Top(&stack) << "\n";
        }
        else if (command == "empty") {
            cout << Empty(&stack) << "\n";
        }
        else if (command == "size") {
            cout << Size(&stack) << "\n";
        }
    }
 
    return 0;
}
