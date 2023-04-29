#include <iostream>

#include <windows.h>                       //Header File For API (Included For Changing Text Colour)
                                          //This File Doesn't Exist On Online Compiler, So Text Colour Will Not Change.

using namespace std;

class hotel
{

    private:
         struct node
         {
             string name, email, contact, room_type, date;
             int room_no, stay, total;
             node *next;
         };

         node *head= NULL;

    public:

        int insertnode(string n, string id, string no, string r, int rn, string d, int s);
        int display();
        int deletenode();
        int searchnode();
        int update();

};


int hotel::insertnode(string n, string id, string no, string r, int rn, string d, int s)      //Insert A Node
{
    node *ptr= new node;
    int tot= s*1500;            //Per Day Rent 1500 Rs.

    ptr->name= n;
    ptr->email= id;
    ptr->contact= no;
    ptr->room_type= r;
    ptr->room_no= rn;
    ptr->date= d;
    ptr->stay= s;
    ptr->total= tot;

    ptr->next= NULL;

    if(head==NULL)
    {
        head= ptr;
    }

    else
    {
        node *temp= head;

        while(temp->next != NULL)
        {
            temp= temp->next;
        }

        temp->next= ptr;
    }

    system("cls");
    cout<<"\n\nBOOKING IS SUCCESSFULLY...!!!";
    cout<<"\n\nTOTAL RENT IS "<<ptr->total<<" Rs.";
    return 0;
}


int hotel::display()      //Display All Nodes Of The Linked List
{
    if(head==NULL)
    {
        cout<<"\n\nGUEST LIST IS EMPTY!!!";
    }

    else
    {
        cout<<"\t\t\t\t\t\t****************** DETAILS OF ALL GUESTS ******************"<<endl;
        node *temp= head;

        while(temp!=NULL)
        {
            cout<<"\n\nName: "<<temp->name<<endl;
            cout<<"Email: "<<temp->email<<endl;
            cout<<"Contact No.: "<<temp->contact<<endl;
            cout<<"Room Type: "<<temp->room_type<<endl;
            cout<<"Room No.: "<<temp->room_no<<endl;
            cout<<"Check In Date: "<<temp->date<<endl;
            cout<<"No. Of Days Of Stay: "<<temp->stay<<endl;
            cout<<"\nTotal Rent: "<<temp->total<<" Rs."<<endl;

            temp= temp->next;
        }

    }

    return 0;
}

int hotel::deletenode()   //Delete A Node
{
    int a, c=0;

    if(head == NULL)
    {
        cout<<"\n\nALL ROOMS ARE VACANT!!!";
    }

    else
    {

        cout<<"Enter Room Number To Be Vacated: ";
        cin>>a;

        if(a == head->room_no)
        {
            node *ptr1= head;
            head= ptr1->next;
            delete ptr1;
            c++;

            system("cls");
            cout<<"\n\nROOM IS SUCCESSFULLY VACATED....!!!";
        }

        else
        {
            node *ptr1= head;
            node *ptr2= head->next;

            while(ptr2 != NULL)
            {
                if(a == ptr2->room_no)
                {
                    ptr1->next= ptr2->next;
                    delete ptr2;
                    c++;

                    system("cls");
                    cout<<"\n\nROOM IS SUCCESSFULLY VACATED....!!!";

                    break;
                }

                ptr1= ptr2;
                ptr2= ptr2->next;
            }
        }

        if(c==0)
        {
            system("cls");
            cout<<"\n\nGUEST RECORD NOT FOUND!!!"<<endl;
            cout<<"ENTER AN EXISTING ROOM NUMBER.";
        }
    }

    return 0;

}

