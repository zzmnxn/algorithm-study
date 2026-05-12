#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int l =triangle[triangle.size()-1].size();
    
    vector<int> dp(l);
    for(int i=0;i<l;i++){
        dp[i]=triangle[l-1][i];
    }
    for(int i=l-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[j] = triangle[i][j] + max(dp[j], dp[j + 1]);
        }
    }
    int answer = dp[0];
    return answer;
}