#include <iostream>
#include "SparseMatrix.h"
#include "Node.h"
#include <string>
using namespace std;

void ShowMenu(){
    SparseMatrix myMatrix;
    int option=0;

    while(option != -1){
        cout << "\n=============Menu=============";
        cout << "\n=         1.Add value         =";
        cout << "\n=         2.Get Value         =";
        cout << "\n=         3.Deploying         =";
        cout << "\n=         4.Remove            =";
        cout << "\n=         5.Density           =";
        cout << "\n=         6.Multiply          =";
        cout << "\n=         -1.Exit             =";
        cout << "\n==============================" << endl;
        cout << "Select a Option: ";
        cin >> option;


        //i get this from CHATGPT,  
        //For some strange reason, when I typed a letter in my input, it caused an infinite loop of prints,
        //and I spent 10 hours breaking my head over it, so I just get this from ChatGPT.
        //please dont give me a 1.0 ;(
        if(cin.fail()){ 
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Invalid option. Please retry: ";            
            continue;
        }

        switch (option) 
        {
        case 1:
            cout << "add" << endl;
            break;
        case 2:
            cout << "getting" << endl;
            break;
        case 3:
            cout << "deploying" << endl;
            break;
        case 4:
            cout << "removing" << endl;
            break;
        case -1:
            cout <<"Turning off the system" <<endl;
            break;
        default:
            cout << "Invalid option. Please retry: ";
            continue;
        }
    }

}
  
int main(int argc, char const *argv[])
{
    ShowMenu();
    return 0;
}


