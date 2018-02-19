#ifndef MENU_H_
#define MENU_H_
#include "Book.h"
#include <vector>
#include <fstream>
class Menu:Book
{
private:
	int num;
	int all = 0;
	std::ifstream IF;
	std::ofstream OF;
	std::vector<Book> AllBook;
	

public:
	
	void PreLoad();
	void StartMenu();
	void MenuOne();
	void showAll();
	void EnterBook(int n);
	void MenuTwo();
	void Update();
	void MenuThree();
	void Remove(int v);

	//void AddPage();
}static menu;

#endif; //MENU_H_