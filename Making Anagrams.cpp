//  Created by Macbook on 2018-04-18.
//  Sam Ganjian.
//
//We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency. For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.
//
//Alice is taking a cryptography class and finding anagrams to be very useful. She decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Can you help her find this number?
//
//Given two strings, s1 and s2, that may not be of the same length, determine the minimum number of character deletions required to make s1 and s2 anagrams. Any characters can be deleted from either of the strings.
//Input Format
//
//The first line contains a single string,s1.
//The second line contains a single string, s2.
//
//Constraints
//
//It is guaranteed that s1 and s2 consist of lowercase English letters, ascii[a-z].
//Output Format
//
//Print a single integer denoting the minimum number of characters which must be deleted to make the two strings anagrams of each other.
//
//Sample Input
//
//cde
//abc
//Sample Output
//
//4
//Explanation
//
//We delete the following characters from our two strings to turn them into anagrams of each other:
//
//Remove d and e from cde to get c.
//Remove a and b from abc to get c.
//We had to delete 4 characters to make both strings anagrams.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//s1:bacdcfr
//s2:dcbad
//deletedChars:cfrd//size:4
int determineAnagram(string s1, string s2){
    string deletedChars;
    // find all the s1 characters in s2 and remove them from s1 and s2. put them in deletedChars
    for(auto itr = s1.begin(); itr != s1.end(); ++itr){
        //cout<< s1 << " "<<s2 <<endl;
        auto location = find(s2.begin(),s2.end(),*itr);
        if (location == s2.end()){
            deletedChars+= (*itr);
        }
        else{
            s1.erase(itr);
            *itr--;
            s2.erase(location);
        }
    }
    //find all the s2 characters in s1 and remove them from s1 and s2. put them in deletedChars
    for(auto itr = s2.begin(); itr != s2.end(); ++itr){
        //cout<< s1 << " "<<s2 <<endl;
        auto location = find(s1.begin(),s1.end(),*itr);
        if (location == s1.end()){
            deletedChars+= (*itr);
        }
        else{
            s2.erase(itr);
            *itr--;
            s1.erase(location);
        }
    }
    //cout<<deletedChars<<endl;
    return deletedChars.size();
}

int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<determineAnagram(s1,s2)<<endl;
    return 0;
}


