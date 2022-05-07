#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    string hour = s.substr(0,2);
    string mins = s.substr(3,2);
    string secs = s.substr(6,2);
    string ap = s.substr(8,2);

    if ( ap == "AM") {
        if (hour == "12") {
            hour = "00";
        }
    }
    else {
        if (hour != "12") {
            int temp = stoi(hour);
            temp = temp +12;
            hour = to_string(temp);
        }
    }

    string result = hour+":"+mins+":"+secs;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
