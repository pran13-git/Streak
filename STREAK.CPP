#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<fstream.h>
#include<graphics.h>

class record
{
 public:
 char a[20],b[20];
 int t,playerno;
 void enter(char*,char*);
 void display();
 void time(int,int);
};
void record::enter(char* p1, char* p2)
{
 strcpy(a,p1);
 strcpy(b,p2);
}
void record::display()
{
 cout<<"Game Details:"<<endl;
 cout<<a<<" vs "<<b<<endl;
 if(playerno==1)
 cout<<a<<" won";
 else if(playerno==2)
 cout<<b<<" won";
 else
 cout<<" Game tied";
 cout<<" with "<<200-t<<" seconds remaining."<<endl;
}

void record::time(int j,int i)
{
 playerno=j;
 t=i;
}
void tune()
{
 //error sound
  sound(100);
  delay(180);
  nosound();
  delay(30);
  sound(400);
  delay(120);
  nosound();
  delay(30);
  sound(300);
  delay(100);
  nosound();
  delay(30);
  sound(200);
  delay(400);
  nosound();
}

void database()
{
 clrscr();
 char database[8]="DATABASE";int s,ctr=0;
 cout<<endl<<"                                    ";
  for(s=0;s<8;++s)
 {
  delay(50);
  cout<<database[s];
 }
 cout<<endl<<"                                    ";
 delay(250);
 for(s=0;s<8;++s)
 {
  delay(80);
	textcolor(RED);
	 cprintf("_");
 }
 cout<<endl<<endl<<"Welcome to STREAK DATABASE"<<endl;
 cout<<endl<<endl;
 delay(500);
 cout<<"Enter player name:"<<endl;
 char playerdummy[20];
 gets(playerdummy);
 record dummy;
 fstream fdummy;
 fdummy.open("database.dat", ios::in|ios::binary);
 while(fdummy.read((char*)&dummy, sizeof(dummy)))
 {
  if ((strcmpi(dummy.a,playerdummy)==0)||(strcmpi(dummy.b,playerdummy)==0))
  {
   ctr++;
   dummy.display();
   delay(2000);
   cout<<endl;
  }
 }
 if(ctr==0)
 {
  cout<<"No records found!";
  tune();
 }
 fdummy.close();
 getch();
 clrscr();
}
void title()
{
  clrscr();
 int q;
	//initilizing graphic driver and
	//graphic mode variable
 int graphicdriver=DETECT,graphicmode;
	//calling initgraph with parameters
 initgraph(&graphicdriver,&graphicmode,"c:\\turboc3\\bgi");

 setcolor(4);
 settextstyle(3,HORIZ_DIR,9);
 outtextxy(40,140,"S T R E A K");
 for(q=0;q<18;++q)
 cout<<endl;
 cout<<endl<<"     ";
 for(q=0;q<=70;++q)
 {
  cout<<"-";
  sound(25*q);
  delay(30);
  nosound();
  delay(50);
 }
 closegraph();
}

void about()
{
 //three things: (1) Game name / version, (2) game developers and details.
 clrscr();
 char settings[5]="ABOUT";
 cout<<endl<<"                                    ";
 for(int s=0; s<5; ++s)
 {
  delay(50);
  cout<<settings[s];
 }
 cout<<endl<<"                                    ";
 delay(250);
 for(s=0;s<5; ++s)
 {
  delay(80);
  textcolor(RED);
  cprintf("_");
 }
 cout<<endl;
 textcolor(RED);
 cout<<"                         ";
 cprintf("Welcome to STREAK (beta) v11");
 cout<<endl<<endl;
 cout<<"                        ";
 cprintf("Developers and Acknowledgements");
 cout<<endl<<endl<<endl<<endl;
 delay(2000);
 cout<<"Programmers: P Pranith"<<endl;
 cout<<"             Prithvi A"<<endl
 <<"Music by:    Tarun Raja"<<endl;
 cout<<endl;
 delay(2000);
 cout<<"Special thanks to Revathy Ma'am and Vidyalakshmi Ma'am for their support during the inception of the programme.                                       "<<endl;
 delay(2000);
 getch();
}

