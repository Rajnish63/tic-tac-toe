#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int arr_box[3][3];
int count;
void initialize_data();
void data_enter();
void data_rival();
void rival_steps(int *row, int *col);
void display();
int check_win();
int main()
{
	int ch = 1;
	printf("Hello Player,Welcome in the game of tic-tac-toe\n");
	do{
		//initialize the array to 0
		initialize_data();
		count = 0;

		while(1){
			//take input from user and display the boxes
			data_enter();
			++count;
			//take computers data
			data_rival();
			//check for winning
			if (check_win() == 2){
				printf("\n\n\n************* Rival wins ************\n\n\n");
				break;
			}
			else if (check_win() == 1)
			{
				printf("\n\n\n************** You won *************\n\n\n");
				break;
			}
			else if (check_win() == 3)
			{	
				printf("\n\n\n************ No one won ***********\n\n\n");
				break;
			}
		}
		printf("Enter 1 to continue playing\n");
		scanf("%d",&ch);
	}while( ch == 1 );
	return 0;
}

void initialize_data(){
	int i,j;
		for ( i = 0; i < 3; ++i)
		{
			for ( j = 0; j < 3; ++j)
			{
				arr_box[i][j] = 0;
			}
		}
}

void data_enter(){
	int row,col;
	printf("Enter the row number to select.\n");
	scanf("%d",&row);
	printf("Enter column number to select\n");
	scanf("%d",&col);
	//reduce row and col in array form 
	--row;
	--col;

	if (arr_box[row][col] == 0)
	{
		arr_box[row][col] = 1;
	}
	else{
		printf("Box is already marked, please select another one\n");
		data_enter();
	}
}

void display(){
	int i,j;
	for ( i = 0; i < 3; ++i)
	{
		for ( j = 0; j < 3; ++j)
		{
			if (arr_box[i][j] == 1)
				printf(" X ");
			else if (arr_box[i][j] == 2)
				printf(" 0 ");
			else
				printf("   ");
			if (j != 2)
				printf("|");
		}
		if (i != 2)
			printf("\n-----------\n");
		else 
			printf("\n");
	}
}

int check_win(){
	int i;

	//linear row wise check 
	for ( i = 0; i < 3; ++i)
	{
		if (arr_box[i][0] == arr_box[i][1] && arr_box[i][1] == arr_box[i][2]
			  && arr_box[i][0] != 0)
			return arr_box[i][0];
	}

	//linear column wise check
	for ( i = 0; i < 3; ++i)
	{
		if (arr_box[0][i] == arr_box[1][i] && arr_box[1][i] == arr_box[2][i]
			 && arr_box[0][i] != 0)
			return arr_box[0][i];
	}

	//diagonal wise  check
	//forward diagonol
	if (arr_box[0][0] == arr_box[1][1] && arr_box[1][1] == arr_box[2][2]
		    && arr_box[0][0] != 0)
		return arr_box[0][0];

	//backward diagonol
	else if (arr_box[0][2] == arr_box[1][1] && arr_box[1][1] == arr_box[2][0] 
		 	&& arr_box[0][2] != 0)
		return arr_box[0][2];

	//when all moves are done and no one wins
	else if (count == 4)
		return 3;
	
	//when no one wins and moves are left
	else
		return 0;
}

