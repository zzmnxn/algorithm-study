#include <iostream>
#include <vector>
#include <set>

using namespace std;

void backtracking(int n);

vector<int> result;
int m,n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    result.assign(m,0);
    //1부터 n까지 자연수 중
    // 중복없이 m개를 고른 수열
    // 이번엔 중복되는 수열 아예 한번만 출력
    backtracking(0);



}


void backtracking(int l){
    if(l==m){
        for(int i=0;i<m;i++){
            cout<<result[i]<<" ";
            
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        //이번에는 계속 시작하는 지점이 저번 꺼보다 앞서야 함
        // 그러면 start 지점을 track-> 인자로?
     
            result[l]=i;
            backtracking(l+1);
    
    }

}