class details
{
 public:
 int a,localwin,i,t1,t2,t;
 details()
 {
  a=0;
  t1=0;
  t2=0;
 }
 int record(int i,int t)
 {
  if(i==0)
  { t1=0; t2=0;}
  if(i%2==0)
  {
  t1+=t;
  a=t1;
  }
  else
  {
  t2+=t;
  a=t2;
  }
  if(t1>=200)
  {
	cout<<"Time up for player 1! Player 2 has won!"<<endl;
	delay(1000);
  }
  else if (t2>=200)
  {
	cout<<"Time up for player 2! Player 1 has won!"<<endl;
	delay(1000);
  }
  return a;
}}player;

int menu()
{
 clrscr();
 int i,s,choice=0;
 char name[11]="S T R E A K",start[5]="START",instructions[12]="INSTRUCTIONS",quit[4]="QUIT",settings[8]="SETTINGS",about[5]="ABOUT",database[8]="DATABASE";
 clrscr();
 cout<<endl<<"                                  ";
 for(s=0;s<11;++s)
 {
  delay(50);
  cout<<name[s];
 }
 cout<<endl<<"                                  ";
 delay(250);
 for(s=0;s<11;++s)
 {
  delay(80);
	textcolor(RED);
	 cprintf("_");
 }
 cout<<endl<<endl<<endl<<endl<<endl;
 cout<<"                  ";
 for(i=0;i<5;++i)
 {
  delay(40);
  cout<<start[i];
 }
 textcolor(RED);
 cprintf(" (1)");
 cout<<"                      ";
 for(i=0;i<12;++i)
 {
  delay(40);
  cout<<instructions[i];
 }
 textcolor(RED);
 cprintf(" (2)");
 cout<<endl<<endl<<endl<<endl<<endl;
 cout<<"                  ";
 for(i=0;i<4;++i)
 {
  delay(40);
  cout<<quit[i];
 }
 textcolor(RED);
 cprintf(" (3)");
 cout<<"                        ";
 for(i=0;i<8;++i)
 {
  delay(40);
  cout<<settings[i];
 }
 textcolor(RED);
 cprintf(" (4)");
 cout<<endl<<endl<<endl<<endl<<endl;
 cout<<"                  ";
 for (i=0; i<5; ++i)
 {
  delay(40);
  cout<<about[i];
 }
 textcolor(RED);
 cprintf(" (5)");
 cout<<"                       ";
 for (i=0; i<8; ++i)
 {
  delay(40);
  cout<<database[i];
 }
 textcolor(RED);
 cprintf(" (6)");
 cout<<"                     ";
 cout<<endl<<endl<<endl<<endl<<endl;
 textcolor(WHITE);
 cprintf("Type in your choice (i.e.the number accompanying the option): ");
 cin>>choice;

 return choice;
}
int settings()
{
  clrscr();
  int s,choice;char settings[8]="SETTINGS";
  cout<<endl<<"                                    ";
 for(s=0;s<8;++s)
 {
  delay(50);
  cout<<settings[s];
 }
 cout<<endl<<"                                    ";
 delay(250);
 for(s=0;s<8;++s)
 {
  delay(80);
	textcolor(RED);
	 cprintf("_");
 }
 cout<<endl<<endl<<endl<<endl<<endl;
 cout<<"                           ";
 textcolor(RED);cprintf("Choose Your Difficulty Level: ");
 cout<<endl<<endl<<endl<<"                                ";
 cout<<"Novice Easy";textcolor(RED); cprintf(" (1)");
 cout<<endl<<endl<<"                                ";
 cout<<"Amateur Medium";textcolor(RED);cprintf(" (2)");
 cout<<endl<<endl<<"                                ";
 cout<<"Pro Hard";textcolor(RED);cprintf(" (3)");
 cout<<endl<<endl<<endl<<endl<<endl;
 cout<<"          ";
 textcolor(WHITE);
 cprintf("Type in your choice (i.e.the number accompanying the option): ");
 cin>>choice;
 if(choice>3||choice<0)
 {
  cout<<"Invalid Output, you will be taken back to the menu.";
  tune();
  choice=4;
 }
 return choice;
}

