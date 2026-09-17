#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "conio2.h"
#include "rlyres.h"

int enterchoice()
{
    int choice , i;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<=80;i++)
    {
        printf("_");
    }

    printf("\n\n");
    printf("Select an Option\n");
    printf("1- View Trains\n");
    printf("2- Book Ticket\n");
    printf("3- View Ticket\n");
    printf("4- Search Ticket No.\n");
    printf("5- View All Bookings\n");
    printf("6- View Train Bookings\n");
    printf("7- Cancel Ticket\n");
    printf("8- Cancel Train\n");
    printf("9- Quit\n");

    printf("\n ENTER CHOICE: ");
    scanf("%d",&choice);
    return choice;

}
void add_trains()
{
    Train alltrains[4]={
    {"123","BPL","GWA",2100,1500},
    {"546","BPL","KNW",3500,2240},
    {"345","HBJ","DEL",2100,1135},
    {"896","HBJ","MUM",4500,3360},
    };
    FILE *fp=fopen("E:\\Railway_Reservation_System_C\\alltrains.dat","rb");
    if(fp==NULL)
    {
        fp=fopen("E:\\Railway_Reservation_System_C\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        printf("File Created And saved\n");
    }
    else
        printf("File already present\n");
        fclose(fp);

}


void view_trains()
{
    int i;
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE");
     for(i=1;i<=80;i++)
    {
        printf("_");
    }
     FILE *fp=fopen("E:\\Railway_Reservation_System_C\\alltrains.dat","rb");
     Train tr;
     while(fread(&tr,sizeof(tr),1,fp)==1)
     {
         printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);

     }
     printf("\n\n\n\n");
     fclose(fp);
}

int check_train_no(char *trainno)
{
    FILE *fp=fopen("E:\\Railway_Reservation_System_C\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }

    }
   fclose(fp);
   return 0;

}
  //importanttttttt
int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
        return 0;
    while(*p_mob!='\0')
    {
       if(isdigit(*p_mob)==0)
            return 0;
       p_mob++;

    }
    return 1;

}


Passenger * get_passenger_details()
{
    clrscr();
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    static Passenger psn;
    printf("Enter passenger name: ");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    int valid;
    printf("Enter Gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
       {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
       }
       if(psn.gender!='M'&&psn.gender!='F')
       {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("ERROR ! Gender should be either M or F(in UPPER CASE");
        valid=0;
        getch();
        gotoxy(19,2);
       printf(" \b");
       textcolor(YELLOW);
       }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter Train Number:");
    do
    {
        fflush(stdin);
        scanf("%s",psn.train_no);
        if(strcmp(psn.train_no,"0")==0)
       {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
       }
       valid=check_train_no(psn.train_no);
        if(valid==0)
       {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("ERROR !INVALID TRAIN NUMBER");
        getch();
        gotoxy(20,3);
       printf("\t\t\t\t");
       gotoxy(20,3);
       textcolor(YELLOW);
       }

    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter Travelling Class(First AC:F,Second AC:S):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
       {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
       }
       if(psn.p_class!='F'&&psn.p_class!='S')
       {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("ERROR ! Travelling Class should be either F or S(in UPPER CASE");
        valid=0;
        getch();
        gotoxy(49,4);
       printf(" \b");
       textcolor(YELLOW);
       }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,5);

    printf("Enter Address");
    fflush(stdin);
    fgets(psn.address,20,stdin);

     pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
    }
    printf("Enter AGE");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%d",&psn.age);
        if(psn.age==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
        }
        if(psn.age<0||psn.age>=130)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("ERROR ! AGE SHOULD BE POSITIVE & VALID");
        valid=0;
        getch();
        gotoxy(11,6);
        printf("\t\t\t\t");
        textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,7);


    //mobile number input

    printf("Enter Mobile Number:");
    do
    {
        fflush(stdin);
        fgets(psn.mob_no,12,stdin);
        pos=strchr(psn.mob_no,'\n');
        if(pos!=NULL)
        *pos='\0';
        if(strcmp(psn.mob_no,"0")==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
        }
        valid=check_mob_no(psn.mob_no);
        if(valid==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("ERROR !INVALID MOBILE NUMBER");
        getch();
        gotoxy(21,7);
       printf("\t\t\t\t\t\t\t\t");
       gotoxy(21,7);
       textcolor(YELLOW);
        }


    }while(valid==0);

   return &psn;
}




int get_booked_ticket_count(char *train_no,char tc)
{
    FILE *fp=fopen("E:\\Railway_Reservation_System_C\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0 && pr.p_class==tc)
            ++count;
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    FILE *fp=fopen("E:\\Railway_Reservation_System_C\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;
    fseek(fp,-1L*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}
int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==5)
    {
        textcolor(LIGHTRED);
        printf("All seats in train no %s in class %c is full",p.train_no,p.p_class);
        return -1;
    }
    int ticket_no=last_ticket_no()+1;
    p.ticketno=ticket_no;
    FILE *fp=fopen("E:\\Railway_Reservation_System_C\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!File cannot be opened");
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}







int accept_ticket_no()
{
    printf("ENTER A VALID TICKET NUMBER:");
    int valid;
    int ticket_no;
    do
    {
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("CANCELLING INPUT.....");
        getch();
        textcolor(YELLOW);
        clrscr();
        return 0;
        }
        if(ticket_no<0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("ERROR !INVALID TICKET NUMBER....ticket number should be positive");
        getch();
        valid=0;

        gotoxy(29,1);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(29,1);
        textcolor(YELLOW);
        }

    }while(valid==0);
    return ticket_no;

}


 void view_ticket(int ticket_no)
 {
    int i;
    FILE *fp=fopen("E:\\Railway_Reservation_System_C\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!File cannot be opened");
        return ;
    }

    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticketno==ticket_no)
        {
            printf("\nNAME:%s\nGENDER:%c\nTRAIN NO:%s\nCLASS:%c\nADDRESS:%s\nAGE:%d\nMOBILE NO:%s\nTICKET NO:%d\n\n\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
            found=1;
            break;
        }
    }
    if(!found)
    {
        textcolor(LIGHTRED);
        printf("\nNO details of the ticket number %d found!\n",ticket_no);
    }
    fclose(fp);

 }


