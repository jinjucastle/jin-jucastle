// 아까 만든 음악 프로그램 원형리스트를 사용해서 만들자 템플릿을 사용하자
#include<iostream>

template<typename T>
struct circle_node{
T*data;
circle_node *next;
circle_node *prev;
~circle_node(){
    delete data;
}
};
template<typename T>
class circle_list{
using node=circle_node<T>;
using node_ptr=node*;

private:
node_ptr head;
size_t v;
public:
circle_list():v(0){
    head= new node{NULL,NULL,NULL};
    head->next=head;
    head->prev=head;
}
size_t size()const {
    return v;
}
void insert(const T& value){
node_ptr newNode=new node{new T(value),NULL,NULL};
v++;
auto dummy=head->prev;
newNode->prev=dummy;
if(dummy==head){
    dummy->prev=newNode;
    newNode->next=dummy;
    head=newNode;
    return ;
}
newNode->next=head;
head->prev=newNode;
head=newNode;
}

void erase(const T& value){
    auto cur=head,dummy=head->prev;
    while(cur!=dummy){
    if(*(cur->data)==value){
        cur->next->prev=cur->prev;
        cur->prev->next=cur->next;

        if(cur==head)
        head=head->next;

        delete cur;
        v--;
        return ;
    }
    cur=cur->next;
    }
}
struct circle_list_ll{
private: 
node_ptr ptr;

public:
circle_list_ll(node_ptr p):ptr(p){}
T& operator*(){
    return *(ptr->data);
}
node_ptr get(){
    return ptr;
}
circle_list_ll operator++(){
    ptr=ptr->next;
    return *this;
}
circle_list_ll operator++(int){
    circle_list_ll result=*this;
    ++(*this);
    return result;
}
circle_list_ll operator--(){
    ptr=ptr->prev;
    return *this;
}
circle_list_ll operator--(int){
    circle_list_ll result=*this;
    --(*this);
    return result;
}
friend bool operator==(const circle_list_ll& left,const circle_list_ll&right){
    return left.ptr==right.ptr;
}
friend bool operator!=(const circle_list_ll&left,const circle_list_ll&right){
    return left.ptr!=right.ptr;
}
};
circle_list_ll begin(){
    return circle_list_ll{head};
}
circle_list_ll begin() const{
    return circle_list_ll{head};
}
circle_list_ll end(){
    return circle_list_ll{head->prev};
}
circle_list_ll end() const{
    return circle_list_ll{head->prev};
}

circle_list(const circle_list<T>& other):circle_list(){
    for(const auto &il:other)
    insert(il);
}
circle_list(const std::initializer_list<T>power):head(NULL),v(0){
    for(const auto &il:power)
    insert(il);
}
~circle_list(){
    while(size()){
        erase(*(head->data));
    }
    delete head;
}
};

struct PlayList{

 circle_list<int>list;

void insert(int a){
    list.insert(a);
}
void erase(int a){
    list.erase(a);
}
void loopList(){
for(auto& il:list)
    std::cout<<il<<" ";
    std::cout<<std::endl;
}
};

int main(){
    PlayList p1;
    p1.insert(1);
    p1.insert(2);
    std::cout<<"재생목록";
    p1.loopList();
    PlayList p12=p1;
    p12.erase(2);
    p12.insert(3);
    std::cout<<"두 번째 재생목록";
    p12.loopList();
}