void rival_steps(int *row, int *col){
	int i,j;
	//complete an row if only one box is left
	for (int i = 0; i < 3; ++i)
	{
		if (arr_box[i][0] == arr_box[i][1] && arr_box[i][0] == 2 && arr_box[i][2] == 0)
			{*row =i;*col=2;return;}
		else if (arr_box[i][1] == arr_box[i][2] && arr_box[i][1] == 2 && arr_box[i][0] == 0)
			{*row =i;*col=0;return;}
		else if (arr_box[i][0] == arr_box[i][2] && arr_box[i][0] == 2 && arr_box[i][1] == 0)
			{*row =i;*col=1;return;}
	}
	//complete an column if only one box is left
	for (int i = 0; i < 3; ++i)
	{
		if (arr_box[0][i] == arr_box[1][i] && arr_box[0][i] == 2 && arr_box[2][i] == 0)
			{*row =2;*col=i;return;}
		if (arr_box[1][i] == arr_box[2][i] && arr_box[2][i] == 2 && arr_box[0][i] == 0)
			{*row =0;*col=i;return;}
		else if (arr_box[0][i] == arr_box[2][i] && arr_box[0][i] == 2 && arr_box[1][i] == 0)
			{*row =1;*col=i;return;}
	}
	//complete an diagonal if only one box is left
	//forward diagonol
	if (arr_box[0][0] == arr_box[1][1] && arr_box[0][0] == 2 && arr_box[2][2] == 0)
		{*row =2;*col=2;return;}
	else if (arr_box[1][1] == arr_box[2][2] && arr_box[1][1] == 2 && arr_box[0][0] == 0)
		{*row =0;*col=0;return;}
	else if(arr_box[0][0] == arr_box[2][2] && arr_box[0][0] == 2 && arr_box[1][1] == 0)
		{*row =1;*col=1;return;}

	//backward diagonol
	else if (arr_box[0][2] == arr_box[1][1] && arr_box[0][2] == 2 && arr_box[2][0] == 0)
		{*row =2;*col=0;return;} 
	else if (arr_box[1][1] == arr_box[2][0] && arr_box[1][1] == 2 && arr_box[0][2] == 0) 
		{*row =0;*col=2;return;}
	else if (arr_box[0][2] == arr_box[2][0] && arr_box[0][2] == 2 && arr_box[1][1] == 0) 
		{*row =1;*col=1;return;}

	//moves linear row wise checking user 
	for ( i = 0; i < 3; ++i)
	{
		if (arr_box[i][0] == arr_box[i][1] && arr_box[i][0] == 1 && arr_box[i][2] == 0)
			{*row =i;*col=2;return;}
		else if (arr_box[i][1] == arr_box[i][2] && arr_box[i][1] == 1 && arr_box[i][0] == 0)
			{*row =i;*col=0;return;}
		else if (arr_box[i][0] == arr_box[i][2] && arr_box[i][0] == 1 && arr_box[i][1] == 0)
			{*row =i;*col=1;return;}
	}

	//moves linear column wise checking user 
	for ( i = 0; i < 3; ++i)
	{
		if (arr_box[0][i] == arr_box[1][i] && arr_box[0][i] == 1 && arr_box[2][i] == 0)
			{*row =2;*col=i;return;}
		if (arr_box[1][i] == arr_box[2][i] && arr_box[2][i] == 1 && arr_box[0][i] == 0)
			{*row =0;*col=i;return;}
		else if (arr_box[0][i] == arr_box[2][i] && arr_box[0][i] == 1 && arr_box[1][i] == 0)
			{*row =1;*col=i;return;}
	}

	//moves diagonal wise  checking user
	//forward diagonol
	if (arr_box[0][0] == arr_box[1][1] && arr_box[0][0] == 1 && arr_box[2][2] == 0)
		{*row =2;*col=2;return;}
	else if (arr_box[1][1] == arr_box[2][2] && arr_box[1][1] == 1 && arr_box[0][0] == 0)
		{*row =0;*col=0;return;}
	else if(arr_box[0][0] == arr_box[2][2] && arr_box[0][0] == 1 && arr_box[1][1] == 0)
		{*row =1;*col=1;return;}

	//backward diagonol
	else if (arr_box[0][2] == arr_box[1][1] && arr_box[0][2] == 1 && arr_box[2][0] == 0)
		{*row =2;*col=0;return;} 
	else if (arr_box[1][1] == arr_box[2][0] && arr_box[1][1] == 1 && arr_box[0][2] == 0) 
		{*row =0;*col=2;return;}
	else if (arr_box[0][2] == arr_box[2][0] && arr_box[0][2] == 1 && arr_box[1][1] == 0) 
		{*row =1;*col=1;return;}

	//expected first move
	while(arr_box[*row][*col] == 0){
		time_t t;
		srand((unsigned) time(&t));
		*row = (rand()%2);
		*col = (rand()%2);
		if (arr_box[*row][*col] == 0)
			return;
	}

	//when no pattern found
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (arr_box[i][j] == 0)
			{
				*row = i;
				*col = j;
				break;
			}
		}
	}
}

void data_rival(){
	int row = 2 , col = 2 ;
	rival_steps(&row , &col);
	arr_box[row][col] = 2;
	display(); 
}
