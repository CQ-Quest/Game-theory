# Game-theory
# Bash博弈(在一堆石子中取任意个)  
        A,B两个人，n个物品，每个人每次都可以取1 to m个物品，取走最后一个物品的人胜利。问先手A在什么条件下必胜。
        
        解析： Bash博弈先手必败的条件就是n%(m+1)==0,我们来分析一下这个情况。  
              首先假设n=m+1，这个时候无论先手第一次拿多少个，由于剩下的物品数量一定是小于等于m的，所以后手一定可以一次拿完。所以这个时候先
              手必败。如果n是m+1的倍数，其实也很简单的，因为无论先手一次拿多少个物品，后手总是可以做出这样的策略：拿的物品和先手加在一起恰
              好是m+1个，这样若干回合之后哦一定又会回到我们说的第一种情况，先手必败。所以结论得证。
              
             
              int main(){
                int n,m,t;
                cin>>t;
                while(t--){
                  int flag=0;
                  cin>>n>>m;
                  if(n%(m+1)==0) printf("B\n");
                    else printf("A\n");
                }
                return 0;
              }

# Nim博弈(在n堆中的一堆石子中取任意个)
    博弈描述：有任意堆物品，每堆物品的个数是任意的，双方轮流从中取物品，每一次只能从一堆物品中取部分
              或全部物品，最少取一件，取到最后一件物品的人获胜。取完最后一个为胜！
            
            推导：我们假设有三堆物品用(a,b,c)来表示。我们用（a，b，c）表示某种局势，其中a,b,c分别表示当你选择时每一堆剩余的物品数。
                .无论谁面对某种局势时，都必败的话，我们称这种局势为奇异局势。我们先来看奇异局势：
                  ①首先（0，0，0）显然是奇异局势。
                  ②第二种奇异局势是（0，n，n）。因为在这种情况下无论你拿走多少件物品，对方都可以拿走和你一样多的物品，这样你必败
                  ③其次（1，2，3）也是奇异局势。因为无论你怎么拿，对手都可以将它变为（0，n，n）格式。

                  任何奇异局势(a,b,c)都有a xor b xor c =0。该结论可以推广至若干堆，都是成立的。

                  如果我们面对的是一个非奇异局势(a,b,c),要如何变为奇异局势呢？假设a < b< c,我们只要将c 变为a xor b,即可,
                  因为有如下的运算结果: a xor b xor (a xor b)=(a xor a) xor (b xor b)=0 xor 0=0.要将c 变为a xor b,只要从c中减去c-(a xor b)即可.

                  也就是判断a xor b xor c 是否为0，如果为0，则先手必败，否则先手必胜
            
                  
                   int main(){
                      int n,ans,temp;
                      while(cin>>n)
                      {
                          temp=0;
                          for(int i=0;i<n;i++) {
                              cin>>ans;
                              temp^=ans;
                          }
                          if(temp==0)  cout<<"后手必胜"<<endl;
                          else cout<<"先手必胜"<<endl;
                      }
                      return 0;
                   }

# 威佐夫博弈（Wythoff Game）
    有两堆各若干个物品，两个人轮流从任一堆取至少一个或同时从两堆中取同样多的物品，规定每次至少取一个，多者不限，最后取光者得胜。
    
        void swap(int *a,int *b){
                int temp=*a;
                *a=*b;
                *b=temp;
        }
        int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)&&a&&b){
		if(a>b) swap(&a,&b);
		int n=b-a;
		double x=(sqrt(5.0)+1)/2;
		int temp=(int)n*x;
		if(temp==a) puts("0");  //先手必输 
	       else puts("1");
	}
	return 0;
        }
        
# SG函数
    nim游戏的衍生变形，状态转移 AcWing取石子中的规律  最大操作数b=堆数+石子数-1
    例如有一个有向无环图，在set集合{0，1}中，sg(u)为集合不存在的一个最小自然数，即为2
    AcWing 1319移棋子游戏(sg模板)
        #include<bits/stdc++.h>
        using namespace std;
        int n,m,k;  //点，边，棋子个数
        const int N=2020,M=6010;
        int h[N],e[M],ne[M],idx; //邻接表，下标 
        int f[N]; //存储sg函数的值 
        void add(int a,int b){
                e[idx]=b,ne[idx]=h[a],h[a]=idx++;
        } 
        int sg(int u){
                if(f[u]!=-1) return f[u];
                set<int>S;
                for(int i=h[u];i>=0;i=ne[i]){
                        int j=e[i];
                        S.insert(sg(j));
                }
                for(int i=0;; i++)
                if(S.count(i)==0){
                        f[u]=i;
                        break;
                }
                return f[u];
        }
        int main(){
                ios::sync_with_stdio(0);
                cin>>n>>m>>k;
                memset(h,-1,sizeof h);
                memset(f,-1,sizeof f);
                for(int i=0;i<m;i++) {
                        int a,b;
                        cin>>a>>b;
                        add(a,b);
                }
                int ans=0;
                for(int i=0;i<k;i++){
                        int u;cin>>u;
                        ans^=sg(u);
                }
                if(ans) puts("win");
                else puts("lose");
        } 
