#include<iostream>
#include<string>
#include<utility>
#include<cstdlib> 
#include<ctime>
using namespace std;

//Global variables
const int SIDE=3;
char PLAYER1='X' , PLAYER2='O';
string nameP1,nameP2;

//Functions declaration 
void beginKKT(char board[][SIDE],char turn);
void playKKT(char board[][SIDE],char &whoseTurn);
char toss();
void showInstructions();
int bestMove(char board[][SIDE]);
int minimax(char board[][SIDE],int depth,bool isAI);
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
    cout<<"-----------------> KIT-KAT-TOE <------------------\n=>Play against COMPUTER, Try to Beat it: \n";
    cout<<"Enter your name :";
    string name;
    cin>>name;
    char turn;
    nameP1="COMPUTER";
    nameP2=name;
    //Check out instructions 
    showInstructions();
    //Let's toss to find who'll start game 
    turn=toss();
    if(turn=='X'){
        swap(PLAYER1,PLAYER2);
    }else if(turn=='$'){
        turn='X';
    }
    char board[SIDE][SIDE];
    initialise(board);
    //Let's place 3 X's and 3's into board 
    beginKKT(board,turn); 
    showBoard(board);
    //Real game starts here
    playKKT(board,turn);
    declareWinner(turn);
    return (0);
}


//Function Definitions 
int minimax(char board[][SIDE],int depth,bool isAI){
    int score=0;
    int bestScore=0;

    if(gameOver(board)==true){ //Stalemate case is handled with  returning-999 and 999 (no worries)
        if(isAI==true){
            return -1;
        }
        if(isAI==false){
            return +1;
        }
    }else{
        //MiniMax Algorithm Implementation :)
        if(depth>0){
            if(isAI==true){
                bestScore=-999;
        for(int i=0;i<SIDE;i++){
        for(int j=0;j<SIDE;j++){
            if(board[i][j]==PLAYER1){

                if(j+1<SIDE &&  board[i][j+1]==' '){
                    swap(board[i][j],board[i][j+1]);
                    score=minimax(board,depth-1,false);
                    swap(board[i][j],board[i][j+1]);
                    if(score > bestScore){
                        bestScore=score;//Just stor score , indexes not needed
                    }
                }
                if(j-1>=0 && board[i][j-1]==' '){
                    swap(board[i][j],board[i][j-1]);
                    score=minimax(board,depth-1,false);
                    swap(board[i][j],board[i][j-1]);
                    if(score > bestScore){
                        bestScore=score;
                    }
                }
                if(i+1<SIDE && board[i+1][j]==' '){
                    swap(board[i][j],board[i+1][j]);
                    score=minimax(board,depth-1,false);
                    swap(board[i][j],board[i+1][j]);
                    if(score > bestScore){
                        bestScore=score;
                    }
                }
                if(i-1>=0 && board[i-1][j]==' '){
                    swap(board[i][j],board[i-1][j]);
                    score=minimax(board,depth-1,false);
                    swap(board[i][j],board[i-1][j]);
                    if(score > bestScore){
                        bestScore=score;
                    }
                }
            }
        }
    } 
    return bestScore;

            }else{
                bestScore=999;
                   for(int i=0;i<SIDE;i++){
        for(int j=0;j<SIDE;j++){
            if(board[i][j]==PLAYER2){
                if(j+1<SIDE &&  board[i][j+1]==' '){
                    swap(board[i][j],board[i][j+1]);
                    score=minimax(board,depth-1,true);
                    swap(board[i][j],board[i][j+1]);
                    if(score < bestScore){
                        bestScore=score;//Just need to store score 
                    }
                }
                if(j-1>=0 && board[i][j-1]==' '){
                    swap(board[i][j],board[i][j-1]);
                    score=minimax(board,depth-1,true);
                    swap(board[i][j],board[i][j-1]);
                    if(score < bestScore){
                        bestScore=score;
                    }
                }
                if(i+1<SIDE && board[i+1][j]==' '){
                    swap(board[i][j],board[i+1][j]);
                    score=minimax(board,depth-1,true);
                    swap(board[i][j],board[i+1][j]);
                    if(score < bestScore){
                        bestScore=score;
                    }
                }
                if(i-1>=0 && board[i-1][j]==' '){
                    swap(board[i][j],board[i-1][j]);
                    score=minimax(board,depth-1,true);
                    swap(board[i][j],board[i-1][j]);
                    if(score < bestScore){
                        bestScore=score;
                        //we just score 
                    }
                }
            }
        }
    }
                return bestScore;
            }

        }else{
            return 0;
        }
    }
    return 0;
}

