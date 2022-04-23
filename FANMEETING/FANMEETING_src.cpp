//https://algospot.com/judge/problem/read/FANMEETING
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void addTo(vector<int>& a, const vector<int>& b, int k)
{
    a.resize(max(a.size(), b.size() + k));
    for (int i=0; i < b.size(); i++)
        a[k + i] += b[i];
}

void subFrom(vector<int>& a, const vector<int>& b)
{
    a.resize(max(a.size(), b.size()) + 1);
    for (int i=0; i < b.size(); i++) 
        a[i] -= b[i];
}

vector<int> multiply(vector<int>& a, const vector<int>& b)
{
    vector<int> c(a.size() + b.size() + 1);
    for (int i=0; i < a.size(); i++)
        for (int j=0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    return c;
}

vector<int> karatsuba(vector<int>& a, vector<int>& b)
{
    if (a.size() < b.size()) return karatsuba(b, a);
    if (a.size() + b.size() == 0) return vector<int>();
    if (a.size() <= 50) return multiply(a, b);

    int half = a.size() / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    // z2 = a1 * b1, z0 = a0 * b0
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    
    // z1 = (a0 + a1) * (b0 + b1) - z0 - z2
    addTo(a0, a1, 0); addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0); subFrom(z1, z2);

    // result = z0 + z1 * 10^half + z2 * 10^(half * 2)
    vector<int> result;
    addTo(result, z0, 0);
    addTo(result, z1, half);
    addTo(result, z2, half + half);
    return result;
}

int hugs(vector<int>& members, vector<int>& fans)
{
    vector<int> ret = karatsuba(members, fans);
    int count = 0;
    for (int i=members.size() - 1; i < fans.size(); i++)
        if (ret[i] == 0)
            count++;
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    string members_in, fans_in;
    for (int i=0; i < c; i++)
    {
        cin >> members_in >> fans_in;
        vector<int> members(members_in.size(), 0);
        vector<int> fans(fans_in.size(), 0);
        for (int j=0; j < members_in.size(); j++)
            members[j] = members_in[j] == 'M';
        for (int j=0; j < fans_in.size(); j++)
            fans[j] = fans_in[fans_in.size() - j - 1] == 'M';
        
        cout << hugs(members, fans) << '\n';
    }
}