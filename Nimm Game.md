# 尼姆博弈(Nimm Game)
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
            
            
            Code:
                  #include <cmath>
                  #include <iostream>
                  using namespace std;
                  int main()
                  {
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
