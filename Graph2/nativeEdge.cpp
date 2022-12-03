#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct Edge
{
    int src;
    int dst;
    int weight;
};
const int UNKONW=INT_MAX;
vector<int>Bellmanford(vector<Edge> edges, int V,int start )
{
    vector<int> distance(V,UNKONW);
    distance[start]=0;

    for(int i=0;i<V-1;i++)
    {
        for(auto &e:edges)
            {
                if(distance[e.src]==UNKONW)
                    continue;
                
                if(distance[e.dst]>distance[e.src]+e.weight)
                {
                    distance[e.dst]=distance[e.src]+e.weight;
                }
            }

    }

    for(auto&e :edges)
    {
        if(distance[e.src]==UNKONW)
            continue;   

        if(distance[e.dst]>distance[e.src]+e.weight)
        {
            cout<<"음수 가중치 사이클 발견"<<endl;
            return {};
        }
    }
    return distance;
}

int main(){
    int V=5;
    vector<Edge> edges;
    
    vector<vector<int>>edge_map
    {
        {0,1,3},
        {1,3,-8},
        {2,1,3},
        {2,5,5},
        {3,2,3},
        {2,4,2},
        {4,5,-1},
        {5,1,8}
    };
    for(auto &e :edge_map)
    {
        edges.emplace_back(Edge {e[0],e[1],e[2]});
    }
    int start=0;
    vector<int>distance= Bellmanford(edges,V,start);
    if(!distance.empty()){
    cout<<"["<<start<<"번 정점으로부터 최소 거리]"<<endl;
    for(int i=0;i<distance.size();i++)
    {
        if(distance[i]==UNKONW)
            cout<<i<<"번 정점: 방문하지 않음!"<<endl;
        else
            cout<<i<<"번 정: "<<distance[i]<<endl;


        } 
   }
}
