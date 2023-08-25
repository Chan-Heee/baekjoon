#include <iostream>
#include <string>

using namespace std;

int alpha[26];
int main()
{
    string in;
    cin >> in;

    for (int i = 0; i < in.size(); i++)
        alpha[in[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        cout << alpha[i] << " ";
    }
}