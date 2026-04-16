#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Person {
public:
    int age;
    string name;
    Person() {}

    void input() {
        cin >> age >> name;
    }

    // 출력 함수
    void output() const {
        cout << age << " " << name << "\n";
    }
};

bool compare(const Person& a, const Person& b) {
   
    return a.age < b.age;
}

int main() {
    int n;
 
    cin >> n;

    Person* people = new Person[n];

    for (int i = 0; i < n; i++) {
        people[i].input();
    }

    // 정렬
    stable_sort(people, people + n, compare);

    
    for (int i = 0; i < n; i++) {
        people[i].output();
    }

    delete[] people;
    return 0;
}
