#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the aVeryBigSum function below.
 */
long long aVeryBigSum(int n, vector<long> ar) {
    /*
     * Write your code here.
     */
    long long result = 0;
    for (int itr=0; itr<n; itr++) {
        result = result+ar[itr];
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<long> ar(n);

    for (int ar_itr = 0; ar_itr < n; ar_itr++) {
        ar[ar_itr] = stol(ar_temp[ar_itr]);
    }

    long long result = aVeryBigSum(n, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
