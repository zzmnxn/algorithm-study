//35. Special Sort(버블 정렬 응용 : 구글 인터뷰)
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    //freopen("input.txt","rt",stdin);
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>0 &&arr[j+1]<0){
                swap(arr[j],arr[j+1]);
            }
        }
        
    }

    for(int a: arr){
        printf("%d ",a);
    }


}