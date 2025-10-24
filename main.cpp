#include <iostream>
#include "SparseMatrix.h"
#include "Node.h"
#include <string>
using namespace std;

void ShowMenu(){
    SparseMatrix myMatrix;
    SparseMatrix* second = new SparseMatrix();
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

        switch (option) {
            case 1: {
                int value;
                int x;
                int y;

                while (true){ //error test in value
                cout << "Insert value: ";
                cin >> value;
                if(cin.fail()){ //I reused code here
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Invalid option. Please retry "<< endl;            
                    continue;
                    }
                break;            
                }
                while (true){ 
                cout << "Insert xPos: ";
                cin >> x;
                if(cin.fail()){ 
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Invalid option. Please retry"<< endl;            
                    continue;
                    }
                break;            
                }
                while (true){ 
                cout << "Insert yPos: ";
                cin >> y;
                if(cin.fail()){ 
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Invalid option. Please retry "<< endl;;            
                    continue;
                    }
                break;            
                }
                myMatrix.add(value,x,y);
                cout << "==========================================================================" <<endl;
                cout << "                   !!!!!!!Value added success!!!!!!!                     " << endl;
                cout << "==========================================================================" <<endl;

                break;
            }
            case 2: {
                int x;
                int y;
                while (true){
                    cout << "Insert xPos: ";
                    cin >> x;
                    if(cin.fail()){ 
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Invalid option. Please retry"<< endl;            
                    continue;
                    }
                    break;
                }
                
                while (true){
                    cout << "Insert yPos: ";
                    cin >> y;
                    if(cin.fail()){ 
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Invalid option. Please retry"<< endl;            
                    continue;
                    }
                    break;
                }
                
                
                int value = myMatrix.get(x,y);
                cout << "==========================================================================" <<endl;
                cout << "             Your Value from X: " << x << " and Y : " << y << " is " << value << endl;
                cout << "==========================================================================" <<endl;
                break;
            }
            case 3: {
                
                cout << "==========================================================================" <<endl;
                cout << "                             Matrix content                               " <<endl;
                cout << "==========================================================================" <<endl;
                
                myMatrix.printStoredValues();
                            
                cout << "==========================================================================" <<endl;


                break;
            }
            case 4: {
                int x;
                int y;
                
                while (true){
                    cout << "Insert xPos: ";
                    cin >> x;
                    if(cin.fail()){ 
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "Invalid option. Please retry"<< endl;            
                        continue;
                    }
                    break;
                }
                while (true){
                    cout << "Insert yPos: ";
                    cin >> y;
                    if(cin.fail()){ 
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "Invalid option. Please retry"<< endl;            
                        continue;
                    }
                    break;
                }

                if(myMatrix.get(x,y) != 0){
                    myMatrix.remove(x,y);
                    cout << "==========================================================================" <<endl;
                    cout << "                           Element destroyes                              " << endl;
                    cout << "==========================================================================" <<endl;
                } else {
                    cout << "==========================================================================" <<endl;
                    cout << "                  There is no element to be destroyed                     " << endl;
                    cout << "==========================================================================" <<endl;

                }
                break;
            }

            case 5: {
                int porcentage = myMatrix.density();
                if(porcentage != 0){
                    cout << "Density : " << porcentage << " %" << endl;
                }
                break;

            }

            case 6: {
                int keepAdding = 0;
                cout << "Create your second matrix to multiply it with your original one" << endl;
                cout << "NOTE: IF IT DOESNT FOLLOW THE BASIC RULES OF MATRIX MULTIPLICATION, IT WONT WORK" << endl;
                
                while (keepAdding != -1){
                    cout << "\n=============Menu=============";
                    cout << "\n=   1.Add in second matrix    =";
                    cout << "\n=    2.Multiply Matrices      =";
                    cout << "\n=         -1.Exit             =";
                    cout << "\n==============================" << endl;
                    cout << "Select a Option: ";
                    cin >> keepAdding;
                    
                    switch (keepAdding){
                        case 1:{

                            //REUSED CODE FROM THE FIRST ADDING SYSTEM
                            int value;
                            int x;
                            int y;

                            while (true){ //error test in value
                            cout << "Insert value: ";
                            cin >> value;
                            if(cin.fail()){ //I reused code here
                                cin.clear();
                                cin.ignore(1000,'\n');
                                cout << "Invalid option. Please retry "<< endl;            
                                continue;
                                }
                            break;            
                            }
                            while (true){ 
                            cout << "Insert xPos: ";
                            cin >> x;
                            if(cin.fail()){ 
                                cin.clear();
                                cin.ignore(1000,'\n');
                                cout << "Invalid option. Please retry"<< endl;            
                                continue;
                                }
                            break;            
                            }
                            while (true){ 
                            cout << "Insert yPos: ";
                            cin >> y;
                            if(cin.fail()){ 
                                cin.clear();
                                cin.ignore(1000,'\n');
                                cout << "Invalid option. Please retry "<< endl;;            
                                continue;
                                }
                            break;            
                            }
                            second -> add(value,x,y);
                            cout << "==========================================================================" <<endl;
                            cout << "                   !!!!!!!Value added success!!!!!!!                     " << endl;
                            cout << "==========================================================================" <<endl;    
                            break;
                        }

                        case 2: {

                            cout << "==========================================================================" <<endl;
                            cout << "                        Multiplying both Matrices                         " << endl;
                            cout << "==========================================================================" <<endl;    
                            
                            
                            cout << "===========================YOUR MATRIX===================================="<< endl;
                            myMatrix.printStoredValues();
                            cout << "==========================================================================" <<endl;    
                            
                            
                            cout << "===========================SECOND MATRIX==================================" << endl;
                            second->printStoredValues();
                            cout << "==========================================================================" <<endl;    
                            
                            
                            SparseMatrix* newMatrix = myMatrix.multiply(second);
                            
                            if(newMatrix != nullptr){
                                cout << "==========================================================================" <<endl;    
                                cout << "                    Matrices multiplied successfully                      " << endl;
                                cout << "==========================================================================" <<endl;    
                                newMatrix->printStoredValues();
                                cout << "==========================================================================" <<endl;    
                            } else {
                                cout << "An error occurred while trying to multiply" << endl;
                            }
                            break;
                        }
                    }
                }
            }
                

            break;
            
            case -1: {
                cout <<"Turning off the system" <<endl;
                break;

            }
            default: {
                cout << "Invalid option. Please retry: ";
                continue;

            }
        }
    }
}

int main(int argc, char const *argv[]){
    ShowMenu();
    return 0;
}