int bestMove(char board[][SIDE]){
    int x1=0,y1=0,x2=0,y2=0;
    int score=0,bestScore=-999;
    int depth=5;//by changing depth value from [0 to 5],you can change difficult level of COMPUTER. 
    for(int i=0;i<SIDE;i++){
        for(int j=0;j<SIDE;j++){
            if(board[i][j]==PLAYER1){
                if(j+1<SIDE &&  board[i][j+1]==' '){
                    swap(board[i][j],board[i][j+1]);
                    score=minimax(board,depth,false);
                    swap(board[i][j],board[i][j+1]);
                    if(score > bestScore){
                        bestScore=score;
                        x1=j;y1=i;x2=j+1;y2=i;
                    }
                }
                if(j-1>=0 && board[i][j-1]==' '){
                    swap(board[i][j],board[i][j-1]);
                    score=minimax(board,depth,false);
                    swap(board[i][j],board[i][j-1]);
                    if(score > bestScore){
                        bestScore=score;
                        x1=j;y1=i;x2=j-1;y2=i;
                    }
                }
                if(i+1<SIDE && board[i+1][j]==' '){
                    swap(board[i][j],board[i+1][j]);
                    score=minimax(board,depth,false);
                    swap(board[i][j],board[i+1][j]);
                    if(score > bestScore){
                        bestScore=score;
                        x1=j;y1=i;x2=j;y2=i+1;
                    }
                }
                if(i-1>=0 && board[i-1][j]==' '){
                    swap(board[i][j],board[i-1][j]);
                    score=minimax(board,depth,false);
                    swap(board[i][j],board[i-1][j]);
                    if(score > bestScore){
                        bestScore=score;
                        x1=j;y1=i;x2=j;y2=i-1;
                    }
                }
            }
        }
    }
    return (((3*y1+x1)*9)+(3*y2+x2));

}

void beginKKT(char board[][SIDE],char whoseTurn){
    int n,x,y;
    int p1=0;
    if(whoseTurn==PLAYER1 && p1==0){
            board[0][0]=PLAYER1;
            board[1][1]=PLAYER1;
            board[2][2]=PLAYER1;
            whoseTurn=PLAYER2;
            p1=3;
            cout<<nameP1<<" has Entered 3 pieces ,Now your turn\n";
            showBoard(board);
    }
    while(whoseTurn==PLAYER2){
        if(whoseTurn==PLAYER2){
            cout<<nameP2<<" Enter the 3 cell numbers in [1-9] to place three '"<<PLAYER2<<"' :"<<endl;
            int c1,c2,c3;
            cin>>c1>>c2>>c3;
            c1--;c2--;c3--;
            if(c1>=0 && c1<9 && c2>=0 && c2<9 && c3>=0 && c3<9){
                if(c1!=c2 && c2!=c3 && c1!=c3){
                    int y1=c1/3,x1=c1%3,y2=c2/3,x2=c2%3,x3=c3%3,y3=c3/3;
                    if(board[y1][x1]==' ' && board[y2][x2]==' ' && board[y3][x3]==' '){
                        board[y1][x1]=PLAYER2;
                        board[y2][x2]=PLAYER2;
                        board[y3][x3]=PLAYER2;
                        if(gameOver(board)==true){
                            showBoard(board);
                            cout<<"Hey "<<nameP2<<",intially all pieces should not be aligned in same row or column,try again\n";
                            initialise(board);
                            cin.clear();
                            cin.ignore(10000,'\n');
                            continue; 
                        }
                        cout<<nameP2<<" , Cells are filled, check out\n";
                        showBoard(board);
                        whoseTurn=PLAYER1;
                        if(p1==3){ 
                            return ;
                        }else{

                        }
                        
                    }else{
                        cout<<"Hey,few cell locations are already occupied\n";
                        cin.clear();
                        cin.ignore(10000,'\n');
                        continue;
                    }
                }else{
                    cout<<"Hey,cell numbers shouldn't be same.\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                    continue;
                }
            }else{
                cout<<"Hey, Invalid cell numbers\n";
                cin.clear();
                cin.ignore(10000,'\n');
                continue;
            }
        }
    }

    swap(PLAYER1,PLAYER2); //This is confusing statement , dry run the whole code to understand
    while(p1<3){
        n=bestMove(board)%9;
        y=n/SIDE;
        x=n%SIDE;
        board[y][x]=PLAYER2;//in realP2 referse to PLAYER 1 piece
        p1++;
    }
    swap(PLAYER1,PLAYER2);
    return ;
}

