#include <iostream>
#include <string>
using namespace std;
class Passenger
{
public:
	string Name;
	string Flight_Name, Destination_Name;
	int Ticket_No;
	Passenger *Next, *Prev;

	Passenger(string name, string F_name, string D_name, int ticket)
	{
		Name = name;
		Flight_Name = F_name;
		Destination_Name = D_name;
		Ticket_No = ticket;
		Next = Prev = NULL;
	}
};
class Flight
{
public:
	Passenger *Head, *Tail;
	string pname, fname,dname;
	int ticket;

	Flight()
	{
		Head = Tail = NULL;
	}

	void reserve_ticket()
	{

		
			cout << "WElCOME TO PAKISTAN AIRLINES " << endl;
			cout << "Enter Your Name" << endl;
			cin >> pname;
			cout << "Enter Your Flight Departure Name" << endl;
			cin >> fname;
			cout << "Enter Your Flight Arrival Name" << endl;
			cin >> dname;
			cout << "Enter the ticket Number" << endl;
			cin >> ticket;
			Passenger *newpass = new Passenger(pname, fname, dname, ticket);
			if (Head == NULL)
			{
				Head = newpass;
				Tail = Head;
				return;
			}
			Passenger *temp = Head;
			while (temp->Next != NULL)
			{
				temp = temp->Next;
			}
			temp->Next = newpass;
			newpass->Prev = temp;
			Tail = newpass;
		
	}

	void cancel(int key)
	{
		if (Head == NULL)
		{
			return;
		}

		Passenger *temp = Head;
		for (int i = 1; i < key; i++)
		{
			temp = temp->Next;
		}
		if (temp->Next != NULL)
		{
			temp->Next->Prev = temp->Prev;
		}
		else
		{
			Tail = temp->Prev;
		}
		if (temp->Prev != NULL)
		{
			temp->Prev->Next = temp->Next;
		}
		else
		{
			Head = temp->Next;
		}
		delete(temp);
	}

	void display()
	{
		Passenger *temp = Head;
		while (temp != NULL)
		{
			cout << "COSTUMER  NAME -----------" << temp->Name << endl;
			cout << "CUSTOMER  TICKET NUMBER-    " << temp->Ticket_No << "   --DATA :" << endl;
			cout << "CUSTUMER  FLIGHT Departure From ----" << temp->Flight_Name << endl;
			cout << "CUSTOMER FLIGHT ARRIVAL " << temp->Destination_Name << endl;
			
			
			temp = temp->Next;
			cout << endl;
		}
		
	}
};
int main()
{
	Flight p1;
	int	choice;
	cout << "Press 1 Reserve A Ticket" << endl;
	cout << "Press 2 Display All Flights" << endl;
	cout << "Press 3 Delete any FLight" << endl;
	cout << "Press 0 To exit the program" << endl;
	cin >> choice;
	cout << endl;
	while (choice != NULL)
	{
		
		system("cls");
		switch (choice)
		{
			case 0:
				break;
			case 1:
				cout << "Reserve A Ticket" << endl;
				p1.reserve_ticket();
				break;
			case 2:
				cout << "Display All Flights" << endl;
				p1.display();
				break;
			case 3:
				int c;
				cout << "Enter Any Number to delete flight" << endl;
				cin >> c;
				cout << "Delete any FLight" << endl;
				p1.cancel(c);
				break;
			default:
				cout << "Wrong Choice Entered..." << endl;

		}
		choice = 0;
		cout << "Press 1 Reserve A Ticket" << endl;
		cout << "Press 2 Display All Flights" << endl;
		cout << "Press 3 Delete any FLight" << endl;
		cout << "Press 0 To exit the program" << endl;
		cin >> choice;

	}
	
	system("pause");
	return 0;
}
