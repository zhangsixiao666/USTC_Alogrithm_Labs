#include<iostream>
#include<algorithm>
#include<vector>
//���������ʽͬdp�ⷨ
using namespace std;
const int N = 1010;
double v[N],w[N];  //v��ʾ���  w��ʾ��ֵ/Ȩ��
pair<double,int> w1[N];  //̰���㷨������ÿ��λȨ��
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<double,int>> w1;
    for(int i=0;i<n;i++){ 
        cin>>v[i]>>w[i];
        w1.push_back({w[i]/v[i],i});
    }
    sort(w1.begin(),w1.end(),[](const auto a ,const auto b){
        return a.first>b.first;
    });
    int res=0;
    for(int i=0;i<n;i++){
        if(m>=v[w1[i].second]){
            m-=v[w1[i].second];
            res+=w[w1[i].second];
        }
        cout<<"��ʱ��������Ϊ: "<<m<<" �ܼ�ֵΪ: "<<res<<endl;
    }
    cout<<res<<endl;
    return 0;
}