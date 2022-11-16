#include <iostream>
#include <string>
#include <fstream>

#define ArchP "C:\UF\Introduccion a Redes e Internet\2022\Trabajos\Tp Final\Tp Final (2da entrega)\data_files\input\IRI_Pacientes.csv"

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
	int matricula;
	string nombre;
	string apellido;
	int telefono;
	string especialidad;
	bool activo;
};
struct Contacto {
	Paciente dni_p; //saco dni
	int telefono;
	int celular;
	string direccion;
	string email;
};
struct Consulta {
	Paciente dni_p;//saco dni
	Fecha solicitado; //dia que pidio el turno
	Fecha turno; //fecha del turno
	int presento[1];
	Medico matricula_m;//saco matricula
};
/*-----------------*/

/*-----ARCHIVOS-----*/
void Archpaciente_out(Paciente* paciente, int i);
void Archpaciente_In();
/*------------------*/
void Archpaciente_out(Paciente* paciente, int i)
{
	string coma = " - ";
	fstream arch_paciente;

	arch_paciente.open(ArchP, ios::out | ios::app);
	if (!(arch_paciente.is_open())) {
		return;
	}
	arch_paciente << paciente[i].dni << coma;
	arch_paciente << paciente[i].nombre << coma;
	arch_paciente << paciente[i].apellido << coma;
	arch_paciente << paciente[i].sexo << coma;
	arch_paciente << paciente[i].natalicio.dia << "/" << paciente[i].natalicio.mes << "/" << paciente[i].natalicio.anio << coma;
	arch_paciente << paciente[i].estado << coma;
	arch_paciente << paciente[i].id_os.obra_social << endl;
	
	arch_paciente.close();
}

void Archpaciente_In()
{
	int i = 0;

	ifstream arch_paciente;

	arch_paciente.open(ArchP, ios::in);
	if (!(arch_paciente.is_open())) {
		return ;
	}
	Paciente* ptrpaciente = nullptr;
	while (arch_paciente) {
		
		arch_paciente >> ptrpaciente[i].dni;
		getline(arch_paciente, ptrpaciente[i].nombre);
		getline(arch_paciente, ptrpaciente[i].apellido);
		arch_paciente >> ptrpaciente[i].sexo;
		arch_paciente >> ptrpaciente[i].natalicio.dia >> ptrpaciente[i].natalicio.mes >> ptrpaciente[i].natalicio.anio;
		getline(arch_paciente, ptrpaciente[i].estado);
		getline(arch_paciente, ptrpaciente[i].id_os.obra_social);
		cout << ptrpaciente[i].dni << ptrpaciente[i].nombre << ptrpaciente[i].estado << endl;
		i++;
	}


	arch_paciente.close();


	//return ptrpaciente;//devuelve puntero
}