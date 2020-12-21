#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

struct StElem
{
    StElem* link;
    string prizv;
    double averageMark;
    int stipend;
};

void CreateList(StElem*& first, StElem*& last, int N);
void AddElem(StElem*& first, StElem*& last, string prizv, double averageMark, int stipend);
void Print(StElem* first, int i);
void Find(StElem* first, int i, double x);
void DeleteBegElem(StElem*& first, StElem*& last);
void DeleteElem(StElem*& first, StElem*& last);
void Scanning(StElem* first, StElem* last);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    StElem* first = NULL,
        * last = NULL;

    int N;
    double x;
    cout << "Введіть к-сть студентів у списку: "; cin >> N;
    cout << endl;
    CreateList(first, last, N);
    cout << endl;
    for (int i = 0; i < 3; i++)
        Print(first, i);
    cout << endl;
    cout << "Пошук студентів за середнім балом" << endl << endl;
    cout << "Вкажіть середній бал: "; cin >> x;
    cout << endl;
    for (int i = 0; i < 3; i++)
        Find(first, i, x);
    cout << endl;
    cout << "Вилучення із списку студентів, що не мають стипендії..." << endl << endl;
    Scanning(first, last);
    for (int i = 0; i < 3; i++)
        Print(first, i);
    cout << endl;
    return 0;
}

void CreateList(StElem*& first, StElem*& last, int N)
{
    string prizv;
    double averageMark;
    int stipend;
    for (int i = 0; i < N; i++)
    {
        cin.sync();
        cout << "Введіть прізвище: "; cin >> prizv;
        cout << "Введіть середній бал: "; cin >> averageMark;
        {
            cout << "Введіть стипендію у грн: "; cin >> stipend;
        } while (stipend < 0);
        AddElem(first, last, prizv, averageMark, stipend);
        cout << endl << endl;
    }
}

void AddElem(StElem*& first, StElem*& last, string prizv, double averageMark, int stipend)
{
    StElem* tmp = new StElem;
    tmp->prizv = prizv;
    tmp->averageMark = averageMark;
    tmp->stipend = stipend;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void Print(StElem* first, int i)
{
    while (first != NULL)
    {
        if (i == 0)
            cout << "| " << setw(8) << left << first->prizv << " ";
        else if (i == 1)
            cout << "| " << setw(8) << left << first->averageMark << " ";
        else
            cout << "| " << setw(8) << left << first->stipend << " ";

        first = first->link;
    }
    cout << "|" << endl;
}

void Find(StElem* first, int i, double x)
{
    while (first != NULL)
    {
        if (first->averageMark == x)
        {
            if (i == 0)
                cout << "| " << setw(8) << left << first->prizv << " ";
            else if (i == 1)
                cout << "| " << setw(8) << left << first->averageMark << " ";
            else
                cout << "| " << setw(8) << left << first->stipend << " ";
        }
        first = first->link;
    }
    cout << "|" << endl;
}

void DeleteBegElem(StElem*& first, StElem*& last)
{
    StElem* tmp = first->link;
    delete first;
    first = tmp;
}

void DeleteElem(StElem*& first, StElem*& last)
{
    StElem* tmp = first->link->link;
    delete first->link;
    first->link = tmp;
}

void Scanning(StElem* first, StElem* last)
{
    while (first != NULL && first->stipend == 0)
        DeleteBegElem(first, last);
    while (first != NULL && first->link != NULL)
    {
        if (first->link->stipend == 0)
            DeleteElem(first, last);
        else
            first = first->link;
    }
}