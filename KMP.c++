Knuth-Morris-pratt
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void ComputePrefix(string s, int next[])
{
    int n = s.length();
    int q, k;
    next[0] = 0;
    for (k = 0, q = 1; q < n; ++q)
    {
        while (k > 0 && s[k] != s[q])
        {
            k = next[k];  
        }
        if (s[k] == s[q])
        {
            ++k;
        }
        next[q] = k;
    }
}

void KMPMatcher(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int next[m];
    ComputePrefix(pattern, next);

    for (int i = 0, q = 0; i < n; ++i)
    {
        while (q > 0 && pattern[q] != text[i])
        {
            q = next[q];
        }
        if (pattern[q] == text[i])
        {
            ++q;
        }
        if (q == m)
        {
            cout << "Pattern occurs with shift " << i - m + 1 << endl;
            q = 0;
        }
    }
}
int main()
{
    string s = "abaxabacabaxabad";
    string p = "aba";
    KMPMatcher(s, p);

    return 0;
}
