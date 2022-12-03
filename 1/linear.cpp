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
auto find_median(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator last)
{
    quick_sort<T>(begin,last);
    return begin+(std::distance(begin,last)/2);

}

template<typename T>
auto partition_using_given_pivot(typename std::vector<T>::iterator begin,typename std::vector<T>::iterator end,typename std::vector<T>::iterator pivot)
{
    
    auto left_val=begin;
    auto right_val=end;

    while(true)
    {
        while (*left_val<*pivot&&left_val!=right_val)
            left_val++;
        
        while (*right_val>=*pivot&&left_val!=right_val)
            right_val--;

        if(left_val==right_val)
            break;
        else 
            std::iter_swap(left_val,right_val);

    }
        if(*pivot>*right_val)
            std::iter_swap(pivot,right_val);

    return right_val;
}
template<typename T>
typename std::vector<T>::iterator linear_time_select(typename std::vector<T>::iterator begin,typename std::vector<T>::iterator last,size_t i)
{

    auto size=std::distance(begin,last);
    if(size>0&&i<size)
    {
        auto num_vi=(size+4)/5;
        size_t k=0;
        std::vector<T> v;
        for(;k<size;k++)
        {
            auto b=begin+(k*5);
            auto l=begin+(k*5)+5;

            v.push_back(*find_median<T>(b,l));
        }
        if(k*5<size)
        {   
            auto b= begin+(k*5);
            auto l= begin+(k*5)+(size&5);
            v.push_back(*find_median<T>(b,l));
        }

        auto median_of_medians=(v.size()==1)?v.begin():linear_time_select<T>(v.begin(),v.end()-1,v.size()/2);
        auto partition_iter=partition_using_given_pivot<T>(begin,last,median_of_medians);
        auto a=std::distance(begin,partition_iter)+1;
        if(i==a)
            return partition_iter;
        else if(i<a)
            return linear_time_select<T>(begin,partition_iter-1,i);
        else if(i>a)
            return linear_time_select<T>(partition_iter+1,last,i-a);

    }
    else {
        return begin;
    }
   return last;
}

template<typename T>
std::vector<T>merge(std::vector<T>& arr1, std::vector<T>&arr2)
{
    std::vector<T> merged;
    

    auto iter1=arr1.begin();
    auto iter2=arr2.begin();

    while(iter1!=arr1.end()&&iter2!=arr2.end())
    {
        if(*iter1<*iter2)
        {
            merged.emplace_back(*iter1);
            iter1++;

        }
        else 
            {
                merged.emplace_back(*iter2);
                iter2++;

            }
    }
    if(iter1!=arr1.end())
    {
        for(;iter1!=arr1.end();iter1++)
            merged.emplace_back(*iter1);

    }
    else 
    {
        for(;iter2!=arr2.end();iter2++)
            merged.emplace_back(*iter2);
    }
    return merged;
}

template<typename T>
std::vector<T> merge_sort(std::vector<T> arr)
{
    if(arr.size()>1)
    {
        auto mid=size_t(arr.size()/2);
        auto left_half=merge_sort(std::vector<T>(arr.begin(),arr.begin()+mid));
        auto right_half=merge_sort(std::vector<T>(arr.begin()+mid, arr.end()));

        return merge<T>(left_half,right_half);

    }
    return arr;
}
template<typename T>
void print_vector(std::vector<T> arr)
{
    for(auto i:arr)
        std::cout<<i<<" ";
    std::cout<<std::endl;

}
void run_linear_select()
{
    std::vector<int>s1{45,1,3,1,2,3,45,5,1,2,44,5,7};

    std::cout<<"입력 벡터: "<<std::endl;
    print_vector<int> (s1);

    std::cout<<"정렬된 벡터: "<<std::endl;
    print_vector<int>(merge_sort<int>(s1));

    std::cout<<"3 번째 원소: "<<*linear_time_select<int>(s1.begin(),s1.end()-1,3)<<std::endl;
    std::cout<<"5 번째 원소: "<<*linear_time_select<int>(s1.begin(),s1.end()-1,5)<<std::endl;
    std::cout<<"11 번째 원소: "<<*linear_time_select<int>(s1.begin(),s1.end()-1,11)<<std::endl;

}

int main(){
    run_linear_select();
    return 0;
}
