#include<iostream>
#include<algorithm>

struct new_list{
int data;
new_list *next;
};
class new_list_node{
    using node=new_list;
    using node_ptr=node*;
    private:
    node_ptr head;

    public:
    void push_front(int val){
        auto first=new node{val,NULL};
        if(head!=NULL)
        first->next=head;

        head=first;
    }
    void pop_front(){
        auto first=head;
        if(head){
        head=head->next;

        delete first;
        }
    }

    struct new_list_ll{
        private:
        node_ptr ptr;
        public:
        new_list_ll(node_ptr p):ptr(p){}
        int &operator*(){return ptr->data;}
        node_ptr get(){return ptr;}

        new_list_ll& operator++()
        {
        ptr=ptr->next;
        return *this;
        }
        new_list_ll operator++(int)
        {
            new_list_ll result=*this;
            ++(*this);
            return result;
        }
        friend bool operator==(const new_list_ll&left,const new_list_ll&right){
            return left.ptr==right.ptr;
        }
        friend bool operator!=(const new_list_ll&left,const new_list_ll&right){
            return left.ptr!=right.ptr;
        }
    };
    new_list_ll begin(){return new_list_ll(head);}
    new_list_ll end(){return new_list_ll(NULL);}
    new_list_ll begin()const{return new_list_ll(head);}
    new_list_ll end() const{return new_list_ll(NULL);}

    new_list_node()=default;
    new_list_node(const new_list_node& other):head(NULL){
        if(other.head)
        {
            head=new node{0,NULL};
            auto cur=head;
            auto it=other.begin();
            while(true){
                cur->data=*it;
                auto tmp=it;
                ++tmp;
                if(tmp==other.end())
                    break;
                    cur->next=new node{0,NULL};
                    cur=cur->next;
                    it=tmp;
            }
        }
    }
    new_list_node(const std::initializer_list<int>&ilist):head(NULL)
    {
        for(auto it=std::rbegin(ilist);it!=std::rend(ilist);it++)
            push_front(*it);
    }
};
int main(){
    new_list_node sll={1,2,3};
    sll.push_front(0);
    std::cout<<"첫 번째 리스트: ";
    for(auto i:sll)
        std::cout<<i<<" ";
    std::cout<<std::endl;
    auto sll2=sll;
    sll2.push_front(-1);
    std::cout<<" 첫 번째 리스트를 복사한 후, 맨앞에 -1을 추가: ";
    for(auto i:sll2)
        std::cout<<i<<' ';
    std::cout<<std::endl;

    std::cout<<"깊은 복사 후 첫 번째 리스트: ";
    for(auto i :sll)
        std::cout<<i<<' ';
    std::cout<<std::endl;
}