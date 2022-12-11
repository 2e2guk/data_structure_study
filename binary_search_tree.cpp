// 이진 검색 트리 구현
//2022.12.11
#include <iostream>
struct node
{
    int data;
    node* left;
    node* right;
};
struct BST
{
    node* root = nullptr;
    node* find(int value)
    {
        return find_impl(root, value);
    }
private:
    node* find_impl(node* current, int value) // 재귀적으로 원소 검색을 수행한다. 
    {
        if(!current)
        {
            std::cout << std::endl;
            return NULL;
        }
        if(current->data == value)
        {
            std::cout << value << " 를(을) 찾았습니다!" << std::endl;
            return current;
        }
        if(current->data > value) // value 값이 현재 노드의 왼쪽에 있는 경우.
        {
            std::cout << current->data << " 에서 왼쪽 서브 트리로 이동 -> ";
            return find_impl(current->left, value);
        }
        // value 값이 현재 노드의 오른쪽에 있는 경우. 
        std::cout << current->data << " 에서 오른쪽 서브 트리로 이동 -> ";
        return find_impl(current->right, value);
    }
public: 
    void insert(int value) // 원소 삽입 함수. 재귀적으로 하위 노드로 이동하면서 삽입 위치의 부모 노드를 찾는다. 
    {
        if(!root) //  루트 노드가 비어 있는 경우, 루트 노드에 값을 추가한다. 
            root = new node{value, NULL, NULL};
        else
            insert_impl(root, value);
    }
private:
    void insert_impl(node* current, int value)
    {
        if(value < current->data) // 왼쪽에 삽입해야 한다. 
        {
            if(!current->left) // 왼쪽 노드에 추가할 수 있는 경우. 
                current->left = new node{value, NULL, NULL};
            else
                insert_impl(current->left, value); 
        }
        else // 오른쪽에 삽입해야 한다.
        {
            if(!current->right) // 오른쪽 노드에 추가할 수 있는 경우
                current->right = new node {value, NULL, NULL};
            else
                insert_impl(current->right, value);
        }
    }
public:
    void in_order() // 중위 순회 함수
    {
        in_order_impl(root);
    }
private:
    void in_order_impl(node* start)
    {
        if(!start)
            return;
        in_order_impl(start->left);
        std::cout << start->data << ", ";
        in_order_impl(start->right);
    }
public:
    node* successor(node* start) // 후손 노드를 찾는 함수. 현재 노드의 오른쪽 서브 트리로 이동한 후, 현재 서브 트리의 가장 왼쪽 원소를 찾는다. 
    {
        auto current = start->right;
        while(current && current->left)
            current = current->left;
        return current;
    }
    void delete_value(int value) // 원소 삭제 함수 구현.
    {
        root = delete_impl(root, value);
    }
private:
    node* delete_impl(node* start, int value)
    {
        if(!start)
            return NULL;
        if(value < start->data)
            start->left = delete_impl(start->left, value);
        else if(value > start->data)
            start->right = delete_impl(start->right, value); // 여기까지, 삭제할 노드를 찾는 과정. 
        else
        {
            if(!start->left) // 자식 노드가 전혀 없거나, 왼쪽 자식 노드만 없는 경우.
            {
                auto tmp = start->right;
                delete start;
                return tmp;
            }
            if(!start->right) // 오른쪽 자식 노드만 없는 경우.
            {
                auto tmp = start->left;
                delete start;
                return tmp;
            }
            // 자식 노드가 둘 다 있는 경우. 
            auto succ_node = successor(start);
            start->data = succ_node->data;
            // 오른쪽 서브 트리에서 후속 노드를 찾아서 삭제한다. 
            start->right = delete_impl(start->right, succ_node->data);
        }
        return start;
    }
};
int main()
{
    BST tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    std::cout << "중위 순회: ";
    tree.in_order(); /// BST의 모든 원소를 오름차순으로 출력한다. 
    std::cout << std::endl;
    tree.delete_value(12);
    std::cout << "12를 삭제한 후 중위 순회: ";
    tree.in_order();
    std::cout << std::endl;
    if(tree.find(12))
        std::cout << "12 발견" << std::endl;
    else
        std::cout << "12 미발견" << std:: endl;
}