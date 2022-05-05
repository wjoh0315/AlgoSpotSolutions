//https://algospot.com/judge/problem/read/JUMPGAME
#include <iostream>
#include <cstring>
using namespace std;

int n;
int gameboard[100][100];
int dp[100][100];

bool jump(int y, int x)
{
    // 기저 사례 1: 범위를 벗어난 경우 실패
    if (y >= n || x >= n) return false;
    // 기저 사례 2: 목표에 도달한 경우 성공
    if (y + x >= 2 * n - 2) return true;
    // 기저 사례 3: 이미 탐색했던 칸이라면 탐색 결과 반환
    if (dp[y][x] != -1) return dp[y][x];

    int jumpSize = gameboard[y][x];
    dp[y][x] = jump(y + jumpSize, x) || jump(y, x + jumpSize);
    return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    for (int i=0; i < c; i++)
    {
        cin >> n;
        memset(gameboard, 0, sizeof(gameboard));
        memset(dp, -1, sizeof(dp));
        for (int j=0; j < n; j++)
        {
            for (int k=0; k < n; k++)
                cin >> gameboard[j][k];
        }
        cout << (jump(0, 0) ? "YES" : "NO") << '\n';
    }
}