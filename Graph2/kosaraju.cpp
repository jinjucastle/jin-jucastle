#include<iostream>
#include<stack>
#include<vector>

using namespace std;
void FillStack(int i,vector<bool>&visited, vector<vector<int>>& adj,stack<int>&stack)
{
        visited[i]=true;

        for(auto next: adj[i])
        {
            if(!visited[next])
            {
                FillStack(next,visited,adj,stack);
            }
        }
    stack.push(i);
}

vector<vector<int>>Transpose(int V,vector<vector<int>> adj)
{
    vector<vector<int>> transpose(V);
    for(int i=0;i<V;i++)
    {
        for(auto next: adj[i])
        {
            transpose[next].push_back(i);
        }
    }
    return transpose;
}
void collectConnetedComponents(int node,vector<bool>& visited,vector<vector<int>>&adj,vector<int>& component)
{
    visited[node]=true;
    component.push_back(node);
    for(auto next:adj[node])
    {
        if(!visited[next])
        {
            collectConnetedComponents(next,visited,adj,component);
        }
    }
}
vector<vector<int>>kosaraju(int V, vector<vector<int>> adj)
{
    stack<int> stack;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
    {
            if(!visited[i])
            {
                FillStack(i,visited,adj,stack);

            }
    }
    vector<vector<int>> transpose=Transpose(V,adj);
    fill(visited.begin(),visited.end(),false);

    vector<vector<int>>connetedComponent;
    while(!stack.empty())
    {
        int node=stack.top();
        stack.pop();
        if(!visited[node])
        {
            vector<int>component;
            collectConnetedComponents(node,visited,transpose,component);
            connetedComponent.push_back(component);
        }
    }
    return connetedComponent;
    
}

int main()
{
    int V=9;
    vector<vector<int>> adj{
        {1,3},
        {2,4},
        {3,5},
        {7},
        {2},
        {4,6},
        {7,2},
        {8},
        {3}
    };

    vector<vector<int>>connectedComponent=kosaraju(V,adj);
    cout<<"강한 연결 요소 개수: "<<connectedComponent.size()<<endl;
    for(int i=0;i<connectedComponent.size();i++)
    {
        cout<<"["<<i+1<<"]";
        for(auto node:connectedComponent[i])
            cout<<node<<" ";

            cout<<endl; 
    }
}