
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdio.h>
using namespace std;


void solve() {
    int N;
    cin >> N;

    if (N == 1) {
        answer({{0, 0}});
        return;
    }

    vector<int> final_mapping(N, -1);

    vector<pair<int, int>> a_pairs1;
    for(int i=1;i<N-1;i+=2){
        link_wire(i,i+1);
        a_pairs1.push_back({i,i+1});
    }

    move_to_opposite();

    vector<pair<int,int>> b_pairs1;
    vector<bool> b_is_paired(N, false);
    for (int i = 0; i < N; ++i) {
        if (b_is_paired[i]) continue;
        for(int j=i+1;j<N;j++){
            if(b_is_paired[j]) continue;
            if(check_connectivity(i,j)){
                b_pairs1.push_back({i,j});
                b_is_paired[i] = true;
                b_is_paired[j] = true;
                break;
            }
        }
    }

    int b_anchor = -1;
    for (int i = 0; i < N; ++i) {
        if (!b_is_paired[i]) {
            b_anchor = i;
            break;
        }
    }

    final_mapping[0] = b_anchor;

    clean_wires();
    if(N>1){
        link_wire(b_anchor,b_pairs1[0].first);
        for(size_t i=0;i< b_pairs1.size() - 1; ++i) {
            link_wire(b_pairs1[i].second, b_pairs1[i + 1].first);
        }
    }

    move_to_opposite();

    int current_a = 0;
    vector<bool> a_visited(N, false);
    a_visited[current_a] = true;

    int a_prev = 0;
    int b_prev = final_mapping[0];
    a_visited.assign(N, false);
    a_visited[a_prev] = true;

    for(int i=1;i<N;i++){
        int a_curr=-1;
        for(int j=1;j<N;j++){
            if(!a_visited[j] && check_connectivity(a_prev, j)) {
                a_curr = j;
                break;
            }
        }
        
        int a_partner = -1;
        for(const auto& p : a_pairs1) {
            if(p.first == a_curr) a_partner = p.second;
            else if(p.second == a_curr) a_partner = p.first;
        }
        vector<int> b_chain;
        vector<bool> b_chain_visited(N, false);
        b_chain.push_back(b_anchor);
        b_chain_visited[b_anchor] = true;

        if(N>1){
            int last_in_chain = b_pairs1[0].first;
            b_chain.push_back(last_in_chain);
            b_chain_visited[last_in_chain] = true;

            for(size_t k=0;k<b_pairs1.size();k++){
                for(const auto&p : b_pairs1){
                    if(p.first== last_in_chain && !b_chain_visited[p.second]){
                        last_in_chain = p.second;
                        b_chain.push_back(last_in_chain);
                        b_chain_visited[last_in_chain] = true;
                        break;
                    }else if(p.second == last_in_chain && !b_chain_visited[p.first]){
                        last_in_chain = p.first;
                        b_chain.push_back(last_in_chain);
                        b_chain_visited[last_in_chain] = true;
                        break;
                    }
                }
                for(size_t j=0;j<b_pairs1.size()-1;j++){
                    if(b_pairs1[j].second == last_in_chain && !b_chain_visited[b_pairs1[j+1].first]){
                       last_in_chain = b_pairs1[j+1].first;
                       b_chain.push_back(last_in_chain);
                       b_chain_visited[last_in_chain] = true;
                       break;
                    }
                }
            }
        }

        int a_current_in_chain = 0;
        for(int k=0;k<N-1;k++){
            for(int j=1;j<N;j++){
                if(check_connectivity(a_current_in_chain, j) && final_mapping[j] == -1){
                     final_mapping[j] = b_chain[k+1];
                     a_current_in_chain = j;
                     break;
                 }
            }
        }
    }

    vector<pair<int,int>> result;
    for(int i=0;i<N;i++){
        result.push_back({i,final_mapping[i]});
    }
    answer(result);
}

    
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}