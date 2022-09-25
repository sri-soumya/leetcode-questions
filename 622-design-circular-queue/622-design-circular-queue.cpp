class MyCircularQueue {
public:
    vector<int> q;
    int n;
    int front;
    int rear;
    
    MyCircularQueue(int k) {
        q.reserve(k);
        for(int i=0; i<k; i++) q.push_back(0);
        n = k; front = -1; rear = -1;
    }
    
    bool enQueue(int val) {
        bool result = !isFull();
        if(result) { 
            rear=(rear+1)%n;
            q[rear] = val; 
            if(front==-1) front=rear;
        }
        return result;
    }
    
    bool deQueue() {
        bool result = !isEmpty();
        if(result) {
            if(front==rear) front=rear=-1;
            else front=(front+1)%n;
        }
        return result;
    }
    
    int Front() { return isEmpty() ? -1 : q[front]; }
    
    int Rear() { return isEmpty() ? -1 : q[rear]; }
    
    bool isEmpty() { return front==-1; }
    
    bool isFull() { return (rear+1)%n==front; }
    
};