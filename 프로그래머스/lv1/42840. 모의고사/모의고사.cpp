#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> num_1 = {1,2,3,4,5};
    vector<int> num_2 = {2, 1, 2, 3, 2, 4, 2, 5};  //8
    vector<int> num_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; //10
    
    int l= answers.size();
    int a=0, b=0, c=0;
    for(int i=0;i<l;i++){
        if(answers[i]==num_1[i%5]) a++;
        if(answers[i]==num_2[i%8]) b++;
        if(answers[i]==num_3[i%10]) c++;
    }
    int max_result= max({a,b,c}); //{} 이용하여 여러개의 인자 중 max 추출 가능
    
    if(max_result == a) answer.push_back(1);
    if(max_result == b) answer.push_back(2);
    if(max_result == c) answer.push_back(3);
    
    
    return answer;
}