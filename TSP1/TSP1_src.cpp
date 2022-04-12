//https://algospot.com/judge/problem/read/TSP1
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
double dist[8][8];
bool visited[8];

double shortestPath(int start, int count, double curDist)
{
    // 기저 사례 1: 모든 정점을 순회했다면 종료
    if (count >= n) return curDist;

    double newPath;
    double shortest = numeric_limits<double>::max();
    for (int i=0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            newPath = shortestPath(i, count + 1, curDist + dist[start][i]);
            shortest = min(shortest, newPath);
            visited[i] = false;
        }
    }
    return shortest;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << fixed;
    cout.precision(10);

    int c;
    cin >> c;

    double shortest;
    for (int i=0; i < c; i++)
    {
        shortest = numeric_limits<double>::max();
        
        cin >> n;
        for (int j=0; j < n; j++)
        {
            for (int k=0; k < n; k++)
                cin >> dist[j][k];
        }
        for (int j=0; j < n; j++)
        {
            memset(visited, false, sizeof(visited));
            visited[j] = true;
            shortest = min(shortest, shortestPath(j, 1, 0));
        }

        cout << shortest << '\n';
    }
}