//问题 D: 虎哥看电影1
//题目描述
//虎哥去影城看电影，
//每部电影有开始时间、结束时间和好看度等信息。
//由于看完一部电影后需要换影厅，
//因此下部电影的开始时间必须严格大于上部电影的结束时间才能观看。
//现在虎哥请帮他选择看哪些电影，使所选电影的好看度之和最大。

//输入
//第一行为正整数n(2<=n<=1000)，接下来n行，每行三个整数si,ei,ti(1<=si<ei<=10000, 1<=ti<=10000)，
//分别表示电影的开始时间、结束时间和好看度。

//输出
//输出一个整数，表示所选电影的好看度之和.

//样例输入
//4
//1 3 6
//3 5 8
//8 10 7
//10 12 5

//样例输出
//15

#include<bits/stdc++.h>
using namespace std;
struct node {
    int s,e,t;
}a[1005];
int dp[1005]={0},ans=0,n;
int cmp(node b,node c){
    return b.e<c.e;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].e>>a[i].t;
    }
    sort(a+1,a+n+1,cmp);		//按照结束时间从小到大排序
    for(int i=1;i<=n;i++){
        dp[i]=a[i].t;			//dp[i]表示前i个电影最大的好看度之和
        for (int j=1;j<i;j++){
            if (a[i].s>a[j].e && dp[i]<dp[j]+a[i].t){	//如果这个电影的开始时间大于前一个电影的结束时间，就累加
                dp[i]=dp[j]+a[i].t;
            }
        }
        if (dp[i]>ans) ans=dp[i];
    }
    cout<<ans<<endl;
    return 0;
}