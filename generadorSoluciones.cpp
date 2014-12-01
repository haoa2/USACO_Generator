/*
    Programa que genera el Template para
    las soluciones necesarias para la 
    plataforma USACO.

    El programa pedirá de entrada el ID,
    el PROG, y el Lenguaje siempre se
    colocará C++.

    Generador USCAO 2014 <Humberto Alcocer>
*/

#include <iostream>
#include <fstream>
#include <string>

//                  Filename,      ID,          PROG
void crear_archivo(std::string, std::string, std::string); 
void ayuda();

int main(int argc, char *argv[])
{
    std::string archivo = "NULL.cpp", 
                id      = "ID_NULA", 
                prog    = "PROG_NULO";
    char opcion;

    if(argc != 4)
    {
        std::cout << "Error: Número de parámetros insuficiente." << std::endl;
        ayuda();
        return -1;
    }

    std::cout << "Iniciando programa..." << std::endl << std::endl;

    id      = argv[1];
    prog    = argv[2];
    archivo = argv[3];

    std::cout << "Configuración detectada: " << std::endl << std::endl;

    std::cout << "\t ID:    " << id << std::endl;
    std::cout << "\t PROG:  " << prog << std::endl;
    std::cout << "\t .CPP:  " << archivo << std::endl;

    std::cout << std::endl;
    std::cout << "¿La configuración es correcta? [S/N]: ";
    std::cin >> opcion;

    if(opcion == 'S' || opcion == 's' || opcion == 'Y' || opcion == 'y')
    {
        crear_archivo(archivo, id, prog);
    }
    else
    {
        std::cout << "Error: La configuración no es correcta." << std::endl;
        ayuda();
        return -1;
    }

    std::cout << "¡Suerte con el Problema " << prog << "!" << std::endl;
    std::cout << "Fin del Programa." << std::endl;
    std::cout << "Programa hecho por: Humberto Alejandro Ortega Alcocer" << std::endl;
    return 0;
}

void crear_archivo(std::string file,
                   std::string id,
                   std::string prog)
{
    std::cout << "Generando Archivo " << file << " ..." << std::endl;

    std::ofstream fout(file.c_str(), std::ios::out);

    fout << "/*" << std::endl;
    fout << "ID: " << id << std::endl;
    fout << "PROG: " << prog << std::endl;
    fout << "LANG: " << "C++" << std::endl;
    fout << "*/" << std::endl;
    fout << "/// Template Realizado por Humberto Alejandro Ortega Alcocer." << std::endl << std::endl;

    fout << "// Librerías base." << std::endl;
    fout << "#include <iostream>" << std::endl;
    fout << "#include <fstream>" << std::endl;
    fout << "#include <vector>" << std::endl;
    fout << "#include <deque>" << std::endl;
    fout << "#include <string>" << std::endl;
    fout << "#include <cmath>" << std::endl;
    fout << "#include <algorithm>" << std::endl;
    fout << "#include <cstdio>" << std::endl;
    fout << "#include <cstdlib>" << std::endl;
    fout << "#include <ctime>" << std::endl;

    fout << std::endl;
    fout << "// Para evitar std::X, aunque por estándar estamos incorrectos." << std::endl;
    fout << "using namespace std;" << std::endl;
    fout << std::endl;
    fout << "// Declare aquí los templates de las funciones necesarias." << std::endl << std::endl;

    fout << "// Función Principal (Main)." << std::endl;
    fout << "int main(int argc, char *argv[])" << std::endl;
    fout << "{" << std::endl;
    fout << "   std::ifstream fin(\"" << prog << ".in\", std::ios::in );" << std::endl;
    fout << "   std::ofstream fout(\"" << prog <<  ".out\", std::ios::out );" << std::endl;
    fout << std::endl;
    fout << "   // Lógica del Programa." << std::endl;
    fout << std::endl;
    fout << "   return 0;" << std::endl;
    fout << "}" << std::endl;

    fout << std::endl << std::endl;
    fout << "// Coloque aquí las implementaciones de las funciones." << std::endl << std::endl;

    fout << "/// Humberto Alejandro Ortega Alcocer - 2014." << std::endl;
    fout << "/// Generador de Templates de Solución de USACO." << std::endl;
    fout << "/// Comentarios: <humbertowoody@gmail.com>";

    std::cout << "¡Ha finalizado la generación del Archivo!" << std::endl;
}

void ayuda()
{
    std::cout << std::endl;
    std::cout << "Generador de Archivos de Solución para USACO (C++)." << std::endl << std::endl;
    std::cout << "Programa que genera un archivo .cpp para resolver problemas de olimpiada" << std::endl;
    std::cout << "basándose en un template pre-establecido. Se puede utilizar para otros fines," << std::endl;
    std::cout << "pero ya está configurado adecuadamente." << std::endl << std::endl;
    std::cout << "Uso:" << std::endl << std::endl;
    std::cout << "\t ./Generador ID_PERSONAL NOMBRE_DEL_PROGRAMA NOMBRE_ARCHIVO.CPP" << std::endl << std::endl;
    std::cout << "Parámetros:" << std::endl << std::endl;
    std::cout << "\t-ID_PERSONAL            Se refiere al ID de la persona que responde el problema planteado" << std::endl;
    std::cout << "\t                        y debe ser el nombre que se muestra en la página." << std::endl << std::endl;
    std::cout << "\t-NOMBRE_DEL_PROGRAMA    Se refiere a la clave única del problema que se resolverá." << std::endl;
    std::cout << "\t                        Nótese que éste nombre NO SERÁ el nombre del Archivo resultante." << std::endl << std::endl;
    std::cout << "\t-NOMBRE_ARCHIVO.CPP     Es el nombre del archivo a generar. Se deberá especificar con todo" << std::endl;
    std::cout << "\t                        y extensión (.cpp), porque el programa no la añadirá en caso de no" << std::endl;
    std::cout << "\t                        existir." << std::endl << std::endl;
    std::cout << "Programa hecho por: Humberto Alejandro Ortega Alcocer. 2014" << std::endl;
    std::cout << "           \"Después de la sección 4, que Dios se ampare de tu alma.\"" << std::endl;
    std::cout << "                                      -HumbertoWoody" << std::endl << std::endl;
}
