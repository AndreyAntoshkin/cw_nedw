#ifndef CLASS_HPP_INCLUDED
#define CLASS_HPP_INCLUDED

#include <string>
#include <string.h>


using namespace std;

class UPS
{
    string gBrand;
    string gModel;
    int gCost;
    string gColor;
    int gPower;
    bool gInStock;
    string gConnector;

public:
    
    UPS();
    ~UPS()
    {}                                   // деструктор

    void setBrand(const string);
    void setModel(const string);
    void setCost(const int);
    void setColor(const string);
    void setPower(const int);
    void setInStock(const bool);
    void setConnector(const string);
    string getBrand();
    string token(string&, string);


    friend ostream& operator<<(ostream &out, const UPS &Other);
};




 
class doubleList: public UPS {
    struct Node {
        UPS other; //данные
        Node *next; //указатель на следующий узел
        Node *prev; //указатель на предыдущий
    };
public:

    Node *head;
    Node *tail;
    doubleList();
    void add_object(UPS other);
    void edit_object(int);
    void find_object(int);
    void save_file();
    int delete_object(int, doubleList);
    void showList() const;

};
 
class Menu: public doubleList
{
public:
    void select_menu();
    doubleList add_file(doubleList b);
    doubleList open_file();
    void about();

};

#endif