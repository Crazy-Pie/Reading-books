#include "Book.h"

Book::Book()
{

}

Book Book::AddBook(std::string bName, int bPage, int readPage)
{
	Book temp;
	temp.Name = bName;
	temp.Page = bPage;
	temp.ReadPage = readPage;
	return temp;
}


void Book::ChangeReadPage(int bReadPage)
{
	ReadPage = bReadPage;
}

std::ostream & operator<<(std::ostream & os, Book & b)
{
	b.prec();
	os << "Name book: " << b.Name << ", All page: " << b.Page<< ", "  << "Read Page: " << b.ReadPage << " : " << b.Percent << "%" << std::endl;
	return os;
}
