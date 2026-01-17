#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF =4e18;

void solve(){
   int N, K;
   cin>>N>>K ;

   int M, A_cnt, B_cnt;
   cin>>M >> A_cnt >> B_cnt;

   vector<ll>  costs(K+1);
   for(int i=1; i<=K ;i++) cin >> costs[i];

   map<int, bool> hanbyeol_prefs;
   for (int i = 0; i < A_cnt; ++i) { int idx; cin >> idx; hanbyeol_prefs[idx] = true; }
    map<int, bool> eunha_prefs;
    for (int i = 0; i < B_cnt; ++i) { int idx; cin >> idx; eunha_prefs[idx] = true; }

    vector<ll> AB, A, B, O;
    for(int i=1; i<=K;i++){
        bool is_a = hanbyeol_prefs[i];
        bool is_b = eunha_prefs[i];
        if(is_a && is_b) A.push_back(costs[i]);
        else if (is_a) A.push_back(costs[i]);
        else if (is_b) B.push_back(costs[i]);
        else O.push_back(costs[i]);
    }

    sort(AB.begin(), AB.end());
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(O.begin(), O.end());

    vector<ll> AB_sum(AB.size()+1, 0);
    for(int i=0; i<AB.size(); i++) AB_sum[i+1]=AB_sum[i]+AB[i];
    vector<ll> A_sum(A.size() + 1, 0);
    for (int i = 0; i < A.size(); ++i) A_sum[i + 1] = A_sum[i] + A[i];

    vector<ll> B_sum(B.size() + 1, 0);
    for (int i = 0; i < B.size(); ++i) B_sum[i + 1] = B_sum[i] + B[i];

    ll min_cost =INF;

    for(int x= 0; x<= (int)AB.size();x++){
        ll current_cost =0;
        int current_N=0;

        current_cost += AB_sum[x];
        current_N +=x;

        int k = max(0,M-x);

        if(k>A.size() || k> B.size()) continue;

        current_cost += A_sum[k];
        current_N += k;
         current_cost += B_sum[k];
        current_N += k;

        int N_rem N- current_N;
        
        vector<ll> remaining_candidates;
        for(int i=k ;i<A.size(); i++){
            remaining_candidates.push_back(A[i]);
        }
        for(int i=k; i<B.size(); i++){
            remaining_candidates.push_back(B[i]);

        }
        
        remaining_candidates.insert(remainding_candidates.end(), O.begin(), O.end());

        sort(remaining_candidates.begin(), remaining_candidates.end());
        for (int i=0;i<N_rem;i++)
        current_cost += remaining_candidates[i];

    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}