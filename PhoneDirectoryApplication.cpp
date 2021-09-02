#include<iostream>
#include <stdlib.h>
#include<string.h>
using namespace std;
struct node
{
   string name , number;
   node *next;
};
node *head = NULL , *newnode , *temp;
int len = 0 ;
void C_node ()
{
    newnode = new node;
    cout<<"Enter Name ";
    cin>>newnode->name;
    cout<<"Enter number ";
    cin>>newnode->number;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next= newnode;
        temp = newnode;
    }
}
void display ()
{
    if(head == NULL)
    {
        cout<<"Contact list is Empty "<<endl;
    }
    else
    {
        node *trav = head ;
        while (trav != NULL)
        {
            cout<<"\n\t\tName :"<<trav->name<<endl;
            cout<<"\t\tPhone Number :"<<trav->number<<endl;
            trav= trav->next;
            len++;
        }
        cout<<"Total contacts in the list = "<<len<<endl;
    }
}
void search_contact ()
{
    node *search_node = head;
    string srch;

    cout<<"Enter your desired contact you want to search ";
    cin>>srch;
    bool found = false;
    if(head == NULL)
    {
        cout<<"\nList is Empty "<<endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if(srch == search_node->name || srch == search_node->number)
            {
                cout<<"\n\t\tName: "<<search_node->name<<endl;
                cout<<"\t\tPhone number: "<<search_node->number<<endl;
                found =true;

            }
            search_node = search_node->next;
        }
    }
    if(found == true)
    {

        cout<<"\t\tContact found"<<endl;
    }
    else
    {
        cout<<"Not fount "<<endl;
    }
}
void at_given () ///deletion function
{
    int pos ;
    node *next_node;
    temp = head;
    cout<<"Enter your desired position from where you want to delete contact "<<endl;
    cin>>pos;
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else if (pos > len)
    {
        cout<<"Invalid Position "<<endl;
    }
    else if(pos == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        cout<<"Contact has been deleted "<<endl;
    }
    else
    {
        for (int i = 1 ; i<pos ; i++)
        {
            temp = temp->next;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
        cout<<"Contact has been deleted "<<endl;
    }
}
void clear_all ()
{
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        while (head != NULL)
        {
            temp = head ;
            delete temp;
            head = head->next;
        }
        cout<<"\n\t\tALL contact list has been deleted "<<endl;
    }
}

void my_swap (node *node_1, node *node_2)
{
	string temp = node_1->name;
	node_1->name = node_2 -> name;
	node_2 -> name = temp;
}
void bubble_sort()
{
	int swapped;

	node *lPtr;
	node *rPrt = NULL;
	do
	{
		swapped = 0;
		lPtr = head;
		while(lPtr->next != rPrt)
		{
			if (lPtr->name > lPtr->next->name)
			{
				my_swap(lPtr, lPtr->next);
                swapped = 1;
			}
			lPtr = lPtr->next;
		}
		rPrt = lPtr;

	}while(swapped);

}
void suggestions ()
{
    node *search_node = head;
    string srch;
    cout<<"Enter string you want to search ";
    cin>>srch;
    bool found = false;

    if(head == NULL)
    {
        cout<<"Contact list is Empty "<<endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if(search_node->name.find(srch,0)  == 0 )
            {
                cout<<"\n\t\tName: "<<search_node->name<<endl;
                cout<<"\t\tPhone number: "<<search_node->number<<endl;
                found =true;
            }
            search_node = search_node->next;
        }
    }
    if(found == false)
    {
        cout<<"Not found "<<endl;
    }
}
void menu ()
{
    cout<<"Enter 1 to add contact "<<endl;
    cout<<"Enter 2 to display all contact "<<endl;
    cout<<"Enter 3 to search contact "<<endl;
    cout<<"Enter 4 to delete contact from where you want "<<endl;
    cout<<"Enter 5 to clear All record "<<endl;
    cout<<"Enter 6 to sort "<<endl;
    cout<<"Enter 7 to search by suggestion"<<endl;
    cout<<"Enter 0 to exit"<<endl;
}
int main ()
{
    cout<<"          *****PHONEBOOK*****\n"<<endl;
    int op;
    while (true )
    {
        menu();
        cin>>op;
        switch (op)
        {
        case 1:
            C_node();
            break;
        case 2:
            len = 0;
            display();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            at_given();
            break;
        case 5:
            clear_all();
            break;
        case 6:
            bubble_sort();
            break;
        case 7:
            suggestions();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout<<"Invalid Option "<<endl;
        }
    }
}
