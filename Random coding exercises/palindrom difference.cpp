//To do this exercise,  follows two rules:
//
//You can only reduce the value of a letter by , i.e. he can change d to c, but he cannot change c to d or d to b.
//The letter a may not be reduced any further.
//Each reduction in the value of any letter is counted as a single operation. Find the minimum number of operations required to convert a given string into a palindrome.
//
//Input Format
//
//The first line contains an integer q, the number of queries.
//The next q lines will each contain a string s.
//
//Constraints
//
//
//All characters are lower case English letters, no spaces.
//
//Output Format
//
//A single line containing the number of minimum operations corresponding to each test case.
//
//Sample Input
//
//4
//abc
//abcba
//abcd
//cba
//Sample Output
//
//2
//0
//4
//2
//Explanation
//
//For the first test case, abc -> abb -> aba.
//For the second test case, abcba is already a palindromic string.
//For the third test case, abcd -> abcc -> abcb -> abca = abca -> abba.
//For the fourth test case, cba -> bba -> aba.
//
#include <iostream>
using namespace std;


int main() {
    int q ;
    cin>>q ;
    while(q--){
        string s ;
        cin>>s ;
        int i = 0  ;
        int j = s.length() - 1 ;
        int difference = 0 ;
        while(i <= j )
        {
            difference+=abs(s[i]-s[j]); // calculate the ascii difference of the characters
            // cout<<s1[i]<<" "<<s1[j]<<" " <<ans <<endl;
            i++;
            j--;
            
        }
        cout<<difference<<"\n" ;
    }
    return 0;
}