int instruct()
{
 int val=0;
 delay(1000);
 clrscr();
 cout<<"                              ";
 textcolor(RED);
 cprintf("INSTRUCTIONS") ;
 cout<<endl<<endl;
 cout<<"Do you wish to learn how to play STREAK? Then you've come to the right place!"<<endl<<endl;
 cout<<"STREAK is a 2 player game, so be sure to have a friend with you! The game is    played on a board that appears like this - "<<endl<<endl;
 for (int instructx=0; instructx<8; instructx++)
 {
  for (int instructy=0;instructy<8; instructy++)
  {
	textcolor(WHITE);
	cprintf("0   ");
  }
  cout<<endl;
 }
 delay (6000);
 cout<<endl;
 textcolor(WHITE);
 cprintf("Players are denoted by their player numbers. Player one is denoted by ");
textcolor(RED);
cprintf("1 ");
cout<<"and     player two is denoted by ";
textcolor(GREEN);
cprintf("2 ");
textcolor(WHITE);
cprintf("!");
cout<<endl;
delay (8000);
clrscr();
cout<<endl;
textcolor(YELLOW);
cprintf("The game begins with an empty board as you saw earlier. Each turn, a player is  allowed to place a token in any column on the board.");
cprintf("The token falls to the      lowest unoccupied space in that column. For example  :");
cout<<endl;
for (int instructa=0; instructa<8; instructa++)
{
 for (int instructb=0;instructb<8; instructb++)
 {
  textcolor(WHITE);
  cprintf("0  ");
 }
cout<<endl;
}
cout<<endl;
textcolor(YELLOW);
cprintf("It is player one's turn. Let us assume player one wishes to place their token inthe third column.");
cout<<endl;
cprintf("Player one is asked which column they wish to place the token in, and they enter3.");
cout<<endl;
for (int instructc=0; instructc<8; instructc++)
{
 for (int instructd=0; instructd<8; instructd++)
 {
  if (instructc==7 && instructd==2)
  {
	textcolor(RED);
	cprintf("1  ");
  }
  else
  {
	textcolor(WHITE);
	cprintf("0  ");
  }
 }
 cout<<endl;
}
delay(15000);
clrscr();
textcolor(WHITE);
cprintf("In Novice mode, for example, the player wins when they get a STREAK of 4. This  ");
textcolor(RED);
cprintf(" STREAK ");
textcolor(WHITE);
cprintf(" can be vertical, horizontal, or diagonal.");
delay(2000);
cout<<endl<<endl<<endl;
textcolor(GREEN);
cprintf("In such a case, a vertical streak would look like this: ");
delay (500);
cout<<endl;
for (int instructp=0; instructp<8; instructp++)
{
 for (int instructq=0; instructq<8; instructq++)
 {
  if ( (instructp==7&&instructq==1) || (instructp==6&&instructq==1) || (instructp==5&&instructq==1) || (instructp==4&&instructq==1) )
  {
	textcolor(RED);
	cprintf("1  ");
  }
  else
  {
	textcolor(WHITE);
	cprintf("0  ");
  }
 }
 cout<<endl;
}
delay(6000);
clrscr();
cout<<"Remember!"<<endl<<endl<<"While these instructions simulate the Novice mode having an 8x8 board with the   goal of making a STREAK of 4, you can also play on Amateur (9*9 with a STREAK  of 5) and Pro (10*10 board with a STREAK of 6)";
cout<<endl<<endl<<"The time however, is 200 seconds per player - regardless of the mode."<<endl;
delay(6000);
clrscr();
for(int i=0;i<14;++i)
cout<<endl;
cout<<"              ";
textcolor(WHITE);
cprintf("G"); cout<<"     ";
textcolor(RED);
cprintf("O"); cout<<"     ";
textcolor(YELLOW);
cprintf("O"); cout<<"     ";
textcolor(WHITE);
cprintf("D"); cout<<"     ";
textcolor(WHITE);
cprintf("L"); cout<<"     ";
textcolor(RED);
cprintf("U"); cout<<"     ";
textcolor(YELLOW);
cprintf("C"); cout<<"     ";
textcolor(WHITE);
cprintf("K"); cout<<"     ";
textcolor(GREEN);
cprintf("!");
for(i=0;i<14;++i)
cout<<endl;
cout<<"                  " ;
 textcolor(WHITE);
 cprintf("Enter 1 to return back to the menu!");
 cin>>val;
 return val;
}
void printboard(int a[10][10],int &f,int h)
{
 int i,j;

 for(i=0;i<10-h;++i)
 {
  if(f==1)
  {
    if(i==(10-h-1))
    {sound(500);}
    else
    {sound(200);}
    delay(5);
    nosound();
  }
  cout<<"                               ";
  for(j=0;j<10-h;++j)
  {
	if(f==1)
	{
	 delay(30);
	}
	if(a[i][j]==1)
	{
	 textcolor(RED);
	 cprintf("1 ");
	}
	else if(a[i][j]==2)
	{
	 textcolor(GREEN);
	 cprintf("2 ");
	}
	else
	cout<<a[i][j]<<" ";
  }
  cout<<endl;
 }
 cout<<endl;
}


