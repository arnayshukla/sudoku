#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<process.h>
#include<stdio.h>

void frontpage(); //displays the first page

void grid(); //displays the sudoku grid

void logic(const char a[9][9],int); // contains the main logic including
//random placement of elements, control of cursor etc.

void array(int);//contains the initialized array and passes it randomly
//to the logic function along with a integer according to difficulty level

void mmenu(); //displays main menu and accepts the choice from user

void play(); //displays play menu and accepts the choice from user

void ins(); // displays the instructions

void abt(); //contains information about the project and developers

void beg(); // starts sudoku with beginner's level

void inter(); //starts sudoku with intermediate level

void exp(); //starts sudoku with expert level

void win(); // displays winning message and menu options

void lose(); // displays losing message and menu options

void time(dostime_t); // calculates the time elapsed during playing sudoku


void main()
{
	randomize();
	textcolor(YELLOW);
	frontpage();
	mmenu();
}

void frontpage()
{
	clrscr();
       _setcursortype(_NOCURSOR); //hides the cursor
	gotoxy(5,1);
	cout<<"É";
	gotoxy(6,1);

	for(int j=0; j<69; j++)
	cout<<"Í";

	gotoxy(75,1);
	cout<<"»";

	for(int i=2;i<9;i++)
	{
		gotoxy(5,i);
		cout<<"º";
		gotoxy(75,i);
		cout<<"º";
	}

	gotoxy(5,i);
	cout<<"Ì";

	for(j=0; j<69; j++)
	cout<<"Í";

	gotoxy(75,i);
	cout<<"¹";

	for(i;i<22;i++)
	{
		gotoxy(5,i);
		cout<<"º";
		gotoxy(75,i);
		cout<<"º";
	}

	gotoxy(5,i);
	cout<<"È";

	for(j=0; j<69; j++)
	cout<<"Í";

	gotoxy(75,i);
	cout<<"¼";

	delay(1000);
	gotoxy(9,3);
	cout<<"ÚÄÄ¿ ¿  Ú ÂÄÄ¿ ÚÄÄ¿ ¿ ÚÄ  ¿  Ú   ÚÄÄ¿ ¿  Ú ÚÄÄ¿ ÚÄÄ¿ ¿    ÚÄÄ¿";
	gotoxy(9,4);
	cout<<"ÀÄÄ¿ ³  ³ ³  ³ ³  ³ ÃÄÁ¿  ³  ³   ³ÄÄÙ ³  ³ ÚÄÄÙ ÚÄÄÙ ³    ³ÄÄÄ";
	gotoxy(12,5);
	cout<<"³ ³  ³ ³  ³ ³  ³ ³  ³  ³  ³   ³    ³  ³ ³    ³    ³    ³";
	gotoxy(9,6);
	cout<<"ÀÄÄÙ ÀÄÄÙ ÁÄÄÙ ÀÄÄÙ Ù  À  ÀÄÄÙ   ³    ÀÄÄÙ ÀÄÄÙ ÀÄÄÙ ÀÄÄÙ ÀÄÄÙ";
	gotoxy(9,7);

	for(i=0;i<62;i++)
	cout<<"Ä";

	delay(1000);
	char ch[]={"WELCOME TO OUR PROJECT"};
	char ch1[]={"Developed By:"};
	char ch2[]={"Anshul Tayal"};
	char ch3[]={"Arnay Shukla"};
	char ch4[]={"Guided By:"};
	char ch5[]={"Mr. Shaktirish K. Agrawal"};

	gotoxy(28,12);
	for(j=0;ch[j]!='\0';j++)
	{
		sound(10000); //turns on speakers and produces sound
		delay(50);
		nosound(); //turns of speaker
		cout<<ch[j];
	}

	gotoxy(7,18);
	delay(500);
	for(j=0;ch1[j]!='\0';j++)
	{
		sound(10000);
		delay(50);
		nosound();
		cout<<ch1[j];
	}

	gotoxy(7,19);
	delay(200);
	for(j=0;ch2[j]!='\0';j++)
	{
		sound(10000);
		delay(50);
		nosound();
		cout<<ch2[j];
	}

	gotoxy(7,20);
	delay(100);
	for(j=0;ch3[j]!='\0';j++)
	{
		sound(10000);
		delay(50);
		nosound();
		cout<<ch3[j];
	}

	gotoxy(49,18);
	delay(200);
	for(j=0;ch4[j]!='\0';j++)
	{
		sound(10000);
		delay(50);
		nosound();
		cout<<ch4[j];
	}

	gotoxy(49,20);
	delay(200);
	for(j=0;ch5[j]!='\0';j++)
	{
		sound(10000);
		delay(50);
		nosound();
		cout<<ch5[j];
	}

	delay(500);
	_setcursortype(_NORMALCURSOR); // displays normal cursor
	gotoxy(5,23);

	cout<<"Press Any Key To Proceed";
	_setcursortype(_NOCURSOR);
	getch();
	sound(10000);
	delay(50);
	nosound();
}

