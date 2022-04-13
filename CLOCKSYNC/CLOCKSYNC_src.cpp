//https://algospot.com/judge/problem/read/CLOCKSYNC
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 100000

int clocks[16];
vector<int> switches[10] = {
    vector<int>({ 0, 1, 2 }),
    vector<int>({ 3, 7, 9, 11 }),
    vector<int>({ 4, 10, 14, 15 }),
    vector<int>({ 0, 4, 5, 6, 7 }),
    vector<int>({ 6, 7, 8, 10, 12 }),
    vector<int>({ 0, 2, 14, 15 }),
    vector<int>({ 3, 14, 15 }),
    vector<int>({ 4, 5, 7, 14, 15 }),
    vector<int>({ 1, 2, 3, 4, 5 }),
    vector<int>({ 3, 4, 5, 9, 13 })
};

bool isComplete()
{
    for (int i=0; i < 16; i++)
    {
        if (clocks[i] != 12)
            return false;
    }
    return true;
}

void push(int index)
{
    for (vector<int>::iterator iter = switches[index].begin(); 
        iter != switches[index].end(); iter++)
    {
        clocks[*iter] += 3;
        if (clocks[*iter] == 15)
            clocks[*iter] = 3;
    }
}

int minSwitch(int index)
{
    // 기저 사례 1: 시계가 모두 12시를 가리키고 있다면 모두 12시를 가리키는지 확인하고 종료
    if (index >= 10) return isComplete() ? 0 : INF;

    int minCount = INF;
    // 각 버튼을 0 ~ 3번 눌러보기
    for (int i=0; i < 4; i++)
    {
        minCount = min(minCount, i + minSwitch(index + 1));
        push(index);
    }
    return minCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    int result;
    for (int i=0; i < c; i++)
    {
        for (int j=0; j < 16; j++)
            cin >> clocks[j];
        result = minSwitch(0);
        result = result == INF ? -1 : result;
        cout << result << '\n';
    }
}