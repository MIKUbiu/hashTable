//2022/5/17
#include <bits/stdc++.h>

using namespace std;
const int maxn=8000;
//定义数组中的某个数 ai 如果是特殊的，则满足：在数组中存在一个长度 **大于等于** 2 的连续子序列，其和为 ai 。
//给你一个长度为 n 的数组，问有多少数是特殊的。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(auto &e:a)cin>>e;//引用a，利用e输入
        int lim=*max_element(begin(a),end(a));
        bitset<maxn+1>st;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=a[j];
                if(sum>lim)break;//sum大于a中的元素就没有意义了，因为此时就算存入哈希表也用不上
                if(j-i>=1)st[sum]=1;//表示sum这个数存在，即n项和=1//连续序列长度要大于等于2
            }
        }
        int cnt=0;
        for(auto e:a){
            cnt+=st[e];//e这个数在hash中存在则加一，不存在则加0
        }
        cout<<cnt<<endl;
    }

    return 0;
}
