/*
	Filename: InvItem.h
	Author: Kayla Humphrey 1310-002
	Due Date: 10/16/2023
	Purpose: header file for lab 5 implementing a stack
*/
#ifndef INVITEM_H
#define INVITEM_H
	#include <string>
	using namespace std;

	class InvItem
	{
		private:
			long serialNum;			// Serial number
			string manufactDate;	// Manufacture date
			int lotNum;				// Lot number

		public:
			// Default constructor
			InvItem()
			{ 
				serialNum = 0; 
				manufactDate = ""; 
				lotNum = 0; 
			}

			// Constructor
			InvItem(long s, string m, int lot)
			{ 
				serialNum = s; 
				manufactDate = m; 
				lotNum = lot; 
			}

			void setSerialNum(long s)
			{ 
				serialNum = s; 
			}

			void setManufactDate(string m)
			{ 
				manufactDate = m; 
			}

			void setLotNum(int lot)
			{ 
				lotNum = lot; 
			}

			long getSerialNum() const
			{ 
				return serialNum; 
			}

			string getManufactDate()
			{ 
				return manufactDate; 
			}

			int getLotNum() const
			{ 
				return lotNum;
			}
	};

#endif