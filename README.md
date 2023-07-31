# Kit-Kat-Toe
A simple variation of popular Tic-Tac-Toe game.

## Game Rules & Instructions
- This is two player game ,consits of **three 'X'** pieces, **three 'O'** pieces & 3*3 board.
- Initially board will be empty, follow below procedure according to which mode you want to play.
- `Two Player Mode`
- Each player have to fill pieces one by one until 6 pieces are placed inside the board.
- **_To place piece inside board simply enter the cell number_** (E.g: 2)
- cell should be empty before placing piece. 
- `Single Player Mode`
- In which game played against AI-Integrated engine,where player have to,
- **_enter all 3 desired cell numbers in one go_**(E.g: 1 5 8).
- cells should be empty before placing the 3 pieces.
- `Continue` 
- First turn will be decided randomly and followed by second player.
- After both players placing their pieces into board ,game will start in which player can move pieces.
- Player can move any of his/her piece from its position to immediate adjacent cell(either left or right or up or down cell) (only if destination cell is empty).
- Player can move one piece among 3 pieces in each turn. 
- **_Player have to enter initial(current cell) and final(cell to move) cell numbers_**, if its invalid move then you'll be prompted again to enter the legal move.
- if you don't have any legal moves means your **_stalemated_** ,then your turn will be skipped and opponent can play and after that you can move.
- Like this game will continue until winner is decided.(no draw choice right now) 
- `CELL NUMBERING`<br>![Board](https://graph.org/file/5be7b627616be25a55ec3.png)
- `Win rules`
- The first player to get all three of their pieces in a `ROW or COLUMN wise` wins the game.
- Alert: Diagonally aligned pieces will not considered as win.


## Instructions to Play Game:
- In following commands replace `game.cpp` with the game file you downloaded from this repo.
- For Two Player Game download:`Two-Player-KKT-Game.cpp`
- For Single player Game download:`Single-Player-KKT-Game.cpp` 
### VS code
1. If you've Visual Studio Code installed in system
2. Download game file
3. Simply run the file & Play
### Windows 
1. Installed a cpp compiler(MingW/g++)
2. Open commmand prompt in the folder where program is saved.
3. run `g++ game.cpp -o output.exe` then run `output.exe`
### Linux
1. Install a cpp compiler(g++/gcc) 
2. Open terminal in the folder where program is saved
3. run `g++ game.cpp -o output` then run `./output`

## What's new ??
- [Single Player Game](https://github.com/Kevin-0-0/Kit-Kat-Toe/blob/main/Single-Player-KKT-Game.cpp)

## Upcoming Updates
- Web-Based Game(Browser Game)

## References and Acknowledgements
- MiniMax Algorithm : https://en.wikipedia.org/wiki/Minimax
- GeeksForGeeks Articles: [GfGLink1](https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-game/) || [GfGLink2](https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-for-2-person-game-user-vs-user/)
- Clear and best visual explanation to understand MiniMax : https://www.youtube.com/watch?v=l-hh51ncgDI <br>
- _"Special thanks to all the listed invaluable resources that assisted in making the project possible! 🙏 "_
  
