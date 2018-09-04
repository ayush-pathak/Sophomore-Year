#include<iostream>
#include<string>
using namespace std;
class Date{
private:
  int month,day,year;
public:
  Date(int m = 1,int d = 1, int y = 2000): month(m),day(d),year(y){} 
  void setMonth(int val){month=val;}  // Function to change the month
  void setDay(int val){day=val;}      // Function to change the day
  void setYear(int val){year = val;}  // Function to change the year
  void showDate1(){
	cout<<month<<"/"<<day<<"/"<<year<<endl;   //Outputs date in the form MM/DD/YYYY
  }
  void showDate2(){
	string monthName[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	cout<<day<<" "<<monthName[month-1]<<" "<<year<<endl;  //Outputs date in the form DATE MONTH YEAR
  }
  void showDate3(){
	string monthName[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	cout<<monthName[month-1]<<" "<<day<<","<<" "<<year<<endl; //Outputs date in the form MONTH DAY, YEAR
  }

};

int main(){
Date test1;
cout<<"Default with no input"<<endl;
test1.showDate1();
test1.showDate2();
test1.showDate3();
cout<<endl;

Date test2(1,25,2018);
cout<<"With Inputs"<<endl;
test2.showDate1();
test2.showDate2();
test2.showDate3();
cout<<endl;

cout<<"Mutators"<<endl;
cout<<endl;

Date test3(1,30,2018);
cout<<"Change the Month"<<endl;
test3.showDate1();
test3.setMonth(3);
cout<<endl;
test3.showDate1();
cout<<endl;

Date test4(2,25,2018);
cout<<"Change the Day"<<endl;
test4.showDate2();
test4.setDay(28);
cout<<endl;
test4.showDate2();
cout<<endl;

Date test5(3,15,2018);
cout<<"Change the Year"<<endl;
test5.showDate3();
test5.setYear(2020);
cout<<endl;
test5.showDate3();
cout<<endl;
}
