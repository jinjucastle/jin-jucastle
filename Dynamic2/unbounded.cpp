#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int UnboundKnapsack(int items,int capacity,vector<int>value,vector<int> weight)
{
    vector<int>DP(capacity+1,0);
    for(int w=0;w<=capacity;w++)
    {
        for(int i=1;i<items;i++)
        {
            if(weight[i]<=w)
            {
                DP[w]=max(DP[w],DP[w-weight[i]]+value[i]);
            }
        }
    }
    return DP[capacity];

    }






int main()
{
    int items,capacity;
    cin>>items>>capacity;

    vector<int> value(items),weight(items);
    
    for(auto& v: value)cin>>v;
    for(auto& w: weight)cin>>w;

    int result=UnboundKnapsack(items,capacity,value,weight);
    cout<<"배낭에 채울 수 있는 물건들의 최고 가격"<<result<<endl;
}