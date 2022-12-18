#include <iostream>
#include <queue>
#include <vector>

struct median
{
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    void insert(int data)
    {
        if(max_heap.size() == 0)
        {
            max_heap.push(data);
            return;
        }
        if(max_heap.size() == min_heap.size())
        {
            if(data <= get())
                max_heap.push(data);
            else
                min_heap.push(data);
            return;
        }
        if(max_heap.size() < min_heap.size())
        {
            if(data > get())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(data);
            }
            else
                max_heap.push(data);
            return;
        }
        if(data < get())
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(data);
        }
        else
            min_heap.push(data);
    }
    double get()
    {
        if(max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top()) / 2.0;
        if(max_heap.size() < min_heap.size())
            min_heap.top();
        return max_heap.top();
    }
};
int main()
{
    median med;
    med.insert(1);
    std::cout << "1 삽입 후 중앙값: " << med.get() << std::endl; 
    med.insert(5);
    std::cout << "5 삽입 후 중앙값: " << med.get() << std::endl; 
    med.insert(2);
    std::cout << "2 삽입 후 중앙값: " << med.get() << std::endl; 
    med.insert(10);
    std::cout << "10 삽입 후 중앙값: " << med.get() << std::endl; 
    med.insert(40);
    std::cout << "40 삽입 후 중앙값: " << med.get() << std::endl; 
    return 0;
}