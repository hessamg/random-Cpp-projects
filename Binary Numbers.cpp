//  Created by Macbook on 2018-04-17.
//  Sam Ganjian.

//Task
//Given a base-10 integer,n, convert it to binary (base-2).
//Then find and print the base-10 integer denoting the maximum number of consecutive 1's in n's binary representation.
//
//Input Format
//
//A single integer,n .
//
//Constraints
//
// 1 <= n <= 1000000
//
//Output Format
//
//Print the binary representation of n and a single base-10 integer denoting the maximum number of consecutive 1's in the binary representation of n.
//
//Sample Input 1
//
//5
//Sample Output 1
//
//101 1
//Sample Input 2
//
//13
//Sample Output 2
//
//1101 2
//Explanation
//
//Sample Case 1:
//The binary representation of 5 is 101, so the maximum number of consecutive 1's is 1.
//
//Sample Case 2:
//The binary representation of 13 is 1101, so the maximum number of consecutive 1's is 2.

#include <iostream>
#include <vector>

using namespace std;
string convertToBinary(int intNum){
    string memo;
    if(memo.empty()){
        if(intNum == 0)
            memo += "0";
        else if (intNum == 1)
            memo += "1" ;
        else
            memo += (convertToBinary(intNum/2) + convertToBinary(intNum%2));
        }
    return memo;
}

int main() {
    int n;
    cin>>n;
    string binaryNum;
    binaryNum = convertToBinary(n);
    
    int count = 1;
    int maximumConsecutive = 1;
    for(int i=0 ; i<binaryNum.size()-1;i++){
        if(binaryNum.at(i) == '1'){
            if(binaryNum.at(i+1) == '1'){   //check if the next charecter is '1'
                count++;
                if(count > maximumConsecutive)  //make sure to save the maximum consecutive number
                    maximumConsecutive = count;
            }
            else{   //reset count
                count = 1;
            }
        }
    }
    cout<< binaryNum<< " " <<maximumConsecutive <<endl;
    return 0;
}

