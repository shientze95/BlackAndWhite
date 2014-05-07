#include<stdio.h>
#include<stdbool.h>
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
	}while (b<8);
}

struct player
{
	char name[32];
	char token;
	int score;
};
	
struct player game()
{	
	int x=0;
	int hurairah=0;
	char bob;
	char userinput;
	int a,b,c;
	char box[8][8];
	int invisibleplayer=2;
	bool loop = true, confirm=false;
	struct player player1;
	struct player player2;
	struct player playerinvisible;
	int allx,allhurairah;
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
			printf("\n %s\n",playerinvisible.name);
			bob=box[x][hurairah];
			box[x][hurairah]= 'X';
			allx=x;
			allhurairah=hurairah;
			display(box);
			userinput=getch();
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
			else if(userinput == 'x')
			{
				printf("Holy-moly");
				if(box[x][hurairah]== ' ')
				{	
					box[x][hurairah]= '&';
					confirm=true;
				}
			}	
			else 
			
			{	
				printf("InVAliD Inpuy\n");
			}
			box[allx][allhurairah]=bob;
	}
	return player1;
	}
}
int main()
{	
	struct player winningplayer;
	winningplayer=game();
	printf("%s",winningplayer.name);
	return 0;
}

