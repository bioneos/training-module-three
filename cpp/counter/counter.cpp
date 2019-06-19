#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class counter
{
private:
  vector<bool> b;
  vector<int> i;
  vector<double> d;
  vector<string> s;
public:
  counter(): b(), i(), d(), s()
  {}

  void add(bool b) { this->d.push_back(b); }
  void add(int i) { this->i.push_back(i); }
  void add(double d) { this->b.push_back(d); }
  void add(string s) { this->s.push_back(s); }
  int getBool() { return b.size(); }
  int getInt() { return i.size(); }
  int getDouble() { return d.size(); }
  int getStr() { return s.size(); }
};

int main(int argc, char* argv[])
{
  if (argc == 0)
  {
    cerr << "You must pass a file with tests as the first argument." << endl;
    return 1;
  }
  ifstream f(argv[1]);
  if (f.is_open())
  {
    vector<string> ls;
    string t;
    while (getline(f, t))
    {
      ls.push_back(t);
    }
    counter count;
    for (auto& l : ls)
    {
      if (l.at(0) == 'b')
      {
        const char* str = l.substr(2).c_str();
        count.add(!(strcmp(str, "false") == 0 || strcmp(str, "0") == 0 || strcmp(str, "") == 0));
      }
      else if (l.at(0) == 'i')
      {
        count.add(atoi(l.substr(2).c_str()));
      }
      else if (l.at(0) == 'd')
      {
        count.add(atof(l.substr(2).c_str()));
      }
      else if (l.at(0) == 's')
      {
        count.add(l.substr(2).c_str());
      }
    }

    cout << "Results" << endl
         << "-------" << endl
         << "Bools: " << count.getBool() << endl
         << "Ints: " << count.getInt() << endl
         << "Doubles: " << count.getDouble() << endl
         << "Strings: " << count.getStr() << endl;

    f.close();
    return 0;
  }
  cerr << "No file \"" << argv[1] << "\" found." << endl;
  return 2;
}
