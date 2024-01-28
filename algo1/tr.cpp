#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Node{
    public:
        int x;
        int y;
        Node(int xx=0,int yy=0){
            x=xx;
            y=yy;

        }

};

class triangle{
    public:
        Node* ar[3];
        int power;
        triangle(Node*n1=NULL,Node*n2=NULL,Node*n3=NULL,int power=0){
            ar[0]=n1;
            ar[1]=n2;
            ar[2]=n3;
        }
};

int diff(Node* a,Node* b){
    return (a->x)-(b->x)+(a->y)-(b->y);
}
int power(triangle* tri){
    return diff((tri->ar[1]),(tri->ar[0]))+diff(tri->ar[2],tri->ar[0]);

}

int main(){
    int N=0;
    int power_ar[N+1];
    Node* ptr1=new Node;
    Node* ptr2=new Node;
    Node* ptr3=new Node;
    Node* ptr4=new Node;
    Node* ptr5=new Node;
    Node* ptr6=new Node;
    triangle* tr1= new triangle(ptr1,ptr2,ptr3);
    triangle* tr2= new triangle(ptr4,ptr5,ptr6);
    cin>>N;
    for(int i=0;i<3;i++){
        cin>>tr1->ar[i]->x;
        cin>>tr1->ar[i]->y;
    }
    for(int j=0;j<3;j++){
        cin>>tr2->ar[j]->x;
        cin>>tr2->ar[j]->y;
    }
    //cout<<tr2->ar[1]->y;
    power_ar[1]=power(tr1);
    power_ar[2]=power(tr2);
    //cout<<power_ar[1]<<endl;
    //cout<<power_ar[2]<<endl;

    for(int k=3;k<N+1;k++){
        Node* ptr_temp1=new Node;
        Node* ptr_temp2=new Node;
        Node* ptr_temp3=new Node;
        triangle* tr_temp= new triangle(ptr_temp1,ptr_temp2,ptr_temp3);
        if(k==3){
            tr_temp->ar[0]->x=ptr1->x;
            tr_temp->ar[0]->y=ptr1->y;
            tr_temp->ar[1]->x=(ptr2->x)+power_ar[2];
            tr_temp->ar[1]->y=(ptr2->y)+power_ar[2];
            tr_temp->ar[2]->x=(ptr3->x)+power_ar[1];
            tr_temp->ar[2]->y=(ptr3->y)+power_ar[1];
            power_ar[k]=power(tr_temp);
            continue;
        }
        tr_temp->ar[0]->x=ptr1->x;
        tr_temp->ar[0]->y=ptr1->y;
        tr_temp->ar[1]->x=(ptr2->x)+power_ar[k-1];
        tr_temp->ar[1]->y=(ptr2->y)+power_ar[k-1];
        tr_temp->ar[2]->x=(ptr3->x)+power_ar[k-2];
        tr_temp->ar[2]->y=(ptr3->y)+power_ar[k-2];
        power_ar[k]=power(tr_temp);

    }
    
    cout<<power_ar[N];
    return 0;
}