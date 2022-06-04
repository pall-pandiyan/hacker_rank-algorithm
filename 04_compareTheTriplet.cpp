#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the solve function below.
 */
vector<int> solve(vector<string> aList_str, vector<string> bList_str) {
    /*
     * Write your code here.
     */
    int aScore=0;
    int bScore=0;
    for(int itr=0; itr<aList_str.size(); itr++) {
        if(stoi(aList_str[itr])>stoi(bList_str[itr]))
            aScore++;
        if(stoi(bList_str[itr])>stoi(aList_str[itr]))
            bScore++;
    }
    
    vector<int> result {aScore,bScore};
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string alist_temp;
    getline(cin, alist_temp);
    
    string blist_temp;
    getline(cin, blist_temp);
    
    vector<string> aList_str = split_string(alist_temp);
    vector<string> bList_str = split_string(blist_temp);

    vector<int> result = solve(aList_str,bList_str);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];
        fout << " ";
    }

    fout << "\n";

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
