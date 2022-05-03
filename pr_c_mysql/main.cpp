// crud de la base de datos estudiantes

#include <mysql.h>
#include <iostream>
#include <Windows.h>
#include "estudiantes.h"
using namespace  std;

int main()
{
	int opcion;
	cout << "--BIENVENIDO A LA BASE DE DATOS DE ESTDUIANTES--" << endl;
	cout << "--ESCOGE UNA OPCION--" << endl;
	cout << "1. CREAR ESTUDIANTE" << endl;
	cout << "2. MOSTRAR ESTUDIANTE" << endl;
	cout << "3. MODIFICAR ESTUDIANTE" << endl;
	cout << "4. ELIMINAR ESTUDIANTE" << endl;
	cout << "5. SALIR" << endl;
	cin >> opcion;
	cout << "--ESCOGE UNA OPCION----" << endl;
	switch (opcion)
	{
	case 1: {
		system("cls");
		cout << "--CREAR ESTUDIANTE--" << endl;
		string carnet, nombres, apellidos, direccion, genero, email, fecha_nacimiento;
		int telefono;
		cout << "--INGRESE LOS DATOS DEL ESTUDIANTE--" << endl;
		cout << "Carnet: ";
		getline(cin, carnet);
		cout << "Nombres: ";
		getline(cin, nombres);
		cout << "Apellidos: ";
		getline(cin, apellidos);
		cout << "Direccion: ";
		getline(cin, direccion);
		cout << "Genero: ";
		getline(cin, genero);
		cout << "Email: ";
		getline(cin, email);
		cout << "Fecha de nacimiento: ";
		getline(cin, fecha_nacimiento);
		cout << "Telefono: ";
		cin >> telefono;

		estudiante es = estudiante(carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento);
		es.crear();
		es.leer();
		break;
	}
	case 2: {
		system("cls");
		cout << "--MOSTRAR ESTUDIANTE--" << endl;
		string estudiante;
		cout << "--INGRESE EL ID DEL ESTUDIANTE--" << endl;
		cout << "ID: ";
		getline(cin, estudiante);
		estudiante es= estudiante(estudiante);
		es.leer();


		break;
	}
	case 3: {
		system("cls");
		cout << "--MODIFICAR ESTUDIANTE--" << endl;
		string carnet, nombres, apellidos, direccion, genero, email, fecha_nacimiento;
		int telefono;
		cout << "--INGRESE LOS DATOS DEL ESTUDIANTE--" << endl;
		cout << "Carnet: ";
		getline(cin, carnet);
		cout << "Nombres: ";
		getline(cin, nombres);
		cout << "Apellidos: ";
		getline(cin, apellidos);
		cout << "Direccion: ";
		getline(cin, direccion);
		cout << "Genero: ";
		getline(cin, genero);
		cout << "Email: ";
		getline(cin, email);
		cout << "Fecha de nacimiento: ";
		getline(cin, fecha_nacimiento);
		cout << "Telefono: ";
		cin >> telefono;

		estudiante es = (carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento);
		es.modificar();
		es.leer();
		break;
	}
		  //eliminar con id_Estudiente
	case 4: {
		system("cls");
		cout << "--ELIMINAR ESTUDIANTE--" << endl;
		string estudiante;
		cout << "--INGRESE EL ID DEL ESTUDIANTE--" << endl;
		cout << "ID: ";
		getline(cin, estudiante);
		estudiante es = (estudiante);
		es.eliminar();
		es.leer();
		break;
	}
	case 5: {
		system("cls");
		cout << "--SALIR--" << endl;
		break;
	}


	}
	system("pause");
	return 0;
}





