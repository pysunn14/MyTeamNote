#include "../setting/template.h"

/*
    https://ansohxxn.github.io/algorithm/kmp/
*/

vector<int> Fail(string pattern)
{
    int m = pattern.length();
    vector<int> pi(m); // partial match table

    int begin = 1;   // 📌 접두사 역할을 하는 검색어에서 일치하기 시작한 "시작" 포인터
    int matched = 0; // 📌 접미사 역할을 하는 검색어의 일치한 개수이자 포인터
    pi[0] = 0;
    while (begin + matched < m)
    {
        if (pattern[begin + matched] == pattern[matched])
        {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        
        else
        {
            if (matched == 0)
                begin++;
            else
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

vector<int> KMP(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();
    vector<int> pos;
    vector<int> pi = Fail(pattern);

    int begin = 0;
    int matched = 0;
    while (begin + m <= n)
    {
        if (matched < m && text[begin + matched] == pattern[matched])
        {
            matched++;

            if (matched == m)
                pos.push_back(begin);
        }
        else
        {
            if (matched == 0)
                begin++;
            else
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pos;
}