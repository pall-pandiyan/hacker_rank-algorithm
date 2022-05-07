#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the plusMinus function below.
 */
void plusMinus(vector<int> arr) {
    /*
     * Write your code here.
     */
    int pCount = 0;
    int nCount = 0;
    int zCount = 0;
    int arSize = arr.size();
    
    for(int itr=0; itr<arSize; itr++) {
        if (arr[itr]==0) {
            zCount++;
        }
        if (arr[itr]<0) {
            nCount++;
        }
        if (arr[itr]>0) {
            pCount++;
        }
    }
    float p = (float)pCount/arSize;
    float n = (float)nCount/arSize;
    float z = (float)zCount/arSize;
    
    cout << p << endl;
    cout << n << endl;
    cout << z << endl;

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int arr_itr = 0; arr_itr < n; arr_itr++) {
        arr[arr_itr] = stoi(arr_temp[arr_itr]);
    }

    plusMinus(arr);

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
