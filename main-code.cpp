#include <iostream>
using namespace std;
//constants & global varaibles 
#define SIDE 3 
const char PLAYER1='X' , PLAYER2='O';
string nameP1,nameP2;

void showInstructions()
{
    printf("\t\t\t Kit-Kat-Toe\n\n");
    printf("->You can fill 1st 3 pieces in desired location and late you just have move the pieces\n");
    printf("->Choose a cell numbered from 1 to 9 as below and play\n");
    printf("->whoever first makes either row crossed or column crossed with their 3 pawns, he/she is the winner\n");
    printf("-> Apart from player names , all inputs should be in intergers from 1 - 9\n\n");
    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t------------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t------------\n");
    printf("\t\t\t 7 | 8 | 9 \n\n");
 
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
 
}

void showBoard(char board[][SIDE])
{
    printf("\n\n");
 
    printf("\t\t\t %c | %c | %c \n",
           board[0][0],
           board[0][1],
           board[0][2]);
 
    printf("\t\t\t------------\n");
 
    printf("\t\t\t %c | %c | %c \n",
           board[1][0],
           board[1][1],
           board[1][2]);
 
    printf("\t\t\t------------\n");
    printf("\t\t\t %c | %c | %c \n\n",
           board[2][0],
           board[2][1],
           board[2][2]);
 
    return;
}

//function to get piece location in board(x,y)
bool getIndex(int a,pair<int,int> &p){
    switch(a){
        case 1:
        p.first=0; p.second=0;
        break;
        case 2:
        p.first=0;p.second=1;
        break;
        case 3:
        p.first=0; p.second=2;
        break;
        case 4:
        p.first=1; p.second=0;
        break;
        case 5:
        p.first=1; p.second=1;
        break;
        case 6:
        p.first=1; p.second=2;
        break;
        case 7:
        p.first=2; p.second=0;
        break;
        case 8:
        p.first=2; p.second=1;
        break;
        case 9:
        p.first=2; p.second=2;
        break;
        default:
        return (false);
    }
    return (true);
}
//To place 3 piecs of both players into board
void initialise(char board[][SIDE],char turn)
{
    //Initially the board is empty
    for(int i=0;i<SIDE;i++){
        for(int j=0;j<SIDE;j++){
            board[i][j]=' ';
        }
    }
    string curName;
    if(turn==PLAYER1){
        curName=nameP1;
    }else{
        curName=nameP2;
    }
    int start=6;//3 pieces each , player1 & player2
    int a;
    pair<int,int> p;
    while(start--){
        again:
        cout<<curName<<" enter the "<<turn<<" piece cell NUMBER to place in range [1-9]:"<<endl;
        cin>>a; //there's a bug here
        if(getIndex(a,p)==false || board[p.first][p.second]!=' '){
            cout<<"Lol!, cell location is not in range oR its already filled.\n";
            goto again;
        }else{
            board[p.first][p.second]=turn;
        }
        if(turn==PLAYER1){
            curName=nameP2;
            turn=PLAYER2;
        }else{
            curName=nameP1;
            turn=PLAYER1;
        }
        showBoard(board);
    }
    return ;
}

bool verifyInput(char board[][SIDE],int x1,int y1,int x2,int y2,char PLAYER)
{
    if(board[y2][x2]==' ' && board[y1][x1]==PLAYER){
        if(((x1==x2) && abs(y2-y1)==1) || (y1==y2 && abs(x2-x1)==1)){
            return true;
        }else{
            return false;
        }  
    }else{
        return false;
    }           
}

// Function that returns true if any of the row is crossed with the same player's move
bool rowCrossed(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return (true);
    }
    return (false);
}
 
// Function that returns true if any of the column is crossed with the same player's move
bool columnCrossed(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return (true);
    }
    return (false);
}

