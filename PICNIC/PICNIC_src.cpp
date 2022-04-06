#include <iostream>
#include <cstring>
using namespace std;

int n, m;
bool areFriends[10][10];
bool taken[10];

int combin()
{
    int cur = -1;
    for (int i=0; i < n; i++)
    {
        // i번째 학생이 아직 선택되지 않았다면 선택하기
        if (!taken[i])
        {
            cur = i;
            break;
        }
    }
    // 기저 사례: 남은 학생이 없다면 종료
    if (cur == -1) return 1;

    int count = 0;
    for (int i=cur+1; i < n; i++)
    {
        // i번째 학생과 친구이고 아직 선택되지 않았다면 선택하고 카운트, 이 상태에서 다시 재귀 돌려서 남은 경우의 수 구하기
        if (areFriends[cur][i] && !taken[i])
        {
            taken[cur] = taken[i] = true;
            count += combin();
            taken[cur] = taken[i] = false;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    int first, second;
    for (int i=0; i < c; i++)
    {
        memset(areFriends, false, sizeof(areFriends));
        memset(taken, false, sizeof(taken));
        
        cin >> n >> m;
        for (int j=0; j < m; j++)
        {
            cin >> first >> second;
            areFriends[first][second] = areFriends[second][first] = true;
        }
        
        cout << combin() << '\n';
    }
}