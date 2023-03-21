#include<iostream>
using namespace std;
/*输入格式：第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。*/
/*
输出格式
输出一个整数，表示最大价值。
*/
/*
数据范围
0<N,V≤1000
0<vi,wi≤1000
*/
const int N = 1010;
int v[N],w[N];
int f[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
    for(int j=m;j>=v[i];j--)
        f[j] = max(f[j],f[j-v[i]]+w[i]);

    for(int i=0;i<=m;++i)
    cout<<"f["<<i<<"] = "<<f[i]<<" ";

    cout<<endl<<"最终解为:"<<f[m]<<endl;
    return 0;
}