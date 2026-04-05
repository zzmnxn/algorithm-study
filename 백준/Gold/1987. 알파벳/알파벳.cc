#include <iostream>
#include <set>
#include<vector>
using namespace std;

int dx[4]= {1,0,-1,0};
int dy[4] = {0, 1, 0, -1};

bool characters[26];
int r, c;
vector<vector<char>> board;
int result=0;
void backtracking(int x, int y,int d){
    (result< d) ? result=d : result;
    for(int i=0;i<4;i++){
        int nx=dx[i]+x;
        int ny= dy[i]+y;
        if(ny<0 || nx<0 || ny>=r || nx>=c) {
            continue;
        }
        int n = board[ny][nx]-'A';
        if(characters[n]==0){
            characters[n]=1;
            backtracking(nx,ny, d+1);
            characters[n]=0;
        }
    }
    return;

}

int main(){

    cin>>r>>c;
    board.assign(r,vector<char>(c));
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
        }
    }

    characters[board[0][0]-'A']=1;
    backtracking(0,0,1);
    cout<<result;

    return 0;


}