#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
void lcs(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> L(m + 1, vector<int>(n + 1));;
 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    int index = L[m][n];
    int max = L[m][n];

    string lcs(index, ' ');
    
    int i = m, j = n;

    while (index > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        }
        else {
            if (L[i - 1][j] > L[i][j - 1])
                i--;
            else
                j--;
        }
  }
    cout << "LCS is: " << lcs << endl << "LCS length: " << max << endl;
}
 
int main(int argc, char* argv[])
{
  if(argc < 3) {
    cout << "Please enter 2 strings to compare" << endl;
  } else {
    string s1 = argv[1];
    string s2 = argv[2];
    lcs(s1, s2);
  }
    return 0;
}
