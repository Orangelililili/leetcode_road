https://kamacoder.com/problempage.php?pid=1179

#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>father=vector<int>(101,0);//比节点数量多

void init(){
    for(int i=1;i<=n;i++){
        father[i]=i;//初始化，father[0]不会使用，不管他
    }
}

int find(int s){
    return father[s]==s ? s:father[s]=find(father[s]);
}

void join(int s,int t){
    //找根节点
    s=find(s);
    t=find(t);
    if(s==t) return ;//无需返回
    father[t]=s;
}



bool isSame(int s,int t){
    s=find(s);
    t=find(t);
    return s==t;
}


int main (){
    int m,s,t,source,destination;
    cin>>n>>m;
    init();

    while(m--){
        cin>>s>>t;
        join(s,t);
    }

    cin>>source>>destination;

    if(isSame(source,destination)){
        cout<<1<<endl;
    }
    else cout<<0<<endl;

}

