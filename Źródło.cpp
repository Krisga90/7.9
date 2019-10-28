#include <iostream>

const int Slen = 30;
const int Size = 10;

struct student
{
	char fullname[Slen];
	char hobby[Slen];
	int ooplevel;
};

int get_info(student pa[], int n);
void display1(student st);
void display2(const student *st);
void display3(const student st[], int n);

int main()
{
	std::cout << "Podaj wielkosc grupy: ";
	int ilosc;
	int class_size;
	std::cin >> class_size;
	while (std::cin.get() != '\n')
		continue;
	student *ptr_stu = new student[class_size];
	ilosc = get_info(ptr_stu,class_size);
	for (int i = 0; i < ilosc; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, ilosc);
	delete[] ptr_stu;

	std::cin.get();

	return 0;
}


int get_info(student pa[], int n)
{
	std::cout << "Aby zakonczyc nie wpisuj nazwy i wcisnij enter\nPodaj nazwe 1 studenta: ";
	int i;
	for (i = 0; i < n; i++)
	{
		std::cin.getline(pa[i].fullname,Slen);
		if (pa[i].fullname[0] == '\0')
			break;
		std::cout << "Podaj hobby studenta: ";
		std::cin.getline(pa[i].hobby,Slen);
		std::cout << "Podaj poziom studenta: ";
		while (!(std::cin >> pa[i].ooplevel))
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "wprowadzono zly znak\nPodaj poziom studenta: ";
		}
		std::cin.get();
		std::cout << "Aby zakonczyc nie wpisuj nazwy i wcisnij enter\nPodaj nazwe "<<i+1<<" studenta: ";


	}
	return i;
}
void display1(student st)
{
	std::cout << "imie: " << st.fullname << "\thobby: " << st.hobby << "\tpoziom: " << st.ooplevel << std::endl;
}
void display2(const student *st)
{
	std::cout << "imie: " << st->fullname << "\thobby: " << st->hobby << "\tpoziom: " << st->ooplevel << std::endl;
}
void display3(const student st[] , int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "imie: " << st[i].fullname << "\thobby: " << st[i].hobby << "\tpoziom: " << st[i].ooplevel << std::endl;
	}
}