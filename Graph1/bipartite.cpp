//이분 그래프 예제
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>

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


        void add_edge(Edge<T>&& e)
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

    edge_map[1]={{2,0},{5,0}};
    edge_map[2]={{1,0},{5,0},{4,0}};
    edge_map[3]={{4,0},{7,0}};
    edge_map[4]={{2,0},{3,0},{5,0},{6,0},{8,0}};
    edge_map[5]={{1,0},{2,0},{4,0},{8,0}};
    edge_map[6]={{4,0},{7,0},{8,0}};
    edge_map[7]={{3,0},{6,0}};
    edge_map[8]={{4,0},{5,0},{6,0}};

    for(auto& i:edge_map)
        for(auto& j:i.second)
            G.add_edge(Edge<T>{i.first,j.first,j.second});
            
    return G;
}
 
 template<typename T>
 auto bipartite_check(const Graph<T>&G)
 {
    stack<unsigned> stack;
    set<unsigned> visited;
    stack.push(1);

    enum class colors{None,Black,Red};
    colors current_color{colors::Black};
    vector<colors>vertex_colors(G.vertices(),colors::None);

    while(!stack.empty())
    {
        auto current_vertex=stack.top();
        stack.pop();
        if(visited.find(current_vertex)==visited.end())
        {
            visited.insert(current_vertex);
            vertex_colors[current_vertex]=current_color;
            if(current_color==colors::Red){
            cout<<current_vertex<<"번 정점:빨간색"<<endl;
            current_color=colors::Black;
            }
        
        else 
      {
            cout<<current_vertex<<"번 정점: 검은색"<<endl;
            current_color=colors::Red;
        }
        for(auto e: G.edges(current_vertex))
        
            if(visited.find(e.dst)==visited.end())
                stack.push(e.dst);


             }    
            else if(vertex_colors[current_vertex]!=colors::None&&vertex_colors[current_vertex]!=current_color)
                return false;
            
        
    

   
    }       return true;
 }

 int main()
 {
    using T=unsigned ;

    auto G=create_reference_graph<T>();
    cout<<"[입력 그래프]"<<endl;
    cout<<G<<endl;

    if(bipartite_check<T>(G))
    cout<<endl<<"이분 그래프가 맞습니다 "<<endl;

    else 
        cout<<endl<<"이분 그래프가 아닙니다"<<endl;
   
 }