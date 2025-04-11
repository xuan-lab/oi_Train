#include<iostream>
using namespace std;

int mouth_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int runround = 0;
int year = 2000, mouth = 1, day = 1, week = 6; // 2000.1.1 is Saturday (week = 6)

bool isLeapYear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}

int main() {
    // Set February days for the initial year
    if (isLeapYear(year)) {
        mouth_day[2] = 29;
    } else {
        mouth_day[2] = 28;
    }

    while (true) {
        // Calculate running distance for today
        if (week == 1 || day == 1) {
            runround += 2; // Monday or 1st day of month: run 2km
        } else {
            runround += 1; // Normal day: run 1km
        }
        
        // Move to the next day
        day++;
        week = week % 7 + 1; // Week cycles from 1-7 (1=Monday, 7=Sunday)
        
        // Check if we need to move to next month
        if (day > mouth_day[mouth]) {
            day = 1;
            mouth++;
            
            // Check if we need to move to next year
            if (mouth > 12) {
                mouth = 1;
                year++;
                
                // Update February days for the new year
                if (isLeapYear(year)) {
                    mouth_day[2] = 29;
                } else {
                    mouth_day[2] = 28;
                }
            }
        }
        
        if (year == 2020 && mouth == 10 && day > 1) {
            break;
        }
    }
    
    cout << runround;
    return 0;
}