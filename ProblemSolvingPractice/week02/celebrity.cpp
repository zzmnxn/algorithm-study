#include <bits/stdc++.h>
#include <casssert>

using namespace std;

bool ask_a_to_know_b(int a, int b) {
    int result;
    std::cout << "? " << a << ' ' << b << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

bool answer(int x) {
    int result;
    std::cout << "! " << x << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    int candidate = 1;

    for(int i=2;i<=n;i++){
        if(ask_a_to_know_b(candidate,i)){
            candidate=i;
        }
    }
    bool verify=true;
    for(int i=1;i<=n;i++){
        //중요!! 자기 자신은 count 하면 안됨!!
        if(i==candidate) continue;
        if(ask_a_to_know_b(candidate,i)||!ask_a_to_know_b(i,candidate)){
            verify=false;
            break;
        }
    }

    if(verify) answer(candidate);
    else answer(-1); //언제나 예외처리 해주기!!!




}