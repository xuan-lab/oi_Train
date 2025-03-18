#include<iostream>
using namespace std;
int mouth_day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
//2000.1.1 --2020.10.1
int runround=0;
int year=2000,mouth=1,day=1,week=6;
bool isLeapYear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}
int main()
{
    for(;;day++)
    {
        if(week == 1 ||day==1)
        {
            runround++;
        }
        runround++;
        week++;
        if(week == 7)
        {
            week =1;
        }

        if(day>=mouth_day[mouth])
        {
            mouth++;
            day = 1;
        }
        if(mouth>=12){
            year++;
            mouth =1;
            if(isLeapYear(year))
            {
                mouth_day[2]=29;
            }
            else{
                mouth_day[2]=28;
            }
        }
        if(year==2020&&mouth==10)
        {
            break;
        }

    }
    cout<<runround;
    return 0;

}