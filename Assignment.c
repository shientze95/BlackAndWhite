#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<conio.h>

void display(char box[8][8])
{	
	int a=0;
	int b=0;		
	do
	{
		for(a=0;a<8;a++)
		{
			for(b=0;b<8;b++)
			{
				printf("| %c",box[a][b]);
			}
		
			printf("|\n");
		}
	printf("\n 'w' to go up\n");
	printf("\n 'a' to go left\n");
	printf("\n 's' to go down\n");
	printf("\n 'd' to go right\n");
	printf("\n 'Space' to confirm");
	printf("\n 'Q' to quit");
	}while (b<8);
}

struct player
{
	char name[32];
	char token;
	int score;
};
int counttokens(char box[8][8],char playertokens)
{
	int counter=0;
	int x,y;
	for(x=0;x<8;x++)
	{	for(y=0;y<8;y++)
			if (box[x][y]== playertokens)
				counter++;

	}

return counter;

} 
int fliptokens(char box[8][8],char playertoken,int x,int hurairah)
{	
	int count=0;
	int innercount=0;
	int x1,y1;
	int x2,y2;
	
	for(y1=hurairah;y1<8;y1++)
		{	
			if(box[x][y1] == ' ')
			
			break;
			
			else if(box[x][y1] == playertoken)
				
				for(y2=hurairah;y2<y1;y2++)
				{
					box[x][y2]=playertoken;
					innercount++;
				}
				
				if(innercount>0)
				{	
					count--;
					break;
				}
		}
	for(y1=hurairah;y1>=0;y1--)
		{
			if(box[x][y1] == ' ')
			
			break;
			
			else if(box[x][y1] == playertoken)
			
				for(y2=hurairah;y2>y1;y2--)
				{
					box[x][y2]=playertoken;
					innercount++;
					
				}
				if(innercount>0)
				{
					count--;
					break;
				}
		}		
	for(x1=x;x1<8;x1++)
		{
			if(box[x1][hurairah] == ' ')
			
			break;
			
			else if(box[x1][hurairah] == playertoken)
				
				for(x2=x;x2<x1;x2++);
				{
					box[x2][hurairah]=playertoken;
					innercount++;
				
				}
				if(innercount>0)
				{	
					count--;
					break;
				}
		}
	
	for(x1=x;x1>=0;x1--)
		{
			if(box[x1][hurairah] == ' ')
			
			break;
			
			else if (box[x1][hurairah] = playertoken)
				for(x2=x;x2>x1;x2--);
				{
					box[x2][hurairah]=playertoken;
					innercount++;
				
				}
				if (innercount>0)
				{	
					count--;
					break;
				}
		}
	return count;
}
	
struct player game()
{	
	int x=0;
	int hurairah=0;
	char bob;
	char userinput;
	int a,b,c;
	char box[8][8];
	int invisibleplayer=2;
	int allx=0;
	int allhurairah=0;
	int counter=0;
	int tokencount=0;
	bool loop = true, confirm=false;
	struct player player1;
	struct player player2;
	struct player playerinvisible;
	printf("@o@o@o@o@o@o@o Welcome to The Game Black and White @o@o@o@o@o@o@o\n");
	printf("\nPlease enter your details\n");
	player1.token='@';
	printf("What is player 1 name?");
	scanf(" %s",&player1.name);
	player2.token='o';
	printf("What is player 2 name?");
	scanf(" %s",&player2.name);
		
	for(a=0;a<8;a++)
		for(b=0;b<8;b++)
	{
		box[a][b]= ' ';
	}
	box[3][3]='@';
	box[4][4]='@';
	box[3][4]='o';
	box[4][3]='o';
	while(loop)
	{
		if (invisibleplayer==2)
		{
			playerinvisible=player1;
			invisibleplayer=1;
		}
		else 
		{
			playerinvisible=player2;
			invisibleplayer=2;
		}
		display(box);
		confirm=false;
		while(!confirm)
		{
			system("cls");
			bob=box[x][hurairah];
			box[x][hurairah]= 'X';
			printf("\nIts %s turn\n",playerinvisible.name);
			player1.score=counttokens(box,player1.token);
			player2.score=counttokens(box,player2.token);
			printf("\n%s Tokens: %i\n",player1.name,player1.score);
			printf("\n%s Tokens: %i\n",player1.name,player2.score);
			display(box);
			userinput=getch();
			
			if(userinput == ' ')
			{
				if(bob!='@' && bob!='o')
				{	
					box[x][hurairah]= playerinvisible.token;
					confirm=true;
					
				}
				else 
					box[x][hurairah]=bob;
					
			}
			else
			{
				allx=x;
				allhurairah=hurairah;
				if (userinput== 'w')
				{
					if(x>0)
				
						x--;
				
				}
				else if(userinput=='a')
				{
					if(hurairah>0)
				
						hurairah--;
				
				}
				else if(userinput=='s')
				{
					if(x<7)
				
						x++;
				
				}
				else if(userinput=='d')
				{
					if(hurairah<7)
				
						hurairah++;
				}
					
				box[allx][allhurairah]=bob;
			}
		}	 
	}
	return player1;
}


int main()
{	
	struct player winningplayer;
	winningplayer=game();
}
