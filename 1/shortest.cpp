#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
//최단거리 우선 스케줄링(그리디 알고리즘)
template<typename T>
auto computer_waiting_time(std::vector<T>&service_time){
    std::vector<T>w(service_time.size());
    w[0]=0;
    for(int i=1;i<service_time.size();i++)
    {
        w[i]=w[i-1]+service_time[i-1];
    }

    return w;

}
template<typename T>
void print_vector(std::vector<T>&a)
{
    for(auto& i:a)
{
    std::cout.width(2);
    std::cout<<i<<" ";
    
}
    std::cout<<std::endl;
}

template<typename T>
void computer_and_print_wait(std::vector<T>&service_time)
{
    auto waiting_time=computer_waiting_time<int>(service_time);
    std::cout<<"처리 시간 : ";
    print_vector<T>(service_time);
    std::cout<<"대기 시간: ";
    print_vector<T>(waiting_time);

    auto average_time=std::accumulate(waiting_time.begin(),waiting_time.end(),0.0)/waiting_time.size();
    std::cout<<"평균 시간대: "<<average_time;

    std::cout<<std::endl;
}

int main(){
    std::vector<int>service_time{8,1,2,4,9,2,3,5};
    std::cout<<"[처음 일 처리 시간 & 대기 시간]"<<std::endl;
    computer_and_print_wait<int>(service_time);

    std::sort(service_time.begin(),service_time.end());

    std::cout<<std::endl;

    std::cout<<"[정렬후 일 처리 시간 &대기 시간]"<<std::endl;
    computer_and_print_wait<int>(service_time);

}