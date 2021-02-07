#include <iostream>

using namespace std;

class node
{
public:
  string dni;
  string name;
  string address;
  string data;
  string city;
  string hotel; 
  string price;
  string id_reg;
  node *next;
};

class singly_linked_list
{
private:
  node *head;
public:
  int length;
  singly_linked_list();
  ~singly_linked_list();

  void add_first(string, string, string);
  void add_last(string, string, string);
  void add_particularposition(int, string, string, string);
  void add_travel(string, string, string, string, string);
  void delete_first();
  void delete_last();
  void delete_particularposition(int);
  void delete_bydni(string);
  void delete_travel(string, string);
  void display_all();
  void display_first();
  void display_last();
  void display_particularposition(int); 
};