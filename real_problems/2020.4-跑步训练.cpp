#include<iostream>
using namespace std;
int month_day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//2000.1.1 --2020.10.1
int runround=0;
int year=2000,month=1,day=1,week=6;
bool isLeapYear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}
int main()
{
    if(isLeapYear(2000)) {
        month_day[2] = 29;
    }
    
    while(!(year==2020 && month==10 && day==1))
    {
        if(week == 1 || day==1)
        {
            runround++;
        }
        
        day++;
        week++;
        if(week > 7)
        {
            week = 1;
        }

        if(day > month_day[month])
        {
            month++;
            day = 1;
            
            if(month > 12){
                year++;
                month = 1;
                
                // Update February days for the new year
                if(isLeapYear(year))
                {
                    month_day[2] = 29;
                }
                else{
                    month_day[2] = 28;
                }
            }
        }
    }
    cout<<runround;
    return 0;

}