int hotel::searchnode()      //Display The Node Which Has Entered Room No.
{
     int a, c=0;

    if(head==NULL)
    {
        cout<<"\n\nGUEST LIST IS EMPTY!!!";
    }

    else
    {
        cout<<"Enter Room Number To Search: ";
        cin>>a;

        node *temp= head;

        while(temp != NULL)
        {
            if(a==temp->room_no)
            {
                system("cls");
                cout<<"\t\t\t\t\t\t****************** DETAILS OF GUEST IN ROOM NUMBER "<<a<<" ******************"<<endl;

                cout<<"\n\nName: "<<temp->name<<endl;
                cout<<"Email: "<<temp->email<<endl;
                cout<<"Contact No.: "<<temp->contact<<endl;
                cout<<"Room Type: "<<temp->room_type<<endl;
                cout<<"Room No.: "<<temp->room_no<<endl;
                cout<<"Check In Date: "<<temp->date<<endl;
                cout<<"No. Of Days Of Stay: "<<temp->stay<<endl;
                cout<<"\nTotal Rent: "<<temp->total<<" Rs."<<endl;

                c++;
            }

            temp= temp->next;
        }

        if(c==0)
        {
           system("cls");
           cout<<"\n\nGUEST RECORD NOT FOUND!!!"<<endl;
           cout<<"ENTER AN EXISTING ROOM NUMBER.";
        }
    }

    return 0;
}

int hotel::update()      //Update A Node
{
    int c=0;
    string n, id, no, r, d;
    int rn, s;

    if(head==NULL)
    {
        cout<<"\n\nGUEST LIST IS EMPTY!!!";
    }

    else
    {
        cout<<"Enter The Room Number To Update Details: ";
        cin>>rn;

        node *temp= head;

        while(temp != NULL)
        {
            if(rn==temp->room_no)
            {
               system("cls");

               cout<<"Enter The Updated Details"<<endl;

               cout<<"\n\nName: ";
               cin.ignore();
               getline(cin,n);

               email:
               cout<<"\nEmail-ID: ";
               cin>>id;

               int i;
               for(i=0; id[i] != '\0'; i++)                     //Email Condition Check
               {
                   if(id[i] == '@')
                   {
                       break;
                   }
               }

               if(id[i]=='\0')
               {
                   system("Color 0C");
                   cout<<"Warning: include '@'"<<endl;
                   goto email;
               }

  			   system("Color 0A");
               contact:
               cout<<"\nContact Number: ";
               cin>>no;

               if(no.length() != 10)                            //Phone No. Condition Check
               {
                  system("Color 0C");
                   cout<<"Warning: invalid phone no."<<endl;
                   goto contact;
               }

  			   system("Color 0A");
               room:
               cout<<"\nRoom Type (Single/Twin/Suite/Deluxe): ";
               cin>>r;

               if(r=="Single" || r=="Twin" || r=="Suite" || r=="Deluxe")
               {
                   goto roomNo;
               }

               else if(r=="single" || r=="twin" || r=="suite" || r=="deluxe")
               {
                   goto roomNo;
               }

               else
               {
                  system("Color 0C");
                   cout<<"Warning: incorrect room type"<<endl;       //Room Type Condition Check
                   goto room;
               }

               roomNo:
               system("Color 0A");
               cout<<"\nRoom Number: ";
               cin>>rn;
               cout<<"\nCheck In Date: ";
               cin>>d;
               cout<<"\nNo. Of Days Of Stay: ";
               cin>>s;

               int tot= s*1500;


                temp->name= n;
                temp->email= id;
                temp->contact= no;
                temp->room_type= r;
                temp->room_no= rn;
                temp->date= d;
                temp->stay= s;
                temp->total= tot;

                c++;

                system("cls");
                cout<<"\n\nRECORD IS SUCCESSFULLY UPDATED....!!!";
                cout<<"\n\nTOTAL RENT IS "<<temp->total<<" Rs.";
            }

            temp= temp->next;
        }

        if(c==0)
        {
            system("cls");
            cout<<"\n\nGUEST RECORD NOT FOUND!!!"<<endl;
            cout<<"ENTER AN EXISTING ROOM NUMBER.";
        }

    }

    return 0;
}


