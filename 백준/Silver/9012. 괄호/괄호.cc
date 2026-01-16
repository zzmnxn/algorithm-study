#include <bits/stdc++.h>
//ctr + alt +n

using namespace std;

int main(){

    int n;
    cin>>n;
    string str;

    
    for(int i=0;i<n;i++){
        stack<int> s;
        bool result=true;
        cin>>str;
        for(char c : str){
            if(c=='(') {
                s.push(c);
            }
            else if(c == ')'){
                if(s.empty()){
                    result=false; 
                    break;
                }
                char tmp = s.top();
                s.pop();
                if(tmp ==')'){
                    result=false;
                    break;
                }
            }
        }
        if(!s.empty()) result=false;
        if(result){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        
        

    }

    return 0;
}