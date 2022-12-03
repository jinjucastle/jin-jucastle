#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<limits>

using namespace std;

template<typename T>
struct Edge{
    unsigned src;
    unsigned dst;
    T weight;

};

template<typename T>
class Graph{
    public:
    //n개의 정점으로 구성된 그래프
        Graph(unsigned N): V(N){}
        //정점의 갯수 반환
        auto vertices() const{return V;}
        //전체 에지 리스트 반환
       auto& edges()const {return edge_lists;}
        //정점 v에서 나가는 모든 에지를 반환
        auto edges(unsigned v)const
        {
                vector<Edge<T>>edges_from_v;
                for(auto&e: edge_lists){
                    if(e.src==v)
                        edges_from_v.emplace_back(e);
                }

                return edges_from_v;
        }


        void add_edge(Edge<T>&& e)//우측값 참조
        {
            if(e.src>=1&&e.src<=V&&e.dst>=1&&e.dst<=V)
                edge_lists.emplace_back(e);
                else    
                cerr<<" 에러 : 유효범위를 벗어난 정점"<<endl;
                        
        }

        template<typename U>
        friend ostream& operator<<(ostream& os, const Graph<T>& G);

    private:
        unsigned V;    
        vector<Edge<T>>edge_lists;
};

template<typename U>
ostream& operator<<(ostream& os ,const Graph<U>& G)
{
    
    for(unsigned i=1; i<G.vertices(); i++)
    {
        os<<i<<":\t";
        auto edges=G.edges(i);
        for( auto& e: G.edges(i))
            os<<"{"<<e.dst<<":"<<e.weight<<"},";
    
        os<<endl;
    }
    return os;
    
}
template<typename T>
auto create_reference_graph(){
    Graph<T>G(9);
    map<unsigned, vector<pair<unsigned,T>>>edge_map;

    edge_map[1]={{2,2},{5,3}};
    edge_map[2]={{1,2},{5,5},{4,1}};
    edge_map[3]={{4,2},{7,3}};
    edge_map[4]={{2,1},{3,2},{5,2},{6,4},{8,5}};
    edge_map[5]={{1,3},{2,5},{4,2},{8,3}};
    edge_map[6]={{4,4},{7,4},{8,3}};
    edge_map[7]={{3,3},{6,4}};
    edge_map[8]={{4,5},{5,3},{6,1}};

    for(auto& i:edge_map)
        for(auto& j:i.second)
            G.add_edge(Edge<T>{i.first,j.first,j.second});//i.first는 키값을 의미 
            
    return G;
}
 template<typename T>
 struct Label{
    unsigned ID;
    T distance;

    inline bool operator>(const Label<T>& i)const//비교 연산자 정의 하는 부분
    {
        return this->distance>i.distance;
    }
 };
 
 template<typename T>
 auto dijkstra_shortest_path(const Graph<T>&G, unsigned src,unsigned dst )
 {

    priority_queue<Label<T>,vector<Label<T>>,greater<Label<T>>>heap;//우선순위 큐를 사용하며 마지막 매개변수가 우선순위를 정해준다
    vector<T>distance(G.vertices(),numeric_limits<T>::max());//최대 값을 V개로 초기화 하는 벡터 입니다.

    set<unsigned>visited; //정점을 지났으면 저장하는 공간
    vector<unsigned>parent(G.vertices());//가중치를 비교하기 위해서 정점들의 부모를 저장하고 있는 값

    heap.emplace(Label<T>{src,0});//시작 자점 초기화
    parent[src]=src;//시작 지점의 부모 저장 // 시작지점의 부모= 시작지점

    while(!heap.empty()) // 힙이 비어있지 않을때 작동
    {
            auto current_vertex=heap.top();//현재 지점을 변수에 저장 함
            heap.pop();//힙에서 삭제함

            if(current_vertex.ID==dst)//목적지에 도착을 하면 출력을 함
            {
                cout<<current_vertex.ID<<"번 정점(목적 정점)에 도착"<<endl;
                break;
            }
            if(visited.find(current_vertex.ID)==visited.end())//정점들에 도착을 하면 출력하고작업을 수행
            {
                cout<<current_vertex.ID<<"번 정점에 안착!"<<endl;

                for(auto& e: G.edges(current_vertex.ID))//컨테이너에 저장된 정점을 이용하며
                {
                    auto neighbor=e.dst;//이웃집의 다음 목적지
                    auto new_distance=current_vertex.distance+e.weight;//가중치를 결정한다

                    if(new_distance<distance[neighbor])//기존의 가중치가 새로운 가중치보다 크다면
                    {
                        heap.emplace(Label<T>{neighbor,new_distance});//힙에 근접하고 가중치가 작은 정점과 엣지를 힙에 저장하고
                        distance[neighbor]=new_distance;//엣지 가중치에 거리가 짧은 가중치를 저장함
                        parent[neighbor]=current_vertex.ID;//그리고 부모를 저장하는 곳에 현대 정점을 저장 합니다
                    }
                }
                visited.insert(current_vertex.ID);
            }
    }//아래 부분은 목적 정점에서 시작하며 시작 정점까지 올라가는 부분인것 같다
    vector<unsigned> shortest_path;//짧은 경로 벡터를 선언하고
        auto current_vertex=dst;//목표지점을 저장
        while(current_vertex!=src)//정점과  목표 정점이 같지 않다면 //사이클이 아니라면
        {
            shortest_path.push_back(current_vertex);// path 에 저장 하고 
            current_vertex=parent[current_vertex];//부모를 저장 하는 벡터에  목적 정점을 저장한다.
        }
        shortest_path.push_back(src);//현 점점을 저장하고 끝낸다/
        reverse(shortest_path.begin(),shortest_path.end());//오름차순으로 정렬되어 있으면 내림차순으로 저장을 한다

    return shortest_path;
 }

 int main()
 {
    using T=unsigned ;

    auto G=create_reference_graph<T>();
    cout<<"[입력 그래프]"<<endl;
    cout<<G<<endl;
    
    auto MST=dijkstra_shortest_path<T>(G,1,6);
  cout<<endl<<"[1번과 6번 정점 사이의 최단 경로]"<<endl;
    for(auto v: MST)
    {
        cout<<v<<" ";
    }
    cout<<endl;
 }