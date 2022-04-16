//https://algospot.com/judge/problem/read/FENCE
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> fence;

int maxSize(int begin, int end)
{
    // 기저 사례 1: 너비가 1이라면 종료
    if (begin == end) return fence[begin];
    
    // 두 구간으로 분할
    int mid = (begin + end) / 2;
    int first = maxSize(begin, mid);
    int second = maxSize(mid + 1, end);

    int size = 0;
    // 왼쪽 구간 또는 오른쪽 구간에만 존재하는 직사각형의 넓이
    size = max(first, second);
    
    int low = mid, high = mid + 1;
    int height = min(fence[low], fence[high]);
    size = max(size, height * 2);

    // 가운데부터 시작해 모든 구간을 다 덮을 때까지 확장
    while (low > begin || high < end)
    {
        if (high < end && (low == begin || fence[low - 1] < fence[high + 1]))
        {
            high++;
            height = min(height, fence[high]);
        }
        else
        {
            low--;
            height = min(height, fence[low]);
        }

        size = max(size, height * (high - low + 1));
    }
    return size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n, cur;
    cin >> c;
    for (int i=0; i < c; i++)
    {
        fence.clear();
        cin >> n;
        for (int j=0; j < n; j++)
        {
            cin >> cur;
            fence.push_back(cur);
        }
        cout << maxSize(0, fence.size() - 1) << '\n';
    }
}