#ifndef BOOK_H_
#define BOOK_H_
#include <string>
#include <iostream>
class Book
{
private:
	int Percent = 0;
	void prec() { Percent = (double)((double)ReadPage / (double)Page) * 100.0; }
public:

	std::string Name;
	int Page;
	int ReadPage;

	Book();

	Book AddBook(std::string bName, int bPage, int readPage = 1);

	void ChangeReadPage(int bReadPage);

	friend std::ostream & operator<<(std::ostream & os, Book & b);

}static book;

#endif // !BOOK_H_


