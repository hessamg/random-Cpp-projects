/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>

int bfs( std::vector<std::vector<int>>& grid )
{
  int ROWS = grid.size();
  int COLS = grid [ 0 ].size();
  std::set<std::pair<int , int>> visit;
  const std::set<std::pair<int , int>> neighbours {{0,1},{0,-1},{1,0},{-1,0}};
  std::queue<std::pair<int , int>> queue;
  visit.insert( {0,0} );
  queue.push( {0,0} );

  int length = 0;

  while ( !queue.empty() )
  {
    for ( int i = 0; i < queue.size(); i++ )
    {
      const auto& [r , c] = queue.front();
      queue.pop();
      if ( r == ROWS - 1 && c == COLS - 1 )
        return length;

      for ( const auto& [nr , nc] : neighbours )
      {
        int newR = r + nr;
        int newC = c + nc;


        if ( newR < 0 || newC < 0 || newR >= ROWS || newC >= COLS ||

          grid [ newR ][ newC ] == 1 || visit.find( {newR, newC} ) != visit.end() )
        {

          continue;

        }

        queue.push( {newR,newC} );
        visit.insert( {newR,newC} );
      }

    }
    ++length;

  }
  return 0;
}

int dfs( std::vector<std::vector<int>>& grid , int r , int c , std::set<std::pair<int , int>>& visit )
{
  int ROWS = grid.size();
  int COLS = grid [ 0 ].size();

  if ( r < 0 || c < 0 || r >= ROWS || c >= COLS || grid [ r ][ c ] == 1 || visit.find( {r,c} ) != visit.end() )
    return 0;
  if ( r == ROWS - 1 && c == COLS - 1 )
    return 1;

  visit.insert( {r,c} );

  int count = 0;
  count += dfs( grid , r + 1 , c , visit );
  count += dfs( grid , r , c + 1 , visit );
  count += dfs( grid , r - 1 , c , visit );
  count += dfs( grid , r , c - 1 , visit );

  visit.erase( {r,c} );
  return count;
}

int main()
{
  std::vector<std::vector<int>> grid = {{0,0,0,0},
                                        {1,1,0,1},
                                        {0,0,0,0},
                                        {0,1,1,1},
                                        {0,0,0,0}};
  std::set<std::pair<int , int>> res;
  std::cout << "BFS: " << bfs( grid ) << std::endl;

  std::cout << "DFS: " << dfs( grid , 0 , 0 , res ) << std::endl;
  return 0;
}
