#include<iostream>
#include<vector>

template<typename T>
auto partition(typename std::vector<T>::iterator begin,typename std::vector<T>::iterator end)
{
    auto pivot_val=*begin;
    auto left_val=begin+1;
    auto right_val=end;

    while(true)
    {
        while (*left_val<=pivot_val&&std::distance(left_val,right_val)>0)
            left_val++;
        
        while (*right_val>pivot_val&&std::distance(left_val,right_val)>0)
            right_val--;

        if(left_val==right_val)
            break;
        else 
            std::iter_swap(left_val,right_val);

    }
        if(pivot_val>*right_val)
            std::iter_swap(begin,right_val);

    return right_val;
}

template<typename T>

void quick_sort(typename std::vector<T>::iterator begin,typename std::vector<T>::iterator last)
{

    if(std::distance(begin,last)>=1)
    {
        auto partition_val=partition<T>(begin,last);

        quick_sort<T>(begin,partition_val-1);

        quick_sort<T>(partition_val,last);

    }
}

template<typename T>
void print_vector(std::vector<T> arr)
{
    for(auto i:arr)
        std::cout<<i<<" ";
    std::cout<<std::endl;

}

void run_quick(){
    std::vector<int> s1{45,1,3,1,2,3,45,5,1,2,44,5,7};
    std::vector<float> s2{45.6f,1.0f,3.8f,1.01f,2.2f,3.9f,45.5f,5.5f,1.0f,2.0f,44.0f,5.0f,7.0f};
    std::vector<double> s3{45.6,1.0,3.8,1.01,2.2,3.9,45.5,5.5,1.0,2.0,44.0,5.0,7.0};
    std::vector<char> s4{'b','z','a','e','f','t','q','u','y'};

    std::cout<<"정렬되지 않은입력 벡터"<<std::endl;
    print_vector<int>(s1);
    print_vector<float>(s2);
    print_vector<double>(s3);
    print_vector<char>(s4);
    std::cout<<std::endl;

    quick_sort<int>(s1.begin(),s1.end()-1);
    quick_sort<float>(s2.begin(),s2.end()-1);
    quick_sort<double>(s3.begin(),s3.end()-1);
    quick_sort<char>(s4.begin(),s4.end()-1);

    std::cout<<" 퀵정렬 수행 후의 벡터: "<<std::endl;
    print_vector<int>(s1);
    print_vector<float>(s2);
    print_vector<double>(s3);
    print_vector<char>(s4);
    std::cout<<std::endl;
}

int main(){
        run_quick();
        return 0;
}

    
