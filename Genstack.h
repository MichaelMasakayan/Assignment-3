
#include <iostream>

using namespace std;

template <class T>
//makes Genstack from the genque example from class
class Genstack
{
    public:
    Genstack(); 
    Genstack(int maxSize); 
    ~Genstack(); 
    void insert (char d);
    char remove();
    char peek();
    int pop();
    bool isFull();
    bool isEmpty();
    int getSize();
    private:
    int front; 
    int rear; 
    int mSize;
    int numElements;
    T *myStack;
};
template <class T>
Genstack<T>::Genstack() 
{
    myStack = new char [128];
    mSize = 128;
    front = 0;
    rear = 0;
    numElements = 0;
}
template <class T>
Genstack<T>::Genstack(int maxSize) {
    myStack = new char [maxSize];
    mSize = maxSize;
    front = 0;
    rear = 0;
    numElements = 0;
}
template <class T>
Genstack<T>::~Genstack() {
    delete myStack;
}
template <class T>
void Genstack<T>::insert(char d) {
    // make sure is not full before proceeding
    myStack [rear++] = d;
    rear = (rear) % mSize;
    numElements++;
}
template <class T>
char Genstack<T>::remove() {
    // check if empty before proceeding
    char c = '\0';
    c = myStack [front++];
    front = (front) % mSize;
    --numElements;
return c;
}
template <class T>
char Genstack<T>::peek() {
    return myStack [front];
}
template <class T>
bool Genstack<T>::isFull() {
    return (numElements == mSize);
}
template <class T>
bool Genstack<T>::isEmpty() {
    return (numElements == 0);
}
template <class T>
 int Genstack<T>::getSize() {
    return numElements;
}
template <class T>
 int Genstack<T>::pop() {
    if(!isEmpty())
    {
        front--;
        T t = myStack[front];
        
        return t;
    }
    else
    {
        {
           
            return 0;
        }
    }


    if(!isEmpty())
    front--;
    return myStack[front];
    
}