// 타뷸레이션(상향식 접근 방법) 으로 피보나치 수열의 n번째 해 구하기
#include<iostream>
#include<vector>
#include <time.h>

int Fibonacci(int n)
{   
    std::vector<unsigned long long int> DP(n + 1, 0);
    DP[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2]; // 피보나치 수열의 값들이 DP 배열에 자동적으로 모두 저장된다. 
    }
    return DP[n];
}
int main()
{
    clock_t start, finish;
    double duration;
    start = clock();
    std::cout << Fibonacci(30) << std::endl;
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    std::cout << "코드 실행 시간 = " << duration;
    return 0;
}