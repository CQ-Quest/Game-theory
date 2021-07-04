 #include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long a[maxn];
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        long long odd=0,even=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
          if(a[i]&1) odd+=a[i]/2+1;
            else even+=a[i]/2-1;
        }
        if(odd==0) cout<<"Bob"<<endl;
        else if(even==0) cout<<"Alice"<<endl;
        else if(odd>even) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
