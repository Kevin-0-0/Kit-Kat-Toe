#include<iostream>
#include<string>
#include<utility>
#include<cstdlib> 
#include<ctime>
using namespace std;
 
const int SIDE=3;
const char PLAYER1='X' , PLAYER2='O';
string nameP1,nameP2;

//Functions Declarations
void beginKKT1(char board[][SIDE],char turn);
void playKKT(char board[][SIDE],char &whoseTurn);
char toss();
void showInstructions();
void showBoard(char board[][SIDE]);
void initialise(char board[][SIDE]);
bool rowCrossed(char board[][SIDE]);
bool columnCrossed(char board[][SIDE]);
bool isStalemate(char board[][SIDE]);
bool gameOver(char board[][SIDE]);
void declareWinner(char whoseTurn);
bool verifyInput(char board[][SIDE],int x1,int y1,int x2,int y2,char PLAYER);

//Main Code
int main(){
    //Here Goes Main function of Person to Person (P2P) game 
    cout << "Enter name of first Player: ";
    cin >>nameP1;
    cout << "Enter name of Second Player: ";
    cin >>nameP2;
    
    // Let's do toss
    showInstructions();
    char turn=toss();  

    //Place Pieces X's & O's in board
    cout<<"Place you'r 3 pieces in 3 desired locations,\n Good Luck guys! :)\n";
    char board[SIDE][SIDE];
    initialise(board);
    
    //to put 3 O's & X's into board
    beginKKT1(board,turn);

    //Real game start here
    playKKT(board,turn);

    //declare who's the winner nameP1 or nameP2
    declareWinner(turn);

    return (0);

}

//Function Definitions
void beginKKT1(char board[][SIDE],char turn)
{
    //Initially the board is empty
    string curName;
    if(turn==PLAYER1){
        curName=nameP1;
    }else{
        curName=nameP2;
    }
    int start=6;//3 pieces each , player1 & player2
    int a;
    while(start--){
        again:
        cout<<curName<<" Enter the cell NUMBER in range [1-9] to place '"<<turn<<"' :\n";
        cin>>a;
        a=a-1;
        if(a<0 || a>8 || board[a/3][a%3]!=' '){
            cout<<"Lol!, that cell location is not in range oR its already filled. Try again:\n";
            cin.clear();
            cin.ignore(10000,'\n');
            goto again;
        }else{
            board[a/3][a%3]=turn;
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

void playKKT(char board[][SIDE],char &whoseTurn)
{
    //
    int a,b;
    int x1,y1,x2,y2;
    string curName;
    bool wrongInput;
    // Keep playing till the game is over
    while (gameOver(board)==false){
        if(whoseTurn==PLAYER1){
            curName=nameP1;
        }else{
            curName=nameP2;
        }
        wrongInput=true;
        while(wrongInput){
            cout<<curName<<" Enter the respective initial & final cell NUMBERs  in range [1-9] to move piece '"<<whoseTurn<<"' :";
            cin>>a>>b; 
            a--;b--;
            if(a>=0 && b>=0 && b<9 && a<9){
                y1=a/3;
                x1=a%3;
                x2=b%3;
                y2=b/3;
                if(verifyInput(board,x1,y1,x2,y2,whoseTurn)){
                    swap(board[y2][x2],board[y1][x1]);
                    if(whoseTurn==PLAYER1){
                        whoseTurn=PLAYER2;
                    }else{
                        whoseTurn=PLAYER1;
                    }
                }else{
                    cout << "Oops, thats an illegal move , try again\n";
                    cin.clear();//clearing invalid stream of input 
                    cin.ignore(10000,'\n');//without these , program will skip cin statement in next iteration to avoid this , use cin.ignore() function 
                    continue;
               }
            }else{
                cout<<"Oops ,that moves are out of range \n";
                cin.clear();
                cin.ignore(10000,'\n');
                continue;
            }
            
            showBoard(board);
            //let's check , will this move make stalemate 
            if(isStalemate(board)==true){
                cout<<curName<<" You stalemate Opponent So Play again ,Opponent don't have any legal moves rn :):\n";
                continue;
            }
            wrongInput=false;
        }
    }
    return ;
}

char toss(){
    srand(time(0));//to avoid getting same value 
    int toss=rand()%10;//generates random value of range 0 to 9 (each has 50% chance of win)
    if(toss>4){
        swap(nameP1,nameP2);
    }
    cout<<nameP1 << " has won the toss,Game will start with you,Take three 'X' pieces"<< endl;
    cout<<nameP2<< " here you go , take three 'O' pieces\n\n";
    return PLAYER1; 
}

void showBoard(char board[][SIDE])
{
    //Printing game status
    printf("\n\n");
 
    printf("\t\t\t %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
 
    printf("\t\t\t------------\n");
 
    printf("\t\t\t %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
 
    printf("\t\t\t------------\n");

    printf("\t\t\t %c | %c | %c \n\n",board[2][0],board[2][1],board[2][2]);
 
    return;
}

void initialise(char board[][SIDE]){
    //creating matrix(array) to play game 
    for(int i=0;i<SIDE;i++){
        for(int j=0;j<SIDE;j++){
            board[i][j]=' ';
        }
    }
    showBoard(board);

    return ;
}

bool gameOver(char board[][SIDE]){

    //check if gameover or not
    return (rowCrossed(board) || columnCrossed(board));

}

bool rowCrossed(char board[][SIDE]){

    for (int i = 0; i < SIDE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return (true);
    }

    return (false);
}

bool columnCrossed(char board[][SIDE]){

    for (int i = 0; i < SIDE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return (true);
    }

    return (false); 
}

bool isStalemate(char board[][SIDE]){

    //stalemate means , one player can't move any of his pieces
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){

        if(board[0][1]==board[0][2] && board[0][2]==board[1][2]){
            return true;
        }

    }else if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){

        if(board[0][0]==board[0][1] && board[0][0]==board[1][0]){
            return true;
        }
    }

    return (false);
}

void declareWinner(char whoseTurn){

    if (whoseTurn == PLAYER1)
        cout <<nameP2<< " has won the game\n";
    else
        cout <<nameP1<< " has won the game\n";

    return;
}

bool verifyInput(char board[][SIDE],int x1,int y1,int x2,int y2,char PLAYER){
    //Lets check if given move is valid or not 
    if(board[y2][x2]==' ' && board[y1][x1]==PLAYER){
        if(((x1==x2) && abs(y2-y1)==1) || (y1==y2 && abs(x2-x1)==1)){
            return true;
        }else{
            return false;
        }  
    }

    return (false);
}

void showInstructions()
{
    printf("\n===\t===\t===\t===\t===\t===\t===\t===\t===\t===\t===\t\n\n");
    printf("\t\t\t Kit-Kat-Toe Instructions \n\n");
    printf("->You can fill 1st 3 pieces in desired location and later you just have move the pieces\n");
    printf("->Choose a cell numbered from 1 to 9 as below and play\n");
    printf("->whoever first makes either row crossed or column crossed with their 3 pawns, he/she is the winner\n");
    printf("-> Apart from player names , all inputs should be in intergers from 1 - 9\n\n");
    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t------------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t------------\n");
    printf("\t\t\t 7 | 8 | 9 \n\n");
    printf("\n===\t===\t===\t===\t===\t===\t===\t===\t===\t===\t===\t\n\n");
 
}
