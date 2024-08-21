#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include"usedfunction.cpp"
using namespace std;

int main(){
    Bill obj;
    bool isExit=false;

    while(!isExit){
            //hide previous output
            //clear screen
        displayMenu();
        cout<<"Choose the option: ";
        int val;
        cin>>val;

        switch(val){
            case 1:
            {
                system("cls");
                addItem(obj);
                Sleep(3000);
                break;
            }
            case 2:
            {
                printBill();
                break;
            }
            case 3:
            {
                system("cls");
                isExit=true;
                cout<<"\tTHANKS FOR COMING"<<endl;
                Sleep(3000);
                break;
            }

            default:
                cout<<"Enter Valid choice"<<endl;
        }
        system("cls");
    }
    return 0;
}

