#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the staircase function below.
 */
void staircase(int n) {
    /*
     * Write your code here.
     */
    for(int i=n-1; i>=0; i--) {
        
        for(int j=i; j>0; j--) {
            cout<<" ";    
        }
        for(int k=0; k<(n-i); k++){
            cout<<"#";
        }
        cout<<"\n";
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
