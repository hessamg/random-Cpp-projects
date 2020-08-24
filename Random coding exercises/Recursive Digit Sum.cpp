//  Created by Macbook on 2018-04-15.
//  Sam Ganjian.
//
// Given an integer, we need to find the super digit of the integer.
//
// We define super digit of an integer x using the following rules:
//
// If x has only 1 digit, then its super digit is .
// Otherwise, the super digit of x is equal to the super digit of the digit-sum of x. Here, digit-sum of a number is defined as the sum of its digits.
// For example, super digit of 9875 will be calculated as:
//
// super_digit(9875) = super_digit(9+8+7+5)
// = super_digit(29)
// = super_digit(2+9)
// = super_digit(11)
// = super_digit(1+1)
// = super_digit(2)
// = 2.
//
// You are given two numbers n and k. You have to calculate the super digit of p.
//
// is created when number  is concatenated  times. That is, if n = 123 and k = 3, then p = 123123123 .
//
// Input Format
//
// The first line contains two space separated integers, n and k.
//
// Output Format
//
// Output the super digit of p, where p is created as described above.
//
// Sample Input
//
// 148 3
// Sample Output
//
// 3
// Explanation
//
// Here n = 148 and k = 3, so p = 148148148.
//
// super_digit(P) = super_digit(148148148)
// = super_digit(1+4+8+1+4+8+1+4+8)
// = super_digit(39)
// = super_digit(3+9)
// = super_digit(12)
// = super_digit(1+2)
// = super_digit(3)
// = 3.


#include <iostream>

using namespace std;

int super_digit(string s){
    
    int sum = 0;
    for( char &c : s){
        sum += c - '0'; //'0' is the ascii character number. '0' = 48
    }
    if(sum<10){
        return sum;
    }
    else{
        return super_digit(to_string(sum));
    }
}
int main() {
    string n;
    int k;
    cin >>n>>k;
    k=k%9;
    
    string temp = "";
    
    for(int i=0;i<k;i++){
        temp+=n;
    }
    cout<<super_digit(temp)<<endl;
    return 0;
}
