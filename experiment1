#include <bits/stdc++.h>
using namespace std;
int ops=0;
int depth=0;
void complexRec(int n) {
   if (n <= 2) {
    ops++;
       return;
   }
   int p = n;
   while (p > 0) { 
      ops++;
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {//T.C=O(n)
           temp[i] = i ^ p;
            ops++;
       }
       p >>= 1;//divide by 2
   }
//O(log n)

   vector<int> small(n);
   for (int i = 0; i < n; i++) { //T.C=O(n)
       small[i] = i * i;
         ops++;
   }
//T.C=O(n)+O(n)=O(n)

   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
         ops++;

   } else {
       reverse(small.begin(), small.end());
         ops++;
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
}
int main(){
    int n=8;
    complexRec(n);
    cout<<"Operations "<<ops<<endl;
    cout<<"Depth is: "<<depth<<endl;
    return 0;
}

//Recurrence relation= 3T(n/2)+ O(logn
//Using master theorem
//T.C=O(n^log(base 2)3)
