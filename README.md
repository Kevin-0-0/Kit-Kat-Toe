# Kit-Kat-Toe
A simple variation of popular Tic-Tac-Toe game.

## Game Rules & Instructions
- Board consists of 3*3 grid and 3 'X' pieces and 3 'O' pieces.
- This is two player game , each player have to play with three 'X' pieces or three  'O' pieces.
- Initially board will be empty , each player have to fill it one by one until 6 pieces are placed inside the board.
- First turn will be decided randomly,and followed by second player.
- Player just need to enter EMPTY cell number to place the piece.
- After placing pieces,game will start.
- You can move any of your piece from its position to just 1 place NEXT position of it (either left or right or up or down) (only if destination cell is empty).
- You have to enter initial(your piece) and final(to move) cell numbers, if its invalid move then you'll be prompted again to enter the legal move.
- CELL NUMBERING:
- ![Board](https://graph.org/file/5be7b627616be25a55ec3.png)
- if you don't have any legal moves means your `stalemated` ,then your turn will be skipped and opponent can play again.
- After 6 pieces are placed inside board ,in each turn player can move any one of his piece from initial cell to empty destination cell(adjacent cell), like this game will continue,the first player to get all three of their pieces in a `ROW or COLUMN wise` wins the game.
- Alert: Diagonally aligned pieces will not considered as win.

## Instructions to run:
#### VS CODE
1. If you've Visual Studio Code installed in system
2. Download `Two-Player-KKT-Game.cpp` file
3. Simple run the file & Play
    
#### Windows 
1. Install a cpp compiler
2. Open commmand prompt in the folder where program is saved(having MingW/GCC downloaded)
3. `g++ Two-Player-KKT-Game.cpp -o output.exe` then run `output.exe`

#### Linux
1. Install a cpp compiler 
2. Open terminal in the folder where program is saved
3. `g++ Two-Player-KKT-Game.cpp -o output` then run `./output`

## Upcoming Updates
- Single Player game
- Web-Based Game(Browser Game) 
  
