#include <iostream>
#include <unordered_map>
#include <functional>

int main()
{
  int n;
  std::cout << "Enter the Fibonacci number index: ";
  std::cin >> n;

  // Memoization map to store previously computed values
  std::unordered_map<int , int> memo {{0,0},{1,1}};

  // Lambda function for Fibonacci with memoization
  std::function<long( int )> fibonacci = [ & ] ( int n ) -> long
  {
    // Base cases
    if ( n < 2 ) return n;

    // Check if the result is already computed
    if ( memo.find( n ) != memo.end() )
    {
      return memo [ n ];
    }

    // Compute and store the result in the memoization map
    memo [ n ] = fibonacci( n - 1 ) + fibonacci( n - 2 );
    return memo [ n ];
  };

  std::cout << "Fibonacci number at index " << n << " is: " << fibonacci( n ) << std::endl;
  system( "pause" );
  return 0;
}
