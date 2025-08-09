//34. 버블정렬
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n;
    freopen("input.txt","rt",stdin);
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int a: arr){
        printf("%d ",a);
    }

    return 0;
}