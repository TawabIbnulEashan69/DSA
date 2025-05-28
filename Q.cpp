#include<iostream>
using namespace std;

const int q_size = 20;
int queue[q_size];
int frnt=0, rear=0;

void en_queue(int data){
    if(rear==q_size-1){
        cout<<"Queue is full...."<<endl;
    }
    else{
        queue[rear]=data;
        rear++;
    }
}

void de_queue(){
    if(rear==0){
        cout<<"Queue is empty...."<<endl;
    }
    else{
        frnt++;
    }
}

void peek(){
    cout<<"Top element: "<<queue[frnt]<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int data;
        cout<<"Enter element: "<<endl;
        cin>>data;

        en_queue(data);
    }

    cout<<"Queue elements: "<<endl;
    for(int i=frnt; i<rear; i++){
        cout<<queue[i]<<endl;
    }

    de_queue();

    cout<<"Queue after dequeue: "<<endl;
    for(int i=frnt;i<rear;i++){
        cout<<queue[i]<<endl;
    }

    return 0;
}
