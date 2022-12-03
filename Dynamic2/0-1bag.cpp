#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int Knapsack_01(int items,int capacity,vector<int>value,vector<int> weight)
{
    vector<vector<int>>DP(items+1,vector<int>(capacity+1,0));

    for(int i=1;i<=items;i++)
    {  
        int currentWeight=weight[i-1];
        int currentValue=value[i-1];
        for(int totalWeight=1;totalWeight<=capacity;totalWeight++)
        {
            if(totalWeight<currentWeight)
            {
                DP[i][totalWeight]=DP[i-1][totalWeight];
            }
            else 
            {
                DP[i][totalWeight]=max(DP[i-1][totalWeight],DP[i-1][totalWeight-currentWeight]+currentValue);

            }
        }

    }   
    return DP[items][capacity];
}






int main()
{
    int items,capacity;
    cin>>items>>capacity;

    vector<int> value(items),weight(items);
    
    for(auto& v: value)cin>>v;
    for(auto& w: weight)cin>>w;

    int result=Knapsack_01(items,capacity,value,weight);
    cout<<"배낭에 채울 수 있는 물건들의 최고 가격"<<result<<endl;
}