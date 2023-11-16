//Implementing Queue using arrays

#include "iostream"
using namespace std;

class queue{
    int front, rear, capacity;
    int *Queue;
    public:
    queue(int c){
        front = 0;
        rear = -1;
        capacity = c;
        Queue = new int[capacity];
    }
    bool isEmpty();
    int elements();
    void insert(int);
    void remove();
    int rear_queue();
    int front_queue();
    void show();
};

//Function for checking if the queue is empty.
bool queue::isEmpty(){
   return rear == -1 ? true : false;
}

//Function for elements count.
int queue::elements(){
    return rear+1;
}

//Function for enqueue.
void queue::insert(int data){
    if(rear == capacity -1){
        cout<<"Overflow!: Queue is full."<<endl;
        return;
    }
    rear++;
    Queue[rear] = data;
    cout<<data<<" inserted in Queue."<<endl;
}

//Function for dequeue.
void queue::remove(){
    if(rear == -1){
        cout<<"Underflow!: Queue is empty."<<endl;
        return;
    }
    int front_item = Queue[0];
    for(int i=0; i< rear; i++){
        Queue[i] = Queue[i+1];
    }
    rear--;
    cout<<front_item<<" removed from Queue."<<endl;
}

//Front element.
int queue::front_queue(){
    if(rear == -1){
        cout<<"Queue is empty."<<endl;
        return 0;
    }
    return Queue[front];
}

//Rear element.
int queue::rear_queue(){
    if(rear == -1){
        cout<<"Queue is empty."<<endl;
        return 0;
    }
    return Queue[rear];
}

//Traversing.
void queue::show(){
    if(rear == -1){
        cout<<"Queue is empty."<<endl;
        return;
    }
    cout<<"Queue: [";
    for(int i=0; i<=rear; i++){
        cout<<Queue[i]<<",";
    }
    cout<<"\b]"<<endl;
}

int main(){
    queue myQueue = queue(10);
    myQueue.insert(5);
    myQueue.insert(7);
    myQueue.insert(9);
    myQueue.insert(11);
    cout<<endl;
    myQueue.show();
    cout<<endl<<"Front: "<<myQueue.front_queue()<<endl;
    cout<<endl<<"Rear: "<<myQueue.rear_queue()<<endl;
    cout<<endl<<"Elements: "<<myQueue.elements()<<endl;
    cout<<endl;
    myQueue.remove();
    cout<<endl;
    myQueue.show();
    cout<<endl<<"Elements: "<<myQueue.elements()<<endl;
    return 0;
}
