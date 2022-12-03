#include<iostream>
#include<queue>

class Job{
int id;
std::string name;
int page;
static int count;
public: 
    Job(const std::string&u, int p):name(u),page(p),id(++count){}

    friend std::ostream& operator<<(std::ostream&os,const Job& j){
        os<<"id: "<<j.id<<", 사용자"<<j.name<<", 페이지수"<<j.page<<"장";
        return os;

    }
};
int Job::count=0;

template<size_t N>
class printer{
std::queue<Job>jobs;
public:
bool addNewJob(const Job& job){
    if(jobs.size()==N)
    {
        std::cout<<"인쇄 대기열에 추가 실패"<<job<<std::endl;
        return false;
    }
    std::cout<<"인쇄 대기열에 추가"<<job<<std::endl;
    jobs.push(job);
    return true;
}
void startPrinting()
{
    while(not jobs.empty())
    {
        std::cout<<"인쇄 중:"<<jobs.front()<<std::endl;
        jobs.pop();
    }
}

};
int main(){
    printer<5>producer;
    Job j1("광희",10);
     Job j2("정다",4);
      Job j3("유미",7);
       Job j4("채원",8);
        Job j5("시원",10);
         Job j6("현수",5);
        
        producer.addNewJob(j1);
        producer.addNewJob(j2);
        producer.addNewJob(j3);
        producer.addNewJob(j4);
        producer.addNewJob(j5);
        producer.addNewJob(j6);
        producer.startPrinting();

        producer.addNewJob(j6);
        producer.startPrinting();

}