// Function that returns true if the game is over else it returns a false
bool gameOver(char board[][SIDE])
{
    //over or not
    return (rowCrossed(board) || columnCrossed(board));
}
//Stalemate checker 
bool isStalemate(char board[][SIDE]){
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        if(board[0][1]==board[0][2] && board[0][2]==board[1][2]){
            return true;
        }
    }else if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        if(board[0][0]==board[0][1] && board[0][0]==board[1][0]){
            return true;
        }
    }
    return false;
}
void declareWinner(char whoseTurn)
{
    //either Win or Lose 
    if (whoseTurn == PLAYER1)
        cout <<nameP2<< " has won the game\n";
    else
        cout <<nameP1<< " has won the game\n";
    return;
}
//Let's play real game
void playKKT(char board[][SIDE],char &whoseTurn)
{
    int a,b;
    pair<int,int> p1,p2;
    int x1,y1,x2,y2;
    bool wrongInput; //to handle illegal moves 
    // Keep playing till the game is over
    while (gameOver(board)==false){

        if(whoseTurn == PLAYER1) {
        wrongInput=true;
        while(wrongInput){
            cout<<nameP1<<" Enter the respective initial & final cell numbers of any piece 'X' in range [1-9]:";
            cin>>a>>b; //this behaves like bug sometimes -> [1-9]
            //get move locations from function and also check if its valid input or not 
            if(getIndex(a,p1)==true && getIndex(b,p2)==true){
                y1= p1.first;
                x1=p1.second;
                y2=p2.first;
                x2=p2.second;
            }else{
                cout<<"Oops ,that moves are out of range \n";
                continue;
            }
            if(verifyInput(board,x1,y1,x2,y2,PLAYER1)){
                swap(board[y2][x2],board[y1][x1]);
            }else{
                cout << "Oops, thats an illegal move , try again\n";
                continue;
            }
            //current board position
            showBoard(board);
            //let's check , will this move make stalemate 
            if(isStalemate(board)==true){
                cout<<nameP2<<" You're stalemate by "<<nameP1<<" and he'll get one more turn,cause you don't have any legal moves rn ;(\n";
                whoseTurn=PLAYER1;
            }else{
                whoseTurn = PLAYER2;
            }
            wrongInput=false;
        }
        }
        else{
        // Label for player2 wrong choice
        // of row and column
        wrongInput=true;
        while(wrongInput){
            cout<<nameP2<<" Enter the respective initial & final cell numbers of any piece 'O' in range [1-9] :";
            cin>>a>>b;
            if(getIndex(a,p1)==true && getIndex(b,p2)==true){
                y1= p1.first;
                x1=p1.second;
                y2=p2.first;
                x2=p2.second;
            }else{
                cout << "Oops,that moves are out of range, try again\n";
                continue;
            }
            //Lets check weather the move is possible or not ,in board
            if(verifyInput(board,x1,y1,x2,y2,PLAYER2)){
                swap(board[y2][x2],board[y1][x1]);
            }else{
                cout << "Oops, thats an illegal move , try again\n";
                continue;
            }
            //current board position 
            showBoard(board);
            //let's check , will this move make stalemate 
            if(isStalemate(board)==true){
                cout<<nameP1<<" You're stalemated by "<<nameP2<<" and he'll get one more turn,cause you don't have any legal moves rn ;(\n";
                whoseTurn=PLAYER2;
            }else{
                whoseTurn = PLAYER1;
            }
            wrongInput=false;
        }
        }
    }
    return ;
}
//main code
int main()
{
    // Take the name of players
    //string nameP1,nameP2;
    cout << "Enter name of first Player: ";
    cin >>nameP1;

    cout << "Enter name of Second Player: ";
    cin >>nameP2;

    // Lets do toss
    srand(time(0));
    int toss = rand() % 10;

    cout<<toss<<endl;
    char turn;
    if(toss<5){
        turn=PLAYER1;
        cout<<nameP1 << " has won the toss,Game will start with you,Take three 'X' pieces"<< endl;
        cout<<nameP2<< " here you go , take three 'O' pieces\n\n";
    }
    else{
        turn=PLAYER2;
        cout<<nameP2 << " has won the toss,Take three 'O' pieces"<< endl;
        cout<<nameP1<< " here you go , take three 'X' pieces\n\n";
    }
    //Instructions of game 
    showInstructions();
    cout<<"Place you'r 3 pieces in 3 desired locations,\n Good Luck guys! :)\n";
    // Let us play the game
    char board[SIDE][SIDE];
    initialise(board,turn);
    //Real game start here
    playKKT(board,turn);
    //declare who's the winner nameP1 or nameP2
    declareWinner(turn);

    return (0);
}

