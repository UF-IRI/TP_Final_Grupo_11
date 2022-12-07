#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>
#include <ctime>

//debe cambiar la direccion de cada archivo para que funcione
#define ArchP "C:\\UF\\Introduccion a Redes e Internet\\2022\\Trabajos\\TP Final\\Tp Final (2da entrega)\\data_files\\input\\IRI_Pacientes.csv"
#define ArchOS "C:\\UF\\Introduccion a Redes e Internet\\2022\\Trabajos\\TP Final\\Tp Final (2da entrega)\\data_files\\input\\IRI_ObraSocial.csv"
#define ArchM "C:\\UF\\Introduccion a Redes e Internet\\2022\\Trabajos\\TP Final\\Tp Final (2da entrega)\\data_files\\input\\IRI_Medicos.csv"
#define ArchUMxP "C:\\UF\\Introduccion a Redes e Internet\\2022\\Trabajos\\TP Final\\Tp Final (2da entrega)\\data_files\\input\\IRI_UltimoMedicoXPaciente.csv"
#define ArchContac "C:\\UF\\Introduccion a Redes e Internet\\2022\\Trabajos\\TP Final\\Tp Final (2da entrega)\\data_files\\input\\IRI_Contactos.csv"
#define ArchConsul "C:\\UF\\Introduccion a Redes e Internet\\2022\\Trabajos\\TP Final\\Tp Final (2da entrega)\\data_files\\input\\IRI_Consultas.csv"
#define ArchCE "C:\\UF\\Introduccion a Redes e Internet\\2022\\Trabajos\\TP Final\\Tp Final (2da entrega)\\data_files\\input\\IRI_ConsultasEliminados.csv"
#define ArchUM "C:\\UF\\Introduccion a Redes e Internet\\2022\\Trabajos\\TP Final\\Tp Final (2da entrega)\\data_files\\input\\IRI_UltimoMedico.csv"

using namespace std;

/*------ENUMS------*/
enum Estado{
	FALLECIDO = 1, INTERNADO
};
enum Especialidad {
	NEUROLOGIA = 1, CARDIOLOGIA, PEDIATRIA
};
/*-----------------*/

/*-----STRUCTS-----*/
struct Fecha {
	int dia;
	int mes;
	int anio;
};
struct Matricula {
	int p1;
	int p2;
	int p3;
};
struct Telefono {
	int pais;
	int area;
	int num;
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
	Estado estado;
	ObraSocial id_os;
};
struct Medico {
	Matricula matricula;
	string nombre;
	string apellido;
	Telefono telefono;
	Especialidad especialidad;
	bool activo;

};
struct Contacto {
	Paciente dni_p; //saco dni
	Telefono telefono;
	Telefono celular;
	string direccion;
	string email;
};
struct Consulta {
	Paciente dni_p;//saco dni
	Fecha solicitado; //dia que pidio el turno
	Fecha turno; //fecha del turno
	int presento; // "S" si se presento / "N" no se presento
	Medico matricula_m;//saco matricula
};
/*-----------------*/

/*-----ARCHIVOS-----*/
/*-----PACIENTE-----*/
void ltPaciente_agregar(Paciente*& ltpaciente, Paciente paciente, int* tamactual);
Paciente* ArchPaciente_leer();
void ArchPaciente_agregar();
bool ArchPaciente_crear();
int TamanioArchPaciente();
void ImpPacientes();
/*-----O.SOCIAL-----*/
void ltOS_agregar(ObraSocial*& ltos, ObraSocial os, int* tamactual);
ObraSocial* ArchOS_leer();
void ArchOS_agregar(ObraSocial os);
bool ArchOS_crear();
int TamanioArchOS();
void ImpOS();
/*------MEDICO------*/
void ltM_agregar(Medico*& ltmedico, Medico medico, int* tamactual);
Medico* ArchM_leer();
void ArchM_agregar(Medico m);
bool ArchM_crear();
int TamanioArchMedico();
void ImpMedicos();
void ArchUMxP_agregar(Medico m, Paciente p, Contacto c);
bool ArchUMxP_crear();
/*-----CONTACTO-----*/
void ltContac_agregar(Contacto*& ltcontac, Contacto contacto, int* tamactual);
Contacto* ArchContac_leer();
void ArchContac_agregar(int dni);
bool ArchContac_crear();
int TamanioArchContac();
void ImpContactos();
/*-----CONSULTA-----*/
void ltConsul_agregar(Consulta*& ltconsul, Consulta consulta, int* tamactual);
Consulta* ArchConsul_leer();
void ArchConsul_agregar(Consulta consulta);
bool ArchConsul_crear();
int TamanioArchConsul();
void ImpConsultas();
int DiezAniosCosulta(int solicitado, int presento);
bool ArchConsul_eliminados(Consulta c);
void ArchConsul_RedireccionarEliminado();
void ArchConsul_eliminar(Consulta consulta);
/*------------------*/

/*-----FUNCIONES----*/
void menu();
void PacienteXMedico();
void IoF();
void Secretaria();
void UltimoMedico();

/*------------------*/