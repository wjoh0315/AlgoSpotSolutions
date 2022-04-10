//https://algospot.com/judge/problem/read/BOARDCOVER
#include <iostream>
#include <cstring>
using namespace std;

int h, w;
int gameboard[20][20];
// ㄱ부터 시계 방향으로 회전한 상대 좌표
const int dx[4][3] = { 
    { 0, 1, 1 }, // ㄱ
    { 0, 0, -1 }, // ㄱ 한번 회전
    { 0, 0, 1 }, // ㄱ 두번 회전
    { 1, 0, 0 } // ㄱ 세번 회전
};
const int dy[4][3] = { 
    { 0, 0, -1 }, // ㄱ
    { 0, -1, -1 }, // ㄱ 한번 회전
    { 0, -1, -1 }, // ㄱ 두번 회전
    { 0, 0, -1 } // ㄱ 세번 회전
};

bool isRange(int y, int x)
{
    return y >= 0 && y < h && x >= 0 && x < w;
}

// 블록 놓기/치우기와 가능 여부 (놓기: 1, 치우기: -1)
bool set(int y, int x, int index, int onoff)
{
    bool isCover = true;
    for (int i=0; i < 3; i++)
    {
        int posy = y + -dy[index][i];
        int posx = x + dx[index][i];
        if (!isRange(posy, posx)) 
            isCover = false;
        else if ((gameboard[posy][posx] += onoff) > 1)
            isCover = false;
    }
    return isCover;
}

int combin()
{
    int y, x;
    y = x = -1;
    for (int i=0; i < h; i++)
    {
        for (int j=0; j < w; j++)
        {
            if (!gameboard[i][j])
            {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }
    // 기저 사례 1: 모든 칸이 채워졌다면 경우 1 추가
    if (y == -1) return 1;

    // 4가지 방법 순회하며 블록으로 덮는 경우의 수 계산하기
    int count = 0;
    for (int i=0; i < 4; i++)
    {
        // 블록 놓기
        if (set(y, x, i, 1))
            count += combin();
        // 블록 치우기
        set(y, x, i, -1);
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    string line;
    for (int i=0; i < c; i++)
    {
        cin >> h >> w;
        for (int y=0; y < h; y++)
        {
            cin >> line;
            // 이미 채워져있으면 1, 아니면 0
            for (int x=0; x < w; x++)
                gameboard[y][x] = line.at(x) == '#';
        }
        cout << combin() << '\n';

        /*
        cout << '\n';
        for (int y=0; y < h; y++)
        {
            for (int x=0; x < w; x++)
                cout << (gameboard[y][x] ? '#' : '.');
            cout << '\n';
        }
        */
    }
}