void array(int m)
{
	const char a[9][9]={{'8','4','3','1','9','5','7','2','6'},{'7','9','5','4','2','6','3','1','8'},{'2','6','1','3','8','7','9','5','4'},{'3','7','4','2','1','9','6','8','5'},{'5','8','9','7','6','4','2','3','1'},{'6','1','2','5','3','8','4','7','9'},{'4','3','8','9','5','2','1','6','7'},{'9','2','6','8','7','1','5','4','3'},{'1','5','7','6','4','3','8','9','2'}};
	const char b[9][9]={{'7','8','2','5','1','9','4','3','6'},{'5','9','6','3','4','2','8','7','1'},{'3','1','4','8','6','7','2','9','5'},{'2','5','1','7','3','8','6','4','9'},{'9','3','7','6','5','4','1','2','8'},{'6','4','8','9','2','1','7','5','3'},{'1','2','5','4','8','3','9','6','7'},{'8','7','3','2','9','6','5','1','4'},{'4','6','9','1','7','5','3','8','2'}};
	const char c[9][9]={{'1','4','5','3','2','7','6','9','8'},{'8','3','9','6','5','4','1','2','7'},{'6','7','2','9','1','8','5','4','3'},{'4','9','6','1','8','5','3','7','2'},{'2','1','8','4','7','3','9','5','6'},{'7','5','3','2','9','6','4','8','1'},{'3','6','7','5','4','2','8','1','9'},{'9','8','4','7','6','1','2','3','5'},{'5','2','1','8','3','9','7','6','4'}};
	const char d[9][9]={{'6','3','2','7','8','1','9','4','5'},{'4','8','7','5','9','6','2','1','3'},{'5','1','9','2','4','3','8','7','6'},{'8','6','4','3','5','2','7','9','1'},{'7','5','1','9','6','8','3','2','4'},{'2','9','3','1','7','4','6','5','8'},{'9','4','5','6','3','7','1','8','2'},{'1','7','6','8','2','5','4','3','9'},{'3','2','8','4','1','9','5','6','7'}};
	const char e[9][9]={{'5','8','6','3','7','4','9','1','2'},{'1','3','7','9','5','2','8','6','4'},{'2','4','9','8','1','6','5','7','3'},{'8','7','2','5','4','3','1','9','6'},{'6','9','3','7','8','1','2','4','5'},{'4','1','5','6','2','9','7','3','8'},{'9','5','4','2','3','7','6','8','1'},{'7','2','1','4','6','8','3','5','9'},{'3','6','8','1','9','5','4','2','7'}};
	randomize();
	int r=random(5);
	if(r==0)
	logic(a,m);
	if(r==1)
	logic(b,m);
	if(r==2)
	logic(c,m);
	if(r==3)
	logic(d,m);
	if(r==4)
	logic(e,m);
}


