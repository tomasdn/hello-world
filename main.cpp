#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

char leerOpcion()
{
    char opcion;
    cout << "Ingrese una opción: " << endl;
    cout << "a - Crear un nuevo archivo con dos enteros." << endl;
    cout << "b - Leer dos enteros del archivo." << endl;
    cout << "c - Agregar un entero ingresado por teclado al final del archivo." << endl;
    cout << "d - Mostrar todo el archivo." << endl;
    cout << "e - Buscar un elemento y modificarlo por otro." << endl;
    cout << "f - Escribir un vector al final del archivo." << endl;
    cout << "s - Salir." << endl;
    do
    {
        opcion = getchar();
        opcion = tolower(opcion);
    }
    while(opcion!='a' && opcion!='b' && opcion!='c' && opcion!='d'
          && opcion!='e' && opcion!='f' && opcion!='s');
    return opcion;
}


int main()
{
    FILE *f;
    bool encontrado;
    int x;
    char elegida;
    do
    {
        elegida= leerOpcion();
        switch(elegida)
        {
            case 'a':
                if (f= fopen("archivito.k1253","wb"))
                {
                    x = 807;
                    fwrite(&x, sizeof(int), 1, f);
                    x = 2936;
                    fwrite(&x, sizeof(int), 1, f);
                    fclose(f);
                }
                else
                    cout << "Error: no se puede crear el archivo" << endl;
            break;
            case 'b':
                if (f= fopen("archivito.k1253","rb"))
                {
                    cout << "El curso está en la posición: " << ftell(f) << endl;
                    fread(&x, sizeof(int), 1, f);
                    cout << "Se leyó un: " << x << endl;
                    cout << "El curso está en la posición: " << ftell(f) << endl;
                    fread(&x, sizeof(int), 1, f);
                    cout << "Se leyó un: " << x << endl;
                    cout << "El curso está en la posición: " << ftell(f) << endl;
                    fclose(f);
                }
                else
                    cout << "Error: no se puede abrir el archivo" << endl;
            break;
            case 'c':
                if (f= fopen("archivito.k1253","ab"))
                {
                    cout << "Ingrese el número a agregar:" << endl;
                    cin >> x;
                    fwrite(&x, sizeof(int), 1, f);
                    fclose(f);
                }
                else
                    cout << "Error: no se puede abrir el archivo" << endl;
            break;
            case 'd':
                if (f= fopen("archivito.k1253","rb"))
                {
                    while(fread(&x, sizeof(int), 1, f))
                    {
                        cout << "Se leyó un: " << x;
                        cout << " - El curso está en la posición: " << ftell(f) << endl;
                    }
                    fclose(f);
                }
                else
                    cout << "Error: no se puede abrir el archivo" << endl;
            break;
            case 'e':
                int areemplazar, reemplazo;
                encontrado = false;
                cout << "Ingrese el valor a reemplazar:" << endl;
                cin >> areemplazar;
                cout << "Ingrese el valor de reemplazo:" << endl;
                cin >> reemplazo;
                if (f= fopen("archivito.k1253","rb+"))
                {
                    while (!encontrado && fread(&x, sizeof(int), 1, f))
                    {
                        if (x == areemplazar)
                        {
                            encontrado = true;
                            fseek(f, (-1)* sizeof(int), SEEK_CUR);
                            fwrite(&reemplazo, sizeof(int), 1, f);
                            cout << "Valor reemplazado exitosamente." << endl;
                        }
                    }
                    fclose(f);
                    if (!encontrado)
                        cout << "No se encontró el valor a reemplazar." << endl;
                }
                else
                    cout << "No se encontró el archivo." << endl;
            break;
            case 'f':
                int vec[] = {21,22,23,24,25,26,27,28,29,30};
                cout << "Ingrese cuántos elementos quiere agregar al final del archivo (hasta 10):" << endl;
                cin >> x;
                if (f= fopen("archivito.k1253","ab"))
                {
                    fwrite(vec, sizeof(int), x, f);//escribe x*sizeof(int) bytes desde el principio del vector
                    fclose(f);
                }
                else
                    cout << "Error: no se puede abrir el archivo" << endl;
            break;
        }
    }
    while (elegida != 's');
    return 0;
}