int check(int a[10][10],int &playerno,int h)
{
 int ctr=0,ctr2=0,ctr3=0,ctr4=0,streak=0,n1=0,k,i,j;

 // checking rows and columns
 for(int m=0;m<10-h;++m)
 {
  ctr=0;ctr2=0;
  for(n1=0;n1<10-h;++n1)
  {
	if(a[m][n1]==playerno)
	++ctr;
	else
	ctr=0;
	if(a[n1][m]==playerno)
	++ctr2;
	else
	ctr2=0;
	if(ctr>=6-h||ctr2>=6-h)
	++streak;
  }
 }
 // checking the left diagonals
 for(k=0;k<=9-h;++k)
 {
  i=k;
  j=0;
  ctr3=0;
  while(i>=0)
  {
	if(a[i][j]==playerno)
	{ctr3++;
	 if(ctr3>=6-h)
	 break;
	}
	else
	ctr3=0;

	--i;++j;
  }
  if(ctr3>=6-h)
  ++streak;
 }
 for(k=1;k<=9-h;++k)
 {
  i=9-h;
  j=k;
  ctr3=0;
  while(j<=9)
  {
	if(a[i][j]==playerno)
	{ ctr3++;
	 if(ctr3>=6-h)
	 break;
	}
	else
	ctr3=0;
	--i;	++j;
  }
  if(ctr3>=6-h)
  ++streak;
 }

 // checking the right diagonals
 for(k=0;k<=9-h;++k)
 {
  i=k;
  j=9-h;
  ctr4=0;
  while(i>=0)
  {
  if(a[i][j]==playerno)
	{
	 ctr4++;
	 if(ctr4>=6-h)
	 break;
	}
	else
	ctr4=0;

	--i;--j;
  }
	if(ctr4>=6-h)
  ++streak;
 }
 for(k=8;k>=0;--k)
 {
  i=9-h;
  j=k;
  ctr4=0;
  while(j>=0)
  {
	if(a[i][j]==playerno)
	{
	 ctr4++;
	 if(ctr4>=6-h)
	 break;
	}
	else
	ctr4=0;
	--i;	--j;
  }
  if(ctr4>=6-h)
  ++streak;
 }


 return streak;
}




