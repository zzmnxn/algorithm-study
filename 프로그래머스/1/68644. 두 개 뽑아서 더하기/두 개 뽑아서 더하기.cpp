#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int l=numbers.size();
    answer.reserve(l*(l-1)/2); //미리 필요한만큼 할당해주기(배운 거 응용)
    set<int> hap;
    //중복값 허용 하지 않음 but 마지막에만 정렬된, 중복 X 필요
    // for(int i=0;i<l-1 ;i ++){
    //     for(int j=i+1;j<l;j++){
    //         answer.push_back(numbers[i]+numbers[j]);
    //     }
    // }
    // sort(answer.begin(), answer.end());
    // answer.erase(unique(answer.begin(),answer.end()),answer.end());
    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            hap.insert(numbers[i]+numbers[j]);
        }
    }
    answer= vector<int>(hap.begin(), hap.end());
    
    return answer;
}
