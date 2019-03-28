#include<iostream>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

//1.***Îïèñàòü ñòðóêòóðó Man(Ôàìèëèÿ, Èìÿ, Âîçðàñò, Äàòà ðîæäåíèÿ).Ñîçäàòü ìàññèâ, ïðåäóñìîòðåòü:
//-Âûâîä èíôîðìàöèè ñ ñîðòèðîâêîé ïî ôàìèëèè èëè èìåíè;
//-Âûâîä ñïèñêà èìåíèííèêîâ ìåñÿöà ñ óêàçàíèåì äàòû ðîæäåíèÿ.
//-Èçìåíåíèå ðàçìåðîâ ìàññèâà ïðè äîáàâëåíèè è óäàëåíèè çàïèñåé;
//-Ïîèñê ïî ôàìèëèè è èìåíè;
//-Ðåäàêòèðîâàíèå çàïèñè.

struct Man
{
	char surname[30];
	char name[30];
	char age[30];
	char date1[30];
	char date2[30];
	char date3[30];
};

void filling()
{
	ifstream fin("text.txt");
	ofstream fout1("text1.txt");
	ofstream fout("text.txt");
	char array[100];
	for (int i = 0; i < 10; i++)
	{
		cin.getline(array, 100);
		fout << array << endl;
	}
	while (fin >> array)
	{
		if (strlen(array) >= 10)
			fout1 << array << " ";
	}
}

void imput(Man *arr, int N)
{
	cin.ignore();
	cout << "Ââåäèòå äàííûå" << endl;
	for (int i = 0; i < N; i++)
	{
		cin.ignore();
		cout << "Ôàìèëèÿ: ";
		cin.getline(arr[i].surname, 30);

		cout << "Èìÿ: ";
		cin.getline(arr[i].name, 30);

		cout << "Âîçðàñò: ";
		cin.getline(arr[i].age, 30);

		cout << "Äàòà ðîæäåíèÿ: ";
		cin >> arr[i].date1 >> arr[i].date2 >> arr[i].date3;
		cin.ignore();
	}
}

void output(Man *arr, int N)
{
	ifstream fin("text.txt");
	ofstream fout1("text1.txt");
	ofstream fout("text.txt");
	for (int i = 0; i < N; i++)
	{
		fout << "Ôàìèëèÿ: " << arr[i].surname << " ";
		cout << endl;
		fout << "Èìÿ: " << arr[i].name << " ";
		cout << endl;
		fout << "Âîçðàñò: " << arr[i].age << " ";
		cout << endl;
		fout << "Äàòà ðîæäåíèÿ: " << arr[0].date1 << "." << arr[1].date2 << "." << arr[2].date3 << " ";
		cout << endl;

		cout << "Ôàìèëèÿ: " << arr[i].surname << " ";
		cout << endl;
		cout << "Èìÿ: " << arr[i].name << " ";
		cout << endl;
		cout << "Âîçðàñò: " << arr[i].age << " ";
		cout << endl;
		cout << "Äàòà ðîæäåíèÿ: " << arr[0].date1 << "." << arr[1].date2 << "." << arr[2].date3 << " ";
	}
}

void poisk(Man *arr, int N)
{
	char A[50];
	cin.getline(A, 50);
	for (int i = 0; i < N; i++)
	{
		if (arr[i].surname == A)
		{
			output(arr, N);

		}
	}
}

void mySort(Man *arr, int N)
{
	for (size_t i = 0; i < N - 1; i++)
	{
		for (size_t j = N - 1; j > i; j--)
			if (arr[j].surname < arr[i].surname)
			{
				Man tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}
}



int main()
{
	setlocale(LC_ALL, "");
	ifstream fin("text.txt");
	ofstream fout("text.txt");
	int N;
	cout << "Ââåäèòå ðàìåð ìàññèâà: ";
	cin >> N;
	Man *arr = new Man[N];
	imput(arr, N);
	mySort(arr, N);
	output(arr, N);
	poisk(arr, N);

	system("pause");
}