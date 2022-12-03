#include<iostream>
#include<algorithm>
#include<unordered_map>

struct URL_Hash{//1. 검색 2. 삽입 3. 삭제
    using tinyURL=std::string;
    using realURL=std::string;
    
    //1. 검색 부분
    private:
    std::unordered_map<tinyURL,realURL> URLData;
    public:

    std::pair<bool,realURL>lookup(const tinyURL& tiny)const
    {
        auto temp=URLData.find(tiny);
        if(temp==URLData.end())
        {
            return std::make_pair(false,std::string());
        }
        else 
            return std::make_pair(true,temp->second);
    }

    bool registerURL(const realURL& real,const tinyURL& tiny)
    {
        auto found=lookup(tiny).first;
        if(found)
            return false;
        
        URLData[tiny]=real;
        return true;

    }

    bool destroy(const tinyURL&tiny)
    {
        auto found=lookup(tiny).first;
        if(found)
        {
            URLData.erase(tiny);        
            return true;
        }
        return false;
    }

    void printURLs()const 
    {
        for(const auto &entry:URLData)
        {
            std::cout<<entry.first<<"->"<<entry.second<<std::endl;

        }

        std::cout<<std::endl;
    }
};

int main(){
    URL_Hash hash;
    if(hash.registerURL("http://www.gilbut.co.kr/book","https://py_dojang"))
    {
        std::cout<<"https://py_dojang등록"<<std::endl;
    }
    else
    {
           std::cout<<"https://py_dojang 등록 실패 "<<std::endl;    
    }

    if(hash.registerURL("http://www.gilbyt.co.kr/bbbb","https://cPdojang"))
    {
        std::cout<<"http://cPdojang등록"<< std::endl;
    }
    else   
            std::cout<<"http://cPdojang등록 실패"<< std::endl;

    auto pvBook=hash.lookup("https://py_dojang");
    if(pvBook.first)
        std::cout<<"https://py_dojang 원본 URL"<<pvBook.second<<std::endl;
    else 
        std::cout<<"https://py_dojang 원본을 찾을수 없습니다 "<<std::endl;
    
    auto cppbook=hash.lookup("https://cPdojang");
    if(cppbook.first)
        std::cout<<"https://cPdojang원본 URL"<<cppbook.second<<std::endl;
    else 
        std::cout<<"https://cPdojang 원본을 찾을 수 없습니다 "<<std::endl;


    if(hash.destroy("https://cPdojang"))
    {
        std::cout<<"cPdojang책 URL 삭제"<<std::endl;   
    }    
    else 
        std::cout<<"cPdojang 책 URL 삭제 실패 "<<std::endl;
    
     auto findbook=hash.lookup("https://cPdojang");
    if(findbook.first)
        std::cout<<"https://cPdojang원본 URL"<<cppbook.second<<std::endl;
    else 
        std::cout<<"https://cPdojang 원본을 찾을 수 없습니다 "<<std::endl;
    std::cout<<"등록된 URL 리스트"<<std::endl;

    hash.printURLs();
}


