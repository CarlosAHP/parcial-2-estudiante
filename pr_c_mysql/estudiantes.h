#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>

using namespace std;

class estudiante
{
	//atributos 
private: string  carnet, nombres, apellidos, direccion, genero, email, fecha_nacimiento;
	   int telefono;

//contructor
public: 
	estudiante() {}
	estudiante(string car, string nom, string ape, string dir, string gen, string ema, string f_n, int tel )
	{
		carnet = car;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		genero = gen;
		email = ema;
		fecha_nacimiento = f_n;
		telefono = tel;
	}
	//metodos 
public:
	//set modificar
	void setCarnet(string car) { carnet = car; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setGenero(string gen) { genero = gen; }
	void setEmail(string ema) { email = ema; }
	void setFecha_nacimiento(string f_n) { fecha_nacimiento = f_n; }
	void setTelefono(int tel) { telefono = tel; }
	
	//get mostrar 
	string getCarnet() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	string getGenero() { return genero; }
	string getEmail() { return email; }
	string getFecha_nacimiento() { return fecha_nacimiento; }
	int getTelefono() { return telefono; }
	
	//metodos de la base de datos
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW *fila;
		MYSQL_RES *resultado;
		cn.abrir_conexion();
		
		if (cn.getConectar()) {
			
			
			cout << "--DATOS DEL ESTUDIANTE--" << endl;
			string consulta = "SELECT *FROM estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila [0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << endl;
					}
			}
			else {
				cout << "Error en la consulta" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	
	void crear() {
		int	q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "INSERT INTO estudiantes (carnet, nombres, apellidos, direccion, genero, email, fecha_nacimiento, telefono) VALUES ('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + genero + "','" + email + "','" + fecha_nacimiento + "','" + to_string(telefono) + "')";
			const char* c = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "Estudiante creado" << endl;
			}
			else {
				cout << "Error en la consulta" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	// actualizar con id_Estudiante
	//pedir id_Estudiente
	//pedir datos 
	void actualizar(){
	int q_estado;
	ConexionBD cn = ConexionBD();
	cn.abrir_conexion();
	
	if (cn.getConectar()) {
		string update = "UPDATE estudiante SET estudiente ='" + carnet + "' , '" + nombres + "','" + apellidos + "','" + direccion + "','" + genero + "','" + email + "','" + fecha_nacimiento + "','" + to_string(telefono) + "' WHERE id_Estudiente =";
		string id_Estudiante;
		cout << "Ingrese el id del estudiante a modificar" << endl;
		cin >> id_Estudiante;
		update += id_Estudiante;
		const char* u = update.c_str();
		q_estado = mysql_query(cn.getConectar(), u);
		if (!q_estado) {
			cout << "DATOS ACTUALIZADOS CORRECTAMENTE" << endl;

		}
	}
		else {
			cout << "Error al actualizar datos " << endl;
		}
	cn.cerrar_conexion();
	}
	
	//funcion eliminar 
	// eliimniar  por id_Estduiante
	//pedir los datos 

	// funcion para eliminar
	//pedir id_Estudiante
	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string delete_ = "DELETE FROM estudiantes WHERE id_Estudiante =";
			string id_Estudiante;
			cout << "Ingrese el id del estudiante a eliminar" << endl;
			cin >> id_Estudiante;
			delete_ += id_Estudiante;
			const char* d = delete_.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado) {
				cout << "DATOS ELIMINADOS CORRECTAMENTE" << endl;
			}
			else {
				cout << "Error en la consulta" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	
};

