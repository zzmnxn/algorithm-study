#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check_opening(char c){
    if(c=='(' || c=='[' || c== '{') return true;
    else return false;
}

bool check(char a, char b){
    if(a=='(' && b ==')') return true;
    else if(a=='{' && b =='}') return true;
    else if(a=='[' && b ==']') return true;
    return false; 
}

int solution(string s) {
    int answer = 0;

    int l= s.length();
    
    for(int i=0;i<l;i++){
        stack<char> st;
        int idx=i;
        int j=0;
        bool success=true;
        while(j<l){
            if(check_opening(s[idx%l])) st.push(s[idx%l]);
            else{
                if(st.empty()){
                success=false;
                break;
                }
                char tmp= st.top();
                if(check(tmp, s[idx%l])) {
                    st.pop();
                }
                else {
                    success= false; 
                    break;
                }
                }
            j++;
            idx++;
        }
        if(st.empty() && success) answer++;
    }
    return answer;
}