//  Created by Macbook on 2018-04-18.
//  Sam Ganjian.
//
//Louise and Richard have developed a numbers game. They pick a number and check to see if it is a power of 2. If it is, they divide it by 2. If not, they reduce it by the next lower number which is a power of 2. Whoever reduces the number to 1 wins the game. Louise always starts.
//
//Given an initial value, determine who wins the game.
//
//As an example, let the initial value n = 132 . It's Louise's turn so she first determines that 132 is not a power of 2. The next lower power of 2 is 128, so she subtracts that from 132 and passes 4 to Richard. 4 is a power of 2, so Richard divides it by 2 and passes 2 to Louise. Likewise, 2 is a power so she divides it by 2 and reaches 1. She wins the game.
//
// If they set counter to 1, Richard wins. Louise' cannot make a move so she loses.
//
//Input Format
//
//The first line contains an integer t, the number of testcases.
//Each of the next t lines contains an integer n, the initial value for the game.
//
//Output Format
//
//For each test case, print the winner's name on a new line in the form Louise or Richard.
//
//Sample Input 0
//
//1
//6
//Sample Output 0
//
//Richard
//Explanation 0
//
//6 is not a power of 2 so Louise reduces it by the largest power of 2 less than 6: 6-4=2.
//2 is a power of 2 so Richard divides by 2 to get 1 and wins the game.

#include <iostream>
#include <cmath>

using namespace std;

string counterGame(long n) {
    bool turn = true; //changing player turns
    bool isPowerOfTwo = false;
    
    while(n != 1){
        long largestI = 0;
        turn = (!turn);
        for(int i = 0 ; pow(2,i)<= n; i++ ){
            if(pow(2,i) == n){//n is a power of 2
                n /= 2;
                isPowerOfTwo = true;
            }
            else{             //find the largest 2^i which is still less than n
                largestI = i;
            }
        }
        
        if(!isPowerOfTwo){ //if n was not a power of 2, substract closest power of 2 from n
            largestI = pow(2,largestI);
            n -= largestI;
        }
    }
    if (turn) return "Richard";
    return "Louise";
}

int main()
{
    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        string result = counterGame(n);
        
        cout << result << "\n";
    }
    return 0;
}



