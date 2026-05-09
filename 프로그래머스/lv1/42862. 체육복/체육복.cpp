#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer =0;
    vector<int> students(n,1);
    //없으면 0 있으면 1 두개 있으면 2
    for(int b : reserve){
        students[b-1]=2;
    }
    for(int a : lost){
        //여벌의 체육복을 가진 사람도 도난당할 수 있으니 lost 정보를 뒤로
        students[a-1]--;
    }
    //한 배열 안에 이제 정보가 다 들어 있음 앞에부터 순회하면 나눠주기 시작
    for(int i=0;i<n;i++){
        if(students[i]==0){
            if(students[i-1]>1 && i!=0){
                students[i-1]--;
                students[i]=1;
                continue;
            }
            else if(students[i+1]>1 && i!=n-1){
                students[i+1]--;
                students[i]=1;
                continue;
            }
        }

    }
    for(int a : students){
        if(a>=1) answer++;
    }
    
    return answer;
}