#include<iostream>
#include<vector>

template<typename T>
std::vector<T> merge(std::vector<T>&arr1, std::vector<T>&arr2)
{
    std::vector<T> merged;
    auto itr1=arr1.begin();
    auto itr2=arr2.begin();

    while (itr1!=arr1.end()&&itr2!=arr2.end())
    {
        if(*itr1<*itr2)
        {
            merged.emplace_back(*itr1);
            itr1++;
        }
        else 
        {
            merged.emplace_back(*itr2);
            itr2++;
        }
    }
    if(itr1!=arr1.end())
    {
        for(;itr1!=arr1.end();itr1++){
            merged.emplace_back(*itr1);
        }

    }
    else    
    {
        for(;itr2!=arr2.end();itr2++){
            merged.emplace_back(*itr2);
        }
    }
    return merged;
}

template<typename T>
std::vector<T>merge_sort(std::vector<T> arr){
    if(arr.size()>1)
        {
            auto mid=size_t(arr.size()/2);
            auto left_half=merge_sort<T>(std::vector<T>(arr.begin(),arr.begin()+mid));
            auto right_half=merge_sort<T>(std::vector<T>(arr.begin()+mid,arr.end()));

            return merge<T>(left_half, right_half);
        }
        return arr;

}

template<typename T>
void print(std::vector<T>arr)
{
    for(auto i:arr)
    std::cout<<i<<" ";

    std::cout<<std::endl;
}

void run_marge_sort_test()
{
    std::vector<int> s1{45,1,3,1,2,3,45,5,1,2,44,5,7};
    std::vector<float>s2{45.6f,1.0f,3.8f,1.01f,2.2f,3.9f,45.3f,5.5f,1.0f,2.0f,44.0f,5.0f,7.0f};
    std::vector<double>s3{45.6,1.0,3.8,1.01,2.2,3.9,45.3,5.5,1.0,2.0,44.0,5.0,7.0};
    std::vector<char>c {'b','z','a','e','f','t','q','u','y'};

    std::cout<<"정렬되지 않은 입력 벡터"<<std::endl;

    print(s1);
    print(s2);
    print(s3);
    print(c);

    std::cout<<std::endl;

    auto sorted_s1=merge_sort<int>(s1);
    auto sorted_s2=merge_sort<float>(s2);
    auto sorted_s3=merge_sort<double>(s3);
    auto sorted_c=merge_sort<char>(c);

    std::cout<<"병합정렬에 의해 정렬된 벡터:"<<std::endl;
    print(sorted_s1);
    print(sorted_s2);
    print(sorted_s3);
    print(sorted_c);

    std::cout<<std::endl;

}
int main(){
    run_marge_sort_test();
    return 0;
}