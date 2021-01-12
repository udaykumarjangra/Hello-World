#include<bits/stdc++.h>
using namespace std;
char board[3][3];
char player='X', opponent = 'O';
void printBoard()
{
	cout<<endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool movesLeft()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(board[i][j]=='_')
			{
				return true;
			}
		}
	}
	//cout<<"No Moves Left"<<endl;
	return false;
}

int check()
{
	for(int row=0; row<3; row++)
	{
		if(board[row][0]==board[row][1] && board[row][1]==board[row][2])
		{
			if(board[row][0]==player)
			{
				return 10;
			}
			else if(board[row][0]==opponent){
				return -10;
			}
		}
	}
	
	for(int col=0; col<3; col++)
	{
		if(board[0][col]==board[1][col] && board[1][col]==board[2][col])
		{
			if(board[0][col]==player)
			{
				return 10;
			}
			else if(board[0][col]==opponent)
			{
				return -10;
			}
		}
	}
	
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
	{
		if(board[0][0]==player)
		{
			return 10;
		}
		else if(board[0][0]==opponent)
		{
			return -10;
		}
	}
	if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) 
    { 
        if(board[0][2]==player) 
        {
        	return 10;    	
		} 
        else if(board[0][2]==opponent)
		{
			return -10;
		}  
    }
	return 0; 
}

int minmax(int depth, bool isMax)
{
	int score=check();
	if(score==10 || score==-10)
	{
		return score;
	}
	if(movesLeft()==false)
	{
		return 0;
	}
	
	if(isMax)
	{
		int best = -1000;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				if(board[i][j]=='_')
				{
					board[i][j]==player;
					best = max(best, minmax((depth+1), !isMax));
					board[i][j]='_';
				}
				
			}
		}
		return best;
	}
}
struct Move{
	int row;
	int col;
};
Move findBestMove()
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row=-1;
	bestMove.col=-1;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(board[i][j]=='_')
			{
				board[i][j]=player;
				int moveVal=minmax(0,false);
				board[i][j]='_';
				if(moveVal>bestVal)
				{
					bestMove.row=i;
					bestMove.col=j;
					bestVal=moveVal;
				}
			}
		}
	}
	return bestMove;
}

int main()
{
	int x,y;
	
	memset(board, '_', sizeof(board));
	while(movesLeft())
	{
		cout<<"Enter X, Y value where you want to mark X: ";
		cin>>x>>y;
		board[x][y]=player;
		printBoard();
		Move bestMove = findBestMove();
		board[bestMove.row][bestMove.col]=opponent;
		printBoard();
		cout<<"Check "<<check()<<endl;
		if(check()==10 || check()== -10)
		{
			cout<<"Game Over"<<endl;
			if(check() == 10)
			{
				cout<<"Player Won"<<endl;
			}
			else{
				cout<<"Computer Won"<<endl;
			}
			break;
		}
	}
	if(!movesLeft() && check()==0 )
	{
		cout<<"Draw"<<endl;
	}
}
