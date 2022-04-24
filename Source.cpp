/*Adam Benoit
  CS-210
  chada clock*/
#include <iostream>
using namespace std;


// creates our class for time variables
class Time
{
public:
	int hour;
	int minute;
	int second;
	virtual void addOneHour() = 0;
	virtual void addOneMinute() = 0;
	virtual void addOneSecond() = 0;
};

// creates our 12 hour clock class inherits the Time class
class _12HourTime : public Time
{
	// methods
public: _12HourTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;

}

	  void addOneHour()
	  {
		  if (hour == 12) {
			  hour = 1;

		  }
		  else {
			  hour += 1;
		  }
	  }

	  void addOneMinute()
	  {
		  if (minute == 59) {
			  minute = 0;
			  addOneHour();
		  }
		  else {
			  minute += 1;
		  }
	  }

	  void addOneSecond()
	  {
		  if (second == 59) {
			  second = 0;
			  addOneMinute();
		  }
		  else {
			  second += 1;
		  }
	  }

};

// creates our class for 24 hour clock which inherits the Time class
class _24HourTime : public Time
{
	//methods
public: _24HourTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}
	  // sets limit upper limit of clock and loops it back to 0
	  void addOneHour()
	  {
		  if (hour == 23)
		  {
			  hour = 0;
		  }
		  else {
			  hour += 1;
		  }
	  }

	  void addOneMinute()
	  {
		  if (minute == 59) {
			  minute = 0;
			  addOneHour();
		  }
		  else {
			  minute += 1;
		  }
	  }

	  void addOneSecond()
	  {
		  if (second == 59) {
			  second = 0;
			  addOneMinute();
		  }
		  else {
			  second += 1;
		  }
	  }

	  
	  friend void displayTime(const _12HourTime&, const _24HourTime&);
};

void displayTime(const _12HourTime& time12, const _24HourTime& time24)
{
	// prints clocks to screen
	cout << "***********************   ***********************" << endl;
	cout << "*    12-Hour Clock    *   *    24-Hour Clock    *" << endl;
	cout << "*    ";
	// for single digit numbers adds a 0 in front
	if (time12.hour < 10)
		cout << "0";
	cout << time12.hour << ":";
	if (time12.minute < 10)
		cout << "0";
	cout << time12.minute << ":";
	if (time12.second < 10)
		cout << "0";
	cout << time12.second;
	// sets am and pm for 12 hour clock
	if (time24.hour < 12)
		cout << " AM";
	else
		cout << " PM";
	cout << "      *   *      ";
	if (time24.hour < 10)
		cout << "0";
	cout << time24.hour << ":";
	if (time24.minute < 10)
		cout << "0";
	cout << time24.minute << ":";
	if (time24.second < 10)
		cout << "0";
	cout << time24.second;
	cout << "      *\n";
	cout << "***********************   ***********************" << endl;
}

int main() {
	// set intial time of clocks
	_12HourTime time_12_Clock(11, 59, 59);
	_24HourTime time_24_Clock(23, 59, 59);
	displayTime(time_12_Clock, time_24_Clock);
	// displays menus
	while (true)
	{
		cout << "***************************\n";
		cout << "* 1 - Add One Hour        *\n";
		cout << "* 2 - Add One Minute      *\n";
		cout << "* 3 - Add One Second      *\n";
		cout << "* 4 - Exit Program        *\n";
		cout << "***************************\n";
		int choice;
		// gets user input
		cin >> choice;
		switch (choice)
		{
		// adds an hour
		case 1:
			time_12_Clock.addOneHour();
			time_24_Clock.addOneHour();
			displayTime(time_12_Clock, time_24_Clock);
			break;
		// adds a minute
		case 2:
			time_12_Clock.addOneMinute();
			time_24_Clock.addOneMinute();
			displayTime(time_12_Clock, time_24_Clock);
			break;
		// adds a second
		case 3:
			time_12_Clock.addOneSecond();
			time_24_Clock.addOneSecond();
			displayTime(time_12_Clock, time_24_Clock);
			break;
		// exits program
		case 4:
			cout << "Thank You!";
			exit(1);
			break;
		// allows for incorrect input to not crash program
		default:
			cout << "Invalid option.\n";
			break;
		}
	}
}