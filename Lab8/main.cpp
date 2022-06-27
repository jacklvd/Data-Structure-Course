#include <iostream>
#include <exception>
#include <string>
#include "LinkedOrd.h""
using namespace std;

// task 3
int main() {
    LinkedList<Item> ItemList;

    int choice = 0;

		// list of action for the user
    while(choice != 11){
        cout << "--------------------------------------" << endl;
        cout << "Options: "<<endl << endl;
        cout << "1. AddItem"  << endl;
        cout << "2. GetItem" << endl;
        cout << "3. IsInlist" << endl;
        cout << "4. IsEmpty" << endl;
        cout << "5. Size" << endl;
        cout << "6. SeeNext" << endl;
        cout << "7. SeePrev" << endl;
        cout << "8. SeeAt" << endl;
        cout << "9. Reset" << endl;
        cout << "10. Display" << endl;
        cout << "11. Quit" << endl << endl;
        cout << "Enter your choice: ";
        cin>> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            cout << "Please enter the following information:" << endl;
            cout << endl;

            cout << "SKU: ";
            double a;
            cin >> a;
            cout << endl;

            cout << "Description: ";
            string b;
            cin >> b;
            cout << endl;

            cout << "Price: ";
            double c;
            cin >> c;
            cout << endl;

            cout << "UOM: ";
            string d;
            cin >> d;
            cout << endl;

            Item I(a,b,c,d);

            ItemList.AddItem(I);
            cout << "Item has been added!" << endl;
            cout << endl;
            break;
        }

        case 2: {
            cout << "Please enter the SKU: ";
            double e;
            cin >> e;
            cout << endl;

            cout << "Information: "<< endl;
            cout << ItemList.GetItem(e).GetPartInfo() << endl;
            break;
        }

        case 3: {
            cout << "Please Enter the SKU: ";
            double e;
            cin >> e;
            cout << endl;

            Item I(e);
            cout << "The item is";
            if(ItemList.IsInlist(I) == 1)
                cout << " ";
            else
                cout << " not ";
            cout << "in the list."<< endl;
            break;
        }

        case 4: {
            cout << "The list is";

            if(ItemList.IsEmpty())
                cout << " ";
            else
                cout << " not ";
            cout << "empty."<< endl;
            break;
        }

        case 5: {
            cout << "Size: "<< ItemList.Size()<< endl;
            break;
        }

        case 6: {
            try {
                cout << "Information of the item at the pointer P is: ";
                cout << ItemList.SeeNext().GetPartInfo() << endl;
                break;
            }
            catch(const exception& e) {
                cout << e.what() << endl;
                break;
            }
        }

        case 7: {
            try {
                cout << "Information of the item at the pointer P is: ";
                cout << ItemList.SeePrev().GetPartInfo() << endl;
                break;
            }
            catch(const exception& e) {
                cout << e.what() << endl;
                break;
            }
        }

        case 8: {
            cout << "Please input the index you want to check: ";
            int f;
            cin >> f;
            cout << endl;

            try {
                cout << "Information of the item at the pointer P is: ";
                cout << ItemList.SeeAt(f).GetPartInfo() << endl;
                break;
            }
            catch(const exception& e) {
                cout << e.what() << endl;
                break;
            }
        }

        case 9: {
            ItemList.Reset();
            break;
        }

        case 10: {
            ItemList.display();
        }

        case 11: {
            break;
        }
        
        default: {
            cout << "Please enter options from 1 to 10!" << endl;
            cout << endl;
            break;
        }
      }

    }
    return 0;
}