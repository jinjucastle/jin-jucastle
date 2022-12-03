#include<iostream>

using namespace std;

int main(){

    int f,s;
    int x1,x2,y1,y2,x,y,r;
    
    cin>>f;
    while(f--){
        int enter=0 ,escape=0;
        cin>>x1>>y1>>x2>>y2;
        cin>>s;

        while(s--)
        {
            
            cin>>x>>y>>r;
            ///탈츨 경로
            
                if((x-x1)*(x-x1)+(y-y1)*(y-y1)<r*r)
                    if((x-x2)*(x-x2)+(y-y2)*(y-y2)>r*r)
                    escape++;


            //을어오는 경로
                    if((x-x1)*(x-x1)+(y-y1)*(y-y1)>r*r)
                        if((x-x2)*(x-x2)+(y-y2)*(y-y2)<r*r)
                        enter++;
        }
        cout<<enter+escape<<endl;
    }   
 
}