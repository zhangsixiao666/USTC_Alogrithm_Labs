#include<iostream>
using namespace std;
const int N = 1E5+10;
int q[N];
int cnt[N];
//缺陷：对于待排序序列要求高，排序负数需要做偏移，离散化，对于小数据量的序列仍可能需要较大的额外空间
//时间O(n) 空间O(maxq[i]-minq[i])
void counting_sort(int q[],int n){
    for(int i=0;i<n;i++) cnt[q[i]]++;
    for(int j=0,i=0;i<N;i++){
        if(cnt[i])  cout<<"cnt["<<i<<"] = "<<cnt[i]<<' ';
        while(cnt[i]){
            q[j++]=i;
            cnt[i]--;
        }
    }
};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)  cin>>q[i];
    counting_sort(q,n);
    cout<<endl<<endl;
    for(int i=0;i<n;i++)  cout<<q[i]<<' ';
    return 0;
}