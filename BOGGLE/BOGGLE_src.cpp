//https://algospot.com/judge/problem/read/BOGGLE
#include <iostream>
#include <cstring>
using namespace std;

//게임판
char gameboard[5][5];
// 단어별 해당 위치의 부분 문자열 탐색 정보 (성공: 1, 실패: 0, 탐색 안함: -1)
int dp[5][5][10];
// 8방향의 상대 x좌표 (위쪽부터 시계 방향으로)
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
// 8방향의 상대 y좌표 (위쪽부터 시계 방향으로)
const int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

// 단어의 개수
int n;
// 단어
string words[10];

bool inRange(int y, int x)
{
    return y >= 0 && y < 5 && x >= 0 && x < 5;
}

bool hasWord(int y, int x, int index, const string& word)
{
    // 기저 사례 1: 범위에서 벗어나면 무조건 실패
    if (!inRange(y, x)) return false;
    // 기저 사례 2: 다음 글자가 아니면 실패
    if (gameboard[y][x] != word.at(index)) return false;
    // 기저 사례 3: 글자가 하나만 남았으면 성공
    if (index + 1 >= word.size()) return true;
    // 기저 사례 4: 해당 위치에서의 탐색이 이미 끝났으면 탐색 결과 반환
    if (dp[y][x][index] != -1) return dp[y][x][index];

    dp[y][x][index] = 0;
    // 8방향 순회하며 탐색
    for (int i=0; i < 8; i++)
    {
        int posy = y + dy[i];
        int posx = x + dx[i];
        // 나머지 문자열을 찾았다면 현재 위치에서의 탐색이 끝났음을 캐싱
        if (hasWord(posy, posx, index + 1, word))
        {
            dp[y][x][index] = 1;
            return true;
        }
    }
    return false;
}

bool findWord(const string& word)
{
    for (int y=0; y < 5; y++)
    {
        for (int x=0; x < 5; x++)
        {
            if (hasWord(y, x, 0, word))
                return true;
        }
    }
    return false;
}

void input()
{
    for (int i=0; i < 5; i++)
    {
        string line;
        cin >> line;

        for (int j=0; j < line.size(); j++)
            gameboard[i][j] = line.at(j);
    }

    cin >> n;
    for (int i=0; i < n; i++)
        cin >> words[i];
}

void output()
{
    for (int i=0; i < n; i++)
    {
        memset(dp, -1, sizeof(dp));
        cout << words[i] << ' ' << (findWord(words[i]) ? "YES" : "NO");
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    for (int i=0; i < c; i++)
    {
        input();
        output();
    }

    /*
    cout << '\n';
    for (int i=0; i < 5; i++)
    {
        for (int j=0; j < 5; j++)
            cout << gameboard[i][j];
        cout << '\n';
    }
    */
}