int main()
{
    hotel h;
    string name, email, room_type, date, contact;
    int room_no, stay;
    int ch, ch1;

    system("Color 0A");                                                 //Changes Text Colour To Green

    cout<<"\t\t\t\t\t\t\t ----------------------------------\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t      HOTEL MANAGEMENT SYSTEM      \t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t ----------------------------------\t\t\t\t"<<endl;
    cout<<"\n\n\t\t\t\t\t\t _______||PROJECT IS MADE BY TEAM ACHIEVERS||_______\t\t\t"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\tSRUSHTI KAGE 531\n\t\t\t\t\t\t\t\tTANUSHREE KADUS 530\n\t\t\t\t\t\t\t\tKRUTI NEWALKAR 847\n\t\t\t\t\t\t\t\tDEVANSHI NIKAM 848\n\n\n\n\n\n"<<endl;

    system("pause");

    system("cls");

    do
    {

         cout<<"\t\t\t\t\t\t****************** WELCOME TO OUR HOTEL DELIGHT ******************\t\t\t\t"<<endl;
        cout<<"\n\n1. BOOK ROOM"<<endl;
        cout<<"2. DISPLAY ALL GUEST DETAILS"<<endl;
        cout<<"3. VACATE ROOM"<<endl;
        cout<<"4. SEARCH BY ROOM NUMBER"<<endl;
        cout<<"5. UPDATE GUEST DETAILS"<<endl<<endl;
        cout<<"Enter Your Choice: ";
        cin>>ch;

        system("cls");

        switch(ch)
        {
            case 1:
               cout<<"ENTER THE DETAILS OF GUEST"<<endl;
               cout<<"\n\nName: ";
               cin.ignore();
               getline(cin,name);

               email:
               cout<<"\nEmail-ID: ";
               cin>>email;

               int i;
               for(i=0; email[i] != '\0'; i++)                     //Email Condition Checking
               {
                   if(email[i] == '@')
                   {
                       break;
                   }
               }

               if(email[i]=='\0')
               {
                  system("Color 0C");
                   cout<<"Warning: include '@'"<<endl;
                   goto email;
               }

  			   system("Color 0A");
               contact:
               cout<<"\nContact Number: ";
               cin>>contact;

               if(contact.length() != 10)                            //Phone No. Condition Checking
               {
                  system("Color 0C");
                   cout<<"Warning: invalid phone no."<<endl;
                   goto contact;
               }

  			   system("Color 0A");
               room:
               cout<<"\nRoom Type (Single/Twin/Suite/Deluxe): ";
               cin>>room_type;

               if(room_type=="Single" || room_type=="Twin" || room_type=="Suite" || room_type=="Deluxe")
               {
                   goto roomNo;
               }

 			  else if(room_type=="single" || room_type=="twin" || room_type=="suite" || room_type=="deluxe")
              {
          			  goto roomNo;
 			  }
 			  
               else
               {
                  system("Color 0C");
                   cout<<"Warning: incorrect room type"<<endl;       //Room Type Condition Checking
                   goto room;
               }


               roomNo:
               system("Color 0A");
               cout<<"\nRoom Number: ";
               cin>>room_no;
               cout<<"\nCheck In Date: ";
               cin>>date;
               cout<<"\nNo. Of Days Of Stay: ";
               cin>>stay;

               h.insertnode(name, email, contact, room_type, room_no, date, stay);
               break;

            case 2:
               h.display();
               break;

            case 3:
               h.deletenode();
               break;

            case 4:
                h.searchnode();
                break;

            case 5:
                h.update();
                break;

            default:
                cout<<"ENTER A VALID CHOICE....!!!";
        }

        cout<<"\n\n\nDo You Want To Continue ?"<<endl;
        cout<<"Press 1 For YES & 0 For NO...!!!!"<<endl;
        cin>>ch1;

        system("cls");

    }while(ch1!=0);

  system("Color 09");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t****************** THANKS FOR VISITING US! HOPE YOU ENJOYED YOUR STAY! ******************\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
}

