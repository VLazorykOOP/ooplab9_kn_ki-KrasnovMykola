#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class FitnessCenterRecord
{
private:
   int number;
   int year;
   int month;
   int hours;
public:
  FitnessCenterRecord() : number(0), year(0), month(0), hours(0) {}
  FitnessCenterRecord(int number, int year, int month, int hours)
  : number(number), year(year), month(month), hours(hours) {}
  
  int get_number()
  {
    return number;
  }
  int get_year()
  {
    return year;
  }
  int get_month()
  {
    return month;
  }
  int get_hours()
  {
    return hours;
  }
  void set_number(int number)
  {
    this->number = number;
  }
  void set_year(int year)
  {
    this->year = year;
  }
  void set_month(int month)
  {
    this->month = month;
  }
  void set_hours(int hours)
  {
    this->hours = hours;
  }
  
  friend istream& operator>>(istream& in, FitnessCenterRecord& record)
  {
    in >> record.number >> record.year >> record.month >> record.hours;
    return in;
  }
};

int main()
{
  vector<FitnessCenterRecord> records;
  ifstream in("text.txt");
  while (!in.eof())
  {
    FitnessCenterRecord record;
    in >> record;
    records.push_back(record);
  }
  auto item = min_element(records.rbegin(), records.rend(),
    [&](FitnessCenterRecord a, FitnessCenterRecord b) { return a.get_hours() < b.get_hours(); });
  cout << item->get_hours() << " " << item->get_year() << " " << item->get_month() << " " << endl;
 return 0;
}