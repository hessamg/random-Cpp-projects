#include <iostream>
#include <vector>
#include <cmath>

void drawCircle( std::vector<std::vector<int>>& grid , int h , int k , int r )
{
  int rows = grid.size();
  int cols = grid [ 0 ].size();

      for ( int x = 0; x < rows; ++x )
      {
        for ( int y = 0; y < cols; ++y )
        {
          // Check if the point (x, y) lies inside or on the circle
          if ( ( x - h ) * ( x - h ) + ( y - k ) * ( y - k ) <= M_PI * r * r )
          {
            grid [ x ][ y ] = 1; // Fill the cell
          }
        }
      }
  }

  void printGrid( const std::vector<std::vector<int>>& grid )
  {
    for ( const auto& row : grid )
    {
      for ( int cell : row )
      {
        std::cout << ( cell ? "#" : "." ) << " "; // Use '#' for filled and '.' for empty
      }
      std::cout << "\n";
    }
  }

  int main()
  {
    int rows = 60 , cols = 60;
    std::vector<std::vector<int>> grid( rows , std::vector<int>( cols , 0 ) );

      int centerX = 30 , centerY = 30 , radius = 15;
      drawCircle( grid , centerX , centerY , radius );

      printGrid( grid );
      return 0;
  }
