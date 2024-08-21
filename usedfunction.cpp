#include<iostream>
#include"billclass.cpp"
using namespace std;

void displayMenu(){
    cout<<"\t Welcome to the Super Market System"<<endl;
    cout<<"\t------------------------------------"<<endl;
    cout<<"\t\t 1.Add Item."<<endl;
    cout<<"\t\t 2.Print Bill."<<endl;
    cout<<"\t\t 3.Exit."<<endl;
}

void addItem(Bill obj){

    bool checkOpen=true;
    while(checkOpen){
        cout<<"\t Add Menu"<<endl;
        cout<<"\t----------"<<endl;

        cout<<"\t  1.Add."<<endl;
        cout<<"\t  2.Close."<<endl<<endl;

        int choice;
        cout<<"Enter your Choice: ";
        cin>>choice;


        switch(choice){
            case 1:
                {
                    system("cls");
                    string item;
                    int rate,quantity;

                    cout<<"\tEnter Item Name: ";
                    cin>>item;
                    cout<<"\tEnter Rate :";
                    cin>>rate;
                    cout<<"\tEnter Quantity:";
                    cin>>quantity;

                    obj.setItem(item);
                    obj.setRate(rate);
                    obj.setQuantity(quantity);

                    //append mode item in Bill.text
                    ofstream out("Bill.txt",ios::app);
                    if(!out){
                        cout<<"\t \\*******Error: File Can't Open!*******\\"<<endl;
                    }
                    else{
                    out<<obj.getItem()<<" : "<<obj.getRate()<<" : "<<obj.getQuantity()<<endl;
                    }

                    out.close();
                    cout<<"Item Added Successfully"<<endl;
                    Sleep(2000);
                    break;
                }

            case 2:
                {
                    system("cls");
                    checkOpen=false;
                    cout<<"\tBack to Main Menu"<<endl;
                    Sleep(3000);
                    break;
                }

            default:
                cout<<"Please enter a VALID choice";

        }

    }
}

void printBill(){
    int count=0;
    bool checkOpen=true;
    while(checkOpen){

        system("cls");
        cout<<"\t1.Add Bill"<<endl;
        cout<<"\t2.Close Session"<<endl;

        int choice;
        cout<<"\tEnter Your Choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                {
                    string item;
                    int quantity;
                    cout<<"\tEnter Item Name: ";
                    cin>>item;
                    cout<<"\tEnter Required Quantity:";
                    cin>>quantity;

                    ifstream in("Bill.txt"); //only for read
                    ofstream out("DummyBill.txt");

                    string line;
                    bool found=false;

                    while(getline(in,line)){//getline read line by line in "in" file and assign in line string
                        stringstream ss;
                        ss<<line;
                        string itemName;
                        int itemRate,itemQuantity;
                        char delimiter;   //":"

                        ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuantity;
                        if(item==itemName){
                            found=true;
                            if(quantity<=itemQuantity){
                                int amount=itemRate*quantity;
                                cout<<"\t Item | Rate | Quantity | Amount"<<endl;
                                cout<<"\t"<<itemName<<"\t "<<itemRate<<"\t "<<quantity<<"\t "<<amount<<endl;
                                int newQuantity = itemQuantity-quantity;

                                itemQuantity=newQuantity;
                                count+=amount;

                                out<<itemName<<" : "<<itemRate<<" : "<<itemQuantity<<endl<<endl;
                            }
                            else{
                                cout<<"\tSorry, Quantity of "<<item<<" is Low!"<<endl;
                            }
                        }
                        else{
                            out<<line<<endl;
                        }
                    }
                    if(found==false){
                        cout<<"\t Item Not Available!"<<endl;
                    }
                    out.close();
                    in.close();

                    remove("Bill.text");
                    rename("DummyBill.text","Bill.text");

                    break;
                }

            case 2:
                {
                    checkOpen=false;
                    cout<<"\tCounting Total Bill"<<endl;
                    break;
                }

            default:
                cout<<"Please enter a Valid Choice"<<endl;

        }
        Sleep(3000);
    }
    system("cls");
    cout<<endl<<endl;
    cout<<"\t Total Bill :"<<count<<endl;
    cout<<"----------------------";
    cout<<endl<<"Thanks for Shopping!"<<endl;
    Sleep(4000);
}
