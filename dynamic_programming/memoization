// 메모이제이션(하향식 접근 방법) 으로 피보나치 수열의 n번째 항 구하기
#include <iostream>
#include <vector>

const int UNKNOWN = -1;
const int MAX_SIZE = 100;

std::vector<int> memo(MAX_SIZE, UNKNOWN); // 처음에는 모두 모른다고 가정한다. 

int Fibonacci(int n)
{
    if(n < 2)
        return n;
    if(memo[n] != UNKNOWN) // 만약 구하고 싶은 값을 이미 알고 있는 경우, 캐시를 참고한다. 
        return memo[n];
    int result = Fibonacci(n - 1) + Fibonacci(n - 2);
    memo[n] = result;
    return result;
}
int main()
{
    std::cout << Fibonacci(10);
}
