#include <iomanip>
#include <random>
#include "GraphStruct.h"

// prototype functions
void instructions();

int main() {
    
    // declare all necessary variables
    int uchoice = -1;
    int contchoice = 1;
    int first = 0;
    int second = 0;
    bool cont = true;

    cout << "\t   Welcome to Lab 11!" << endl;
    cout << "Please eneter the number of vertices for the graph: ";
    cin >> first;
    Graph* graph = new Graph(first);
    cout << endl;

    // main execution loop
    while (cont) {

        instructions();
        cout << "Your choice: ";
        cin >> uchoice;
        cout << endl;

        if (!cin) {
            uchoice = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (uchoice) {
            case 1:
            {
                cout << "Please enter source number: ";
                cin >> first;
                cout << "Please enter destination number: ";
                cin >> second;
                graph->addEdge(first, second);
                cout << endl << endl;
            }
                break;
        
            case 2:
            {
                cout << "Please enter source number: ";
                cin >> first;
                cout << "Please enter destination number: ";
                cin >> second;
								graph->removeEdge(first, second);
            }
                break;
        
            case 3:
            {
                cout << "Please enter source number: ";
                cin >> first;
                cout << "Please enter destination number: ";
                cin >> second;
                if (graph->hasEdge(first, second)) {
                    cout << "Graph has that number!" << endl << endl;
                }
                else {
                    cout << "Not in the graph!" << endl << endl;
                }
            }
                break;
        
            case 4:
            {
                cout << "Please enter a vertex number to check outEdge: ";
                cin >> first;
                graph->outEdge(first);
            }
                break;
        
            case 5:
            {
                cout << "Please enter a vertex number to check inEdge: ";
                cin >> first;
                graph->inEdge(first);
            }
                break;
            
            case 6: // Depth First Search
            {
                cout << "Please enter the a vertex number to search graph: ";
                cin >> first;
                cout << "DFS: ";
                graph->DFS(first);
                cout << endl << endl;
            }
                break;

            case 7: // Breath First Search
            {
                cout << "Please enter the a vertex number to search graph: ";
                cin >> first;
                cout << "BFS: ";
                graph->BFS(first);
                cout << endl << endl;
            }
                break;
        
            case 8: // print the graph
                cout << "\n********Your list********" << endl;
                graph->printGraph();
                break;

            case 9: // exit
								cout << "Bye!" << endl;
                return 0;
                break;
        
            default:
                cout << "Invalid Input, please try again." << endl << endl;
                break;
        }

        cout << "Keep running? yes(1)| no(0)" << endl;
        cin >> contchoice;

        // check valid input type
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input sending you back to the menu!" << endl << endl;;
        }
        else {
						if (contchoice == 0) {
		            cout << "Bye!" << endl;
		            cont = false;
		        }
		        else if (contchoice == 1) {
								cout << endl;
		            cont = true;
		        }					
        }
    }
}


void instructions() {
    cout << "------------Table of Choice------------" << endl;
    cout << "1. Add an edge to the graph" << endl;
    cout << "2. Remove an edge from the graph" << endl;
    cout << "3. Find an edge in the graph" << endl;
    cout << "4. Find the out edges of a vertices" << endl;
    cout << "5. Find the in edges of a vertices" << endl;
    cout << "6. Depth First Search the graph" << endl;
    cout << "7. Breath First Search the graph" << endl;
    cout << "8. See the graph" << endl;
    cout << "9. Quit" << endl;
    cout << "---------------------------------------" << endl << endl;
}