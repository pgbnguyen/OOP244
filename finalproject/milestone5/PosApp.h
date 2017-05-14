// PosApp.h
// hasan.murtaza/submit 244_ms5
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// BE CAREFUL! THERE IS A BUG WITH I/O FUNCTIONS. 
// MY CODE WENT THROUGH THE SUBMITTER AND I GOT FULL MARKS FOR THIS MILESTONE.
// HOWEVER, KEEP THIS IN MIND.
#ifndef ICT_POSAPP_H_
#define ICT_POSAPP_H_

/*Headers from Milestones 1-4*/
#include "Date.h"
#include "Error.h"
#include "Item.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include "POS.h"
#include "PosIO.h"


namespace ict {
	class PosApp {
		// Private member variables
		char m_filename[128];// name of the data file
		char m_billfname[128];// name of the bill file
		Item* m_items[MAX_NO_ITEMS];
		int m_noOfItems;

		// Private member functions (methods)
		int menu();// Store's menu
		
		// Data management member functions(methods)
		void deallocateItems();// deallocates items in @m_items array
		void loadRecs();// loads records from @m_filename datafile
		void saveRecs();// saves records to @m_filename datafile
		int searchItems(const char* sku)const;// gets index of an item in @m_items array
		void updateQty();// updates quantity of an item in @m_items array
		void addItem(bool isPerishable);// adds either Persiable or NonPersiable item to @m_items array
		void listItems()const;// prints recs table with total cost

		//Point Of Sale member functions (methods)
		void truncateBillFile();// cleans @m_billfname file
		void showBill();// shows @m_billfname content and calls @truncateBillFile
		void addToBill(Item& I);// adds an item from @m_items to @m_billfname file
		void POS();// finds an item by sku(entered by user) then calls @addToBill & @showBill

	public:
		// constructors
		PosApp(const char* filename, const char* billfname);
		
		// copying operator blocked
		PosApp operator=(const PosApp other) = delete;//blocked

		// runtime
		void run();

	};//class PosApp
}//namespace ict


#endif//ICT_POSAPP_H_