#include<bits/stdc++.h>
using namespace std;
int x[100100];
int mic[100100];
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
        for(int j = 0; j < i; j++)
        {
            if(x[j] < x[i])
            {
                mic[i] = max(mic[i],mic[j]+1);
                ans = max(ans,mic[i]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}