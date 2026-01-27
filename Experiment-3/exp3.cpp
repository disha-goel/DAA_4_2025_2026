//UID: 24BCS10773
//Experiment–3: Stable Attendance Window

#include <iostream>
#include<unordered_map>
using namespace std;
int main() {
    int N;
    cin>>N;
    unordered_map<int,int>mp;
    mp[0]=-1; //base case
    int sum=0;
    int maxLength=0;
    for(int i=0;i<N;i++){
        char ch;
        cin>>ch;
        if(ch=='P'){
           sum++;
        }
        else {
            sum--;
        }
        if(mp.count(sum)){
            int wlength=i-mp[sum];
            maxLength=max(maxLength,wlength);
        }
        else{
            mp[sum]=i;
        }
    }
    cout<<maxLength;
    return 0;
}
/*
Character ch is taken as input.
Present is counted as +1 and Absent as -1.
Calculate the sum.
If sum is same,Present and Absent are equal.
then calculate the window length
and update the maximum length.

EX:
Input:-
5
A A A P P
Output:-
4
*/
