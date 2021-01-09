//https://programmers.co.kr/learn/courses/30/lessons/43238

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//space complexity : O(N)
//time complexitt: O(nlogn + n + logn) // quick sort + Nloop + logn

/*
n명의 심사자가 주어짐
각 심사관이 심사하는대 걸리는 시간이 vector에 주어짐
*/
long long solution(int n, vector<int> times) {
   
    sort(times.begin(), times.end());
    
   //overflow나서 unsigned써야함
    unsigned long long answer = times[times.size() -1] * n; 
    unsigned long long low = 0;
    unsigned long long high = answer;
    unsigned long long mid =  (low + high)/2;
    unsigned long long pivot = 0;

    // binary search
    // 이분탐색으로 가장 적게걸리는 시간(0)과 가장 오래걸리는 시간(가장느린 심사관 * n) 사이의 최적화값을 찾는다.
    
    while (low <= high)
    {
        //주어진 mid시간동안 n명에 대해 입국심사가 이루어질수 있는지 확인   
        mid =  (low + high)/2;
        pivot = 0;
        
        //mid기준으로 심사가능 사람수 세기
        for (int i = 0; i < times.size(); i++)
        {
            // 한사람 심사에 3분이 걸리면 30분동안 10명 심사가능 => 30/3
            pivot += mid / times[i];
            if (times[i] > mid)
            {
                break;
            }
        }
        
        //low--------mid--------high
        if (pivot >= n)
        {
            high = mid -1;
            if (mid < answer)
            {
                answer = mid;
            }
        }
        else
        {
            low = mid + 1;
        }

    }
    
    return answer;
}
