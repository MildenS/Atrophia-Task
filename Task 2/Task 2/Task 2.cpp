#include <iostream>
#include<tchar.h>

//ф-ция для 1 задачи
double Quadratic(int A, int B, int C);

//ф-ция для второй задачи
TCHAR* GetNewString(TCHAR* Str, bool& IsEqual);

int main()
{
    /* Тест функции из первого задания
    int A, B, C;
    std::cin >> A >> B >> C;
    std::cout << Quadratic(A, B, C);
    */   



    /* Тест функции из второго задания
    TCHAR Str[]=_T("b");
    bool IsEqual;
    TCHAR* NewStr = GetNewString(Str, IsEqual);
    std::cout << IsEqual;   
    */
}

double Quadratic(int A, int B, int C)
{
    double Discriminant = B * B - 4 * A * C;
    if (Discriminant < 0)
        return 0;
    else if (Discriminant > 0)
    {
        double X1 = (-B + sqrt(Discriminant)) / (2 * A);
        double X2 = (-B - sqrt(Discriminant)) / (2 * A);
        return (X1 > X2) ? X1 : X2;
    }
    else
        return 2*((double)(- B) / (A * 2));
}

TCHAR* GetNewString(TCHAR* Str, bool& IsEqual)
{
    size_t Length = _tcslen(Str);
    TCHAR* Answer=new TCHAR[Length];
    _tcscpy(Answer, Str);
    TCHAR last = Answer[Length - 1];
    for (size_t i = Length-1; i>0; i--)
        Answer[i] = Answer[i - 1];
    Answer[0] = last;
    if (_tcscmp(Answer, Str)==0)
        IsEqual = true;
    else
        IsEqual = false;
    return Answer;
}