void logic(const char a[9][9],int z)
{
	char d[9][9]={{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'}};
	char e[9][9]={{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0','0','0'}};
	int i,j;
	randomize();
	for(int x=0; x<z; x++)
	{
		P:
		i=random(9);
		j=random(9);
		if(d[i][j]!='0')
		goto P;
		else
		{
			d[i][j]=a[i][j];
			e[i][j]=a[i][j];
		}
	}

	int p=22;
	int q=7;
	for(x=0;x<9;x++)
	{
		delay(200);
		p=22;
		for(int y=0; y<9; y++)
		{
			gotoxy(p,q);
			if(d[x][y]=='0')
			cout<<" ";
			else
			cout<<d[x][y];
			p+=4;
		}
		q+=2;
	}

		_setcursortype(_NORMALCURSOR);
		char ch[50];
		gotoxy(1,7);
		cout<<"Enter Your Name:";
		gotoxy(1,8);
		gets(ch);
		sound(10000);
		delay(50);
		nosound();
		gotoxy(1,7);
		cout<<"                ";
		gotoxy(1,9);
		cout<<"is playing";

		struct dostime_t t; //inbuilt structure stores time
		_dos_gettime(&t); //stores the system time in members of dostime_t structure

		char key;
		p=22,q=7;
		gotoxy(5,25);
		cout<<"Enter = submit | p = play menu | m = main menu | t = timer hide/display";
		gotoxy(p,q);
		while(!kbhit()) //basically the loop condition is while(!0)
		{
			L:
			gotoxy(p,q);
			key=getch();
			gotoxy(59,19);
			cout<<"           ";
			gotoxy(p,q);
			if(key=='w')
			q-=2;
			else if(key=='s')
			q+=2;
			else if(key=='a')
			p-=4;
			else if(key=='d')
			p+=4;
			else if(key=='p')
			play();
			else if(key=='m')
			mmenu();
			else if(key=='t')
			time(t);
			else if(isdigit(key))
			{
				if(p==22)
			       j=0;
			       else if(p==26)
			       j=1;
			       else if(p==30)
			       j=2;
			       else if(p==34)
			       j=3;
			       else if(p==38)
			       j=4;
			       else if(p==42)
			       j=5;
			       else if(p==46)
			       j=6;
			       else if(p==50)
			       j=7;
			       else if(p==54)
			       j=8;
			       if(q==7)
			       i=0;
			       else if(q==9)
			       i=1;
			       else if(q==11)
			       i=2;
			       else if(q==13)
			       i=3;
			       else if(q==15)
			       i=4;
			       else if(q==17)
			       i=5;
			       else if(q==19)
			       i=6;
			       else if(q==21)
			       i=7;
			       else if(q==23)
			       i=8;

			       if(e[i][j]!='0')
					goto L;
			       else
			       {
					if(key=='0')
					{
						gotoxy(59,19);
						cout<<"WRONG INPUT";
						goto L;
					}
					else
				       {
						textcolor(LIGHTRED);
						cprintf("%1c",key);
						d[i][j]=key;
						textcolor(YELLOW);
					}
			       }
			}
		       else if(key==13)
		       {
			       clrscr();
			       int x=0;
			       for(i=0;i<9;i++)
			       for(j=0;j<9;j++)
			       if(a[i][j]!=d[i][j])
			       {
					x=1;
					break;
			       }
			       if(x==1)
			       lose();
			       else
			       win();
			}
			else
			{
				gotoxy(59,19);
				cout<<"WRONG INPUT";
				goto L;
			}


			if(p>54)
			p=22;
			if(p<22)
			p=54;
			if(q>23)
			q=7;
			if(q<7)
			q=23;
			gotoxy(p,q);
		}
}


void grid()
{
	clrscr();
	gotoxy(9,1);
	cout<<"ÚÄÄ¿ ¿  Ú ÂÄÄ¿ ÚÄÄ¿ ¿ ÚÄ  ¿  Ú   ÚÄÄ¿ ¿  Ú ÚÄÄ¿ ÚÄÄ¿ ¿    ÚÄÄ¿";
	gotoxy(9,2);
	cout<<"ÀÄÄ¿ ³  ³ ³  ³ ³  ³ ÃÄÁ¿  ³  ³   ³ÄÄÙ ³  ³ ÚÄÄÙ ÚÄÄÙ ³    ³ÄÄÄ";
	gotoxy(12,3);
	cout<<"³ ³  ³ ³  ³ ³  ³ ³  ³  ³  ³   ³    ³  ³ ³    ³    ³    ³";
	gotoxy(9,4);
	cout<<"ÀÄÄÙ ÀÄÄÙ ÁÄÄÙ ÀÄÄÙ Ù  À  ÀÄÄÙ   Ù    ÀÄÄÙ ÀÄÄÙ ÀÄÄÙ ÀÄÄÙ ÀÄÄÙ";

	gotoxy(9,5);
	for(int i=0;i<62;i++)
	cout<<"Ä";

	gotoxy(20,6);
	cout<<"ÚÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄ¿"<<endl;
	int a=7;
	for(i=0;i<8;i++)
	{
		gotoxy(20,a++);
		cout<<"³   ³   ³   ³   ³   ³   ³   ³   ³   ³"<<endl;
		gotoxy(20,a++);
		cout<<"ÃÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄ´"<<endl;
	}
	gotoxy(20,a);
	cout<<"³   ³   ³   ³   ³   ³   ³   ³   ³   ³"<<endl;
	gotoxy(20,++a);
	cout<<"ÀÄÄÄÁÄÄÄÁÄÄÄÁÄÄÄÁÄÄÄÁÄÄÄÁÄÄÄÁÄÄÄÁÄÄÄÙ"<<endl;
	gotoxy(59,11);
	delay(300);
	cout<<"Use [w] to move up"<<endl;
	gotoxy(59,13);
	delay(300);
	cout<<"Use [s] to move down"<<endl;
	gotoxy(59,15);
	delay(300);
	cout<<"Use [a] to move left"<<endl;
	delay(300);
	gotoxy(59,17);
	cout<<"Use [d] to move right"<<endl;
}

void mmenu()
{
	clrscr();
	_setcursortype(_NOCURSOR);
	int ch;
	gotoxy(5,2);
	cout<<" ÂÄÄÂÄÄÂ  ÂÄÄÄÄÄÂ ÚÄÄÂÄÄ¿  ÂÄÄÄÄÂ       ÂÄÄÄÂÄÄÄÂ  ÂÄÄÄÄÄ  ÂÄÄÄÄÂ  Â     Â"<<endl;
	gotoxy(5,3);
	cout<<" ³  Á  ³  ³     ³    ³     ³    ³       ³   Á   ³  ³       ³    ³  ³     ³ "<<endl;
	gotoxy(5,4);
	cout<<" ³     ³  ÃÄÄÄÄÄ´    ³     ³    ³  ÄÄÄ  ³       ³  ÃÄÄÄÄ   ³    ³  ³     ³  "<<endl;
	gotoxy(5,5);
	cout<<" ³     ³  ³     ³    ³     ³    ³       ³       ³  ³       ³    ³  ³     ³ "<<endl;
	gotoxy(5,6);
	cout<<" Ù     À  Á     Á ÀÄÄÁÄÄÙ  Á    Á       Ù       À  ÁÄÄÄÄÄ  Á    Á  ÁÄÄÄÄÄÁ "<<endl;
	gotoxy(4,7);

	for(int i=0;i<77;i++)
	cout<<"Ä";

	delay(200);
	cout<<"\n \n \n1. ABOUT THE PROJECT"<<endl;
	delay(200);
	cout<<"\n2. INSTRUCTIONS"<<endl;
	delay(200);
	cout<<"\n3. PLAY"<<endl;
	delay(200);
	cout<<"\n4. EXIT"<<endl;
	delay(200);
	P:
	_setcursortype(_NORMALCURSOR);
	cout<<"\n \nEnter the choice"<<endl;
	cin>>ch;
	_setcursortype(_NOCURSOR);
	sound(10000);
	delay(50);
	nosound();
	switch(ch)
	{
		case 1: abt();
		mmenu();
		break;
		case 2: ins();
		mmenu();
		break;
		case 3: play();
		break;
		case 4: exit(0);
		default:
		cout<<" WRONG INPUT"<<endl;
	}
	delay(500);
	cout<<"Try once again :";
	goto P;
}

void ins()
{
	clrscr();
	_setcursortype(_NOCURSOR);
	gotoxy(5,2);
	cout<<" ÚÄÂÄ¿ ÂÄÄÄÂ ÚÄÄ¿ ÚÄÂÄ¿ ÂÄÄ¿ ¿   Ú  ÚÄÄ¿ ÚÄÂÄ¿ ÚÄÂÄ¿  ÚÄÄÄ¿ ÂÄÄÄÂ ÚÄÄ¿      " <<endl;
	gotoxy(5,3);
	cout<<"   ³   ³   ³ ³      ³   ³  ³ ³   ³  ³      ³     ³    ³   ³ ³   ³ ³     "<<endl;
	gotoxy(5,4);
	cout<<"   ³   ³   ³ ÀÄÄ¿   ³   ÃÄÂÙ ³   ³  ³      ³     ³    ³   ³ ³   ³ ÀÄÄ¿       "<<endl;
	gotoxy(5,5);
	cout<<" ÀÄÁÄÙ Á   Á ÀÄÄÙ   Á   Ù ÀÄ ÀÄÄÄÙ  ÀÄÄÙ   Á   ÀÄÁÄÙ  ÀÄÄÄÙ Á   Á ÀÄÄÙ   "<<endl;

	gotoxy(5,6);
	for(int i=0;i<70;i++)
	cout<<"Ä";

	delay(500);
	cout<<"\n\n1. The sudoku puzzle consists of 81 squares divided into nine 3*3 blocks."<<endl;
	cout<<"   Some of the squares already have numbers in them."<<endl;
	delay(500);
	cout<<"\n2. To solve the sudoku puzzle you have to use the numbers 1-9 to fill in the"<<endl;
	cout<<"   blanks spaces so that each row, each coloumn and each 3*3 square has all the"<<endl;
	cout<<"   numbers appearing once."<<endl;
	delay(500);
	cout<<"\n3. The only thing you need to solve a sudoku number place puzzle is logic."<<endl;
	delay(500);
	cout<<"\n4. Focus on one particular blank square at a time , scan its row , coloumn";
	cout<<"         and block."<<endl;
	delay(500);
	textcolor(LIGHTRED+BLINK);
	cprintf("\n5. Use w,a,s,d to move cursor Up, Left, Down & Right respectively.");
	delay(500);
	cout<<endl;
	textcolor(YELLOW);
	cout<<"\n Press any key to go back to main menu.";
	_setcursortype(_NOCURSOR);
	getch();
	sound(10000);
	delay(50);
	nosound();
}

void play()
{
	clrscr();
	_setcursortype(_NOCURSOR);
	int ch;
	gotoxy(5,2);
	cout<<"ÂÄÄÄÄ¿  ¿      ÂÄÄÄÄÄÂ Â     Â        ÂÄÄÄÂÄÄÄÂ  ÂÄÄÄÄÄ  ÂÄÄÄÄÂ  Â     Â "<<endl;
	gotoxy(5,3);
	cout<<"³    ³  ³      ³     ³ ³     ³        ³   Á   ³  ³       ³    ³  ³     ³   "<<endl;
	gotoxy(5,4);
	cout<<"ÅÄÄÄÄÙ  ³      ÃÄÄÄÄÄ´ ÀÄÄÂÄÄÙ  ÄÄÄ   ³       ³  ÃÄÄÄÄ   ³    ³  ³     ³     "<<endl;
	gotoxy(5,5);
	cout<<"³       ³      ³     ³    ³           ³       ³  ³       ³    ³  ³     ³     "<<endl;
	gotoxy(5,6);
	cout<<"Á       ÁÄÄÄÄ  Á     Á    Á           Ù       À  ÁÄÄÄÄÄ  Á    Á  ÁÄÄÄÄÄÁ   "<<endl;
	gotoxy(4,7);

	for(int i=0;i<72;i++)
	cout<<"Ä";

	delay(200);
	cout<<"\n \n \n \n1. BEGINNERS"<<endl;
	delay(200);
	cout<<"\n2. INTERMEDIATE"<<endl;
	delay(200);
	cout<<"\n3. EXPERT"<<endl;
	delay(200);
	cout<<"\n4. BACK TO MAIN MENU"<<endl;
	delay(200);
	cout<<"\n5. EXIT"<<endl;
	P:
	delay(200);
	_setcursortype(_NORMALCURSOR);
	cout<<"\n \nEnter your choice :"<<endl;
	cin>>ch;
	_setcursortype(_NOCURSOR);
	sound(10000);
	delay(50);
	nosound();
	switch(ch)
	{
		case 1:beg();
		break;
		case 2:inter();
		break;
		case 3:exp();
		break;
		case 4:mmenu();
		break;
		case 5:exit(0);
		default:
		cout<<"WRONG CHOICE"<<endl;
	}
	delay(500);
	cout<<"Try once again :";
	goto P;
}

void lose()
{
	_setcursortype(_NOCURSOR);
	gotoxy(11,8);
	cout<<"Â     Â  ÂÄÄÄÄÂ Â    Â    Â     ÂÄÄÄÄÂ  ÚÄÄÄÄ¿  ÂÄÄÄÄÄ    "<<endl;
	gotoxy(11,9);
	cout<<"³     ³  ³    ³ ³    ³    ³     ³    ³  ³       ³      ³ ³ "<<endl;
	gotoxy(11,10);
	cout<<"ÀÄÄÂÄÄÙ  ³    ³ ³    ³    ³     ³    ³  ÀÄÄÄÄ¿  ÃÄÄÄ   ³ ³ "<<endl;
	gotoxy(11,11);
	cout<<"   ³     ³    ³ ³    ³    ³     ³    ³       ³  ³      ³ ³ "<<endl;
	gotoxy(11,12);
	cout<<"   Á     ÁÄÄÄÄÁ ÁÄÄÄÄÁ    ÁÄÄÄÄ ÁÄÄÄÄÁ  ÀÄÄÄÄÙ  ÁÄÄÄÄÄ þ þ "<<endl;

	gotoxy(28,15);
	delay(500);
	cout<<" BETTER LUCK NEXT TIME !!"<<endl;
	gotoxy(20,24);
	cout<<"m = main menu | p = play menu | e = exit";

	L:
	char c=getch();
	_setcursortype(_NORMALCURSOR);
	sound(10000);
	delay(50);
	nosound();
	if(c=='m')
	mmenu();
	else if(c=='p')
	play();
	else if(c=='e')
	exit(0);
	else
	goto L;
}

void win()
{
	 _setcursortype(_NOCURSOR);
	 gotoxy(14,8);
	 delay(200);
	 cout<<"Â     Â  ÂÄÄÄÄÂ Â    Â    Â     Â ÂÄÄÄÄÂ ÂÄÄÄÄÂ       "<<endl;
	 gotoxy(14,9);
	 delay(200);
	 cout<<"³     ³  ³    ³ ³    ³    ³     ³ ³    ³ ³    ³   ³ ³  "<<endl;
	 gotoxy(14,10);
	 cout<<"ÀÄÄÂÄÄÙ  ³    ³ ³    ³    ³     ³ ³    ³ ³    ³   ³ ³  "<<endl;
	 gotoxy(14,11);
	 cout<<"   ³     ³    ³ ³    ³    ³  Â  ³ ³    ³ ³    ³   ³ ³  "<<endl;
	 gotoxy(14,12);
	 delay(200);
	 cout<<"   Á     ÁÄÄÄÄÁ ÁÄÄÄÄÁ    ÁÄÄÁÄÄÁ ÁÄÄÄÄÁ Á    Á   þ þ  "<<endl;

	 gotoxy(35,15);
	 delay(500);
	 cout<<" CONGRATS !!"<<endl;
	 gotoxy(20,24);
	 cout<<"m = main menu | p = play menu | e = exit";

	 L:
	 char c=getch();
	 _setcursortype(_NORMALCURSOR);
	 sound(10000);
	 delay(50);
	 nosound();
	 if(c=='m')
	 mmenu();
	 else if(c=='p')
	 play();
	 else if(c=='e')
	 exit(0);
	 else
	 goto L;

}

void abt()
{
	clrscr();
	_setcursortype(_NOCURSOR);
	gotoxy(5,1);
	cout<<" ÚÄÄ¿ ÂÄÄ¿ÚÄÄ¿¿  ÚÚÄÂÄ¿  ÚÄÂÄ¿¿  ÚÚÄÄ   ÂÄÄ¿ÂÄÄ¿ÚÄÄ¿  ÂÚÄ ÚÄÄ¿ÚÄÂÄ¿"<<endl;
	gotoxy(5,2);
	cout<<" ³  ³ ³  ³³  ³³  ³  ³      ³  ³  ³³     ÃÄÄÙ³  ³³  ³  ³³  ³     ³  "<<endl;
	gotoxy(5,3);
	cout<<" ÃÄÄ´ ÃÄÄ´³  ³³  ³  ³      ³  ÃÄÄ´ÃÄ    ³   ÃÄÂÙ³  ³  ³ÃÄ ³     ³  "<<endl;
	gotoxy(5,4);
	cout<<" Ù  À ÁÄÄÙÀÄÄÙÀÄÄÙ  Á      Á  Ù  ÀÀÄÄ   Ù   Ù ÀÄÀÄÄÙÀÄÁÀÄÄÀÄÄÙ  Á  "<<endl;

	gotoxy(4,5);
	for(int i=0;i<70;i++)
	cout<<"Ä";

	gotoxy(1,6);
	delay(300);
	cout<<"     It improves one's critcal/logical analysis,thus enabling your mind to thinkfaster even when pressured. It increases the mentalfocus ability as you perform the game. This can be applied to our dayÄtoÄday decision making as you learn to focus on your priorities and make the appropriate actions.";
	cout<<"It develops a creativemind as you try to find various ways or tactical gaming moves to finish the     entire game faster with the main target of winning."<<endl;
	gotoxy(1,13);
	delay(1000);
	cout<<"ARNAY SHUKLA :"<<endl;
	cout<<"CoÄdeveloper of the project. He has mainly worked upon the logic of the program.";
	cout<<"He has worked upon the random placement of the elements in the sudoku grid."<<endl;
	cout<<"He solely wrote the code to control the cursor, input the elements and display"<<endl;
	cout<<"the result. He has also applied the sound effect and he has developed the code"<<endl;
	cout<<"for the timer using the inbuilt structure."<<endl;
	delay(1000);
	cout<<"ANSHUL TAYAL :"<<endl;
	cout<<"CoÄdeveloper of the project. He has mainly focused upon the design, presentation";
	cout<<"of the project. He has worked upon the display of the project, that includes the";
	cout<<"frontpage, the grid for the sudoku puzzle and the headings in the project."<<endl;
	cout<<"He has written the code for functions dealing with display and has"<<endl;
	cout<<"interlinked the program."<<endl;
	_setcursortype(_NORMALCURSOR);
	cout<<"Press any key to go back to main menu.";
	getch();
	sound(10000);
	delay(50);
	nosound();
}

void time(dostime_t t)
{
	gotoxy(2,12);
	cout<<"Time elapsed:";
	gotoxy(3,13);
	struct dostime_t t1;
	_dos_gettime(&t1);
	char h=t1.hour-t.hour;
	char m=t1.minute-t.minute;
	char s=t1.second-t.second;

	if(s<0)
	{
		s+=60;
		m--;
	}

	if(m<0)
	{
		m+=60;
		h--;
	}

	if(h<0)
	h+=24;
	_setcursortype(_NOCURSOR);
	cprintf("%02d:%02d:%02d",h,m,s);
	L:
	char a;
	a=getch();
	if(a=='t')
	{
	gotoxy(2,12);
	cout<<"             ";
	gotoxy(3,13);
	cout<<"        ";
	}
	else
	    goto L;
	_setcursortype(_NORMALCURSOR);
}

void beg()
{
	clrscr();
	grid();
	array(60);
	getch();
}

void inter()
{
	clrscr();
	grid();
	array(40);
	getch();
}

void exp()
{
	clrscr();
	grid();
	array(30);
	getch();
}








