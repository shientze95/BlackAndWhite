#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<conio.h>
#include<sys/stat.h>

void display(char box[8][8])
{	
	int a=0;
	int b=0;		
	do
	{	for(a=0;a<8;a++)
		{
			for(b=0;b<8;b++)
			{
				printf("| %c",box[a][b]);
			}

			printf("|\n");	
		}
	
	printf("\n 'w' to go up");
	printf("\n 'a' to go left");
	printf("\n 's' to go down");
	printf("\n 'd' to go right");
	printf("\n 'Space' to confirm");
	printf("\n 'e' to skip turns");
	printf("\n 'q' to quit");
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
	int x1=0;
	int y1=0;
	int x2=0;
	int y2=0;
	int diagonalloop = 0;
	int movingdiagonall=1;
	/*right*/
	for(y1=hurairah;y1<8;y1++)
		{	
			if(box[x][y1] == ' ')
			
			break;
			
			else if(box[x][y1] == playertoken)
			{	
				for(y2=hurairah;y2<y1;y2++)
				{
					box[x][y2]=playertoken;
					innercount++;
					count++;
				}
				
				if(innercount>0)
				{	
					count--;
					break;
				}
			}
		}
	/*Left*/
	innercount=0;
	for(y1=hurairah;y1>=0;y1--)
	{
		if(box[x][y1] == ' ')
			break;
		else if(box[x][y1] == playertoken)
		{
			for(y2=hurairah;y2>y1;y2--)
			{
				box[x][y2]=playertoken;
				innercount++;
				count++;
					
			}
				if(innercount>0)
				{
					count--;
					break;
				}
		}
	}
/*Down*/
	innercount=0;		
	for(x1=x;x1<8;x1++)
		{
			if(box[x1][hurairah] == ' ')
			
			break;
			
			else if(box[x1][hurairah] == playertoken)
			{	
				for(x2=x;x2<x1;x2++)
				{
					box[x2][hurairah]=playertoken;
					innercount++;
					count++;
				}
				if(innercount>0)
				{	
					count--;
					break;
				}
			}
		}
/*Up*/
	innercount=0;
	for(x1=x;x1>0;x1--)
		{
			if(box[x1][hurairah] == ' ')
				break;
			else if (box[x1][hurairah] == playertoken)
			{
				for(x2=x;x2>x1;x2--)
				{
					box[x2][hurairah]=playertoken;
					innercount++;
					count++;
				
				}
				if (innercount>0)
				{	
					count--;
					break;
				}
			}
		}
/*Down right*/
	x1=x;
	y1=hurairah;
	movingdiagonall=1;
	innercount=0;
	do
	{
		if ((x+ movingdiagonall)<8)
			x1=x+movingdiagonall;
		else 
			break;
		if ((hurairah+ movingdiagonall)<8)
			y1=hurairah+movingdiagonall;
		else
			break;
		if (box[x1][y1]==' ')
			break;
		else if (box[x1][y1]==playertoken)
		{
			for (diagonalloop=0; diagonalloop < movingdiagonall; diagonalloop++)
			{
				box[x+diagonalloop][hurairah+diagonalloop]=playertoken;
				innercount++;
				count++;
			}
			if(innercount>0)
			{	
				count--;
				break;
			}
		}
		else 
		{
			movingdiagonall++;
		}
					
	}while (movingdiagonall>1);
/*Downleft*/
	x1=x;
	y1=hurairah;
	movingdiagonall=1;
	innercount=0;
	do
	{
		if ((x+ movingdiagonall)<8)
			x1=x+movingdiagonall;
		else 
			break;
		if ((hurairah- movingdiagonall)>=0)
			y1=hurairah-movingdiagonall;
		else
			break;
		if (box[x1][y1]==' ')
			break;
		else if (box[x1][y1]==playertoken)
		{
			for (diagonalloop=0; diagonalloop < movingdiagonall; diagonalloop++)
			{
				box[x+diagonalloop][hurairah-diagonalloop]=playertoken;
				innercount++;
				count++;
			}
			if(innercount>0)
			{	
				count--;
				break;
			}
		
			}
		else 
		{
			movingdiagonall++;
		}
			
	}while (movingdiagonall>1);
/*up right*/
	x1=x;
	y1=hurairah;
	movingdiagonall=1;
	innercount=0;
	do
	{
		if (x - movingdiagonall>=0)
			x1=x-movingdiagonall;
		else 
			break;
		if ((hurairah+movingdiagonall)<8)
			y1=hurairah+movingdiagonall;
		else
			break;
		if (box[x1][y1]==' ')
			break;
		else if (box[x1][y1]==playertoken)
		{
			for (diagonalloop=0; diagonalloop <movingdiagonall; diagonalloop++)
			{
				box[x-diagonalloop][hurairah+diagonalloop]=playertoken;
				innercount++;
				count++;
			}
			if(innercount>0)
			{	
				count--;
				break;
			}
		
		}
		else 
		{
			movingdiagonall++;
		}
			
	}while (movingdiagonall>1);
/*up left*/
	x1=x;
	y1=hurairah;
	movingdiagonall=1;
	innercount=0;
	do
	{
		if (x-movingdiagonall>=0)
			x1=x-movingdiagonall;
		else 
			break;
		if (hurairah-movingdiagonall>=0)
			y1=(hurairah-movingdiagonall);
		else
			break;
		if (box[x1][y1]==' ')
			break;
		else if (box[x1][y1]==playertoken)
		{
			for (diagonalloop=0; diagonalloop <movingdiagonall; diagonalloop++)
			{
				box[x-diagonalloop][hurairah-diagonalloop]=playertoken;
				innercount++;
				count++;
			}
			if(innercount>0)
			{	
				count--;
				break;
			}
		
		}
		else 
		{
			movingdiagonall++;
		}
			
	}while (movingdiagonall>1);

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
			player1.score=counttokens(box,player1.token);
			player2.score=counttokens(box,player2.token);
			bob=box[x][hurairah];
			box[x][hurairah]= 'X';
			printf("\nIts %s turn\n",playerinvisible.name);
			printf("\n%s(@) Tokens: %i\n",player1.name,player1.score);
			printf("\n%s(o) Tokens: %i\n",player2.name,player2.score);
			display(box);
			userinput=getch();
			
			if(userinput == ' ')
			{
				if(bob!='@' && bob!='o')
				{	
					box[x][hurairah]= playerinvisible.token;
					counter=fliptokens(box,playerinvisible.token,x,hurairah);
					if (counter<1)
					{
						box[x][hurairah]=' ';
						printf("\nInvalid move");
						printf("\nPress any key to continue");
						getch();
						
					}
					else 							
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
				else if(userinput == 'q')
				{	
					loop = false ;
					confirm=true;
				}
				else if(userinput== 'e')
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
				}
				box[allx][allhurairah]=bob;
			}
		}
	}
	if(player1.score > player2.score)
	{	
		return player1;
	}
	else if (player2.score > player1.score)
	{
		return player2;
	}
	else
	{
		player1.score=100;
		return player1;
	}	
}

