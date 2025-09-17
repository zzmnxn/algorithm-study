#include<iostream>
#include<vector>
#include <functional>
#include <algorithm>
using namespace std;

//vector<vector<int>> dp; 
//vector<unordered_set<int>> dpSet; //j 체인 안에 k 있는지 확인용
//dp[i]는 i를 만들기 위한 최소 경로 저장됨

void dfs(int n, int limit, int depth, vector<int>& current_path, vector<int>& result_path, bool& found){
    if(found) return;
    if(depth>= limit) return; //현재 곱셈횟수(depth)가 정해놓은 한계 넘으면 중단
    //가지치기
    //현재 경로에서 가장 큰 수에 남은 횟수만큼 계속 2를 곱해도 n보다 작으면
    //포기
    int max_possible= current_path.back();
    for(int i=0; i<(limit-depth); i++){
        max_possible*=2;
    }
    if(max_possible<n) return;

    //큰 숫자부터 더해야 목표에 빨리 도달?
    for(int i=current_path.size()-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            int next=current_path[i]+current_path[j];

            //next가 경로의 마지막 숫자보다 작으면 이미 탐색한 비효율적 경로
            if(next<=current_path.back() || next>n){
                continue;
            }

            current_path.push_back(next); //경로에 다음 숫자 추가

            if(next==n){
                result_path=current_path;
                found=true;
            }else{
                dfs(n, limit, depth+1, current_path, result_path, found);
            }

            current_path.pop_back(); // !! 탐색 끝났으면 다시 되돌려놓기

            if(found) return;
        }
        if (found) return;
    }
}

vector<int> min_multiplications(int n) {
    if(n==1) return {1};

    vector<int> result;
    bool found=false;

    for(int limit=1;;limit++){
        vector<int> start={1};
        //곱셈 0번에서 시작
        dfs(n, limit, 0, start, result, found);

        if(found) break;
    }
    return result;
    
    // vector<int> parent(n + 1, -1);   // curr를 만든 이전 값
    // vector<bool> visited(n + 1, false);

    // queue<vector<int>> q;
    // q.push({1});  // 시작 체인

    // while (!q.empty()) {
    //     vector<int> chain = q.front();
    //     q.pop();
    //     int last = chain.back();

    //     for (int i = 0; i < chain.size(); ++i) {
    //         int cand = last + chain[i];
    //         if (cand > n || visited[cand]) continue;

    //         visited[cand] = true;
    //         parent[cand] = last;

    //         vector<int> new_chain = chain;
    //         new_chain.push_back(cand);

    //         if (cand == n) return new_chain;  // n에 도달하면 바로 반환

    //         q.push(new_chain);
    //     }
    // }
    // vector<int> e;
    // return e;
   

    // dp.assign(n+1,{});
    // dp[1]={1};
    // dpSet.assign(n+1,{});
    // dpSet[1].insert(1);

    // for(int i=2;i<=n;i++){
    //     //i가 2부터 n까지 순차적으로 돌면서 각각 최단 찾
    //     int bestL=INT_MAX;
    //     vector<int> chain;

    //     //i= j+k로 표현 가능한 모든 경우 탐색
    //     for(int j=1;j<i;j++){
            
    //         int k=i-j;
    //         if(k>j) continue;
    //         //가능한 분할 i=k+j 중 j와 k가 겹치는 부분이 있다면 둘을 합쳐서 
    //         //최단 체인으로 합치기 가능
    //         if(dp[j].empty() || dp[k].empty()) continue;

    //         vector<int> tmpChain= dp[j];
    //         //j를 만드는 최단 경로 체인임

    //         if(dpSet[j].count(k)){
    //             tmpChain.push_back(i);
    //             if((int)tmpChain.size()<bestL){
    //                 bestL= tmpChain.size();
    //                 chain=tmpChain;
    //             }
    //         }
    //     }
    //     if(!chain.empty()){
    //         dp[i]=chain;
    //     for(int x: chain) dpSet[i].insert(x);
    //     }

    // }
    //  return dp[n];

    // int jisoo=1;
    // while(jisoo<tmp){
    //     powers.push_back(jisoo);
    //     jisoo*=2;
    // }

    // if(powers.back()!=n){
    // powers.push_back(tmp);
    // }
    // 이러면 15와 같은 경우에 마지막에 1+2+4+8에서 곱셈 여러번 해서 최소가 아니게 된다
    // 즉 2의 거듭제곱이 아니라면 무쓸모?
   
}

int main(){

    int n;
    cin >> n;

    
    vector<int> steps = min_multiplications(n);
    cout << steps.size() - 1 << " ";
    for (int step : steps) {
        cout << step << " ";
    }

    return 0;
}