#include<iostream>
using namespace std;
/*�����ʽ����һ������������N��V���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���
�������� N �У�ÿ���������� vi,wi���ÿո�������ֱ��ʾ�� i ����Ʒ������ͼ�ֵ��*/
/*
�����ʽ
���һ����������ʾ����ֵ��
*/
/*
���ݷ�Χ
0<N,V��1000
0<vi,wi��1000
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

    cout<<endl<<"���ս�Ϊ:"<<f[m]<<endl;
    return 0;
}