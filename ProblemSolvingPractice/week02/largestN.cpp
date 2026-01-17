#include<bits/stdc++.h>
using namespace std;


int partition(vector<int>& arr, int left, int right){
    if(left == right ) return left;
    int pivot= left+rand()%(left-right+1);
    int val= arr[pivot];
    swap(arr[pivot],arr[right]);

    int tmp_idx=left;
    for(int i=left; i<right;i++){
        if(arr[i]<val){
            swap(arr[i],arr[tmp_idx]);
            tmp_idx++;
        }
    }
    swap(arr[tmp_idx],arr[right]);
    return tmp_idx;
}

vector<int> findLargestElements(const vector<vector<int>>& matrix, int n){
    vector<int> largestElements;

    if(matrix.empty()){
        return{};
    }

    int total=n*n;
    largestElements.reserve(total);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            largestElements.push_back(matrix[i][j]);
        }
    }

    int target= total-n;
    int left=0;
    int right= total-1;

    while(left<=right){
        int pivot = partition(largestElements,left, right);
        if (pivot==target) break;
        else if(pivot<target){
            left=pivot+1;
        }
        else right= pivot-1;
    }

    vector<int> largest=vector<int>(largestElements.begin()+target, largestElements.end());
    sort(largest.begin(),largest.end(),greater<int>());

}

int main(){
   ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    srand(time(0));

    int n;
    cin>>n;
    
    vector<vector<int>> M(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>M[i][j];
        }
    }

    vector<int> largestElements = findLargestElements(M,n);

    for(int element : largestElements){
        cout<<element<<"\n";
    }

    return 0;
}