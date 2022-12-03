#include<iostream>
#include<algorithm>
#include<vector>

struct node{
    int data;
    int listPosition;
    int dataPosition;

};

std::vector<int>merge(const std::vector<std::vector<int>>&input)
{
    auto comparator=[](const node& left ,const node& right){
        if(left.data==right.data)
        return left.listPosition>right.listPosition;
        return left.data>right.data;
    };
    std::vector<node>heap;
    for(int i=0;i<input.size();i++)//초반 묶음들을 정렬하는 부분`````
    {
        heap.push_back({input[i][0],i,0});//시작값을 저장 하여 벡터에 연결하고
        std::push_heap(heap.begin(),heap.end(),comparator);//push_heap을 통해서 heap으로 변경시킨다.여기는 시작 부분만신경을 쓴다
        
        
        
        
    }
    std::cout<<std::endl;
    std::vector<int>result;
    while(!heap.empty())//추출하는 동시에 저장 하는 부분
    {
        std::pop_heap(heap.begin(),heap.end(),comparator);//가장 큰 값을 뒤로 추출하는 함수
        auto min= heap.back();
        heap.pop_back();
        result.push_back(min.data);
        int nextIndex=min.dataPosition+1;
        std::cout<<nextIndex<<" ";
        if(nextIndex<input[min.listPosition].size())//값이 작으면 실행하는데
        {
        heap.push_back({input[min.listPosition][nextIndex],min.listPosition,nextIndex});//벡터들을 다시 집어 넣고
            std::push_heap(heap.begin(),heap.end(),comparator);//여기서 힙으로 변환 시킨다.
        }
    }
    return result;
}
int main()
{
    std::vector<int>v1={1,3,8,15,105};
    std::vector<int>v2={2,3,10,11,16,20,25};
    std::vector<int>v3={-2,100,1000};
    std::vector<int>v4={-1,0,14,18};
    
    auto result=merge({v1,v2,v3,v4});
    for(auto i:result)
    std::cout<<i<<' ';
    std::cout<<std::endl;
    return 0;
}