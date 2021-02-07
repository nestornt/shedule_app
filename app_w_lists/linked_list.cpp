#include "linked_list.h"
#include <regex>

singly_linked_list::singly_linked_list()
{
  this->length = 0;
  this->head = NULL;
}

singly_linked_list::~singly_linked_list()
{
  cout << "Este objeto ha sido borrado"  << "\n";
}

void singly_linked_list::add_particularposition(int pos,std::string dni, std::string name, std::string address)
{
  node *pre = new node();
  node *cur = new node();
  node *temp = new node();
  
  if(pos==0)
  {
    temp->dni = dni;
    temp->name = name;
    temp->address = address;
    temp->next = this->head;
    this->head = temp;
  }
  else
  {
    cur=this->head;
    for (int i = 0; i < pos ; i++)
    {
      pre = cur;
      cur = cur->next;
    }
  
    temp->dni = dni;
    temp->name = name;
    temp->address = address;
    temp->next = cur;
    pre->next = temp;
  }
  this->length++;
}

void singly_linked_list::add_first(std::string dni, std::string name, std::string address)
{
  add_particularposition(0, dni, name, address);
}

void singly_linked_list::add_last(std::string dni, std::string name, std::string address)
{
  add_particularposition(this->length, dni, name, address);
}

void singly_linked_list::add_travel(std::string dni, std::string data, std::string city, std::string hotel, std::string price)
{
  bool user_added = false;
  std::string formated_data;
  std::string id;
  node *pre = new node();
  node *cur = new node();
  cur = this->head;

  for (int i = 0; i < this->length; i++)
  {
    pre = cur;
    cur = cur->next; 
    //std::cout << "dni: " <<  pre->dni << "\n";
    if(pre->dni == dni)
    {
      pre->data = data;
      pre->city = city;
      pre->hotel = hotel;
      pre->price = price;

      std::string formated_data = std::regex_replace(pre->data, std::regex("/"), "_");
      pre->id_reg = dni + "_" + formated_data;
      id = pre->id_reg;
      user_added = true;
    }
  }

  if(user_added)
    std::cout << "\n\nEl viaje ha sido dado de alta con exito!!\nEl identificador asignado al viaje es " << id << "\n";
  else
    std::cout << "\n\nEl DNI proporcionado no hace referencia a ningun usuario registrado.\n";
}

void singly_linked_list::delete_bydni(std::string dni)
{
  node *pre = new node();
  node *cur = new node();

  cur = this->head;

  if(cur->dni == dni)
  {
    pre = this->head;
    head = head->next;
    this->length--;
    std::cout << "\n\nEl usuario con el nombre: " << cur->name << " ha sido eliminado.\n\n";
  }

  for (int i = 0; i < this->length; i++)
  {
    pre = cur;
    cur = cur->next; 

    if(cur->dni == dni)
    {
      pre->next = cur->next;
      this->length--;
      std::cout << "\n\nEl usuario con el nombre: " << cur->name << " ha sido eliminado.\n\n";
    }
  }
}

void singly_linked_list::delete_travel(std::string dni, std::string id)
{
  bool deleted_travel = false;
  node *pre = new node();
  node *cur = new node();

  cur = this->head;

  if(cur->dni == dni && cur->id_reg == id)
  {
    cur->data.clear();
    cur->city.clear();
    cur->hotel.clear();
    cur->price.clear();
    cur->id_reg.clear();
    deleted_travel = true;
    return;
  }

  //std::cout << "lenght = " << this->length << std::endl;

  for (int i = 0; i < this->length-1; i++)
  {
    pre = cur;
    cur = cur->next; 

    if(cur->dni == dni && cur->id_reg == id)
    {
      cur->data.clear();
      cur->city.clear();
      cur->hotel.clear();
      cur->price.clear();
      cur->id_reg.clear();
      deleted_travel = true;
      std::cout << "\nEl viaje ha sido eliminado.\n";
      return;
    }
  }
 
  std::cout << "No se ha encontrado el dni o identificador proporcionados, vuelva a intentarlo.\n";
}

void singly_linked_list::delete_particularposition(int pos)
{
  node *pre = new node();
  node *cur = new node();
  cur = this->head;

  if(pos == 0)
  {
    pre = this->head;
    head = head->next;
  }
  else
  {
    for (int i = 0; i < pos; i++)
    {
      pre = cur; // pre = head
      cur = cur->next; // cur = siguiente nodo
    }
    pre->next = cur->next;
  }
  this->length--;
}

void singly_linked_list::delete_first()
{
  delete_particularposition(0);
}

void singly_linked_list::delete_last()
{
  delete_particularposition(this->length-1);
}

void singly_linked_list::display_particularposition(int n)
{
  node *new_node = this->head;
  cout << "\n****** AGENCIA DE VIAJES *******\n\n";
  for (int i = 0; i < n; i++) 
    new_node = new_node->next;
  cout << n << "\n";
  cout << new_node->dni << "\n";
  cout << new_node->name << "\n";
  cout << new_node->address << "\n";
  cout << new_node->data << "\n";
  cout << new_node->city << "\n";
  cout << new_node->hotel << "\n";
  cout << new_node->price << "\n";
}

void singly_linked_list::display_first()
{
  display_particularposition(0);
}

void singly_linked_list::display_last()
{
  display_particularposition(this->length-1);
}

void singly_linked_list::display_all()
{
  cout << "\n\n****** AGENCIA DE VIAJES *******\n\n";
  node *new_node = this->head;
  int i = 1;
  while(new_node)
  {
    auto data = new_node->data;
    cout << "\nContacto " << i <<":\n";
    cout << "\n[INFORMACION DE CONTACTO]\n\n";
    cout << "DNI: " << new_node->dni << "\n";
    cout << "Nombre: " << new_node->name << "\n";
    cout << "Direccion: " << new_node->address << "\n";

    if(data.length() > 0)
    {
      cout << "\n[INFORMACION DE VIAJES]\n\n";
      cout << "Datos: "<< new_node->data << "\n";
      cout << "Ciudad: "<< new_node->city << "\n";
      cout << "Hotel: "<< new_node->hotel << "\n";
      cout << "Info: "<< new_node->price << "\n";
    }

    new_node = new_node->next;
    i++;
  }
}


int main(int argc, char *argv[])
{
  singly_linked_list *sll = new singly_linked_list();

  // Añade 4 contactos
  sll->add_first("12312312G", "Sandra", "C/ Madrid");
  sll->add_first("78643098D", "Mary", "C/ Alacant");
  sll->add_first("12345678F", "Pepe", "C/ Caceres");
  sll->add_first("87980874F", "Antoine", "C/ Paris");
  // Imprime todos los contactos almacenados
  sll->display_all();
  // Borra un contacto mediante el dni
  sll->delete_bydni("87980874F");
  sll->display_all();
  // Añade un viaje proporcinando el dni de un usuario existente
  sll->add_travel("78643098D", "1/10/2010", "Barcelona", "Hotel H", "500");
  sll->display_all();
  // Borra un viaje de un contacto mediante el dni y el id proporcionado al registrarse
  sll->delete_travel("78643098D", "78643098D_1_10_2010");
  sll->display_all();
  
  return 0;
}