#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <conio.h>
//5 levels
//1 level: 10/14
//2 level: 12/18
//3 level: 16/22
//4 level: two player's simultaneously
//5 level: map in fog
using namespace std;
enum Object {WALL = 1, HERO = 8, EMPTY = 0, EXIT = 2, TRAIL = 3};
void render_maze(vector<vector<Object>> &maze){
 cout<< "\n\n\n\n";
 for (vector<Object> &row: maze) {
  cout<< "                          ";
  for (Object &column: row) {
   switch(column) {
    case EMPTY: cout<< "   "; break;
    case HERO: cout<<  " * "; break;
    case WALL: cout<<  " 1 "; break;
    case EXIT: cout<<  " E "; break;
    case TRAIL: cout<< "   "; break;
   }
  }
  cout<< endl;
 }
}
void move_hero (vector<int> &position, vector<vector<Object>> &maze,char &input) {
 vector<int> previous_position = position;
  vector<int> new_position = position;
 switch (input) {
  case 'w':
   new_position[0]--;
   if( maze[new_position[0]][new_position[1]] != WALL && maze[new_position[0]][new_position[1]] != TRAIL ) {
    position[0]--;
    maze[position[0]][position[1]] = HERO;
    maze[previous_position[0]][previous_position[1]] = TRAIL;
    break;
   }
   else break;
  case 's':
   new_position[0]++;
   if(maze[new_position[0]][new_position[1]] != WALL && maze[new_position[0]][new_position[1]] != TRAIL) {
    position[0]++;
    maze[position[0]][position[1]] = HERO;
    maze[previous_position[0]][previous_position[1]] = TRAIL;
    break;
   }
   else break;
  case 'a':
   new_position[1]--;
   if( maze[new_position[0]][new_position[1]] != WALL && maze[new_position[0]][new_position[1]] != TRAIL) {
    position[1]--;
    maze[position[0]][position[1]] = HERO;
    maze[previous_position[0]][previous_position[1]] = TRAIL;
    break;
   }
   else break;
  case 'd':
   new_position[1]++;
   if( maze[new_position[0]][new_position[1]] != WALL && maze[new_position[0]][new_position[1]] != TRAIL) {
    position[1]++;
    maze[position[0]][position[1]] = HERO;
    maze[previous_position[0]][previous_position[1]] = TRAIL;
    break;
   }
   else break;
}
}
vector<vector<Object>> Levels (int number_level) {
 vector<vector<Object>> level;
 switch(number_level) {
  case 1:
   level = {
   {WALL, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EXIT,  WALL,  WALL,  WALL},
   {WALL, EMPTY, WALL,  EMPTY, EMPTY, EMPTY,  WALL,  WALL, WALL,  EMPTY, EMPTY, EMPTY, WALL,  WALL},
   {WALL, EMPTY, EMPTY, EMPTY,  WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, WALL , WALL},
   {WALL, EMPTY, WALL,  EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, WALL,  EMPTY, WALL , WALL},
   {WALL, EMPTY, WALL,  EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, WALL,  WALL,  EMPTY, WALL,  WALL},
   {WALL, EMPTY, EMPTY, WALL,  WALL,  EMPTY, WALL,  WALL,  EMPTY, WALL,  EMPTY, EMPTY, EMPTY, WALL},
   {WALL, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  WALL},
   {WALL, WALL,  EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, WALL,  EMPTY, WALL,  EMPTY, WALL},
   {WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
   {WALL, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL}
   };
   break;

  case 2:
   level = {
   {WALL, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EXIT,  WALL,  WALL,  WALL},
   {WALL, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,  EMPTY, EMPTY, EMPTY, WALL,  WALL},
   {WALL, EMPTY, EMPTY, EMPTY,  WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, WALL , WALL},
   {WALL, EMPTY, WALL,  EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, WALL,  EMPTY, WALL , WALL},
   {WALL, EMPTY, WALL,  EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, WALL,  WALL,  EMPTY, WALL,  WALL},
   {WALL, EMPTY, EMPTY, WALL,  WALL,  EMPTY, WALL,  WALL,  EMPTY, WALL,  EMPTY, EMPTY, EMPTY, WALL},
   {WALL, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  WALL},
   {WALL, WALL,  EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, WALL,  EMPTY, WALL,  EMPTY, WALL},
   {WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
   {WALL, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL}
   };
   break;
  case 3:
   level = {
   {WALL, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  EXIT,  WALL,  WALL,  WALL},
   {WALL, EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,  EMPTY, EMPTY, EMPTY, WALL,  WALL},
   {WALL, EMPTY, EMPTY, EMPTY,  WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL,  EMPTY, WALL , WALL},
   {WALL, EMPTY, WALL,  EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, WALL,  EMPTY, WALL , WALL},
   {WALL, EMPTY, WALL,  EMPTY, WALL,  EMPTY, EMPTY, EMPTY, EMPTY, WALL,  WALL,  EMPTY, WALL,  WALL},
   {WALL, EMPTY, EMPTY, WALL,  WALL,  EMPTY, WALL,  WALL,  EMPTY, WALL,  EMPTY, EMPTY, EMPTY, WALL},
   {WALL, EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  EMPTY, EMPTY, WALL,  WALL},
   {WALL, WALL,  EMPTY, WALL,  WALL,  WALL,  WALL,  WALL,  EMPTY, WALL,  EMPTY, WALL,  EMPTY, WALL},
   {WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
   {WALL, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL}
   };
   break;
 }
 return level;
}
vector<int> exit_position (vector<vector<Object>> &maze) {
 vector<int> exit_position;
 exit_position.resize(2,0);
 for(int i = 0; i < maze.size(); i++) {
  for (int j = 0; j < maze[i].size(); j++) {
   if (maze[i][j] == EXIT) {
    exit_position[0] = i;
    exit_position[1] = j;
    break;
   }
  }
 }
 return exit_position;
}
int main () {
 vector<vector<int>> positions = { {8, 1}, {5,8}, {1,1} };
 char input;
 vector<int> position;
 vector<int> base_position;
 system("cls");
 for(int level = 1; level <= 3; level++) {
  vector<vector<Object>> maze = Levels(level);
  vector<int> exit = exit_position(maze);
  position = positions[level - 1];
  base_position = position;
  switch(level) {
   case 1: cout<< " Hello,\n This is Maze game.\n to move press wasd\n to restart level press r\n to quit press q\n\t\t\t\t\t   level 1\n\n"; break;
   case 2: cout<< "\n\t\t\t\t\t   Level 2\n"; break;
   case 3: cout<< "\n\t\t\t\t\t   Level 3\n"; break;
  }
  maze[position[0]][position[1]] = HERO;
  render_maze(maze);
  while (true) {
   input = _getch();
   system("cls");
   if (input == 'q') goto end_game;
   if(input == 'r') {
    maze = Levels(level);
    maze[base_position[0]][base_position[1]] = HERO;
    maze[position[0]][position[1]] = EMPTY;
    position = base_position;
   }
   move_hero(position, maze, input);
   if(exit == position) {
    if (level == 3) cout<<"\t\t\t Good Job. You have completed all mission's";
    else cout<< "\n\t\t\t\t you escaped. You're pretty good!.\n";
    break;
   }
   render_maze(maze);
  }
 }
 end_game:
  return 0;
 }
