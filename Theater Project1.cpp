#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int ROWS = 15;
const int COLS = 30;
ifstream infile;
ofstream outfile;
void displayMenu();
int getChoice();
void displaySeats(char [][COLS]);
void displayPrices(double[]);
void updatePrices(double[]);
void displaySales(double);
void purchaseTicket(char [][COLS],double[],double&);

void displaySeats(char seating[][COLS])
{
	//const char seats[ROWS][COLS];
	const char TAKEN = '*';
	const char EMPTY = '#';
	cout << "\n\t\tSeats";
	cout << "\n         1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0" << endl;

	for (int i = 0; i < ROWS; i++)
	{
		cout <<left<<fixed<<setw(4)<< "Row ";
		cout <<left<<fixed<<setw(3) <<(i + 1) << "  ";

		for (int j = 0; j < COLS; j++)
		{
			if (seating[i][j] = EMPTY)
				cout << EMPTY << " ";
			else
				cout << TAKEN <<" ";
		}
		cout << endl;
	}
			cout << "\n\n\n\tLegend:\t*  =  Sold";
		cout << "\n\t\t#  =  Available";
		cout << "\n\n\nPress the Enter key to continue to the Menu.";
		cin.ignore();
		cin.get();
}

void purchaseTicket(char seating[][COLS],double price[],double& sales)
{
	int totaltickets=0;
	int totalsales=0;
	char choice;
	int rowChoice;
	int seatChoice;
	int cost;
	int confirm;
	int quit;
	cout << "Do you wish to view the chart of available seats before making your selections (y/n)? ";
	cin >> choice;
	if (choice == 'y'||choice == 'Y')
	{
			displaySeats(seating);
	}
	else
	{
		do
			{
				do{
				cout <<"Please enter the row: ";
				cin >>rowChoice;
				}while (rowChoice < 1 || rowChoice > 15);
				do{
				cout <<"Please enter the seat: ";
				cin >>seatChoice;	
				}while(seatChoice < 0 || seatChoice > 30);
				if(seating[rowChoice-1][seatChoice-1] == '*')
				{
					cout <<"That seat is unavailable please make another selection.\n";
				}
				else
				{
					cost = price[rowChoice-1];
					cout <<"Ticket price: " <<cost <<endl;
					cout <<"Please confirm your purchase. 1 for yes, 2 for no.";
					cin >>confirm;
					if(confirm==1)
					{
						cout <<"Your ticket purchase has been confirmed.\n";
							seating[rowChoice-1][seatChoice-1] = '*';
							totaltickets++;
							totalsales=totalsales+cost;
					}
					else if (confirm==2)
					{
						cout <<"Would you like to purchase another ticket?  Enter 1 for yes, 2 for no." <<endl;
						cin >>quit;
					}
					cout <<"Would you like to purchase another seat? (y/n) ";
					cin >>quit;
					cout << "You have purchased a total of " << totaltickets << "tickets for a total price of $" << totalsales << endl;
					sales = totalsales;
				}
			}
			while (quit=='y');
	}
	return;
}

int main()
{
	const int ROWS = 15;
	const int COLS = 30;
	char seating [ROWS][COLS];
	double sales;
	int total = 0;
	int quit;
	double price [15];
	int rowChoice;
	int seatChoice;
	int cost;
	int confirm;
	char TAKEN = '*';
	char EMPTY = '#';
	
	
	for(int i=0; i<ROWS; i++)
	{
		for(int ii=0; ii<COLS; ii++)
			seating [i][ii] = EMPTY;
	}

	int choice;
	do
	{
		cout <<endl;
		displayMenu();
		choice = getChoice();
		switch(choice)
		{
		case 1:
			displaySeats(seating);
			break;
		case 2:
			cout <<"View Seating Prices\n\n";
			displayPrices(price);
			break;
		case 3:
			updatePrices(price);
			break;
		case 4:
			purchaseTicket(seating,price,sales);
			break;
 		case 5:
			displaySales(sales);
			break;

		default: cout <<"Error Input\n";
		}
	}
	while (choice<5);
}

void displayMenu()
{
	int menuChoice;
	cout <<"\n\n\tC++ Theatre\n\n";
	cout <<"1. View Available Seats\n";
	cout <<"2. View Seating Prices\n";
	cout <<"3. Update Seating Prices\n";
	cout <<"4. Purchase a Ticket\n";
	cout <<"5. View Ticket Sales\n";
	cout <<"6. Quit\n";
	cout <<"Enter your choice(1-6): ";
}

int getChoice()
{
	int menuChoice;
	cin >>menuChoice;
	cout <<endl;
	return menuChoice;
}

void displayPrices(double[])
{
	int rowPrice [ROWS];
	infile.open("TheaterPrices.txt");

	if (!infile)
	{
		cout << "Failure to open TheaterPrices.txt file.";
	}
	cout << "Ticket Prices By Row\n\n";
	cout << setw(7) << fixed << right << "Row";
	cout << setw(7) << fixed << right << "Price"<<endl;
	cout << setw(7) << fixed << right << "---";
	cout << setw(7) << fixed << right << "----"<<endl;
	for(int count=0; count<ROWS; count++)
	{
		infile >> rowPrice[ROWS];
		int price = rowPrice[ROWS];
		cout << setw(7) << fixed << right << count+1;
		cout << setw(7) << fixed << right << price << endl;
	}
	infile.close();										
	}

void updatePrices(double[])
{
	double price [15];
	outfile.open("TheaterPrices.txt");
	for(int count=0; count<ROWS; count++)
	{
		cout <<"Enter the price for row " << (count+1) <<": $";
		cin >> price[count];
		outfile << price[count]<<endl;
	}
	outfile.close();
	return;
	
}

void displaySales(double sales)
{
	cout << "So far you have purchased $" << sales << " worth of tickets." << endl;
}
