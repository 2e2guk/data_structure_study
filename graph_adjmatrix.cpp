//그래프 구현. 인접 행렬 이용
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
    std::vector<std::vector<int>> data; // 그래프를 표현할 인접 행렬 data
    graph(int n) // 실제 데이터를 저장할 graph 구조체. 비어 있는 그래프를 생성한다.
    {
        data.reserve(n);
        std::vector<int> row(n);
        std::fill(row.begin(), row.end(), -1);
        for(int i = 0; i < n; i++)
        {
            data.push_back(row);
        }
    }
    void add_edge(const city c1, const city c2, int dis) // 에지를 추가하는 함수. 
    {
        std::cout << "에지 추가: " << c1 << "-" << c2 << " = " << dis << std::endl;
        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);
        data[n1][n2] = dis; // 인접 행렬의 [n1,n2], [n2, n1] index를 dis값으로 초기화한다. 
        data[n2][n1] = dis;
    }
    void remove_edge(const city c1, const city c2)
    {
        std::cout << "에지 삭제: " << c1 << "-" << c2 << std::endl;
        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);
        data[n1][n2] = -1; // add_edge 함수에서 추가했던 dis값을, 다시 초기 상태인 -1로 바꾼다. 
        data[n2][n1] = -1;
        
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
    
    g.add_edge(city::SEATTLE, city::LONDON, 8000);
    g.remove_edge(city::SEATTLE, city::LONDON);
    return 0;
}