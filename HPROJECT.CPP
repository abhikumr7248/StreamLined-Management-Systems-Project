
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<iomanip.h>
#include<graphics.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<ctype.h>
#include<process.h>
fstream f,f1,f2,f3,f4,f5,f6,f7,f8;
//**********************************************************
// CLASS NAME : Hotel
// DETAILS : IT CONTROLS OVER ALL FUNCTIONING
// OF THE HOTEL
//**********************************************************
class HOTEL
{
char array[100];
struct bill_restaurant_bar //for bill details
{
long brestaurant,bbar;
} b[100]; //Object of structure
struct booking_data //for booking details
{
long charge,roomno;
char name[25],address[75],telno[10],date[11],roomtype[15];
} d; //Object of structure
struct check_out_data //for check out details
{
char name[25],address[75],telno[10],date[11],odate[11],otime[6];
int roomno;
} C; //Object of structure
struct cancellation_data //for cancellation details
{
char name[25],address[75],telno[10];
} D; //Object of structure
public:
void booking(); //Function for booking details
void check_in(); //Function for check out details
void check_out(); //Function for check out details
void cancellation(); //Function for cancellation details
void taxi_service(); //Function for taxi service details
void restaurant(); //Function for restaurant details
void bar(); //Function for cancellation details
void view_data(); //Function for data details
};
//**********************************************************
// FUNCTION NAME : BOOKING
//**********************************************************
void HOTEL::booking ()
{
textcolor(2);
clrscr();
int c=0;
//FINDING AN UNOCCUPIED ROOM
f.open("ARRAY.DAT",ios::in|ios::binary);      //kyu
f.read((char *)&array,sizeof(array));
while(array[c]!='e') c++;
array[c]='o';
f.close();
f.open("ARRAY.DAT",ios::out|ios::binary);
f.write((char *)&array,sizeof(array));
f.close();
f1.open("HOT.EL",ios::app|ios::binary);
d.roomno=c+1;
//DATA OF THE CUSTOMER
cout<<"ENTER THE REQUIRED DATA\n"
<<"NAME :: ";
gets(d.name);
int l=strlen(d.name);
for(int i=0;i<l;i++)
d.name[i]=toupper(d.name[i]);
cout<<"ADDRESS(R) :: ";
gets(d.address);
cout<<"TEL. NO.(R) :: ";
cin>>d.telno;
cout<<"DATE WHEN YOU WILL CHECK-IN(dd/mm/yyyy) :: ";
cin>>d.date;
cout<<"\n\nROOM TYPES "<<"\t"
<<"CODES"<<"\t"<<"CHARGE PER DAY\n"
<<"ROYAL SUITE "<<"\t"<<"1. "<<"\t"<<"Rs 20,000\n"
<<"SUPER DELUXE"<<"\t"<<"2. "<<"\t"<<"Rs 15,000\n"
<<"DELUXE      "<<"\t"<<"3. "<<"\t"<<"Rs 10,000\n"
<<"DOUBLE BED  "<<"\t"<<"4. "<<"\t"<<"Rs 5,000\n"
<<"SINGLE BED  "<<"\t"<<"5. "<<"\t"<<"Rs 2,000\n";
int roomcode;
REDO: cout<<"ROOM CODE :: ";              //kyu
cin>>roomcode;
switch(roomcode)
{
case 1 : strcpy(d.roomtype,"ROYAL SUITE");
d.charge=20000;
break;
case 2 : strcpy(d.roomtype,"SUPER DELUXE");
d.charge=15000;
break;
case 3 : strcpy(d.roomtype,"DELUXE");
d.charge=10000;
break;
case 4 : strcpy(d.roomtype,"DOUBLE BED");
d.charge=5000;
break;
case 5 : strcpy(d.roomtype,"SINGLE BED");
d.charge=2000;
break;
default: cout<<"ENTER THE RIGHT CODE\n";
goto REDO;
}
clrscr();
cout<<"YOUR ROOM NO. IS :: "<<d.roomno<<"\n";
gotoxy(25,25);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
//COPYING THE RECORD OF THE CUSTOMER INTO A FILE
f1.write((char *)&d,sizeof(d));
f1.close();
clrscr();
} //**********************************************************
// FUNCTION NAME : CHECK IN
//**********************************************************
void HOTEL::check_in()
{
textcolor(12);
clrscr();
int rn;
char ans;
cout<<"HAVE YOU BOOKED IN ADVANCE ?(Y/N)::";
cin>>ans;
if(ans=='n'||ans=='N')
{
cout<<"THEN YOU FIRST HAVE TO BOOK";
gotoxy(25,25);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
booking();
}
clrscr();
cout<<"ROOM NUMBER :: ";
cin>>rn;
f1.open("HOT.EL",ios::in|ios::binary);
do f1.read((char *)&d,sizeof(d)); while(d.roomno!=rn);
cout<<"NAME :: "<<d.name<<"\n"
<<"ADDRESS(R) :: "<<d.address<<"\n"
<<"TEL. NO.(R) :: "<<d.telno<<"\n"
<<"CHECK-IN DATE :: "<<d.date<<"\n"
<<"ROOM TYPE :: "<<d.roomtype;
gotoxy(25,25);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
f1.close();
clrscr();
}
//**********************************************************
// FUNCTION NAME : CHECK OUT
//**********************************************************
void HOTEL::check_out()
{
textcolor(10); //set text colour to light green
clrscr();
int rn;
cout<<"ROOM NUMBER :: ";
cin>>rn;
char od[11],ot[6];
cout<<"CHECK-OUT DATE (dd/mm/yyyy) :: ";
gets(od);
cout<<"CHECK-OUT TIME (in form of 07:30 , 22:55 etc) :: ";
gets(ot);
textcolor(6); //set text colour to brown
clrscr();
fstream e;
f1.open("HOT.EL",ios::in|ios::binary);
do{ f1.read((char *)&d,sizeof(d)); }while(d.roomno!=rn);
gotoxy(25,1); cout<<"**** BILL ****\n\n";
cout<<endl;
cout<<"\t\tROOM NUMBER :: "<<d.roomno<<"\n"
<<"\t\tNAME :: "<<d.name<<"\n"
<<"\t\tADDRESS(R) :: "<<d.address<<"\n"
<<"\t\tTEL. NO.(R) :: "<<d.telno<<"\n"
<<"\t\tROOM TYPE :: "<<d.roomtype<<"\n"
<<"\t\tCHECK-IN DATE :: "<<d.date<<"\n"
<<"\t\tCHECK-OUT DATE :: "<<od<<"\n"
<<"\t\tCHECK-OUT TIME :: "<<ot<<"\n";
//******COPYING THE RECORD OF THE CUSTOMER INTO ANOTHER FILE
f2.open("C.OUT",ios::app|ios::binary);
strcpy(C.name,d.name);
strcpy(C.address,d.address);
strcpy(C.telno,d.telno);
strcpy(C.date,d.date);
strcpy(C.odate,od);
strcpy(C.otime,ot);
C.roomno=d.roomno;
f2.write((char *)&C,sizeof(C));
f2.close();
//******CALCULATING NO. OF DAYS THE CUSTOMER OCCUPIED THE ROOM
//******AND PRINTING THE TARIFF
long tariff;
int dd1,dd2,mm1,mm2,yy1,yy2,p,q,r;
dd1=(d.date[0]-48)*10+(d.date[1]-48);
dd2=(od[0]-48)*10+(od[1]-48);
mm1=(d.date[3]-48)*10+(d.date[4]-48);
mm2=(od[3]-48)*10+(od[4]-48);
yy1=(d.date[6]-48)*1000+(d.date[7]-48)*100+(d.date[8]-48)*10+(d.date[9]-48);
yy2=(od[6]-48)*1000+(od[7]-48)*100+(od[8]-48)*10+(od[9]-48);
if(yy1%4==0) { p=29; q=28; }
else if(yy2%4==0) { p=28; q=29; }
else { p=28; q=28; }
int cy[12]={ 31,p,31,30,31,30,31,31,30,31,30,31 };
int ny[12]={ 31,q,31,30,31,30,31,31,30,31,30,31 };
if(yy1==yy2 && mm1==mm2 && dd1==dd2) tariff=d.charge;
else
{
if(yy1==yy2)
{
if(mm1==mm2) tariff=d.charge*(dd2-dd1);
else
{
r=cy[mm1-1]-dd1+dd2;
for(int l=mm1;l<mm2-1;l++) r+=cy[l];
tariff=d.charge*r;
}
}
else
{
r=cy[mm1-1]-dd1+dd2;
for(int l=mm1;l<12;l++) r+=cy[l];
for(l=0;l<mm2-1;l++) r+=ny[l];
tariff=d.charge*r;
}
}
int c1,c2;
c1=(ot[0]-48)*10+(ot[1]-48);
c2=(ot[3]-48)*10+(ot[4]-48);
if(yy1==yy2 && mm1==mm2 && dd1==dd2);
else if(c1>12) tariff+=d.charge;
else if(c1==12 && c2>0) tariff+=d.charge;
cout<<"\t\tTARIFF :: Rs "<<tariff<<'\n';
f1.close();
//******SHOWING THE CUSTOMER'S RESTAURANT AND BAR BILL
f8.open("BILL.DAT",ios::in|ios::binary);
f8.read((char *)&b,sizeof(b));
cout<<"\t\tRESTAURANT CHARGE :: Rs "<<b[rn-1].brestaurant<<'\n'
<<"\t\tBAR CHARGE :: Rs "<<b[rn-1].bbar<<'\n'
<<"\t\tTOTAL :: Rs "<<b[rn-1].brestaurant+b[rn-1].bbar+tariff;
b[rn-1].bbar=b[rn-1].brestaurant=0;
f8.close();
f8.open("BILL.DAT",ios::out|ios::binary);
f8.write((char *)&b,sizeof(b));
f8.close();
//******DELETING THE RECORD OF THE CUSTOMER
f1.open("HOT.EL",ios::in|ios::binary);
e.open("F.DAT",ios::out|ios::binary);
f1.read((char *)&d,sizeof(d));
while(f1)
{
if(d.roomno!=rn)
{
e.write((char *)&d,sizeof(d));
f1.read((char *)&d,sizeof(d));
}
else f1.read((char *)&d,sizeof(d));
}
e.close();
f1.close();
f1.open("HOT.EL",ios::out|ios::binary);
e.open("F.DAT",ios::in|ios::binary);
e.read((char *)&d,sizeof(d));
while(e)
{
f1.write((char *)&d,sizeof(d));
e.read((char *)&d,sizeof(d));
}
e.close();
f1.close();
//******MAKING THE ROOM OCCUPIED BY THE CUSTOMER AS UNOCCUPIED
f.open("ARRAY.DAT",ios::in|ios::binary);
f.read((char *)&array,sizeof(array));
array[rn-1]='e';
f.close();
f.open("ARRAY.DAT",ios::out|ios::binary);
f.write((char *)&array,sizeof(array));
f.close();
gotoxy(25,25);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
} //**********************************************************
// FUNCTION NAME : CANCELLATION
//**********************************************************
void HOTEL::cancellation()
{
textcolor(1); //set text colour to blue
clrscr();
int rn;
cout<<"ROOM NUMBER :: ";
cin>>rn;
f1.open("HOT.EL",ios::in|ios::binary);
do{f1.read((char*)&d,sizeof(d));} while(d.roomno!=rn);
cout<<"NAME :: "<<d.name<<"\n"
<<"ADDRESS(R) :: "<<d.address<<"\n"
<<"TEL. NO.(R) :: "<<d.telno<<"\n"
<<"ROOM TYPE :: "<<d.roomtype<<"\n"
<<"CANCELLED\n";
//******COPYING THE RECORD OF THE CUSTOMER INTO ANOTHER FILE
f3.open("CAN.CEL",ios::app|ios::binary);
strcpy(D.name,d.name);
strcpy(D.address,d.address);
strcpy(D.telno,d.telno);
f3.write((char *)&D,sizeof(D));
f3.close();
f1.close();
//******MAKING THE ROOM ALLOTED TO THE CUSTOMER AS EMPTY
f.open("ARRAY.DAT",ios::in|ios::binary);
f.read((char *)&array,sizeof(array));
array[rn-1]='e';
f.close();
f.open("ARRAY.DAT",ios::out|ios::binary);
f.write((char *)&array,sizeof(array));
f.close();
fstream e;
//******DELETING THE RECORD OF THE CUSTOMER
f1.open("HOT.EL",ios::in|ios::binary);
e.open("F1.DAT",ios::out|ios::binary);
f1.read((char *)&d,sizeof(d));
while(f1)
{
if(d.roomno!=rn)
{
e.write((char *)&d,sizeof(d));
f1.read((char *)&d,sizeof(d));
}
else f1.read((char *)&d,sizeof(d));
}
e.close();
f1.close();
f1.open("HOT.EL",ios::out|ios::binary);
e.open("F1.DAT",ios::in|ios::binary);
e.read((char *)&d,sizeof(d));
while(e)
{
f1.write((char *)&d,sizeof(d));
e.read((char *)&d,sizeof(d));
}
e.close();
f1.close();
gotoxy(25,25);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
} //**********************************************************
// FUNCTION NAME : TAXI SERVICE
//**********************************************************
void HOTEL::taxi_service()
{
int gd=DETECT,gm,choice;
initgraph(&gd,&gm,"c:\\tc\\bgi");//initialize graph
settextstyle(10,0,1); //set font,direction,size
int x=40,y=10;
setcolor(BROWN); //set text colour to brown
outtextxy(50,20,"I am staying in this hotel");
outtextxy(x,y,".");
setcolor(CYAN); //set text colour to cyan
outtextxy(50,60,"I am not staying in this hotel");
char W;
int count=0;
do
{
count++;
W=getch();
if(W=='\0'+'H')
{
setcolor(BLACK); //set text colour to black
outtextxy(x,y,".");
y-=40;
if(y<10)
{
y=50;
setcolor(CYAN); //set text colour to cyan
outtextxy(x,y,".");
choice=2;
}
else if(y==10)
{
setcolor(BROWN); //set text colour to brown
outtextxy(x,y,".");
choice=1;
}
else if(y==50)
{
setcolor(CYAN); //set text colour to cyan
outtextxy(x,y,".");
choice=2;
}
}
else if(W=='\0'+'P')
{
setcolor(BLACK); //set text colour to black
outtextxy(x,y,".");
y+=40;
if(y>50)
{
y=10;
setcolor(BROWN); //set text colour to brown
outtextxy(x,y,".");
choice=1;
}
else if(y==10)
{
setcolor(BROWN); //set text colour to brown
outtextxy(x,y,".");
choice=1;
}
else if(y==50)
{
setcolor(CYAN); //set text colour to cyan
outtextxy(x,y,".");
choice=2;
}
}
else if(count==1 && W==13) choice=1;
} while(W!=13);
closegraph();
textcolor(8); //set text colour to dark gray
clrscr();
if(choice==1)
{
char n[25],t[6],date[11];
int x,room;
cout<<"ROOM NUMBER :: ";
cin>>room;
cout<<"NAME :: ";
gets(n);
int l=strlen(n);
for(int i=0;i<l;i++) n[i]=toupper(n[i]);
//******VERIFYING THE ENTERED DATA
f1.open("HOT.EL",ios::in|ios::binary);
f1.read((char *)&d,sizeof(d));
while(f1)
{
if(d.roomno==room && strcmp(d.name,n)==0)
{
f1.close();
goto PROCEED;
}
f1.read((char *)&d,sizeof(d));
}
f1.close();
clrscr();
cout<<"SORRY.ENTERED DATA IS NOT MATCHING THE ACTUAL DATA"
<<"\nYOU CAN NOT USE THIS FACILITY";
gotoxy(25,25);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
return;
PROCEED: cout<<"NO. OF TAXIS NEEDED :: ";//for labelling
cin>>x;
cout<<"TAXI(s) NEEDED ON (date) :: ";
gets(date);
cout<<"TAXI(s) NEEDED AT (time) :: ";
gets(t);
clrscr();
if(x==1)
cout<<"A TAXI WILL BE WAITING FOR YOU AT "<<t
<<" ON "<<date<<" OUTSIDE THE HOTEL GATE";
else
cout<<x<<" TAXIS WILL BE WAITING FOR YOU AT "<<t
<<" ON "<<date<<" OUTSIDE THE HOTEL GATE";
gotoxy(25,25);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
}
clrscr();
} //**********************************************************
// FUNCTION NAME : RESTAURANT
//**********************************************************
void HOTEL::restaurant()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
cleardevice();
setbkcolor(RED); //set text colour to red
settextstyle(8,0,4); //set font,direction,size
setcolor(YELLOW); //set text colour to yellow
delay(1000);
outtextxy(50,150,"WELCOME TO THE RESTAURANT");
delay(2000);
outtextxy(100,200,"PLEASE TAKE YOUR SEAT");
delay(2000);
closegraph();
int price[113]={245,245,245,245,240,240,240,240,235,235,250,235,235,
220,215,230,215,240,250,250,250,250,250,250,250,255,245,245,245,245,
250,240,240,360,290,360,290,370,295,360,290,360,290,250,360,290,360,
290,250,370,290,360,290,250,250,280,245,290,235,265,240,290,300,256,
240,265,270,255,255,240,240,235,220,25,30,25,30,35,35,25,30,35,25,35,
25,25,30,100,105,105,100,105,100,105,125,105,105,100,105,110,115,100,
100,100,105,105,105,105,125,105,120,120,100};
char food[113][30]={"SHAHI PANEER","KADAI PANEER","CHEESE KORMA",
"MALAI KOFTA","MATAR PANEER","PALAK PANEER","MIX VEG.","ALOO GOBI",
"ALOO JEERA","CHANA MASALA","MATAR MUSHROOM","RAJMA MAKHANI",
"DAL MAKHANI","MIXED RAITA","BUNDI RAITA","PINEAPPLE RAITA",
"SALAD(GREEN)","DUM ALOO","MUSHROOM PANEER","MUTTON MASALA",
"MUTTON MUGHLAI","MUTTON KORMA","MUTTON DO PYAZA","MUTTON SAGH",
"MUTTON DAHI","MUTTON ROGAN JOSH","MUTTON CURRY","KADAI MUTTON",
"KEEMA LEVER","KEEMA MATAR","KEEMA EGG","BRAIN CURRY","EGG CURRY",
"BUTTER CHICKEN","BUTTER CHICKEN(1/2)","KADAI CHICKEN",
"KADAI CHICKEN(1/2)","BUTTER CHICKEN(BL)","BUTTER CHICKEN(BL)(1/2)",
"CHICKEN MUGHLAI","CHICKEN MUGHLAI(1/2)","CHICKEN MASALA",
"CHICKEN MASALA(1/2)","CHICKEN MASALA(1/4)","CHICKEN SAGH",
"CHICKEN SAGH(1/2)","CHICKEN DAHI","CHICKEN DAHI(1/2)",
"CHICKEN DAHI(1/4)","CHICKEN KORMA","CHICKEN KORMA(1/2)",
"CHICKEN DO PYAZA","CHICKEN DO PYAZA(1/2)","FISH CURRY",
"CHICKEN CURRY","CHICKEN CURRY(1/2)","CHICKEN CURRY(1/4)",
"CHILLI CHICKEN","TANDOORI ALOO","CHICKEN TIKKA","SEEKH KABAB",
"FISH TIKKA","CHICKEN TANDOORI","CHICKEN TANDOORI(1/2)",
"PANEER TIKKA","CHICKEN SEEKH KABAB","CHICKEN HARA KABAB",
"CHICKEN BIRYANI","MUTTON BIRYANI","PANEER PULAO","VEG.PULAO",
"JEERA RICE","STEAMED RICE","RUMALI ROTI","ROTI","NAN","ALOO NAN",
"PANEER NAN","KEEMA NAN","PARANTHA","ALOO PARANTHA",
"PANEER PARANTHA","PUDINA PARANTHA","BUTTER NAN","LACHCHA PARANTHA",
"MISSI ROTI","KHASTA ROTI","VEG.BURGER","PANEER BURGER",
"CHEESE SANDWICH","VEG.PATTI","CHICKEN PATTI","TEA","COFFEE",
"COLD COFFEE","PINEAPPLE","STRAWBERRY","CHOCOLATE","BLACK FOREST",
"DOUBLE STORIED","TRIPLE STORIED","SOFT CONE","VANILLA","STRAWBERRY",
"CHOCOLATE","CHOCO CHIPS","MANGO","TUTTI FRUITY","LICHI",
"PISTA BADAM","CHOCOLATE PISTA BADAM","CHOCO DIP","CHOCOLATE LICHI"};
START: textcolor(4);//for labelling //set text colour to red
clrscr();
gotoxy(31,1); cout<<"*********";
gotoxy(31,2); cout<<"MENU CARD";
gotoxy(31,3); cout<<"*********";
gotoxy(31,5); cout<<"VEGETARIAN";
for(int i=0;i<15;i++)
{
gotoxy(15,i+7); cout<<i+1;
gotoxy(30,i+7); cout<<food[i];
gotoxy(55,i+7); cout<<price[i];
}
gotoxy(25,25); cout<<"PRESS ANY KEY TO CONTINUE"; getch();
clrscr();
for(i=15;i<19;i++)
{
gotoxy(15,i-14); cout<<i+1;
gotoxy(30,i-14); cout<<food[i];
gotoxy(55,i-14); cout<<price[i];
}
gotoxy(33,7); cout<<"MUTTON";
for(i=19;i<33;i++)
{
gotoxy(15,i-10); cout<<i+1;
gotoxy(30,i-10); cout<<food[i];
gotoxy(55,i-10); cout<<price[i];
}
gotoxy(25,25) ;cout<<"PRESS ANY KEY TO CONTINUE"; getch();
clrscr();
gotoxy(31,1); cout<<"CHICKEN";
for(i=33;i<54;i++)
{
gotoxy(15,i-30); cout<<i+1;
gotoxy(25,i-30); cout<<food[i];
gotoxy(55,i-30); cout<<price[i];
}
gotoxy(25,25) ;cout<<"PRESS ANY KEY TO CONTINUE"; getch();
clrscr();
for(i=54;i<58;i++)
{
gotoxy(15,i-53); cout<<i+1;
gotoxy(30,i-53); cout<<food[i];
gotoxy(55,i-53); cout<<price[i];
}
gotoxy(31,7); cout<<"BAR-BE-QUE";
for(i=58;i<73;i++)
{
gotoxy(15,i-49); cout<<i+1;
gotoxy(30,i-49); cout<<food[i];
gotoxy(55,i-49); cout<<price[i];
}
gotoxy(25,25); cout<<"PRESS ANY KEY TO CONTINUE"; getch();
clrscr();
gotoxy(30,1); cout<<"ROTI-NAN-PARANTHA";
for(i=73;i<92;i++)
{
gotoxy(15,i-70); cout<<i+1;
gotoxy(30,i-70); cout<<food[i];
gotoxy(55,i-70); cout<<price[i];
}
gotoxy(25,25); cout<<"PRESS ANY KEY TO CONTINUE"; getch();
clrscr();
gotoxy(30,1); cout<<"BEVERAGES";
for(i=92;i<95;i++)
{
gotoxy(15,i-89); cout<<i+1;
gotoxy(30,i-89); cout<<food[i];
gotoxy(55,i-89); cout<<price[i];
}
gotoxy(30,8) ;cout<<"PASTRIES";
for(i=95;i<101;i++)
{
gotoxy(15,i-85); cout<<i+1;
gotoxy(30,i-85); cout<<food[i];
gotoxy(55,i-85); cout<<price[i];
}
gotoxy(25,25); cout<<"PRESS ANY KEY TO CONTINUE"; getch();
clrscr();
gotoxy(30,1); cout<<"ICE-CREAMS";
for(i=101;i<113;i++)
{
gotoxy(15,i-98); cout<<i+1;
gotoxy(30,i-98); cout<<food[i];
gotoxy(55,i-98); cout<<price[i];
}
gotoxy(25,25);cout<<"PRESS ANY KEY TO CONTINUE"; getch();
clrscr();
int answ,fc,fch[113],fe=0,z=-1;
char fi[113][30],answe;
RETRY: clrscr();
cout<<"PRESS 0 TO GO BACK TO MENU CARD\n"
<<"PRESS 1 TO CONTINUE ";
cin>>answ;
switch(answ)
{
case 0 : goto START;
break;
case 1 : clrscr();
do
{
z++;
cout<<"ENTER THE FOOD CODE YOU WANT TO HAVE :: ";
cin>>fc;
fch[z]=price[fc-1];
fe+=price[fc-1];
strcpy(fi[z],food[fc-1]);
cout<<"DO YOU WANT MORE(Y/N) :: ";
cin>>answe;
} while(answe=='y' || answe=='Y');
clrscr();
for(int y=0;y<z+1;y++)
{
cout<<fi[y];
gotoxy(40,y+1); cout<<fch[y]<<"\n";
}
cout<<"TOTAL";
gotoxy(40,y+1); cout<<fe<<"\n";
cout<<"ARE YOU STAYING IN THIS HOTEL (Y/N) ? ";
char ans;
cin>>ans;
if(ans=='y' || ans=='Y')
{
char na[25];
int rn;
cout<<"ROOM NO. :: ";
cin>>rn;
cout<<"NAME :: ";
gets(na);
for(i=0;na[i]!='\0';i++) na[i]=toupper(na[i]);
//*******************VERIFYING THE ENTERED DATA
f1.open("HOT.EL",ios::in|ios::binary);
f1.read((char *)&d,sizeof(d));
while(f1)
{
if(d.roomno==rn && strcmp(d.name,na)==0)
{
f1.close();
goto BILL;
}
f1.read((char *)&d,sizeof(d));
}
f1.close();
cout<<"ENTERED DATA IS NOT MATCHING THE ACTUAL DATA";
gotoxy(25,25); cout<<"PRESS ANY KEY AFTER PAYING THE BILL ";
getch();
return;
BILL:
//*******************ENTERING THE RESTAURANT CHARGE INTO THE FILE
f8.open("BILL.DAT",ios::in|ios::binary);
f8.read((char *)&b,sizeof(b));
int first=0;
cout<<" \nVisiting first ";
cout<<" \nPress 1 if Yes ";
cout<<" \nPress 0 if No";
cin>>first;
if (first == 1)
{
b[rn-1].brestaurant = 0;
b[rn-1].brestaurant+=fe;
}
else
b[rn-1].brestaurant+=fe;
f8.close();
f8.open("BILL.DAT",ios::out|ios::binary);
f8.write((char *)&b,sizeof(b));
f8.close();
cout<<"THE RESTAURANT BILL HAS BEEN ENTERED INTO YOUR RECORD";
}
else
{
gotoxy(25,25);
cout<<"PRESS ANY KEY AFTER PAYING THE BILL ";
getch();
return;
}
gotoxy(25,25);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
break;
default: cout<<"YOU HAVE PRESSED A WRONG KEY\nRETRY\n";
getch();
goto RETRY;
}
clrscr();
} //**********************************************************
// FUNCTION NAME : BAR
//**********************************************************
void HOTEL::bar()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
cleardevice();
setbkcolor(RED); //set text colour to red
settextstyle(8,0,4); //set font,direction,size
setcolor(YELLOW); //set text colour to yellow
delay(1000);
outtextxy(120,150,"WELCOME TO THE BAR");
delay(2000);
outtextxy(150,200,"PLEASE BE SEATED");
delay(2000);
closegraph();
char bottle[32][20]={"RED LABEL","BLACK LABEL","GOLD LABEL",
"SIGNATURE","SEAGRAMS","8 PM","CHIVAS REGAL","MC DOWELL","BLACK DOG",
"BAGPIPER","PETER SCOT","JOHNY WALKER","KINGFISHER","FOSTERS",
"BUD WEISER","HAYWARD 2000","HAYWARD 5000","VORIAN 6000","RED WINE",
"WHITE WINE","PORT WINE","IRISH CREAM","OLD MONK","BACARDI",
"BLUE RIBAND","SMIRNOFF","VO DE FRANCE","LEMAR DE VONCON",
"VINTAGE BUBBLY","KINGFISHER","BAGPIPER","EVIAN BRAND"};
int cost[32]={1500,4000,6000,3000,2500,2000,5000,1500,4000,1500,
2000,6000,1000,1500,1000,1000,1500,1500,500,550,600,4000,1500,1000,
1000,1500,5000,5500,8000,150,150,80};
START:
textcolor(4); //set text colour to red
clrscr();
gotoxy(18,1); cout<<"CODE";
gotoxy(35,1); cout<<"BRAND";
gotoxy(59,1); cout<<"PRICE";
gotoxy(35,4); cout<<"WHISKY";
for(int i=0;i<12;i++)
{
gotoxy(20,i+6); cout<<i+1;
gotoxy(35,i+6); cout<<bottle[i];
gotoxy(60,i+6); cout<<cost[i];
}
gotoxy(25,25); cout<<"PRESS ANY KEY TO CONTINUE"; getch();
clrscr();
gotoxy(35,1); cout<<"BEER";
for(i=13;i<18;i++)
{
gotoxy(20,i-10); cout<<i+1;
gotoxy(35,i-10); cout<<bottle[i];
gotoxy(60,i-10); cout<<cost[i];
}
gotoxy(35,10); cout<<"WINE";
for(i=18;i<22;i++)
{
gotoxy(20,i-6); cout<<i+1;
gotoxy(35,i-6); cout<<bottle[i];
gotoxy(60,i-6); cout<<cost[i];
}
gotoxy(35,18); cout<<"RUM";
for(i=22;i<26;i++)
{
gotoxy(20,i-2); cout<<i+1;
gotoxy(35,i-2); cout<<bottle[i];
gotoxy(60,i-2); cout<<cost[i];
}
gotoxy(25,25); cout<<"PRESS ANY KEY TO CONTINUE"; getch();
clrscr();
gotoxy(35,1); cout<<"CHAMPAIGNE";
for(i=26;i<29;i++)
{
gotoxy(20,i-23); cout<<i+1;
gotoxy(35,i-23); cout<<bottle[i];
gotoxy(60,i-23); cout<<cost[i];
}
gotoxy(35,8); cout<<"SODA";
for(i=29;i<31;i++)
{
gotoxy(20,i-19); cout<<i+1;
gotoxy(35,i-19); cout<<bottle[i];
gotoxy(60,i-19); cout<<cost[i];
}
gotoxy(35,14); cout<<"WATER";
gotoxy(20,16); cout<<"32";
gotoxy(35,16); cout<<"EVIAN BRAND";
gotoxy(60,16); cout<<"80";
gotoxy(25,25); cout<<"PRESS ANY KEY TO CONTINUE"; getch();
clrscr();
int answ,fc,fch[32],fe=0,z=-1;
char fi[32][20],answe;
RETRY: clrscr();
cout<<"PRESS 0 TO GO BACK TO THE LIST OF ITEMS\n"
<<"PRESS 1 TO CONTINUE ";
cin>>answ;
switch(answ)
{
case 0 : clrscr();
goto START;
break;
case 1 : clrscr();
do
{
z++;
cout<<"ENTER THE CODE YOU WANT TO HAVE :: ";
cin>>fc;
fch[z]=cost[fc-1];
fe+=cost[fc-1];
strcpy(fi[z],bottle[fc-1]);
cout<<"DO YOU WANT MORE(Y/N) :: ";
cin>>answe;
} while(answe=='y'||answe=='Y');
clrscr();
for(int y=0;y<z+1;y++)
{
cout<<fi[y];
gotoxy(40,y+1);
cout<<fch[y]<<"\n";
}
cout<<"TOTAL";
gotoxy(40,y+1);
cout<<fe<<"\n";
cout<<"ARE YOU STAYING IN THIS HOTEL (Y/N) ? ";
char ans;
cin>>ans;
if(ans=='y' || ans=='Y')
{
char na[25];
int rn;
cout<<"ROOM NO. :: ";
cin>>rn;
cout<<"NAME :: ";
gets(na);
int l=strlen(na);
for(i=0;i<l;i++) na[i]=toupper(na[i]);
//*******************VERIFYING THE ENTERED DATA
f1.open("HOT.EL",ios::in|ios::binary);
f1.read((char *)&d,sizeof(d));
while(f1)
{
if(d.roomno==rn && strcmp(d.name,na)==0)
{
f1.close();
goto BILL;
}
f1.read((char *)&d,sizeof(d));
}
f1.close();
cout<<"ENTERED DATA IS NOT MATCHING THE ACTUAL DATA";
gotoxy(25,25); cout<<"PRESS ANY KEY AFTER PAYING THE BILL ";
getch();
return;
BILL:
//*******************ENTERING THE BAR CHARGE INTO THE FILE
f8.open("BILL.DAT",ios::in|ios::binary);
f8.read((char *)&b,sizeof(b));
int first=0;
cout<<" \nVisiting first ";
cout<<" \nPress 1 if Yes ";
cout<<" \nPress 0 if No";
cin>>first;
if (first == 1)
{
b[rn-1].bbar = 0;
b[rn-1].bbar+=fe;
}
else
b[rn-1].bbar+=fe;
f8.close();
f8.open("BILL.DAT",ios::out|ios::binary);
f8.write((char *)&b,sizeof(b));
f8.close();
gotoxy(25,30);
cout<<"THE BAR BILL HAS BEEN ENTERED INTO YOUR RECORD";
}
else
{
gotoxy(25,25);
cout<<"PRESS ANY KEY AFTER PAYING THE BILL ";
getch();
return;
}
gotoxy(25,25);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
break;
default: cout<<"YOU HAVE PRESSED A WRONG KEY\nRETRY\n"
<<"\n\n\n\nPRESS ANY KEY TO CONTINUE\n";
getch();
goto RETRY;
}
clrscr();
} //**********************************************************
// FUNCTION NAME : VIEW DATA
//**********************************************************
void HOTEL::view_data()
{
START:
int choice;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
cleardevice();
settextstyle(10,0,2); //set font,direction,size
setcolor(LIGHTBLUE); //set text colour to light blue
outtextxy(10,5,"Which data you want to view ?");
setcolor(YELLOW); //set text colour to light yellow
settextstyle(10,0,1); //set font,direction,,size
outtextxy(50,85,"Hotel");
setcolor(LIGHTRED); //set text colour to light red
outtextxy(50,125,"Check out");
setcolor(DARKGRAY); //set text colour to dark grey
outtextxy(50,165,"Cancelled");
setcolor(RED); //set text colour to light red
outtextxy(50,205,"Back to options");
setcolor(YELLOW); //set text colour to yellow
int x=40,y=77;
outtextxy(x,y,".");
char W;
int count=0;
do
{
count++;
W=getch();
if(W=='\0'+'H')
{
setcolor(BLACK);
outtextxy(x,y,".");
y-=40;
if(y<77)
{
y=277;
setcolor(WHITE);
outtextxy(x,y,".");
choice=6;
}
else if(y==77)
{
setcolor(YELLOW);
outtextxy(x,y,".");
choice=1;
}
else if(y==117)
{
setcolor(LIGHTRED);
outtextxy(x,y,".");
choice=2;
}
else if(y==157)
{
setcolor(DARKGRAY);
outtextxy(x,y,".");
choice=3;
}
else if(y==197)
{
setcolor(RED);
outtextxy(x,y,".");
choice=4;
}
}
else if(W=='\0'+'P')
{
setcolor(BLACK);
outtextxy(x,y,".");
y+=40;
if(y>277)
{
y=77;
setcolor(YELLOW);
outtextxy(x,y,".");
choice=1;
}
else if(y==77)
{
setcolor(YELLOW);
outtextxy(x,y,".");
choice=1;
}
else if(y==117)
{
setcolor(LIGHTRED);
outtextxy(x,y,".");
choice=2;
}
else if(y==157)
{
setcolor(DARKGRAY);
outtextxy(x,y,".");
choice=3;
}
else if(y==197)
{
setcolor(RED);
outtextxy(x,y,".");
choice=4;
}
}
else if(count==1&&W==13) choice=1;
} while(W!=13);
closegraph();
switch(choice)
{
case 1 : textcolor(6);
clrscr();
//******DATA OF PEOPLE STAYING IN THE HOTEL
f1.open("HOT.EL",ios::in|ios::binary);
f1.read((char *)&d,sizeof(d));
while(f1)
{
cout<<"ROOM NO. :: "<<d.roomno<<"\n"
<<"NAME :: "<<d.name<<"\n"
<<"ADDRESS :: "<<d.address<<"\n"
<<"TEL.NO :: "<<d.telno<<"\n"
<<"CHECK-IN DATE:: "<<d.date<<"\n"
<<"ROOM TYPE :: "<<d.roomtype<<"\n\n\n";
getch();
f1.read((char *)&d,sizeof(d));
}
f1.close();
clrscr();
goto START;
case 2 : textcolor(12);
clrscr();
//********DATA OF PEOPLE WHO HAVE CHECKED-OUT
f2.open("C.OUT",ios::in|ios::binary);
f2.read((char *)&C,sizeof(C));
while(f2)
{
cout<<"ROOM NO. :: "<<C.roomno<<"\n"
<<"NAME :: "<<C.name<<"\n"
<<"ADDRESS :: "<<C.address<<"\n"
<<"TELEPHONE NO. :: "<<C.telno<<"\n"
<<"CHECK-IN DATE :: "<<C.date<<"\n"
<<"CHECK-OUT DATE :: "<<C.odate<<"\n"
<<"CHECK-OUT TIME :: "<<C.otime<<"\n\n\n";
getch();
f2.read((char *)&C,sizeof(C));
}
clrscr();
f2.close();
goto START;
case 3 : textcolor(8);
clrscr();
//********DATA OF PEOPLE WHO HAVE CANCELLED
f3.open("CAN.CEL",ios::in|ios::binary);
f3.read((char *)&D,sizeof(D));
while(f3)
{
cout<<"NAME :: "<<D.name<<"\n"
<<"ADDRESS :: "<<D.address<<"\n"
<<"TELEPHONE NO. :: "<<D.telno<<"\n\n\n";
getch();
f3.read((char *)&D,sizeof(D));
}
clrscr();
f3.close();
goto START;
}
clrscr();
}
//**********************************************************
// FUNCTION NAME : MAIN
//**********************************************************
void main()
{
//******************** STARTING PAGE ***********************
HOTEL H;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
int driver,mode;
driver=DETECT;
initgraph(&driver,&mode,""); //initialize graph
setbkcolor(0); //set background colour to black
setcolor(9); //set text color to green
settextstyle(1,0,8); //set font,direction,size
outtextxy(80,130,"HOTEL");
outtextxy(200,250,"MANAGEMENT");
delay(5000); //wait for sometime
closegraph();
initgraph(&driver,&mode,""); //initialize graph
setbkcolor(0); //set background colour to black
setcolor(9); //set text color to green
settextstyle(3,0,9); //set font,direction,size
outtextxy(130,100,"CREATED");
settextstyle(3,0,8); //set font,direction,size
outtextxy(250,250,"BY");
delay(5000); //wait for sometime
closegraph();
initgraph(&driver,&mode,""); //initialize graph
setbkcolor(0); //set background colour to black
setcolor(9); //set text color to green
settextstyle(7,0,4); //set font,direction,size
outtextxy(60,100,"STUDENT OF KIIT University:-");
outtextxy(100,200,"1. ABHISHEK KUMAR");
outtextxy(100,220,"2. RISHI AGARWAL");

outtextxy(60,340," Computer Science Engineering");
delay(4000); //wait for sometime
closegraph();
initgraph(&driver,&mode,""); //initialize graph
setbkcolor(0); //set background colour to black
setcolor(9); //set text color to green
settextstyle(1,0,5); //set font,direction,size
delay(1000); //wait for sometime
closegraph();
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(0);
delay(1000);
setcolor(RED);
settextstyle(4,0,5); //set font,direction,size
outtextxy(230,50,"WELCOME"); delay(1000);
settextstyle(7,0,5); //set font,direction,size
setcolor(BLUE);
outtextxy(290,150,"TO"); delay(1000);
settextstyle(8,0,5); //set font,direction,size
setcolor(GREEN);
outtextxy(245,250,"HOTEL"); delay(1000);
setcolor(WHITE);
settextstyle(5,0,5); //set font,direction,size
for(int i=-225,j=639;i<71;i++,j--)
{
outtextxy(i,360,"MAJESTIC"); outtextxy(j,360,"ROYAL");
delay(15); setcolor(BLACK);
outtextxy(i,360,"MAJESTIC"); outtextxy(j,360,"ROYAL");
setcolor(WHITE);
}
outtextxy(70,360,"MAJESTIC");
outtextxy(j,360,"ROYAL"); delay(1000);
i=1;
setbkcolor(BLACK);
do
{
setcolor(i);
settextstyle(4,0,5); //set font,direction,size
outtextxy(230,50,"WELCOME"); delay(100);
settextstyle(7,0,5); //set font,direction,size
setcolor(i+1);
outtextxy(290,150,"TO"); delay(100);
settextstyle(8,0,5); //set font,direction,size
setcolor(i+2);
outtextxy(245,250,"HOTEL"); delay(100);
setcolor(i+3);
settextstyle(5,0,5); //set font,direction,size
outtextxy(70,360,"MAJESTIC");
outtextxy(j,360,"ROYAL"); delay(100);
i++;
} while(i!=13);
delay(500);
cleardevice();
settextstyle(0,0,0);
for(i=400;i>=0;i--) { setcolor(BLUE); circle(320,240,i); delay(5); }
//*********************************************************
//******************** MAIN OPTIONS ***********************
//*********************************************************
int times=0;
LABEL:
times++;
int count=0;
initgraph(&gd,&gm,"c:\\tc\\bgi");
int option_code=0;
setbkcolor(BLACK);
setcolor(CYAN);
settextstyle(10,0,6);
outtextxy(180,-20,"OPTIONS ");
settextstyle(10,0,1);
setcolor(BLUE);
if(times==1)
{
delay(1000);
line(100,70,540,70);delay(1000);
setcolor(LIGHTRED);
outtextxy(220,80,"Booking"); delay(500);
setcolor(RED);
outtextxy(220,110,"Check in"); delay(500);
setcolor(BLUE);
outtextxy(220,140,"Check out"); delay(500);
setcolor(YELLOW);
outtextxy(220,170,"Cancellation"); delay(500);
setcolor(CYAN);
outtextxy(220,200,"Restaurant"); delay(500);
setcolor(MAGENTA);
outtextxy(220,230,"Bar"); delay(500);
setcolor(GREEN);
outtextxy(220,260,"Taxi Service"); delay(500);
setcolor(LIGHTMAGENTA);
outtextxy(220,290,"View Data"); delay(500);
setcolor(WHITE);
outtextxy(220,320,"Quit"); delay(500);
}
else
{
line(100,70,540,70);
setcolor(LIGHTRED);
outtextxy(220,80,"Booking");
setcolor(RED);
outtextxy(220,110,"Check in");
setcolor(BLUE);
outtextxy(220,140,"Check out");
setcolor(YELLOW);
outtextxy(220,170,"Cancellation");
setcolor(CYAN);
outtextxy(220,200,"Restaurant");
setcolor(MAGENTA);
outtextxy(220,230,"Bar");
setcolor(GREEN);
outtextxy(220,260,"Taxi Service");
setcolor(LIGHTMAGENTA);
outtextxy(220,290,"View Data");
setcolor(WHITE);
outtextxy(220,320,"Quit");
}
//***** FOR MOVING THE CURSOR UP OR DOWN *****
int x=190,y=70;
setcolor(LIGHTRED);
outtextxy(x,y,".");
char W;
do
{
count++;
W=getch();
if(W=='\0'+'H')
{
setcolor(BLACK);
outtextxy(x,y,".");
y-=30;
if(y<70)
{
y=400;
setcolor(WHITE);
outtextxy(x,y,".");
option_code=9;
}
else if(y==70)
{
setcolor(LIGHTRED);
outtextxy(x,y,".");
option_code=1;
}
else if(y==100)
{
setcolor(RED);
outtextxy(x,y,".");
option_code=2;
}
else if(y==130)
{
setcolor(BLUE);
outtextxy(x,y,".");
option_code=3;
}
else if(y==160)
{
setcolor(DARKGRAY);
outtextxy(x,y,".");
option_code=4;
}
else if(y==190)
{
setcolor(CYAN);
outtextxy(x,y,".");
option_code=5;
}
else if(y==220)
{
setcolor(MAGENTA);
outtextxy(x,y,".");
option_code=6;
}
else if(y==250)
{
setcolor(GREEN);
outtextxy(x,y,".");
option_code=7;
}
else if(y==280)
{
setcolor(LIGHTMAGENTA);
outtextxy(x,y,".");
option_code=8;
}
else if(y==310)
{
setcolor(WHITE);
outtextxy(x,y,".");
option_code=9;
}
}
else if(W=='\0'+'P')
{
setcolor(BLACK);
outtextxy(x,y,".");
y+=30;
if(y>400)
{
y=70;
setcolor(LIGHTRED);
outtextxy(x,y,".");
option_code=1;
}
else if(y==70)
{
setcolor(LIGHTRED);
outtextxy(x,y,".");
option_code=1;
}
else if(y==100)
{
setcolor(RED);
outtextxy(x,y,".");
option_code=2;
}
else if(y==130)
{
setcolor(BLUE);
outtextxy(x,y,".");
option_code=3;
}
else if(y==160)
{
setcolor(DARKGRAY);
outtextxy(x,y,".");
option_code=4;
}
else if(y==190)
{
setcolor(CYAN);
outtextxy(x,y,".");
option_code=5;
}
else if(y==220)
{
setcolor(MAGENTA);
outtextxy(x,y,".");
option_code=6;
}
else if(y==250)
{
setcolor(GREEN);
outtextxy(x,y,".");
option_code=7;
}
else if(y==280)
{
setcolor(LIGHTMAGENTA);
outtextxy(x,y,".");
option_code=8;
}
else if(y==310)
{
setcolor(WHITE);
outtextxy(x,y,".");
option_code=9;
}
}
else if(count==1&&W==13)
{
closegraph();
H.booking();
goto LABEL;
}
}while(W!=13);
closegraph();
//***** FOR GOING TO THE SPECIFIED OPTION *****
switch(option_code)
{
case 1:H.booking(); // Function for booking detailes
break;
case 2:H.check_in(); // Function for check_in detailes
break;
case 3:H.check_out(); // Function for check out detailes
break;
case 4:H.cancellation(); // Function for cancellation
break;
case 5:H.restaurant(); // Function for resturant detailes
break;
case 6:H.bar(); // Function for Bar detailes
break;
case 7:H.taxi_service(); // Function for taxi service
break;
case 8:H.view_data(); // Function for data details
break;
case 9:exit(0);
}
goto LABEL;
	      }