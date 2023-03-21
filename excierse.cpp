// #include<iostream>
// #include<fstream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<vector<int>> datas;
//     ifstream ifs("Test.dat");
//     int m,n;
//     ifs>>m>>n;
//     int i,j;
//     for(i=0;i<m;i++){
//         vector<int> V;
//         for(j=0;j<n;j++){
//             int x;
//             ifs>>x;
//             V.push_back(x);
//         }
//         datas.push_back(V);
//     }
//     for(i=0;i<m;i++){
//         for(j=0;j<n;j++) cout<<datas[i][j]<<' ';
//         cout<<endl;
//     }
//     return 0;
// }
// #include<iostream>
// using namespace std;
// class CAT{
// public: CAT(){itsAge = new int; *itsAge=5;}
//     ~CAT(){ delete itsAge; itsAge=NULL; }
//     int GetAge(){ return *itsAge;}
//     void SetAge(int age) {  *itsAge = age;}

// protected:
//     int *itsAge;
// };
// int main(){
//     CAT a;
//     cout<<"a's age :"<<a.GetAge()<<endl;
//     a.SetAge(6);
//     CAT b(a);
//     cout<<"a's age :"<<a.GetAge()<<endl;
//     cout<<"b's age :"<<b.GetAge()<<endl;
//     a.SetAge(7);
//     cout<<"a's age :"<<a.GetAge()<<endl;
//     cout<<"b's age :"<<b.GetAge()<<endl;
//     return 0;
// }
#include<iostream>
using namespace std;
class sz{
    int intT1;
public:
    sz() {intT1=5;}
    void Set1(int t) { intT1 = t;}
    int Get1() { return intT1;}
};
class sz2{private:
    sz *mszT;
    sz *mszT2;
public: sz2() { mszT = new sz();mszT2=new sz();}
    sz *f1(){ mszT2=new sz();mszT2->Set1(1);return mszT2;}
    sz *f2() const { return mszT;}
    const sz *f3() {return mszT;}

 
};
int main(){
    sz t;sz2 f;
    sz *s1 = f.f1();
    cout<<s1->Get1()<<endl;  // 1  f1 mszt2
    s1->Set1(10);
    cout<<s1->Get1()<<endl; // 10  f1 mszt2
    s1 = f.f2();
    cout<<s1->Get1()<<endl; // 5   f2 mszt
    s1->Set1(20);
    cout<<s1->Get1()<<endl; // 20  f2 mszt
    const sz *s2=f.f3();
    t = *s2;
    cout<<t.Get1()<<endl;  //  20 sz2 mszt
    s2 = f.f1();
    t = *s2;
    cout<<t.Get1()<<endl;  //  1 new mszt2
    sz *const s3=f.f1();
    t = *s3;
    cout<<t.Get1()<<endl;  // 1
    s3->Set1(30);   
    cout<<s3->Get1()<<endl;  //出错？ 30 ？
    return 0;
}