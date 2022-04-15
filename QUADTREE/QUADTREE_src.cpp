//https://algospot.com/judge/problem/read/QUADTREE
#include <iostream>
using namespace std;

string reverse(string::iterator& iter)
{
    iter++;
    // 기저 사례 1: 더 분할하지 못한다면 그대로 반환
    if (*iter == 'w' || *iter == 'b')
        return string(1, *iter);

    // 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래
    string quad[4];
    for (int i=0; i < 4; i++)
        quad[i] = reverse(iter);
    return string("x") + quad[2] + quad[3] + quad[0] + quad[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
     
    string quadtree;
    string::iterator iter;
    for (int i=0; i < c; i++)
    {
        cin >> quadtree;
        iter = quadtree.begin();
        iter--;
        cout << reverse(iter) << '\n';
    }
}