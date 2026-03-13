#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<char> moeum ={'a','e','i','o','u'};
int j_count=0;
int m_count=0;
vector<char> result;
int l;
vector<char> input;

void bfs(int idx, int depth ){

    if(depth==l){
        if(m_count>=1 && j_count>=2){
            for(char a: result){
            cout<<a;
            }
            cout<<'\n';
            return;
        }
    }
        // 완성된 거 출력하기
    

    for(int i=idx;i<input.size();i++){
        result[depth]=input[i];
        if(moeum.count(result[depth])==1){
            m_count++;
            bfs(i+1, depth+1);
            m_count--;
        }else {
            j_count++;
            bfs(i+1, depth+1);
            j_count--;
        }
    
    }

}


int main(){

    int  c;
    cin>>l>>c;

    
    for(int i=0;i<c;i++){
        char t;
        cin>>t;
        input.push_back(t);
    }


    sort(input.begin(), input.end());

    result=vector<char> (l);

    bfs(0, 0);

    return 0;

    
}

