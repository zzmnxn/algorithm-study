#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<int>> & mat){
    if (mat.empty()) return 0;

    int n=mat.size();

    vector<int> left(n,0);
    vector<int> right(n,n);
    vector<int> height(n,0);

    int max_area=0;

    for(int i=0;i<n;i++){
        int curr_left=0;
        int crr_right=n;
        for(int j=0;j<n;j++){
            if(mat[i][j]){
                height[j]++;
                left[j]=max(curr_left, left[j]);
            }else{
                height[j]=0;
                left[j]=0;
                curr_left=j+1;
            }
        }
        for(int j=n-1;j>=0;j--){
            if(mat[i][j]){
                right[j]=min(curr_right, right[j]);
            }
        }
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    vector<vector<int>> mat(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>> mat[i][j];
        }
    }

    cout<< maximalRectangle(mat);

}