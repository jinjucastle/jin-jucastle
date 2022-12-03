#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>

void transform_test(std::vector<int> s)
{
    std::vector<int>tr;
    std::cout<<"[맵 테스트]"<<std::endl;
    std::cout<<"입력 배열, s: ";
    for(auto i:s)
        std::cout<<i<<" ";
    std::cout<<std::endl;

    std::transform(s.begin(),s.end(),std::back_inserter(tr),[](int x){return std::pow(x,2.0);});

    std::cout<<"std::transform(),tr: ";
    for(auto i:tr)
        std::cout<<i<<" ";
    std::cout<<std::endl;

    std::for_each(s.begin(),s.end(),[](int& x){x=std::pow(x,2.0);});
    std::cout<<"std::for_each(), s: ";
    for(auto i:s)
        std::cout<< i<<" ";
        std::cout<<std::endl; 
    
}
void reduce_test(std::vector<int> s)
{
    std::cout<<std::endl<<"[리듀스 테스트]"<<std::endl;
    std::cout<<"입력 배열, s: ";
    for(auto i:s)
        std::cout<<i<<" ";
    std::cout<<std::endl;

    auto ans= std::accumulate(s.begin(),s.end(),0,[](int acc,int x){return acc+x;});
    std::cout<<"std::accumulate(),ans: "<<ans<<std::endl;

}

int main()
{
    std::vector<int> s {1,10,4,7,3,5,6,9,8,2};

    transform_test(s);
    reduce_test(s);
}