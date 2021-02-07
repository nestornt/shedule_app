#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Agenda
{
    public:

        std::vector<std::string> usuarios;
        std::vector<std::string> viajes;

        // variables para generar un id
        std::string id = "_01_01_18";
        int id_cont = 0;

        // variables para tomar decisiones
        bool repetir = true;
        bool alta;
        bool usr_eliminado;
        bool usr_registrado;

        // Para redimensionar el vector la primera vez
        bool vect_usuarios_init = false;
        bool vect_viajes_init = false;

        // Variables con el numero de lineas por usuario o viaje
        int n_campos_usuario = 4;
        int n_campos_viajes = 6;
        int n_usuarios;
        int n_viajes;

        // Numero de iteraciones o datos introducidos en los vectores para no sobreescribir lo anterior
        int usuarios_it = 0;
        int viajes_it = 0;

        const int DNI = 9;


    void iniciarVectorUsuarios()
    {
        usuarios.resize(n_campos_usuario * n_usuarios, "0");
    }

    void iniciarVectorViajes()
    {
        viajes.resize(n_campos_viajes * n_viajes, "0");
    }

    std::string getID()
    {
        id_cont++;
        std::string id_num = std::to_string(id_cont);
        id = "_" + id_num + id;
        return id;
    }

    void menu()
    {
        while(repetir == true)
        {
            int valor = 0;

            std::cout << "\n*****MENU PRINCIPAL*****\n\n";
            std::cout << "1 - Dar de alta a un usuario\n";
            std::cout << "2 - Dar de baja a un usuario\n";
            std::cout << "3 - Dar de alta un viaje\n";
            std::cout << "4 - Listar datos agencia\n";
            std::cout << "5 - Salir del programa\n\n";
            std::cin >> valor;

            switch(valor)
            {
            case 1:
                nuevoUsuario();
                break;
            case 2:
                borrarUsuario();
                break;
            case 3:
                nuevoViaje();
                break;
            case 4:
                listarDatos();
                break;
            case 5:
                repetir = false;
                break;
            default:
                std::cout << "Introduce un numero entre el 1 y el 5\n";
                break;
            }
        }  
    }

    void nuevoUsuario()
    {
        std::cout << "\n\n***Dar de alta a un usuario***\n\n";
        std::cout << "Introduce el numero de usuarios que quiere registrar\n";
        std::cin >> n_usuarios;
        std::cout << "\n";

        std::string dato1;
        std::string dato2;
        std::string dato3;
        std::string dato4;

        // Inicializar el vector para optimizarlo con el tamaño n_usuarios * n_campos que tiene un usuario
        if(vect_usuarios_init == false)
        {
            iniciarVectorUsuarios();
            vect_usuarios_init = true;
        }

        // Metemos todos los usuarios en el vector de usuarios
        for (int i = 0; i < n_usuarios; i++)
        {
            std::cout << "Registro del usuario " << i+1 << "\n";
            std::cout << "\nIntroduce el DNI\n";
            std::cin >> dato1;
            while(dato1.length() != 9)
            {
                std::cout << "Error, vuelva a introducir el DNI de nuevo\n";
                std::cin >> dato1;
            }
            usuarios[usuarios_it] = dato1;
            usuarios_it++;

            std::cout << "\nCual es el nombre?\n";
            std::cin >> dato2;
            usuarios[usuarios_it] = dato2;
            usuarios_it++;

            std::cout << "\nCuales son los apellidos?\n";
            std::cin >> dato3;
            usuarios[usuarios_it] = dato3;
            usuarios_it++;

            std::cout << "\nIntroduce el domicilio\n";
            std::cin >> dato4;
            usuarios[usuarios_it] = dato4;
            usuarios_it++;
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            std::cout << usuarios[i] << "\n";
        }
          
    }

    void nuevoViaje()
    {
        std::cout << "\n\n***Dar de alta un nuevo viaje***\n\n";
        std::cout << "Introduce el numero de viajes que quiere registrar\n";
        std::cin >> n_viajes;
        std::cout << "\n";

        std::string dato1;
        std::string dato2;
        std::string dato3;
        std::string dato4;
        std::string dato5;
        std::string dato6;

        // Inicializar el vector para optimizarlo con el tamaño n_usuarios * n_campos que tiene un viaje
        if(vect_viajes_init == false)
        {
            iniciarVectorViajes();
            vect_viajes_init = true;
        }

        // Metemos todos los viajes en el vector de viajes
        for (int i = 0; i < n_viajes; i++)
        {
            std::cout << "Registro del viaje" << i+1 << "\n";
            std::cout << "\nIntroduce el DNI\n";
            std::cin >> dato1;

            for (int j = 0; j < usuarios.size(); j++)
            {
                if(dato1 == usuarios[j])
                    this->usr_registrado = true; 
            }
            
            if(usr_registrado == true)
            {
                viajes[viajes_it] = dato1 + getID();
                viajes_it++;

                std::cout << "\nCual es la fecha de registro?\n";
                std::cin >> dato2;
                viajes[viajes_it] = dato2;
                viajes_it++;

                std::cout << "\nCual la ciudad destino?\n";
                std::cin >> dato3;
                viajes[viajes_it] = dato3;
                viajes_it++;

                std::cout << "\nIntroduce el nombre del hotel para el alojamiento\n";
                std::cin >> dato4;
                viajes[viajes_it] = dato4;
                viajes_it++;
                
                std::cout << "\nIntroduce el numero de noches y el precio del mismo\n";
                std::cin >> dato5;
                viajes[viajes_it] = dato5;
                viajes_it++;

                std::cout << "\nCual es el vuelo y el precio?\n";
                std::cin >> dato6;
                viajes[viajes_it] = dato6;
                viajes_it++;
            }
            else
            {
                std::cout << "El dni proporcionado no coincide con el de ningun usuario registrado en el sistema, vuelva a intentarlo\n";
                return;
            } 
        }

        for (int i = 0; i < viajes.size(); i++)
        {
            std::cout << viajes[i] << "\n";
        }
    }

    void borrarUsuario()
    {
        std::cout << "\n\n***Dar de baja a un usuario***\n\n";
        std::cout << "Introduce el numero de usuarios que quiere eliminar\n";
        std::cin >> n_usuarios;
        std::cout << "\n";

        std::string dni;

        if(usuarios[0] == "0")
        {
            std::cout << "No hay usuarios en el sistema\n";
            return;
        }

        for (int i = 0; i < n_usuarios; i++)
        {
            std::cout << "\nUsuario " << i+1 << "\n";
            std::cout << "\nIntroduzca el dni del usuario que quiere eliminar\n";
            std::cin >> dni;
            
            for (int j = 0; j < usuarios.size(); j++)
            {
                if(dni == usuarios[j])
                {
                    usuarios.erase(usuarios.begin()+j, usuarios.begin()+j+4);
                    this->usr_eliminado = true;
                }    
            }
            
            if(usr_eliminado == true)
                std::cout << "\nUsuario eliminado con exito!\n";

            for (int k = 0; k < usuarios.size(); k++)
            {
                std::cout << usuarios[k] << "\n";
            }
        }
    }

    void listarDatos()
    {
        int usr_cont = 1;
        std::cout << "\n\n[LISTADO DE USUARIOS]\n";
        std::cout << "\n\n[USUARIO " << usr_cont << "]\n";

        for (int i = 0, j = 0; i < usuarios.size(); i++, j++)
        {
            std::cout << usuarios[i] << "\n";

            if(j == n_campos_usuario - 1 && usr_cont < n_usuarios)
            {
                usr_cont++;
                std::cout << "\n\n[USUARIO " << usr_cont << "]\n";
                j = -1;
            }
        }

        int viajes_cont = 1;
        std::cout << "\n\n[LISTADO DE VIAJES]\n";
        std::cout << "\n\n[VIAJE " << viajes_cont << "]\n";

        for (size_t i = 0, j = 0; i < viajes.size(); i++, j++)
        {
            std::cout << viajes[i] << "\n";

            if(j == n_campos_viajes - 1 && viajes_cont < n_viajes)
            {
                viajes_cont++;
                std::cout << "\n\n[VIAJE " << viajes_cont << "]\n";
                j = -1;
            }
        }
    }
};

int main()
{
    Agenda agenda;
    agenda.menu();
}