#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;
#define MAX 10
enum muzo{surname,ben,pn};
struct Subscribers
{
char FName[20];
char LName[20];
char Address[20];
long long int PhoneNumber;
double benefits;
double debt;
Subscribers* next;
};
//Subscribers *Head;
class Subscriber
{
    private:
Subscribers* Head;
void element(Subscribers*&head,char na[20],char l[20],char ad[20],long long int pnum,double ben,double deb)
{
    Subscribers*temp=new Subscribers();
strcpy(temp->FName,na);
strcpy(temp->LName,l);
strcpy(temp->Address,ad);
temp->PhoneNumber=pnum;
temp->benefits=ben;
temp->debt=deb;
temp->next=NULL;
if(head==NULL)
{
head=temp;
return;
}
else {
temp->next=Head;
head=temp;}
}

public:
   muzo temp;
   int counter()
    {
         int coun=0;
         Subscribers*temp=Head;
           while(temp!=NULL)
           {
               coun++;
               temp=temp->next;
           }
      return coun;
    }

    void searchByLname(char ln[20])
{
     int flag=0;
     Subscribers*temp=Head;
    while (temp!=NULL)
    {
        if (strcmpi(temp->LName,ln)==0)
              {
                  flag=1;
                  break;

              }
        temp=temp->next;
    }
    if (flag==1)
        cout<<"Information found :"<< temp->FName<<" "<<temp->LName<<" "<<temp->Address<<" "<<temp->benefits<<" "<<temp->debt<<endl;
    else cout<<"Information not found "<<endl;
}

void searchByFname(char fn[20])
{
     int flag=0;
    while (Head!=NULL)
    {
        if (strcmpi(Head->FName,fn)==0)
              {
                  flag=1;
                  break;

              }
        Head=Head->next;
    }
    if (flag==1)
        cout<<"Information found :"<< Head->FName<<" "<<Head->LName<<" "<<Head->Address<<" "<<Head->benefits<<" "<<Head->debt<<endl;
    else cout<<"Information not found "<<endl;
}
void searchByAdress(char adires[20])
{
     int flag=0;
    while (Head!=NULL)
    {
        if (strcmpi(Head->FName,adires)==0)
              {
                  flag=1;
                  break;

              }
        Head=Head->next;
    }
    if (flag==1)
        cout<<"Information found :"<< Head->FName<<" "<<Head->LName<<" "<<Head->Address<<" "<<Head->benefits<<" "<<Head->debt<<endl;
    else cout<<"Information not found "<<endl;
}

Subscriber()
{
Head=NULL;
}
//~Subscriber();
void AddToBack(char na[20],char l[20],char ad[20],long long int pnum,double ben,double deb)
{ char op;
  int j=counter();
  if (j!=MAX)
element(Head,na,l,ad,pnum,ben,deb);
else {
        cout<<"\nLIST IS FULL, WOULD YOU LIKE TO POP OUT ONE RECORD [Y/N]\n";
        cin>>op;
        if(op=='y'||op=='Y')
        {
            DeleteFirstNode();
            AddToBack(na,l,ad,pnum,ben,deb);

        }

    }

}
 //Добавить элемент в конец очереди
 void display()
 {
     Subscribers*temp=Head;
     if(Head!=NULL){
     while(temp!=NULL)
     {
        // cout<<temp->Address <<" "<<temp->debt<<" "<<temp->FName<<" "<<temp->LName<<" "<<temp->PhoneNumber<<" "<<temp->benefits<<endl;
         cout<<temp->FName <<" "<<temp->LName<<" "<<temp->Address<<" "<<temp->PhoneNumber<<" "<<temp->benefits<<" "<<temp->debt<<endl;
         temp=temp->next;
     }}
     else cout<<"empty";
 }
void DeleteFirstNode()
{
Subscribers*del=Head;
Subscribers*current=Head;
 while(del->next!=NULL)
 {
     current=del;
     del=del->next;
 }
 delete(del);
 current->next=NULL;
}; //Удалить первый элемент из очереди
void Print(); //Читаем первый элемент очереди

//Subscribers(); //Прототип конструктора копирования //Прототип оператора присваивания

void clearr()
{
    Subscribers*temp2=Head,*temp1=Head;
    while(temp2!=NULL)
    {
        temp1=temp2->next;
        delete temp2;
        temp2=temp1;

    }
    Head=NULL;
}
void write(string files)
{
    ofstream writetofile(files.c_str(),ios::binary);
    Subscribers*temp=Head;
    while(temp!=NULL)
    {
        writetofile.write(reinterpret_cast<char*>(&temp->FName),sizeof(temp->FName));
        writetofile.write(reinterpret_cast<char*>(&temp->LName),sizeof(temp->LName));
        writetofile.write(reinterpret_cast<char*>(&temp->Address),sizeof(temp->Address));
        writetofile.write(reinterpret_cast<char*>(&temp->benefits),sizeof(temp->benefits));
        writetofile.write(reinterpret_cast<char*>(&temp->debt),sizeof(temp->debt));
        writetofile.write(reinterpret_cast<char*>(&temp->PhoneNumber),sizeof(temp->PhoneNumber));
        temp=temp->next;
    }

}
void read(string re)
{
     Subscribers temp;
          ifstream readfrom(re.c_str()); int j,g;
         // seekg(0,ios::end);
          readfrom.seekg(0,ios::end);
          j=readfrom.tellg();
          g=j/sizeof(temp);
          readfrom.seekg(0,ios::beg);
         // cout<<g;
         char na[20],l[20],ad[20];long long int pnum; double ben,deb;
          for (int i=0;i<=g;i++)
          {
            readfrom.read(reinterpret_cast<char*>(&na),sizeof(na));
           readfrom.read(reinterpret_cast<char*>(&l),sizeof(l));
           readfrom.read(reinterpret_cast<char*>(&ad),sizeof(ad));
           readfrom.read(reinterpret_cast<char*>(&ben),sizeof(ben));
           readfrom.read(reinterpret_cast<char*>(&deb),sizeof(deb));
           readfrom.read(reinterpret_cast<char*>(&pnum),sizeof(pnum));
          AddToBack(na,l,ad,pnum,ben,deb);

          }


}
void sortbysurname()
{
    Subscribers*temp,*temp1;
    for (temp=Head;temp->next!=NULL;temp=temp->next)
    {
        for (temp1=temp->next;temp1!=NULL;temp1=temp1->next)
        {
            if (strcmpi(temp->LName,temp1->LName)>0)
            {

                swap(temp->Address,temp1->Address);
               swap(temp->benefits,temp1->benefits);
               swap(temp->debt,temp1->debt);
               swap(temp->FName,temp1->FName);
              swap(temp->LName,temp1->LName);
              swap(temp->PhoneNumber,temp1->PhoneNumber);}
        }
    }
}
void sortbyben()
{
    Subscribers*temp,*temp1,*temp3;
    for (temp=Head;temp->next!=NULL;temp=temp->next)
    {
        for (temp1=temp->next;temp1!=NULL;temp1=temp1->next)
        {
            if (temp->benefits>temp1->benefits) {


                swap(temp->Address,temp1->Address);
               swap(temp->benefits,temp1->benefits);
               swap(temp->debt,temp1->debt);
               swap(temp->FName,temp1->FName);
              swap(temp->LName,temp1->LName);
              swap(temp->PhoneNumber,temp1->PhoneNumber); }

        }
    }
}
void sortbyphone()
{
    Subscribers*temp,*temp1;
    for (temp=Head;temp->next!=NULL;temp=temp->next)
    {
        for (temp1=temp->next;temp1!=NULL;temp1=temp1->next)
        {
            if (temp->PhoneNumber>temp1->PhoneNumber)
            {

               swap(temp->Address,temp1->Address);
               swap(temp->benefits,temp1->benefits);
               swap(temp->debt,temp1->debt);
               swap(temp->FName,temp1->FName);
               swap(temp->LName,temp1->LName);
               swap(temp->PhoneNumber,temp1->PhoneNumber);}
        }
    }
}

void finalsort(muzo temp)
{
   if(temp==surname)
   {
       sortbysurname();
       return;
   }

   if(temp==pn)
   {
       sortbyphone();
       return;
   }
   if(temp==ben)
   {
       sortbyben();
       return;
   }

}
};

