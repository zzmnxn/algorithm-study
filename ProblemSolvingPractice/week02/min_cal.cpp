#include <bits/stdc++.h>
using namespace std;
vector<int> min_multiplications(int);
void dfs(int, int, int, vector<int>&, vector<int>&, bool&);


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


vector<int> min_multiplications(int n){
    if(n==1) return {1};

    vector<int> result;
    bool found= false;

    for(int limit=1;;limit++){
        vector<int> start={1};

        dfs(n,limit,0,start,result,found);

        if(found) break;

    }
    return result;

}

void dfs(int n, int limit, int depth, vector<int>& current_path, vector<int>& result_path, bool& found){
    if(found) return;

    if(depth>=limit) return;

    int max_possible= current_path.back();
    for(int i=0;i<(limit-depth);i++){
        max_possible*=2;
    }
    if(max_possible<n) return;

    for(int i=current_path.size()-1; i>=0;i--){
        for(int j=i;j>=0;j--){
            int next=current_path[i]+current_path[j];
            if(next<=current_path.back() || next>n) continue;

            current_path.push_back(next);

            if(next==n){
                result_path=current_path;
                found=true;
            }else{
                dfs(n, limit, depth+1,current_path, result_path, found);
            }

            current_path.pop_back();

            if(found) return;

        }
        if(found) return;
    }

}