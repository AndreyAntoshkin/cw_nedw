#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "main.hpp"

using namespace std;

UPS::UPS():
        gBrand("111")
        , gModel("222")
        , gCost(1000)
        , gColor("Black")
        , gPower(15)
        , gInStock(false)
        , gConnector("555")
{}                                  //конструктор



void Menu::select_menu(){
    int count = 0;
    doubleList b;
    while (1)
    {
        int num = 0;
        system("cls");
        wcout << L"(1) Открыть файл" << endl;
        wcout << L"(2) Сохрнаить файл" << endl;
        wcout << L"(3) Добавить обект" << endl;
        wcout << L"(4) Удалить обект" << endl;
        wcout << L"(5) Редактировать обект" << endl;
        wcout << L"(6) Найти" << endl;
        wcout << L"(7) Показать" << endl;
        wcout << L"(8) О программе" << endl;
        wcout << L"(9) Выход" << endl;

        num = getchar();
        switch (num)
        {
            case '1': if (count < 1){
                            b = open_file(); count += 5; break;
                        }
                        else {
                            wcout << L"Файл уже открыт!" << endl;
                            system ("pause");
                        } break;
            case '2': b.save_file(); break;
            case '3': b = add_file(b); count++; break;
            case '4': b.delete_object(count, b); count--; break;
            case '5': b.edit_object(count); break;
            case '6': b.find_object(count); break;
            case '7': b.showList(); break;
            case '8': about(); break;
            case '9': exit(0); break;

        }
    }

}

ostream& operator<<(ostream &out, const UPS &other)
{

        out << "\nBrand: " << other.gBrand
            << "\nModel: " << other.gModel
            << "\nCost: " << other.gCost
            << "\nColor: " << other.gColor
            << "\nPower: " << other.gPower
            << "\nIn Stock: " << boolalpha << other.gInStock
            << "\nConnector: " << other.gConnector
            << endl;

    return out;
}

doubleList Menu::add_file(doubleList spisok){
    system("cls");
    UPS other;
    string a;
    int b;
    bool c;

    wcout << L"Введите свойства ИБП" << endl;
    wcout << L"Бренд: ";
    cin >> a;
    other.setBrand(a);
    wcout << L"Модель: ";
    cin >> a;
    other.setModel(a);
    wcout << L"Цена: ";
    cin >> b;
    other.setCost(b);
    wcout << L"Цвет: ";
    cin >> a;
    other.setColor(a);
    wcout << L"Мощность: ";
    cin >> b;
    other.setPower(b);
    wcout << L"Наличие: (true/false) ";
    cin >> boolalpha >> c;
    other.setInStock(c);
    wcout << L"Входы: ";
    cin >> a;
    other.setConnector(a);

    spisok.add_object(other);
    wcout << L"ИБП успешно добавлен!" << endl;
    system("pause");
    return spisok;
}

void UPS::setBrand(const string brand){
    gBrand = brand;
}

void UPS::setModel(const string model){
    gModel = model;
}

void UPS::setCost(const int cost){
    gCost = cost;
}

void UPS::setColor(const string color){
    gColor = color;
}

void UPS::setPower(const int power){
    gPower = power;
}

void UPS::setInStock(const bool instock){
    gInStock = instock;
}

void UPS::setConnector(const string connector){
    gConnector = connector;
}

string UPS::getBrand(){
    return gBrand;
}
string UPS::token(string &str,string sep){

    string out;
    size_t sep_n = 0;

    sep_n = str.find(sep);
    out = str.substr(0, sep_n);

    str.erase(0, sep_n+1);
    return out;

}

doubleList Menu::open_file(){
    system("cls");

    ifstream in ("D:\\UPS.txt");
    if (!in.is_open()){
        wcerr << L"Файл не открыт!" << endl;
    }
    doubleList spisok;
    string sep = ";";
    string str;

    for(int i=0;i<5;i++)
   {
        UPS other;
        getline(in, str);

        string a = token(str, sep);
        other.setBrand(a);

        a = token(str, sep);
        other.setModel(a);

        a = token(str, sep);
        int b = stoi(a);
        other.setCost(b);

        a = token(str, sep);
        other.setColor(a);

        a = token(str, sep);
        b = stoi(a);
        other.setPower(b);

        a = token(str, sep);
        bool c;
        istringstream is (a);
        is >> boolalpha >> c;
        other.setInStock(c);

        a = token(str, sep);
        other.setConnector(a);

         spisok.add_object(other);

    }
    wcout << L"Файл успешно открыт!" << endl;
    system("pause");
    return spisok;
}


