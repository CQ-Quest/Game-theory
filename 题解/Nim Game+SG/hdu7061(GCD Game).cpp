//nim���ģ������鿴��ʯ�Ӷ�������ÿ����Ϊһ��ʯ�ӣ�
//��gcd(ai,x)��֪ÿ��ʯ��Ϊ���������� 
 
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int prime[N],check[N],num[N];
int n,cnt;
void Prime()  
{  
	for(int i = 2; i <=N; i++)  
	{  
		if(!check[i])  
	        prime[++cnt] = i,num[i]=1;  
		for(int j=1;j<=cnt&&i*prime[j]<=N;j++)  
		{  
			check[i*prime[j]] =true;  
            num[i*prime[j]]=num[i]+1;
			if(i%prime[j] == 0)  break;  	
		}  
		}  
}   

int main()
{
    ios::sync_with_stdio(0);
    int t; cin>>t;
    Prime();
    while(t--)
    {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x;cin>>x;
            ans^=num[x];
        }
        if(!ans)puts("Bob");
        else puts("Alice");
    }
    return 0;
}
