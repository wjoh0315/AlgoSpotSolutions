#include <iostream>
using namespace std;

int triangle[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    for (int i=0; i < c; i++)
    {
        int n;
        cin >> n;

        for (int j=0; j < n; j++)
        {
            for (int k=0; k < j+1; k++)
                cin >> triangle[j][k];
        }

        for (int j=n-2; j >= 0; j--)
        {
            for (int k=0; k < j+1; k++)
                triangle[j][k] += max(triangle[j+1][k], triangle[j+1][k+1]);
        }

        cout << triangle[0][0] << '\n';
    }

    return 0;
}