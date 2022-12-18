// 그래프 구현. 인접 리스트 이용. 
#include <iostream>
#include <algorithm>
#include <vector>

enum class city : int
{
    MOSCOW,
    LONDON,
    SEOUL,
    SEATTLE,
    DUBAI,
    SYDNEY
};
std::ostream& operator<<(std::ostream& os, const city c) // city enum 에 대해서 << 연산자 정의
{
    switch(c)
    {
    case city::MOSCOW:
        os << "모스크바";
        return os;
    case city::LONDON:
        os << "런던";
        return os;
   case city::SEOUL:
        os << "서울";
        return os;
    case city::SEATTLE:
        os << "시애틀";
        return os;
    case city::DUBAI:
        os << "두바이";
        return os;
    case city::SYDNEY:
        os << "시드니";
        return os;
    default:
        return os;
    }
}
struct graph
{
    std::vector<std::vector<std::pair<int, int>>> data;
    graph(int n)
    {
        data = std::vector<std::vector<std::pair<int, int>>>(n, std::vector<std::pair<int, int>>()); // 비어 있는 그래프(인접 리스트) 생성. 
        // 각각 총 n개의 정점에는 비어 있는 pair로 초기화된 vector 가 들어간다. 
    }
    void add_edge(const city c1, const city c2, int dis)
    {
        std::cout << "에지 추가: " << c1 << "-" << c2 << " = " << dis << std::endl;
        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);
        data[n1].push_back({n2, dis}); // n1과 연결된, n2 추가. (pair로 {n2, dis} 값을 추가한다.)
        data[n2].push_back({n1, dis}); // n2와 연결된, n1 추가. (pair로 {n1, dis} 값을 추가한다.)
    } 
    void remove_edge(const city c1, const city c2)
    {
        std::cout << "에지 삭제: " << c1 << "-" << c2 << std::endl;
        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);
        // n1과 연결된 n2, 곧 {n2, dis} pair 를 삭제한다. 
        std::remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair){return pair.first == n2;});
        std::remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair){return pair.first == n1;});
    }
};
int main()
{
    graph g(6);
    g.add_edge(city::LONDON, city::MOSCOW, 2500);
    g.add_edge(city::LONDON, city::SEOUL, 9000);
    g.add_edge(city::LONDON, city::DUBAI, 5500);
    g.add_edge(city::SEOUL, city::MOSCOW, 6600);
    g.add_edge(city::SEOUL, city::DUBAI, 7000);
    g.add_edge(city::SEOUL, city::SYDNEY, 8000);
    g.add_edge(city::SEOUL, city::SEATTLE, 8000);
    g.add_edge(city::SEATTLE, city::MOSCOW, 8400);
    g.add_edge(city::SEATTLE, city::SYDNEY, 12000);
    g.add_edge(city::DUBAI, city::SYDNEY, 8000);
    
    g.add_edge(city::SEATTLE, city::MOSCOW, 12400);
    g.remove_edge(city::SEATTLE, city::MOSCOW);
    return 0;
}