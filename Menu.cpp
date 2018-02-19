#include "Menu.h"

void Menu::PreLoad()
{
	AllBook.clear();
	all = 0;
	std::string name;
	int page;
	int readPage;
	IF.open("Books.txt");
	while (getline(IF, name))
	{
		IF >> page >> readPage;
		all++;
		AllBook.reserve(all);
		AllBook.insert(AllBook.end(), AddBook(name, page, readPage));
		getline(IF, name);
	}
	
	IF.close();
	StartMenu();
}

void Menu::StartMenu()
{
	system("cls");
	std::cout << "||\t Welcome to reading books project!\t\t\n";
	std::cout << "||\t Press 1 to show books.\n"
		<< "||\t Press 2 to add book.\n"
		<< "||\t Press 3 to remove book.\n"
		<< "||\t Press 0 to quit.\n||\t ";
	if (!(std::cin >> num))
	{
		std::cin.clear();
		while (!(std::cin.get() != '\n'))
		{
			std::cin.get();
		}
		StartMenu();
	}

	switch (num)
	{
		case 1: MenuOne(); break;
		case 2: MenuTwo(); break;
		case 3: MenuThree(); break;
		case 0: exit(0); break;
		default: StartMenu(); break;
	}
}

void Menu::MenuOne()
{

	while (1)
	{
		static int i;
		int n;
		system("cls");
		if (all == 0)
			std::cout << "||\t Empty\n";
		else
			while (i < all)
			{
				std::cout << "||\t "<< i + 1 << ": " << AllBook[i];
				i++;
			}
		i = 0;
		std::cout << "||\t \n||\t Press a number book or 0 to back.\n||\t ";
		std::cin >> n;
		if (n > all)
			StartMenu();
		switch (n)
		{
		case 0: StartMenu(); break;
		default: EnterBook(n); break;
		}
	}
}

void Menu::showAll()
{
	system("cls");
	std::cout << "||\t Enter a book.\n";
	for (int i = 0; i << all; i++)
	{

		std::cout << "||\t " << AllBook[i] << std::endl;
	}

}

void Menu::EnterBook(int n)
{
	int temp;
	system("cls");
	std::cout << "||\t " << AllBook[n - 1];
	std::cout << "||\t Press ReadPage or 0 to back: ";
	std::cin >> temp;
	if (temp == 0)
		MenuOne();
	AllBook[n - 1].ChangeReadPage(temp);
	Update();
}

void Menu::Update()
{
	OF.open("Books.txt");
	for (int i = 0; i < all; i++)
	{
		OF << AllBook[i].Name << "\n" << AllBook[i].Page << "\t" << AllBook[i].ReadPage << std::endl;
	}
	OF.close();
	PreLoad();
}


void Menu::MenuTwo()
{
	system("cls");
	std::string name;
	int page;
	std::cout << "||\t Enter a name or 0 to back: \n||\t ";
	std::cin.get();
	std::getline(std::cin, name);
	if (name == "0")
		StartMenu();
	std::cout << "||\t Enter a number page: \n||\t ";
	std::cin >> page;
	if (!std::cin)
		StartMenu();
	OF.open("Books.txt", std::ios_base::app);
	OF << name << "\n" << page << "\t" << 1 << std::endl;
	OF.close();
	PreLoad();
}

void Menu::MenuThree()
{
	system("cls");
	std::cout << "||\t Enter a number or 0 to back: \n";
	for (int i = 0; i < all; i++)
	{
		std::cout << "||\t " << i + 1 << ": " << AllBook[i];

	}
	int val;
	std::cout << "||\t ";
	std::cin >> val;
	if (val == 0)
		StartMenu();
	Remove(val);
}

void Menu::Remove(int v)
{
	OF.open("Books.txt");
	for (int i = 0; i < all; i++)
	{
		std::string spam1;
		int spam2;
		if (i == v - 1)
			std::cout << AllBook[i].Name << "\n" << AllBook[i].Page << "\t" << AllBook[i].ReadPage << std::endl;
		else 
			OF << AllBook[i].Name << "\n" << AllBook[i].Page << "\t" << AllBook[i].ReadPage << std::endl;
	}
	OF.close();
	PreLoad();
}