void playKKT(char board[][SIDE],char & whoseTurn){
    int a,b;
    bool wrongInput;
    int x1,y1,x2,y2;
    while(gameOver(board)==false){
        if(whoseTurn==PLAYER1){
            int n=bestMove(board);
            int x1=(n/9)%3,y1=(n/9)/3;
            int x2=(n%9)%3,y2=(n%9)/3;
            swap(board[y1][x1],board[y2][x2]);
            cout<<"COMPUTER moved piece from "<<((n/9)+1)<<" To "<<((n%9)+1)<<endl;
            showBoard(board);
            if(isStalemate(board)){
                cout<<nameP2<<" you're stalemate by COMPUTER and \nSo It'll get one more turn,cause you don't have any legal moves rn ;(\n";
            }else{
                whoseTurn=PLAYER2;
            }
        }else{
            wrongInput=true;
            while(wrongInput){
            cout<<"Enter the respective Initial & Final cell no.s of any piece '" <<PLAYER2<<"' in range [1-9]: ";
            cin>>a>>b;
            if(a>0 && b>0 && a<10 && b<10){
                a--;b--;
            }else{
                cout<<"Oops ,that moves are out of range \n";
                cin.clear();
                cin.ignore(10000,'\n');
                continue;
            }
            x1=a%3;y1=a/3;x2=b%3;y2=b/3;
            if(verifyInput(board,x1,y1,x2,y2,PLAYER2)){
                swap(board[y1][x1],board[y2][x2]);
            }else{
                cout <<"Oops, thats an illegal move , try again\n";
                cin.clear();
                cin.ignore(10000,'\n');
                continue;
            }
            cout<<nameP2<<" moved piece from "<<a<<" To "<<b<<endl;
            showBoard(board);
            if(isStalemate(board)){
                cout<<nameP1<<" You're stalemated by "<<nameP2<<" and he'll get one more turn,cause you don't have any legal moves rn ;(\n";
            }else{
                whoseTurn=PLAYER1;
            }
            wrongInput=false;
            }
        }
    }
}

char toss(){
    srand(time(0));
    int toss=rand()%2;
    int x;
    if(toss<1){
        cout<<"Hey "<<nameP2<<" You won the toss:\n Choose your piece: \n1.X \n2.O\nReturn the number 1 or 2 of your choise:\nIf choice is invalid then you'll get 'O' :\n";
        cin>>x;
        if(x==1){
            return 'X';
        }else{
            return 'O';
        }
    }else{
        cout<<"COMPUTER Won the toss:\n";
    }
    return '$';
}

void showBoard(char board[][SIDE])
{
    printf("\n\n");
 
    printf("\t\t\t %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
 
    printf("\t\t\t------------\n");
 
    printf("\t\t\t %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
 
    printf("\t\t\t------------\n");

    printf("\t\t\t %c | %c | %c \n\n",board[2][0],board[2][1],board[2][2]);
 
    return;
}

void initialise(char board[][SIDE]){
    //to create matrix(array) to play game
    for(int i=0;i<SIDE;i++){
        for(int j=0;j<SIDE;j++){
            board[i][j]=' ';
        }
    }
    showBoard(board);
    return ;
}

bool gameOver(char board[][SIDE]){

    //to check if game is over or not either win or lose , 
    //there is no way of draw ryt now 

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

    //Stalemate means , one player don't have any legal moves to play 
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
