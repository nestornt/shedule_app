#include <iostream>
#include <fstream>
#include <string>

class Agenda
{
    private:

        std::string cliente[4];
        std::string viajes[6];

    public:

        bool alta = false;
        bool repetir = true;
        std::string identificador = "_1_01_01_18";

    std::string *getClientes()
    {
        return cliente;
    }

    std::string *getViajes()
    {
        return viajes;
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
            std::cout << "4 - Eliminar un viaje\n";
            std::cout << "5 - Guardar estado del programa\n";
            std::cout << "6 - Cargar estado del fichero\n";
            std::cout << "7 - Listar datos agencia\n";
            std::cout << "8 - Salir del programa\n\n";
            std::cin >> valor;

            switch(valor)
            {
            case 1:
                nuevoUsuario();
                listarUsuario();
                if(alta == false) return;
                break;
            case 2:
                borrarCliente();
                break;
            case 3:
                nuevoViaje();
                verificarViaje();
                break;
            case 4:
                borrarViaje();
                break;
            case 5:
                guardarEstado();
                break;
            case 6:
                cargarEstado();
                break;
            case 7:
                listarDatos();
                break;
            case 8:
                repetir = false;
                break;
            default:
                std::cout << "Introduce un numero entre el 1 y el 8\n";
                break;
            }
        }  
    }

    void guardarEstado()
    {
        std::string file;
        std::cout << "El programa va a guardar el estado de la aplicacion.\n\nPor favor, introduzca el nombre y extension del archivo destino\n";
        std::cin >> file;

        if(file == "viajes.txt" || file == "cliente.txt" || file == "dni.txt")
        {
            std::cout << "Por favor, introduzca un nombre de archivo no insertado anteriormente\n";
            return;
        }

        std::fstream fs{ file , std::ios::app };

        std::string *clientes = getClientes();
        std::string *viaje = getViajes();

        for (int i = 0; i < 4; i++)
        {
            fs << clientes[i] << "\n";
        }

        for (int i = 0; i < 6; i++)
        {
            fs << viaje[i] << "\n";
        }

        std::cout << "\nFichero " << file << " guardado con exito!\n";  
    }

    void cargarEstado()
    {
        std::string file;
        std::string datos[10];

        std::cout << "\n\n***Cargar un archivo***\n\n";
        std::cout << "Introduce el nombre del fichero en el que has guardado la informacion de usuario\n";
        std::cin >> file;
        std::cout << "\n";

        // Lee el archivo y lo guarda en un array
        std::fstream fs{ file };
        int cont = 0;

        while(fs)
        {
            std::getline(fs, datos[cont]);
            cont++;
        }
        
        std::string *clientes = getClientes();
        std::string *viaje = getViajes();

        int i = 0;
        int j = 0;

        for (i; i < 10; i++)
        {
            if(i >= 4)
            {
                viaje[j] = datos[i];
                j++;
            }
            else
                clientes[i] = datos[i];     
        }
        std::cout << "Archivo cargado con exito!\n"; 
    }

    void listarDatos()
    {
        if(cliente[0] != "")
        {
            std::cout << "\n\n/****** AGENCIA DE VIAJES *******/\n\n";
            std::cout << "----------------------------------\n";
            std::cout << "Cliente: " << cliente[0] << "\n";
            std::cout << "Nombre: " << cliente[1] << " " << cliente[2] << "\n";
            std::cout << "Calle: " << cliente[3] << "\n";

            std::cout << "     " << "- Viaje: " << viajes[0] << identificador << "\n";
            std::cout << "     " << "- Fecha: " << viajes[1] << "\n";
            std::cout << "     " << "- Lugar: " << viajes[2] << "\n";
            std::cout << "     " << "- Hotel: " << viajes[3] << "\n";
            std::cout << "     " << "- Nº noches y precio alojamiento: " << viajes[4] << "€" << "\n";
            std::cout << "     " << "- Medio de tranporte y precio del vuelo: " << viajes[5] << "€" << "\n";
        }
    }  
    
    void listarUsuario()
    {
        #define DNI 9
        #define NOMBRE 20
        #define APELLIDOS 80
        #define DIRECCION 120

        int dni_lenght = cliente[0].length();
        int nombre_lenght = cliente[1].length();
        int apellidos_lenght = cliente[2].length();
        int direccion_lenght = cliente[3].length();

        if(dni_lenght == DNI && nombre_lenght <= NOMBRE && apellidos_lenght <= APELLIDOS && direccion_lenght <= DIRECCION)
        {
            this->alta = true;
            std::cout << cliente[0] << "\n";
            std::cout << cliente[1] << " " << cliente[2] << "\n";
            std::cout << cliente[3] << "\n";
            std::cout << "\n\nEl usuario ha sido dado de alta con exito!\n";   
        }
        else
        {
            std::cout << "Ha habido algun error al introducir los datos, por favor vuelva a introducirlos\n";
            return;
        }
            
        #undef DNI
        #undef NOMBRE
        #undef APELLIDOS
        #undef DIRECCION
    }
    
    void nuevoUsuario()
    {
        std::string file;

        std::cout << "\n\n***Dar de alta a un usuario***\n\n";
        std::cout << "Introduce el nombre del fichero: \"cliente.txt\"\n";
        std::cin >> file;
        std::cout << "\n";

        std::fstream fs{ file };
        int cont = 0;

        while(fs)
        {
            std::getline(fs, cliente[cont]);
            cont++;
        }
    }

    void nuevoViaje()
    {
        std::string file;

        std::cout << "\n\n***Registrar un nuevo viaje***\n\n";
        std::cout << "Introduce el nombre del fichero: \"viajes.txt\"\n";
        std::cin >> file;
        std::cout << "\n";

        // Lee el archivo y lo guarda en un array
        std::fstream fs{ file };
        int cont = 0;

        while(fs)
        {
            std::getline(fs, viajes[cont]);
            cont++;
        }
    }

    void verificarViaje()
    {
        if(cliente[0] == viajes[0] && cliente[0] != "" && viajes[0] != "")
        {
            identificador = "_1_01_01_18";
            std::cout << "El viaje ha sido dado de alta con exito!!\n" << 
            "El identificador asignado al viaje es " << viajes[0] << identificador << std::endl;
        }
        else
            std::cout << "Error, el cliente no se encuentra registrado\n";
        
    }

    void borrarCliente()
    {
        std::string file;

        std::cout << "\n\n***Dar de baja a un usuario***\n\n";
        std::cout << "Introduce el nombre del fichero: \"dni.txt\"\n";
        std::cin >> file;
        std::cout << "\n";

        std::fstream fs{ file };
        std::string dni;
        while(fs)
        {
            std::getline(fs, dni);
        }

        if(dni == cliente[0])
        {
            for (int i = 0; i < 4; i++)
            {
                cliente[i] = "";
            }

            std::cout << "Usuario eliminado con exito\n";  
        }
        else
            std::cout << "No se ha podidio encontrar el usuario\n";
         
    }

    void borrarViaje()
    {
        std::string file;
        std::string id;

        std::cout << "\n\n***Elimina un viaje***\n\n";
        std::cout << "Introduce el nombre del fichero: \"dni.txt\"\n";
        std::cin >> file;
        std::cout << "\n";

        std::fstream fs{ file };
        std::string dni;
        while(fs)
        {
            std::getline(fs, dni);
        }

        std::cout << "Introduzca el identificador del viaje que se le proporciono al registrarse\n";
        std::cin >> id;

        if(dni == viajes[0] && id == viajes[0] + identificador)
        {
            for (int i = 0; i < 6; i++)
            {
                viajes[i] = "";
            }

            std::cout << "Se ha eliminado su reserva del viaje.\n";  
        }
        else
            std::cout << "No se ha podido encontrar el viaje\n";
    }
    
};

int main()
{
    Agenda agenda;
    agenda.menu();    
}