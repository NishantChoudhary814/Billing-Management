#include<string>
using namespace std;


class Bill{
private:
    string item;
    int rate,quantity;

public:
    Bill(){
        item="";
        rate=0;
        quantity=0;
    }
    Bill(string s,int r,int n){
        item=s;
        rate=r;
        quantity=n;
    }

    void setItem(string s){
        item=s;
    }
    void setRate(int r){
        rate=r;
    }
    void setQuantity(int n){
        quantity=n;
    }

    string getItem(){
        return item;
    }

    int getRate(){
        return rate;
    }
    int getQuantity(){
        return quantity;
    }
};

