#include<bits/stdc++.h>
using namespace std;
int x[100100];
int lis[100100];
vector<int> vlis[100100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int ind = lower_bound(lis,lis+ans,x[i])-lis;
        lis[ind] = x[i];
        vlis[ind].push_back(x[i]);
        if(ind == ans) ans++;
    }
    cout<<ans<<endl;//length of LIS
    //after this you can print the LIS sequence
    stack<int> st;
    int now = 1e9;
    for(int i = ans-1; i >= 0; i--)
    {
        for(int j = 0; j < vlis[i].size(); j++)
        {
            if(vlis[i][j] < now)
            {
                st.push(vlis[i][j]);
                break;
            }
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}