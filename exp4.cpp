#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

template <class T>
class MyStack
{
    T data[10000];
    int top;
public:
    MyStack() { top = -1; }
    void push(T x) { data[++top] = x; }
    void pop() { top--; }
};

template <class T>
class MyQueue
{
    T data[10000];
    int front, rear;
public:
    MyQueue() { front = 0; rear = -1; }
    void enqueue(T x) { data[++rear] = x; }
    void dequeue() { front++; }
};

int main()
{
    const int N = 10000;

    auto start = high_resolution_clock::now();
    MyStack<int> s;
    for (int i = 0; i < N; i++) s.push(i);
    for (int i = 0; i < N; i++) s.pop();
    auto end = high_resolution_clock::now();
    cout << "Custom Stack Time: " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    MyQueue<int> q;
    for (int i = 0; i < N; i++) q.enqueue(i);
    for (int i = 0; i < N; i++) q.dequeue();
    end = high_resolution_clock::now();
    cout << "Custom Queue Time: " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;
    return 0;
}