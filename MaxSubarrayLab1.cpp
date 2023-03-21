#include<iostream>
using namespace std;
const int N = 110;
int q[N];
typedef struct subarray{
    int l;
    int r;
    int sum;
}subarray_info;
subarray_info find_mid(int q[],int l,int mid, int r){
        subarray_info midx;
        int left_sum = INT_MIN;
        int sum=0;
        for(int i=mid;i>=l;i--){
            sum+=q[i];
            if(sum>left_sum){
                left_sum = sum;
                midx.l = i;
            }
        }
        int right_sum = INT_MIN;
        sum = 0;
        for(int j =mid+1;j<=r;j++ ){
            sum+=q[j];
            if(sum>right_sum){
                right_sum = sum;
                midx.r = j;
            }
        }
        midx.sum = left_sum + right_sum;
        return midx;
}
subarray_info find_maxsubarray(int q[], int l,int r){
        subarray_info midx;
        if(l==r){
            midx.l = l;
            midx,r = r;
            midx.sum = q[l];
            return midx;
        }
        int mid = l+r>>1;
        subarray_info midxl = find_maxsubarray(q,l,mid);
        subarray_info midxr = find_maxsubarray(q,mid+1,r);
        subarray_info midxmid = find_mid(q,l,mid,r);
        int t = max(max(midxl.sum,midxr.sum),midxmid.sum);
        if(t==midxl.sum)  return midxl;
        if(t==midxr.sum)  return midxr;
        if(t==midxmid.sum)  return midxmid;

}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)  cin>>q[i];
    subarray_info info =  find_maxsubarray(q,0,n-1);
    for(int i=info.l;i<=info.r;i++)
        cout<<q[i]<<' ';
    cout<<endl<<"sum = "<<info.sum<<endl;
    return 0;
}