void Menu::about(){
    system("cls");
    wcout << L"Программу написал Зоткин Илья ИЦТМС-2-4" << endl;

    system("pause");
}


doubleList :: doubleList() {
    head = tail = NULL;
}

void doubleList :: add_object(UPS other) {
    Node *buf = new Node;
    buf -> other = other;
    if (!head) {
        buf -> next = tail;
        head = buf;
        buf -> prev = NULL;
    }
    else {
        buf -> next = tail -> next;
        buf -> prev = tail;
        tail -> next = buf;
    }
    tail = buf;
}

//Вывод двусвязного списка
void doubleList :: showList() const {
    system("cls");
    if (head) {
        Node *buf = head;
        while (buf) {
            cout << buf -> other;
            buf = buf -> next;
        }
        cout << endl;
    }
    else cout << "List is empty " << endl;
    system("pause");
}
// Удаление объекта
int doubleList :: delete_object(int count, doubleList spisok) {
    system("cls");
    int a = 0;
    wcout << L"Элементов в списке: " << count << endl;
    wcout << L"Введите номер объекта: ";
    cin >> a;
    while (a > count or a <= 0){
        system("cls");
        wcout << L"Данный объект отсутвует! (Объектов - " << count << L") Введите номер еще раз: ";
        cin >> a;
    }
    if (a == count){
        Node *buf = tail;
        tail = tail -> prev;
        tail -> next = NULL;
        delete buf;
        wcout << L"Объект успешно удален!" << endl;
        system("pause");
        return 0;
    }
    if (a == 1){
        Node *buf = head;
        head = head -> next;
        head -> prev = NULL;
        delete buf;
        wcout << L"Объект успешно удален!" << endl;
        system("pause");
        return 0;
    }
    if (!(a > count || a <= 1)) {
        Node *buf = head;
        for (int i = 0;i<a-1;i++){
            buf = buf->next;
        }
        Node *bufPrev = buf ->prev;
        Node *bufNext = buf ->next;
        bufPrev->next = bufNext;
        bufNext->prev = bufPrev;
        delete buf;
    }
    wcout << L"Объект успешно удален!" << endl;
    system("pause");
    return 0;
}
// Редактирование объекта
void doubleList::edit_object(int count){
    system("cls");
    int a = 0;
    string b;
    int c;
    bool d;
    wcout << L"Элементов в списке: " << count << endl;
    wcout << L"Введите номер объекта: ";
    cin >> a;
    Node *buf = head;
    for (int i = 0;i<a-1;i++){
        buf = buf->next;
    }
    wcout << L"Введите свойства ИБП" << endl;
    wcout << L"Бренд: ";
    cin >> b;
    buf -> other.setBrand(b);
    wcout << L"Модель: ";
    cin >> b;
    buf -> other.setModel(b);
    wcout << L"Цена: ";
    cin >> c;
    buf -> other.setCost(c);
    wcout << L"Цвет: ";
    cin >> b;
    buf -> other.setColor(b);
    wcout << L"Мощность: ";
    cin >> c;
    buf -> other.setPower(c);
    wcout << L"Наличие: (true/false) ";
    cin >> boolalpha >> d;
    buf -> other.setInStock(d);
    wcout << L"Входы: ";
    cin >> b;
    buf -> other.setConnector(b);
    wcout << L"Обект успешно редактирован!" << endl;
    system("pause");
}
// Поиск объекта
void doubleList::find_object(int count){
    system("cls");
    int a = 0;
    int b = 1;
    wcout << L"Элементов в списке: " << count << endl;
    wcout << L"Введите номер объекта: ";
    cin >> a;
    while (a > count or a <= 0){
        system("cls");
        wcout << L"Данный объект отсутвует! (Объектов - " << count << L") Введите номер еще раз: ";
        cin >> a;
    }
    Node *buf = head;
    while (a != 1) {
        buf = buf -> next;
        a --;
    }
    cout << buf -> other;
    cout << endl;
    system("pause");
}

void doubleList::save_file(){
    system("cls");
    ofstream out("UPS_new.txt");
    if (!out.is_open())
    {
        cerr << "Error!" << endl;
        exit(1);
    }

    if (head) {
        Node *buf = head;
        while (buf) {
            out << buf -> other;
            buf = buf -> next;
        }
        cout << endl;
    }
    else cout << "List is empty " << endl;
    wcout << L"Файл успешно сохранен" << endl;
    system("pause");
}
