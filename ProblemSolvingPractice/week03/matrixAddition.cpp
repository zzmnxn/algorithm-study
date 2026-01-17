#include <bits/stdc++.h>
using namespace std;


struct query{
    int R1, R2, C1, C2;
    double V;
};

struct event{
    double v;
    int c1, c2;
};

void matirx_addition(int N, vector<vector<double>>& A, int Q, vector<query>& queries){
    vector<vector<event>> events(N+2);

    for(int i=0;i<Q;i++){
        int r1=queries[i].R1;
        int r2=queries[i].R2;
        int c1=queries[i].C1;
        int c2=queries[i].C2;
        double v = queries[i].V;

        events[r1].push_back({v,c1,c2});
        events[r2+1].push_back()
    }
}

int main(){


}