int main()
{
  string storage;
  char details[20];
  Subscriber muzo;
  char na[20],l[20], ad[20],op;long long int pnum,k,v;double ben,deb;
  do{
cout<<"\nChoose a command from the list below\n";

cout<<"\n1. Enter subscriber details\n";
cout<<"2. Save subscriber details\n";
cout<<"3. Retrieve subscriber details\n";
cout<<"4. Display subscriber details\n";
cout<<"5. Sort subscribers by surname\n";
cout<<"6. Sort subscribers by benefits\n";
cout<<"7. Sort subscribers by phone number\n";
cout<<"8. Search subscriber by first name\n";
cout<<"9. Search subscriber by last name\n";
cout<<"10. Search by subscriber address\n";
cout<<"11. Delete subscriber from queue\n";
cout<<endl;
cin>>k;
switch(k)
{
case 1: {do{cout<<"\n1.Enter subscriber's first name : ";
cin>>na;
cin.clear();
cout<<"\n2.Enter subscriber's last name : ";
cin>>l;
cout<<"\n3.Enter subscriber's Address : ";
cin>>ad;
cout<<"Enter subscriber's Phone number: ";
cin>>pnum;
cout<<"\n5.Enter subscriber's Benefits Amount :";
cin>>ben;
cout<<"\n6.Enter subscriber's Debt Amount : ";
cin>>deb;
muzo.AddToBack(na,l,ad,pnum,ben,deb);
cout<<"\nWould you like to enter another record ? [Y/N]\n";
cin>>op;} while(op=='y'||op=='Y'); break;}


case 2: {

cout<<"\nTo which file would you like to save your data? "; cin>>storage;
muzo.write(storage);  cout<<"\nYOUR DATA HAS BEEN SAVED! "; break;}


case 3: {cout<<"\nFrom which file would you like to retrieve your data? "; cin>>storage;
muzo.read(storage); cout<<"\nYOUR DATA HAS BEEN REVTRIVED! "; break;}

case 4: {
muzo.display(); break;}

case 5: {
muzo.sortbysurname(); cout<<"\nYOUR DATA HAS BEEN SUCCESFULLY SORTED BY SURNAME! "; break;}

case 6: {
muzo.sortbyben(); cout<<"\nYOUR DATA HAS BEEN SUCCESFULLY SORTED BY BENEFITS! "; break;}

case 7: {
muzo.sortbyphone(); cout<<"\nYOUR DATA HAS BEEN SUCCESFULLY SORTED BY PHONE NUMBER! "; break;}

case 8: {

cout<<"\nEnter the first name of the Subscriber "; cin>>storage;
muzo.searchByFname(details); break;}

case 9: {

cout<<"\nEnter the last name of the Subscriber "; cin>>storage;
muzo.searchByLname(details); break;}

case 10: {

cout<<"\nEnter the address of the Subscriber "; cin>>storage;
muzo.searchByAdress(details); break;}

case 11: {
muzo.DeleteFirstNode(); break;}

default:cout<<"..........ACCESS DENIED!!!!!"<<endl;break;
}

cout<<"WOULD YOU LIKE TO GO BACK TO THE MAIN MENU? [Y/N]\n";
cin>>op;


}while(op=='y'||op=='Y');
 // muzo.AddToBack("Andrew","salimu","lusaka",89606287862,231.5,777.2);


    return 0;
}
