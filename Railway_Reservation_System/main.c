#include <stdio.h>
#include <stdlib.h>
#include "rlyres.h"
#include "conio2.h"
int enterchoice();
int main()
{

    int choice,ticket_no,result;
    char *pmob_no,*ptrain_no,*train_no;
    int *pticket_no;
    Passenger *ptr;
    add_trains();
    while(1)
    {
       choice=enterchoice();
       clrscr();
       if(choice==9)
        exit(0);
        //break; //THERE ARE MANY WAYS FOR TERMINATION break; or return 1; WE CAN USE ANY ONE OF THESE.....
        //return 1;
      switch(choice)
      {
      case 1:
          clrscr();
          view_trains();
          textcolor(WHITE);
          printf("\nPress any key to go back to main screen");
          getch();
          clrscr();

          break;
      case 2:
           ptr=get_passenger_details();
           clrscr();




          if(ptr!=NULL)
           {
               ticket_no=book_ticket(*ptr);
               if(ticket_no==-1)
               {
                   textcolor(LIGHTRED);
                   printf("BOOKING FAILED!");
               }
               else
                {
                textcolor(LIGHTGREEN);
                printf("Ticket Succesfully Booked\n Your Ticket Number is %d",ticket_no);
                }
                textcolor(WHITE);
                printf("\nPress any key to go back to main screen");
                getch();
                clrscr();
           }
          break;
      case 3:
          //view_ticket();

          clrscr();
          ticket_no=accept_ticket_no();
          if(ticket_no!=0)
            view_ticket(ticket_no);
          textcolor(WHITE);
          printf("Press any key to go back to main menu");
          getch();
          clrscr();
          break;
      case 4:
          //get_ticket_no();

          clrscr();
          pmob_no=accept_mob_no();
          if(pmob_no!=NULL)
          {
             pticket_no=get_ticket_no(pmob_no);
             view_all_tickets(pmob_no,pticket_no);

          }
          clrscr();

          break;
      case 5:
          //view_all_bookings();
          clrscr();
          view_all_bookings();
          textcolor(WHITE);
          printf("\nPress any key to go back to main screen");
          getch();
          clrscr();

          break;
      case 6:
          //view_booking();
          clrscr();
          ptrain_no=accept_train_no();
          if(ptrain_no!=NULL)
            view_booking(ptrain_no);
          clrscr();

          break;
      case 7:
          //cancel_ticket();
          clrscr();
          ticket_no=accept_ticket_no();
          if(ticket_no!=0)
          {
              result=cancel_ticket(ticket_no);
              if(result==0)
              {
                  textcolor(LIGHTRED);
                  printf("Sorry no tickets booked against ticket no %d",ticket_no);

              }
              else if (result==1)
              {
                  textcolor(LIGHTGREEN);
                  printf("Ticket no %d succesfully cancelled ",ticket_no);
              }
              else if(result==2)
              {
                  textcolor(LIGHTRED);
                  printf("Sorry ERROR in cancellation...TRY AGAIN");
              }
            textcolor(WHITE);
          printf("\n\nPress any key to go back to the main screen");

          }

          getch();
          clrscr();
          break;
      case 8:
          //cancel_train();

          clrscr();
          train_no=accept_train_no();
          if(train_no!=0)
          {
              result=cancel_train(train_no);
              if(result==0)
                    {
                        textcolor(LIGHTRED);
                        printf("SORRY! No tickets Booked against train no. %s",train_no);
                    }
                    else if(result==1)
                    {
                        textcolor(LIGHTGREEN);
                        printf("Train no. %s Successfully Cancelled",train_no);
                    }
                    else if(result==2)
                    {
                        textcolor(LIGHTRED);
                        printf("SORRY! Error in Cancellation.TRY AGAIN!!");
                    }
                textcolor(WHITE);
                printf("\n\nPress any key to go back to the main screen!");
                }

            getch();
            clrscr();

            break;
           default:
          textcolor(LIGHTRED);
        printf("\n WRONG CHOICE.....TRY AGAIN\n");
        getch();
        clrscr();
      }
    }
    return 0;
}
