// 전위, 중위, 후위, 레벨 순서 순회 구현. + 이진 트리 구현
// 2022. 12. 11
#include <iostream>
#include <queue>
struct node // node  구조체. data를 담는 부분과, 이진 트리이므로 두 개의 자식 노드를 갖는다고 가정한다. 
{
    std::string data; // std::stirng 으로 선언함으로써, 숫자도 문자열처럼 처리할 수 있다. 
    node* first;
    node* second;
};
struct org_tree
{
    node* root;
    static org_tree create_org_structure(const auto& data) // 새로운 트리를 만드는 정적 함수. 루트 노드만 설정하고, 자식 노드는 모두 NULL로 초기화한다. 
    {
        org_tree tree;
        tree.root = new node{data, NULL, NULL};
        return tree;
    }
    static node* find(node* root, const auto& value) // 특정 노드를 찾아서 반환하는 함수. value 값을 갖고 있는 노드를 찾고 싶다. 
    {
        if(root == NULL)
            return NULL;
        if(root->data == value) // root node의 data 저장부에 찾고자 하는 값이 있는 경우. 
            return root; 
        
        auto firstfound = org_tree::find(root->first, value); // root node에 찾고자 하는 값이 없는 경우. 재귀적으로 왼쪽 서브 트리를 먼저 찾도록 시도한다. 
        if(firstfound != NULL)
            return firstfound;
        return org_tree::find(root->second, value); // root node, 왼쪽 서브 트리에도 모두 없는 경우, 오른쪽 서브 트리에서 찾기를 시도한다. 
    }
    bool add_node(const auto& parent, const auto& child) // node 를 추가하는 함수.먼저 root node의 왼쪽에 추가하고,추가할 수 없는 경우,오른쪽에 추가한다. 
    {
        auto parent_node = org_tree::find(root, parent);

        if(!parent_node)
        {
            std::cout << "parent node 검색 실패" << std::endl;
            return false;
        }
        if(parent_node->first && parent_node->second) // 두 자식 노드가 모두 차 있는 경우. 추가 불가능
        {
            std::cout << "node 추가 불가능. 이미 두 자식 node가 모두 존재합니다." << std::endl;
            return false;
        }
        if(!parent_node->first) // 첫 번째 노드가 비어 있는 경우. 첫 번째 자식 노드에 추가한다. 
        {
            parent_node->first = new node{child, NULL, NULL};
        }
        else // 첫 번째 노드가 차 있는 경우, 두 번째 자식 노드에 추가한다. 
            parent_node->second = new node{child, NULL, NULL};
        std::cout << parent << " 아래에 " << child << " 를(을) 성공적으로 추가했습니다." << std::endl;
        return true;
    }
    // 전위, 중위, 후위, 레벨 순서 순회 구현
    static void pre_order(node* start) // 전위 순회
    {
        if(!start)
            return;
        std::cout << start->data << ", ";
        pre_order(start->first);
        pre_order(start->second);
    }
    static void in_order(node* start) // 중위 순회
    {
        if(!start)
            return;
        pre_order(start->first);
        std::cout << start->data << ", ";
        pre_order(start->second);
    }
    static void post_order(node* start) // 후위 순회
    {
        if(!start)
            return;
        pre_order(start->first);
        pre_order(start->second);
        std::cout << start->data << ", ";
    }
    static void level_order(node* start) // 레벨 순서 순회. 
    {
        if(!start)
            return;
        std::queue<node*> q;
        q.push(start);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++) // 먼저 root node 방문 후, 자식 node 방문. 자식 node 방문 시 해당 node의 자식 node를 모두 큐에 추가. 
            {
                auto current = q.front();
                q.pop();
                std::cout << current->data << ", "; // 현재 레벨의 node를 방문할 때, 다음 레벨의 node를 모두 큐에 추가한다.  
                if(current->first)
                    q.push(current->first);
                if(current->second)
                    q.push(current->second);  
            }
            std::cout << std::endl;
        }
    }
    
};
int main()
{
    auto tree = org_tree::create_org_structure("대대본부 중대장");  /// root node의 값이 "본부중대장" 인 새로운 트리 생성. 

    // 자식 노드 추가
    tree.add_node("대대본부 중대장", "행정보급관");
    tree.add_node("행정보급관", "고려생활관");
    tree.add_node("행정보급관", "발해생활관");
    tree.add_node("행정보급관", "백제생활관"); // 추가 불가능한 경우. 
    tree.add_node("백제생활관", "상병 문석호"); // 추가 불가능한 경우.
    tree.add_node("고려생활관", "일병 이강욱");
    tree.add_node("고려생활관", "일병 임시현");
    tree.add_node("발해생활관", "일병 정민영");
    tree.add_node("발해생활관", "일병 조주안");
    std::cout << std::endl;
    std::cout << "전위 순회: " << std::endl;
    org_tree::pre_order(tree.root);
    std::cout << std::endl;
    std::cout << "중위 순회: " << std::endl;
    org_tree::in_order(tree.root);
    std::cout << std::endl;
    std::cout << "후위 순회: " << std::endl;
    org_tree::post_order(tree.root);
    std::cout << std::endl;
    std::cout << "레벨 순서 순회: " << std::endl;
    org_tree::level_order(tree.root);


}
