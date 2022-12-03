#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<algorithm>
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
void partial_quick_sort(typename std::vector<T>::iterator begin,typename std::vector<T>::iterator last,size_t k){
     if(std::distance(begin,last)>=1)
     {
        auto partition_iter=partition<T>(begin,last);

        partial_quick_sort<T>(begin,partition_iter-1,k);

if(std::distance(begin,partition_iter)<k)
    partial_quick_sort<T>( partition_iter,last,k);
     }
}

template<typename T>
void print_vector(std::vector<T> arr)
{
    for(auto i:arr)
        std::cout<<i<<" ";
    std::cout<<std::endl;

}

template<typename T>
auto generate_random_vector(T size)
{
    std::vector<T> v;

    std::random_device rd;
    std::mt19937 rand(rd());

    std::uniform_int_distribution<std:: mt19937::result_type>uniform_dist(1,size);

    for(T i=0;i<size; i++)
        v.push_back(uniform_dist(rand));

    return std::move(v);
}

template<typename T>
void test_partial_quicksort(size_t size, size_t k)
{
    auto random_vec= generate_random_vector<T>(size);
    auto random_vec_copy(random_vec);

    std::cout<<"입력 벡터: "<<std::endl;

    print_vector<T>(random_vec);

    auto begin1=std::chrono::steady_clock::now();
    partial_quick_sort<T>(random_vec.begin(),random_vec.end()-1,k);
    auto end1=std::chrono::steady_clock::now();
    auto diff1=std::chrono::duration_cast<std::chrono::microseconds>(end1-begin1);

    std::cout<<std::endl;
    std::cout<<"부분 퀵 정렬 수행 시간: "<<diff1.count()<<"us"<<std::endl;

    std::cout<<"(처음 "<<k<<"개의 원소만) 부분 정렬되 벡터: ";
    print_vector<T>(random_vec);


    auto begin2=std::chrono::steady_clock::now();
    quick_sort<T>(random_vec_copy.begin(),random_vec_copy.end()-1);
    auto end2=std::chrono::steady_clock::now();
    auto diff2=std::chrono::duration_cast<std::chrono::microseconds>(end2-begin2);

    std::cout<<std::endl;
    std::cout<<"전체 퀵 정렬 수행 시간: "<<diff2.count()<<"us"<<std::endl;

    std::cout<<"전체 정렬된 벡터:";
    print_vector<T>(random_vec_copy);

}

int main(){
    test_partial_quicksort<unsigned>(100,10);
    return 0;

}