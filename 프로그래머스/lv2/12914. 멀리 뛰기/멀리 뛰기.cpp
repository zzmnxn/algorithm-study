#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    //현재까지 그 칸을 도달하기 위해 뛴 수를 젖아하는 배열
    vector<int> dp (n+1);
    dp[0]=0;
    dp[1]=1; //첫번째 칸까지 1칸
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%1234567;
    }
    answer=dp[n];
    return answer;
}