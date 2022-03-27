#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h> // забезпечення відображення кирилиці

using namespace std;

enum Specialty { ІТ, КН, ПЗ, ВП, СА };

string strSpecialty[] = { "ІТ","КН","ПЗ","ВП","СА" };

struct Student
{
	string prizv;
	Specialty specialty;
	short kurs;
	short physics;
	short math;
	short informatics;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
string WorstAverage(Student* s, const int N);
double lessfour(Student* s, const int N);

int main()
{                             // забезпечення відображення кирилиці
	SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу


	int N;
	cout << "Введіть кількість студентів: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);

	cout << "| Кількість студентів, середній бал яких менше 4 " << char(34) << ": " << fixed << setw(6) << setprecision(2) << lessfour(s, N) << setw(23) << "|" << endl;
	cout << "| Предмет, середній бал якого найменший: " << fixed << setprecision(2) << WorstAverage(s, N) << setw(29) << "   |" << endl;
	cout << "================================================================================" << endl;
	delete[] s;
}

void Create(Student* s, const int N)
{
	int kurs, specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент№ " << i + 1 << ":" << endl;
		cin.get();// очищуємо буфер клавіатури – бо залишаються символи
		cin.sync();// "кінець рядка", які не дають ввести наступний літерний рядок
		cout << "  прізвище: "; getline(cin, s[i].prizv);
		cout << "  курс: "; cin >> s[i].kurs;
		cout << "  спеціальність (0 - КН, 1 - ІТ, 2 - ПЗ, 3 - ВП, 4 - СА): "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "  оцінка з фізики: "; cin >> s[i].physics;
		cout << "  оцінка з математики: "; cin >> s[i].math;
		cout << "  оцінка з інформатики: "; cin >> s[i].informatics;
	}
	cout << endl;

}

void Print(Student* s, const int N)
{
	cout << "================================================================================"
		<< endl;
	cout << "| №  | Прізвище     | Курс | Спеціальність | Фізика | Математика | Інформатика |"
		<< endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
			<< "| " << setw(4) << right << s[i].physics << "   "
			<< "| " << setw(6) << right << s[i].math << "      "
			<< "| " << setw(6) << right << s[i].informatics << "     |" << endl;
	}
	cout << "================================================================================" << endl;
}

string WorstAverage(Student* s, const int N) {
	string worst;
	for (int i = 0; i < N; i++)// прочитали елементи масиву
	{
		double F = (s[i].physics) / N;
		double M = (s[i].math) / N;
		double I = (s[i].informatics) / N;
		if (F < M && F < I)
			worst = "Фізика";
		if (M < F && M < I)
			worst = "Математика";
		if (I < F && I < M)
			worst = "Інформатика";
	}
	return worst;
}


double lessfour(Student* s, const int N)
{
	int k = 0; // кількість елементів, які потрібно залишити
	for (int i = 0; i < N; i++) // скануємо заданий масив і
		if ((s[i].physics + s[i].math + s[i].informatics) / 3 < 4)  
			k++; // які потрібно залишити
	return k;
}