void testfile()
{
	FILE *file;
	int state;
	struct _stat filestat;
	state = _stat("Assignment.txt", &filestat);
	if (state < 0)
	{
		file = fopen("Assignment.txt", "w");
		printf("No log available.\n");
	}
}

int main()
{	
	struct player winningplayer;
	char prevHighscore[120];
	FILE *file;
	printf("@o@o@o@o@o@o@o Welcome to The Game Black and White @o@o@o@o@o@o@o\n");
	printf("Previous winner:\n");
	testfile();
	file = fopen("Assignment.txt","r");
	while (fgets(prevHighscore, 120, file) != NULL)
	{
		printf("%s", prevHighscore);
	}
	fclose(file);
	printf("\n");
	winningplayer=game();
	if (winningplayer.score == 100)
	{
		printf("\nGame is Tied\n");
	}
	else
	{
		printf("\nWinner is %s with a score of %i.Thank you for playing :D",winningplayer.name,winningplayer.score);
	}
	printf("\nPress any key to exit.");
	getch();	
	
	if (winningplayer.score != 100)
	{
		file = fopen("Assignment.txt","w");
		fprintf(file,"Wining Player Name: %s", winningplayer.name);
		fprintf(file,"\nWining Player Tokens: %i", winningplayer.score); 
		fclose(file);
	}
	else
	{
		file = fopen("Assignment.txt","w");
		fprintf(file,"Previous game tied");
		fclose(file);
	}
	getchar(); 
	return 0;
}

