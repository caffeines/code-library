#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* Leap Year Between two dates*/
struct date{
    string month,ch;
    int day,year;
    void read(){
        cin>>month>>day>>ch>>year; /// January 12, 2018
    }
};

bool isLeapYear ( int n ) {
    return ( n % 400 == 0 || ( n % 4 == 0 && n % 100 != 0 ) );
}

int leap_year_between2dates(date d1, date d2){
    int ans = (d2.year/4 - d2.year/100 + d2.year/400) - (d1.year/4 - d1.year/100 + d1.year/400);

    if(isLeapYear(d1.year)){
        if(d1.month == "February" || d1.month == "January") ans++;
    }
    if(isLeapYear(d2.year)){
            if((d2.month == "February" && d2.day < 29) || (d2.month == "January" )) ans--;
    }
    return ans;
}

int main()
{
    /* Leap Year Between two dates*/
    date d1,d2;
    d1.read();
    d2.read();
    cout<<leap_year_between2dates(d1,d2);


    return 0;
}


