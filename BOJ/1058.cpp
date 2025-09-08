#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isFriend(vector<vector<int>> peo, int i, int j){
    if(peo[i][j]) return true;
    else {
        for(int k=0;k<(int)peo[i].size();k++){
            if(peo[i][k]){
                if(peo[k][j]) return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> people(n, vector<int>(n));
    string line;
    for(int i=0;i<n;i++){
        cin>>line;
        for(int j=0;j<n;j++){
            if(line[j]=='N'){
                people[i][j]=0;
            }
            else{
                people[i][j]=1;
            }
        }
    }
    vector<int> count(n);
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && isFriend(people, i, j)) {
                count[i]++;
            }
        }
        if(count[i]>max) max=count[i];
    }

    cout<<max;

    return 0;

}