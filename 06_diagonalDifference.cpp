#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the diagonalDifference function below.
 */
int diagonalDifference(vector<vector<int>> a) {
    /*
     * Write your code here.
     */
    int size = a.size();
    int priDia = 0;
    int secDia = 0;
    int result = 0;
    
    int x = size-1;
    for (int i=0; i<size; i++) {
        priDia = priDia + a[i][i];
        secDia = secDia + a[i][x];
        x--;
    }
    
    result = abs(priDia-secDia);
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> a(n);
    for (int a_row_itr = 0; a_row_itr < n; a_row_itr++) {
        a[a_row_itr].resize(n);

        for (int a_column_itr = 0; a_column_itr < n; a_column_itr++) {
            cin >> a[a_row_itr][a_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(a);

    fout << result << "\n";

    fout.close();

    return 0;
}
