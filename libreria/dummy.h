#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>
#include <ctime>

#define ArchP "C:\\Users\\maite\\OneDrive\\Escritorio\\FAVALORO\\SEGUNDO AÑO\\SEGUNDO CUATRI\\IRI\\TP FINAL\\data_files\\input\\IRI_Pacientes.csv"
#define ArchOS "C:\\Users\\maite\\OneDrive\\Escritorio\\FAVALORO\\SEGUNDO AÑO\\SEGUNDO CUATRI\\IRI\\TP FINAL\\data_files\\input\\IRI_ObraSocial.csv"
#define ArchM "C:\\Users\\maite\\OneDrive\\Escritorio\\FAVALORO\\SEGUNDO AÑO\\SEGUNDO CUATRI\\IRI\\TP FINAL\\data_files\\input\\IRI_Medicos.csv"
#define ArchContac "C:\\Users\\maite\\OneDrive\\Escritorio\\FAVALORO\\SEGUNDO AÑO\\SEGUNDO CUATRI\\IRI\\TP FINAL\\data_files\\input\\IRI_Contactos.csv"
#define ArchConsul "C:\\Users\\maite\\OneDrive\\Escritorio\\FAVALORO\\SEGUNDO AÑO\\SEGUNDO CUATRI\\IRI\\TP FINAL\\data_files\\input\\IRI_Consultas.csv"
#define ArchCE "C:\\Users\\maite\\OneDrive\\Escritorio\\FAVALORO\\SEGUNDO AÑO\\SEGUNDO CUATRI\\IRI\\TP FINAL\\data_files\\input\\IRI_ConsultasEliminados.csv"
#define ArchUM "C:\\Users\\maite\\OneDrive\\Escritorio\\FAVALORO\\SEGUNDO AÑO\\SEGUNDO CUATRI\\IRI\\TP FINAL\\data_files\\input\\IRI_UltimoMedico.csv"

using namespace std;

/*-----STRUCTS-----*/
struct Fecha {
	int dia;
	int mes;
	int anio;
};
struct ObraSocial {
	int id;
	string obra_social;
};
struct Paciente {
	int dni;
	string nombre;
	string apellido;
	char sexo;
	Fecha natalicio;
	string estado;
	ObraSocial id_os;
};
struct Medico {
	string matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	string activo;

};
struct Contacto {
	Paciente dni_p; //saco dni
	string telefono;
	string celular;
	string direccion;
	string email;
};
struct Consulta {
	Paciente dni_p;//saco dni
	Fecha solicitado; //dia que pidio el turno
	Fecha turno; //fecha del turno
	string presento; // "S" si se presento / "N" no se presento
	Medico matricula_m;//saco matricula
};
/*-----------------*/

/*-----ARCHIVOS-----*/
/*-----PACIENTE-----*/
void ltPaciente_agregar(Paciente*& ltpaciente, Paciente paciente, int* tamactual);
Paciente* ArchPaciente_leer();
void ArchPaciente_agregar(Paciente p);
bool ArchPaciente_crear();
int TamanioArchPaciente();
/*-----O.SOCIAL-----*/
void ltOS_agregar(ObraSocial*& ltos, ObraSocial os, int* tamactual);
ObraSocial* ArchOS_leer();
void ArchOS_agregar(ObraSocial os);
bool ArchOS_crear();
/*------MEDICO------*/
void ltM_agregar(Medico*& ltmedico, Medico medico, int* tamactual);
Medico* ArchM_leer();
void ArchM_agregar(Medico m);
bool ArchM_crear();
/*-----CONTACTO-----*/
void ltContac_agregar(Contacto*& ltcontac, Contacto contacto, int* tamactual);
Contacto* ArchContac_leer();
void ArchContac_agregar(Contacto contacto);
bool ArchContac_crear();
/*-----CONSULTA-----*/
void ltConsul_agregar(Consulta*& ltconsul, Consulta consulta, int* tamactual);
Consulta* ArchConsul_leer();
void ArchConsul_agregar(Consulta consulta);
bool ArchConsul_crear();
int DiezAniosCosulta(int solicitado, string presento);
void ArchConsul_eliminados(Consulta c);
void ArchConsul_RedireccionarEliminado();
void ArchConsul_eliminar(Consulta consulta);
int TamanioArchConsul();
/*------------------*/

/*-----FUNCIONES----*/

void IoF();
void Secretaria();
void UltimoMedico();

/*------------------*/