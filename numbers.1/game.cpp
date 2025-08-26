#include <iostream>
#include <windows.h>
#include<time.h>
using namespace std;

int main()
{
   
    srand (unsigned (time(NULL)));
    int a,b,i;
    a=rand()%10+1;
    cout<<"Игра \"Угадай число\".\n\n";
    cout<<"Компьютер \"задумал\" число от 1 до 10.\n";
    cout<<"Введите число и нажмите <Enter>\n\n";
    for(i=1;i<6;i++)
    {
        cout<<"--->";
        cin>>b;
        if(b==a)
        {
            cout<<"Вы выиграли! Поздравляю!\n";
            cout<<"Вы отгадали число с "<<i<<"-ой попытки!\n";
            break;
        }
        if(b>a)
        {
            cout<<"Нет, введённое Вами число, меньше \"задуманного\" компьютером\n";
        }
        if(b<a)
        {
            cout<<"Нет, введённое Вами число, больше \"задуманного\" компьютером\n";
        }
    }
    if(b!=a&&i==5)
    {
        cout<<"К сожалению Вы так и не смогли угадать число...\n";
    }

}
