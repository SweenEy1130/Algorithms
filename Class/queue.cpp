#define DEFAULT_SIZE
class Queue
{
private:
    int front, tail;
    int *data;
public:
    Queue(){
        data = (int *)malloc(sizeof(int) * DEFAULT_SIZE);
        front = tail = 0;
    }
    ~Queue();
    bool enQueue(int x){
        if (front == (tail+1) % DEFAULT_SIZE)
            return false;
        data[tail] = x;
        tail = (tail + 1) % DEFAULT_SIZE;

        return true;
    }

    bool deQueue(int &x){
        if (isEmpty())
            return false;
        x = data[front];
        front = (front + 1) % DEFAULT_SIZE;
        return true;
    }

    bool isEmpty(){
        return front == tail;
    }
};
