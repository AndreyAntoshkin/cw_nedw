#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>

#include "main.hpp"

using namespace std;

int main(){

    setlocale(LC_ALL, "");

    Menu menu;

    menu.select_menu();

    system("pause");
    return 0;
}