void main()
{
 clrscr();
 title();
 clrscr();
 record rec;
 fstream f1;
 f1.open("Database.dat",ios::app|ios::out|ios::binary);
 int h=2;
 clrscr();
 cout<<endl;
 l3:
 clrscr();
 int g,t,i,j,c,f,s,val=0,val2=0,choice,playerno=0,result=0,errorcount; // c=column of choice
 char name[11]="S T R E A K",gameover[16]="G A M E  O V E R";
 choice=menu();
 if(choice==1)
 goto l2;
 else if(choice==2)
 {
  val=instruct();
  if(val==1)
  goto l3;
 }
 else if(choice==3)
 goto l1;
 else if(choice==4)
 {
  val2=settings();
  if(val2!=4)
  h=3-val2;
  goto l3;
 }
 else if(choice==5)
 {
  about();
  goto l3;
 }
 else if(choice==5)
 {
  about();
  goto l3;
 }
 else if(choice==6)
 {
  database();
  goto l3;
 }
 else
 {
  tune();
  cout<<endl<<endl<<"Oops...invalid input! Exiting the game...";
  goto l1;
 }
 l2:
 delay(2000);
 clrscr();

 int board[10][10]	;
 cout<<"                                 ";
 for(i=0;i<10-h;++i)
 {
  for(j=0;j<10-h;++j)
  {
	board[i][j]=0;
  }
 }
 for(s=0;s<11;++s)
 {
  delay(50);
  cout<<name[s];
 }
 cout<<endl<<"                                 ";
 delay(250);
 for(s=0;s<11;++s)
 {
  delay(80);
	textcolor(RED);
	 cprintf("_");
 }
 cout<<endl<<endl;
 delay(800);
 textcolor(WHITE);
 cprintf("This is where the two players will be playing the game of STREAK - A connect4   game !");
 cout<<endl;
 delay(1500);
 textcolor(WHITE);
 cprintf("PLAYER 1 is denoted by the number '1' on the board and PLAYER 2 is denoted by   the number '2'.");
 cout<<endl;
 delay(1500);
 cout<<"Enter the 1st Player's name: ";
 char* P1Name;
 gets(P1Name);
 cout<<"Enter the 2nd Player's name: ";
 char* P2Name;
 gets(P2Name);
 rec.enter(P1Name,P2Name);
 f=1;
 cout<<"			       ";
 for(i=1;i<=10-h;++i)
 cout<<i<<" ";
 cout<<endl<<endl;
 printboard(board,f,h);

 for(i=0;i<((10-h)*(10-h));++i)
 {
	l4:
	cout<<endl;
	playerno=(i%2)+1;
	textcolor(WHITE);
	cprintf("It is PLAYER ");
	cout<<playerno<<": ";
	if(playerno==1)
	cout<<P1Name;
	else
	cout<<P2Name;
	cprintf("'s turn.");
	cout<<endl;
	delay(400);
	textcolor(WHITE);
	cprintf("Input the desired column's number : ");
	clock_t start, end;
	start= clock();
	cin>>c;
	if(playerno==1)
	{
	 sound(400);
	 delay(20);
	 nosound();
	}
	else if(playerno==2)
	{
	 sound(600);
	 delay(20);
	 nosound();
	}
	end= clock();
	  if(c==0)              //inside trick for terminating the game
	  goto l1;
	t=(end-start)/CLK_TCK;
	g=player.record(i,t); //recording time
	if(g==200)
	{goto l1;}
	cout<<"Remaining time for player "<<playerno<<":"<<200-g<<" seconds"<<endl;
	delay(1500);
	cout<<endl<<endl;
	if (c<0||c>10-h)
	{
	 i=i+2; tune();
	 cout<<"That is an invalid input, let's try that again"<<endl;
	 goto l4;
	}
	for(j=9-h;j>=0;--j)
	{
	 if(board[j][c-1]==0)
	 break;
	}
	board[j][c-1]=playerno;
	clrscr();
	cout<<endl<<"                                 ";
	cout<<"S T R E A K";
	cout<<endl<<"                                 ";
	textcolor(RED);
	cprintf("___________");

	for(f=0;f<5;++f)
	cout<<endl;
	f=0;
	cout<<"                               ";
	for(int l=1;l<=10-h;++l)
	cout<<l<<" ";
	cout<<endl<<endl;
	printboard(board,f,h);
	result=check(board,playerno,h);
	if(result>0)
	break;
 }

  //game over screen
  clrscr();
  sound(270);
 delay(116);
 nosound();
 delay(40);
 sound(320);
 delay(168);
 nosound();
 delay(94);
 sound(300);
 delay(176);
 nosound();
 delay(134);
 sound(270);
 delay(146);
 nosound();
 delay(30);
 sound(240);
 delay(124);
 nosound();
 delay(12);
 sound(400);
 delay(144);
 nosound();
 delay(30);
 sound(240);
 delay(138);
 nosound();
 delay(172);
 sound(360);
 delay(150);
 nosound();
 delay(156);
 sound(240);
 delay(154);
 nosound();
  cout<<endl<<endl<<endl<<"                                ";
  for(i=0;i<16;++i)
   {
    cout<<gameover[i];
    delay(50);
   }
  textcolor(WHITE);
  cprintf("!");
  cout<<endl<<"                                ";
  for(i=0;i<16;++i)
  {
   textcolor(WHITE);
   cprintf("_");
   delay(50);
  }
  rec.time(playerno,g);
  if (playerno==1)
   {
    cout<<endl<<endl<<"                       ";
    textcolor(RED);
    cprintf("PLAYER ");
    cout<<playerno;
    cprintf(" has won! Congratulations!");
    delay(4000);

   }
   else if (playerno==2)
   {
    cout<<endl<<endl<<"                       ";
    textcolor(GREEN);
    cprintf("PLAYER ");
    cout<<playerno;
    cprintf(" has won! Congratulations!");
    delay(4000);

   }
   else
  {
   cout<<endl<<endl<<"                        ";
   textcolor(YELLOW);
   cprintf("The game ends in a tie!");
   delay(4000);
  }
 f1.write((char*)&rec,sizeof(rec));
 f1.close();
 goto l3;
 l1: delay(1000);
 exit(0);
 getch();
}