// PosApp.cpp
// hasan.murtaza/submit 244_ms5
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// BE CAREFUL! THERE IS A BUG WITH I/O FUNCTIONS. 
// MY CODE WENT THROUGH THE SUBMITTER AND I GOT FULL MARKS FOR THIS MILESTONE.
// HOWEVER, KEEP THIS IN MIND.
#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "PosApp.h"


using namespace std;

namespace ict {

	void PosApp::deallocateItems() {
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i] = nullptr;
		}
		m_noOfItems = 0;

	}//deallocateItems()

	//constructors
	PosApp::PosApp(const char* filename, const char* billfname) {
		std::strcpy(m_filename, filename);
		std::strcpy(m_billfname, billfname);

		deallocateItems();
	}//two argument constructor


	int PosApp::menu() {
		int user_input;
		
		std::cin.clear(); // clears the error flag on cin

		// menu prompt
		std::cout
			<< "The Sene-Store" << std::endl
			<< "1- List items" << std::endl
			<< "2- Add Perishable item" << std::endl
			<< "3- Add Non-Perishable item" << std::endl
			<< "4- Update item quantity" << std::endl
			<< "5- Show Item" << std::endl
			<< "6- POS" << std::endl
			<< "0- exit program" << std::endl
			<< "> ";
		std::cin >> user_input;
		std::cin.ignore(1000, '\n'); // skips to the next newline



		//user input validation
		if (cin.fail()) {
			user_input = -1; // fail flag
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			
			std::cin.setstate(ios::failbit);
		}

		if (user_input < 0 || user_input > 6) {
			user_input = -1; // fail flag
		}
		return user_input;
	}//int menu()

	

	void PosApp::loadRecs() {
		// deallocate previous memory
		deallocateItems();
		char type_of_item; // either P or N

		// I/O file
		fstream sleep_deprivation;
		
		// reading from file
		sleep_deprivation.open(m_filename, ios::in);

		//it failed = no file
		if (sleep_deprivation.fail()) {
			//clear the failure
			sleep_deprivation.clear();
			//close file
			sleep_deprivation.close();
			//creating a new file
			sleep_deprivation.open(m_filename, ios::out);
			//close it
			sleep_deprivation.close();
		}
		//successfully opened file || created it
		else {

			// fstream.eof stands for the end of file
			// I loop through it till it ends
			// when @fstream.eof == true (means no content inside the file || end of the file) it exits the loop
			while (!sleep_deprivation.eof()) {

				// reading our flag
				sleep_deprivation.get(type_of_item);

				// creating a new object in @m_items[m_noOfItems]
				// either p or n
				if (!sleep_deprivation.fail()) {

					if (type_of_item == 'P') {
						sleep_deprivation.ignore();
						m_items[m_noOfItems] = new Perishable();
						m_items[m_noOfItems]->load(sleep_deprivation); // @Perishable load
						m_noOfItems++;
					}
					else if (type_of_item == 'N') {
						sleep_deprivation.ignore();
						m_items[m_noOfItems] = new NonPerishable();
						m_items[m_noOfItems]->load(sleep_deprivation); // @NonPerishable load
						m_noOfItems++;
					}
					else {
						m_items[m_noOfItems] = nullptr;
					}
				}
			}
			// close file
			sleep_deprivation.close();
		}
	}// loadRecs() - loads all the Item records saved in the data file

	void PosApp::saveRecs() {

		fstream lack_of_sleep;

		// ios::out - flag for write operations
		lack_of_sleep.open(m_filename, ios::out);

		//looping trough our @m_items and write them to file using save
		for (int i = 0; i < m_noOfItems; i++) {
			/*if (m_items[i]->quantity() <= 0) {
				// Does nothing.
				// basically not going to save them!!!!!
			}
			else {*/
				m_items[i]->save(lack_of_sleep);
			//}
		}

		//close file
		lack_of_sleep.close();

	}//saveRecs - overwrites the data in the data file with items

	void PosApp::listItems()const {
		double total = 0;
		int number = 1;
		std::cout << std::endl;
		std::cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << std::endl;
		std::cout << "-----|--------|--------------------|-------|---|----|---------|" << std::endl;
		for (int i = 0; i < m_noOfItems; i++) {
			if (m_items[i]->quantity() > 0) {
				
				std::cout.fill(' ');
				std::cout << setw(4) << right << number << " | ";
			
				m_items[i]->write(std::cout, true);

				// it's not magic lol
				// i declared this opeerator in @Item.h
				// double operator+=(double& d, const Item& I)
				// basically it multiplies cost & quantity and stores in a double(total)
				// *m_items is a dereferencing pointer
				// it points to an object && accesses the value
				// here's a good topic on stackoverflow in case I forget it after a while: http://stackoverflow.com/questions/4955198/what-does-dereferencing-a-pointer-mean
				total += *m_items[i];
				std::cout << endl;
				number += 1;
				
			}
		}
		//                               Total Asset: $  |       1436.59|
		std::cout << "-----^--------^--------------------^-------^---^----^---------^" << std::endl;
		std::cout << "                               Total Asset: $  |" << std::setw(14) << std::setprecision(2) << std::fixed << total << "|" << std::endl;
		std::cout << "-----------------------------------------------^--------------^" << std::endl << std::endl;

	}// listItems() const - Prints the inventory of the Items and calculates and prints the total asset value
	

	void PosApp::updateQty() {
		int add; // add value
		char sku[MAX_SKU_LEN + 1];

		std::cout << std::endl << "Please enter the SKU: " ;
		std::cin >> sku;
		int i = searchItems(sku);// returns the index
		
		// looking for our item
		if (i != -1) {
			//prints item with sku in nonlinear format
			m_items[i]->write(cout, false);
			std::cout << std::endl;
			std::cout << "Please enter the number of purchased items: ";
			std::cin >> add;
			// updating quantity of m_items[i]
			if (!std::cin.fail()) {
				// declared in Item.h 
				// int operator+=(int)
				// adds int to quantity
				(*m_items[i]) += add;

				saveRecs();// saves updated records

				std::cout << "Updated!" << std::endl;
				std::cout << endl;
				std::cin.clear();
			}
		}
		else {
			std::cout << "Not found!" << std::endl;
			std::cout << std::endl;
		}
	}// updateQty() - updates quantity of a single item


	int PosApp::searchItems(const char* sku)const {
		int index_of_item = -1; // by default fail
		for (int i = 0; i < m_noOfItems; i++) {
			// when we find our sku we dont enter the loop	
			if (index_of_item == -1) { // not a gentleman's way to style this but works
				if (*m_items[i] == sku)
					index_of_item = i; //gets it here!
			}
		}

		return index_of_item;
	}// searchItems(const char* sku)const - returns the index of the found item 

	void PosApp::addItem(bool isPerishable) {
		std::cout << std::endl;
		if (isPerishable) {	
			//Pointer to my Item class
			Item* pItem;
			// Persihable item
			// pItem can mutate since its parent = child relation
			pItem = new Perishable(); // derived from Item
			pItem->read(std::cin);
			if (std::cin.fail()) {
				
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				// *pItem->write(cout, true)
				std::cout << *pItem << std::endl << std::endl;
				
			}
			else {
				m_items[m_noOfItems] = pItem; //adding a perishable item to the array
				m_noOfItems++;
				saveRecs();
				std::cout << "Item added." << std::endl << std::endl;
				
			}
			pItem = nullptr;
		}
		//NonPerishable
		else {
			//Pointer to my Item class
			Item* nItem;
			//NonPersihable item
			nItem = new NonPerishable();
			nItem->read(std::cin);
			//Failed input
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				// *nItem->write(cout, true)
				std::cout << *nItem << std::endl << std::endl; //value
				//delete[] nItem;
				
			}
			else {
				m_items[m_noOfItems] = nItem; //adding a nonperishable item to the array
				m_noOfItems++;
				saveRecs();
				std::cout << "Item added." << std::endl << std::endl;
				
			}
			nItem = nullptr; //deallocate

		}
	}// addItem(bool isPerishable) - adds an Item to the m_items array and saves the array in the data file

	void PosApp::truncateBillFile() {
		ofstream final_exam_failure;

		// dont need to check it creates file for us
		// I simply open file for writing
		// and with truncate option I remove all the content inside of it!
		final_exam_failure.open(m_billfname, ios::out | ios::trunc); // awesome!
		final_exam_failure.close(); //ALWAYS CLEAN!
	}//truncateBillFile() - removes all the data from the m_billfname file.


	void PosApp::showBill() {
		//fstream file;
		double total = 0;
		char type_of_item;
		
		fstream cheer_up;//the worst is yet to come
		//open
		cheer_up.open(m_billfname, ios::in);
		std::cout.fill(' ');
		//no file on the disk
		if (cheer_up.fail()) {
			//clear
			cheer_up.clear();
			//close
			cheer_up.close();
			//create
			cheer_up.open(m_billfname, ios::out);
			//close
			cheer_up.close();
		}
		else {
			std::cout << "v--------------------------------------------------------v" << std::endl;
			std::cout << "| " << Date() << "                                      |" << std::endl;
			std::cout << "| SKU    | Item Name          | Price |TX |Qty |   Total |" << std::endl;
			std::cout << "|--------|--------------------|-------|---|----|---------|" << std::endl;



			while (!cheer_up.eof()) {

				cheer_up >> type_of_item;
				cheer_up.ignore(1);
				if (!cheer_up.eof()) {
					std::cout << "| ";
					if (type_of_item == 'P') {
						Item* pItem;
						pItem = new Perishable();
						pItem->load(cheer_up);
						pItem->write(std::cout, true);
						total += pItem->cost();
						
					}
					else if (type_of_item == 'N') {
						Item* nItem;
						nItem = new NonPerishable();
						nItem->load(cheer_up);
						nItem->write(std::cout, true);
						total += nItem->cost();
						
					}	
					std::cout << std::endl;
				} //loop end
				
			}
			std::cout << "^--------^--------------------^-------^---^----^---------^" << std::endl;
			std::cout << "|                               Total: $  |" << std::setw(14) << std::setprecision(2) << std::fixed << total << "|" << std::endl;
			std::cout << "^-----------------------------------------^--------------^" << std::endl;
			std::cout << std::endl;

			cheer_up.clear();
			cheer_up.close();

			// so when we call @truncateBillFile it means that we never going to see the same bill twice
			// 
			truncateBillFile();
		}

		}//showBill() - shows the bill of point of sale

	void PosApp::addToBill(Item& I) {
		int add;
		add = I.quantity(); //stores the real value 

		// FOR SHOW BILL FUNCTION 
		I.quantity(1); //gonna show 1 in POS function
		//didn't find better way to output 1 to bill

		fstream change_is_good;//but dollars are better

		change_is_good.open(m_billfname, ios::out | ios::app);
		if (add > 0) {
			add--; // if we type -number it's gonna deduct it from the quantity
		}

		I.save(change_is_good);//adds to bill
		I.quantity(add);//updates total quantity


		change_is_good.close();
		saveRecs();
	}

	void PosApp::POS() {
		cout << endl;

		char sku[MAX_SKU_LEN + 1];
		int i = 0;

		do {
			cout << "Sku: ";
			cin.getline(sku, MAX_SKU_LEN + 1);

			i = searchItems(sku); //geting the index

			if (i != -1) {

				if (m_items[i]->quantity() > 0) {

					cout
						<< "v------------------->" << endl
						<< "| " << m_items[i]->name() << endl //outputs added to bill name
						<< "^------------------->" << endl;

					addToBill(*m_items[i]);
				}
				else {
					cout << "Not found!" << endl;
				}

			}
			else if (sku[0] != 0) {
				cout << "Not found!" << endl;
			}

		} while (sku[0] != 0); // basically means empty string or enter press '\0'

		showBill();
	}

	void PosApp::run() {
		char sku[MAX_SKU_LEN + 1];
		bool end_program = false; 
		int user_input;

		while (!end_program) {
			user_input = 1337; //reset just in case
			user_input = menu();//get menu number

			//1
			if (user_input == 1) {
				loadRecs();
				listItems();
			}

			//2
			else if (user_input == 2) {
				addItem(true);
			}
			//3
			else if (user_input == 3) {
				addItem(false);
			}

			//4
			else if (user_input == 4) {
				updateQty();
			}
			//5
			else if (user_input == 5) {
				cout << endl << "Please enter the SKU: ";
				cin >> sku;
				if (searchItems(sku) != -1) {
					cout << "v-----------------------------------v" << endl;
					m_items[searchItems(sku)]->write(cout, false); // non linear output
					cout << "^-----------------------------------^" << endl << endl;

				}
				else {
					cout << "Not found!" << endl;
					cout << endl;
				}
			}

			//6
			else if (user_input == 6) {
				POS();
			}

			//0
			else if (user_input == 0) {
				end_program = true;
			}
			//input fail
			else if (user_input == -1){
				cout << "===Invalid Selection, try again===" << endl;
			}

		}//end of while

		cout << endl << "Goodbye!" << endl;
	}//void PosApp::run()



}//namespace ict {