char *accept_mob_no()
{
    static char mob_no[12];
    char *pos;
    int valid;
    printf("ENTER VALID MOBILE NUMBER:");
    do
    {
        fflush(stdin);
        fgets(mob_no,13,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("CANCELLING INPUT.....!");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
        }


        valid=check_mob_no(mob_no);
        if(valid==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("ERROR !INVALID MOBILE NUMBER");
        getch();
        gotoxy(27,1);
       printf("\t\t\t\t\t\t\t\t");
       gotoxy(27,1);
       textcolor(YELLOW);
        }


    }while(valid==0);
    clrscr();
    return mob_no;
    }


int *get_ticket_no(char *p_mob_no)
{
    int count=0;
    FILE *fp=fopen("E:\\Railway_Reservation_System_C\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!File cannot be opened");
        return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp))
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            ++count;
        }
    }
    if(!count)
    {
        fclose(fp);
        return NULL;
    }
    int *p=(int *)malloc((count+1)*sizeof(int));
    rewind(fp);
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            *(p+i)=pr.ticketno;
            i++;
        }
    }

    *(p+i)=-1;
    fclose(fp);
    return p;
}



void view_all_tickets(char *pmob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against Mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("Press any key to go back to main screen");
        textcolor(YELLOW);
        getch();
        return;

    }

    printf("FOLLOWING ARE TICKETS BOOKED FOR THE MOBILE NUMBER %s",pmob_no);
    int i;
    printf("\n\nTICKET NUMBERS\n");
    printf("-----------------------------------------------------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));

    textcolor(WHITE);
    printf("\nPress any key to go back to main screen");
    textcolor(YELLOW);
    getch();
    free(pticket_no);

}





char *accept_train_no()
{
    static char train_no[10];
    int valid;
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to EXIT");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("ENTER TRAIN NUMBER:");
    do
    {
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t\t");
         gotoxy(1,25);
         printf("CANCELLING INPUT.....");
         getch();
        textcolor(YELLOW);
        return NULL;
        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("ERROR !INVALID TRAIN NUMBER");
        getch();
        gotoxy(20,1);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(20,1);
        textcolor(YELLOW);

        }
    }while(valid==0);
    clrscr();
    return train_no;

}


void view_booking(char *train_no)
{
    int found=0;
    FILE *fp=fopen("E:\\Railway_Reservation_System_C\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!File cannot be opened");
        return ;
    }
    Passenger pr;
    printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    for(int i=1;i<=80;i++)
    {
        printf("-");
    }
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            row++;
            found=1;
        }
    }
    if(!found)
    {
        clrscr();
        textcolor(LIGHTRED);
        printf("\nNo details of bookings in train number %s found",train_no);

    }
    textcolor(WHITE);
    printf("\n\nPress any key to continue ");
    textcolor(YELLOW);
    getch();
    fclose(fp);


}




int cancel_ticket(int ticket_no)
{
    int result;
    FILE *fp1=fopen("E:\\Railway_Reservation_System_C\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n NO bookings done yet!");
        return -1;
    }
    FILE *fp2=fopen("E:\\Railway_Reservation_System_C\\temp.dat","wb");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno==ticket_no)
        {
            found=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("E:\\Railway_Reservation_System_C\\temp.dat");
    }
    else
    {
      result=remove("E:\\Railway_Reservation_System_C\\allbookings.dat");
      if(result!=0)
        return 2;

      result=rename("E:\\Railway_Reservation_System_C\\temp.dat","E:\\Railway_Reservation_System_C\\allbookings.dat");
      if(result!=0)
        return 2;
    }
    return found;
}





//ASSIGNMENT.....SOLUTION....


void view_all_bookings()
{
    FILE *fp=fopen("E:\\Railway_Reservation_System_C\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("NO FILE FOUND");
        return ;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        printf("\nNAME:%s\nGENDER:%c\nTRAIN NO:%s\nCLASS:%c\nADDRESS:%s\nAGE:%d\nMOBILE NO:%s\nTICKET NO:%d\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
        for(int i=1;i<=80;i++)
            printf("-");
    }

     fclose(fp);

}


int cancel_train(char* train_no)
{
    int result;

    FILE *fp1=fopen("E:\\Railway_Reservation_System_C\\allbookings.dat","rb");

    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("No Bookings done yet!");
        return -1;
    }

    FILE *fp2=fopen("E:\\Railway_Reservation_System_C\\allbookings.dat","wb");

    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            found=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);

    if(found==0)
    {
        remove("E:\\Railway_Reservation_System_C\\temp.dat");
    }
    else
    {
        result=remove("E:\\Railway_Reservation_System_C\\allbookings.dat");
        if(result!=0)
        return 2;


      result=rename("E:\\Railway_Reservation_System_C\\temp.dat","E:\\Railway_Reservation_System_C\\allbookings.dat");
      if(result!=0)
        return 2;

    }
    return found;
}
















