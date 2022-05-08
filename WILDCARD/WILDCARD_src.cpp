//https://algospot.com/judge/problem/read/WILDCARD
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string wildcard;
string file;
vector<string> names;
int dp[101][101];

bool match(int w, int s)
{
    int &ret = dp[w][s];
    // 기저 사례 처리
    // 이미 탐색이 끝난 경우 탐색 결과 반환
    if (ret != -1) return ret;
    // 패턴이 모두 끝난 경우 남은 문자열이 있는지 여부에 따라 결과 반환
    if (w == wildcard.size()) return ret = s == file.size();

    ret = false;
    if (wildcard[w] == '*')
    {
        // 0글자 대응 혹은 + 1글자 대응
        ret = (w < wildcard.size() && match(w+1, s)) 
            || (s < file.size() && match(w, s+1));
    }
    else if (wildcard[w] == '?' || wildcard[w] == file[s])
    {
        // 다음 패턴, 글자로 넘어가기
        ret = (w < wildcard.size() && s < file.size()) 
            && match(w+1, s+1);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n;
    cin >> c;

    for (int i=0; i < c; i++)
    {
        cin >> wildcard;
        cin >> n;

        names.clear();
        for (int j=0; j < n; j++)
        {
            memset(dp, -1, sizeof(dp));
            cin >> file;
            if (match(0, 0))
                names.push_back(file);
        }
        sort(names.begin(), names.end());
        for (vector<string>::iterator iter = names.begin(); 
                iter != names.end(); iter++)
            cout << *iter << '\n';
    }
}