/*
ouputs:
-------------------------------------
update:
Please enter the SKU: 1313
Name:
Paper Tissue
Sku: 1313
Price: 1.22
Price after tax: 1.38
Quantity: 194
Total Cost: 267.45

Please enter the number of purchased items: 12
Updated!

------------------------------
Please enter the SKU: 3434
Not found!

-------------------------------------
add item:
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 1200/10/12
Invalid Year in Date Entry

Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 2017/5/15
Item added.

--------------------------------------------
list item:
 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
-----|--------|--------------------|-------|---|----|---------|
   1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
   2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
   3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
   4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
   5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
   6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
-----^--------^--------------------^-------^---^----^---------^
                               Total Asset: $  |       1436.59|
-----------------------------------------------^--------------^


--------------------------------------
printbill:
v--------------------------------------------------------v
| 2017/04/02, 12:42                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         22.05|
^-----------------------------------------^--------------^

-------------------------------------------------------
POS:
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1313
v------------------->
| Paper Tissue
^------------------->
Sku: 1234
v------------------->
| Milk
^------------------->
Sku: 7654
Not found!
Sku: 5656
v------------------->
| Honey
^------------------->
Sku:
v--------------------------------------------------------v
| 2017/04/02, 12:58                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 1234   |Milk                |   3.99|  P|   1|     3.99|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         32.03|
^-----------------------------------------^--------------^

------------------------------------------------------
run:
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 5656
v-----------------------------------v
Name:
Honey
Sku: 5656
Price: 12.99
Price after tax: 14.68
Quantity: 10
Total Cost: 146.79
Expiry date: 2017/05/15
^-----------------------------------^

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 12345
Not found!

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> five

===Invalid Selection, try again===

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 0

Goodbye!

*/