#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>

#define ArchP "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2022 2do cuatri\\TpFinal\\data_files\\input\\IRI_Pacientes.csv"
#define ArchOS "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2022 2do cuatri\\TpFinal\\data_files\\input\\IRI_ObraSocial.csv"
#define ArchM "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2022 2do cuatri\\TpFinal\\data_files\\input\\IRI_Medicos.csv"
#define ArchContac "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2022 2do cuatri\\TpFinal\\data_files\\input\\IRI_Contactos.csv"
#define ArchConsul "C:\\Users\\Facu\\OneDrive\\Documentos\\UF\\IRI\\2022 2do cuatri\\TpFinal\\data_files\\input\\IRI_Consultas.csv"

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
	string presento;
	Medico matricula_m;//saco matricula
};
/*-----------------*/

/*-----ARCHIVOS-----*/
/*-----PACIENTE-----*/
void ltPaciente_agregar(Paciente*& ltpaciente, Paciente paciente, int* tamactual);
//void ArchPaciente_resize(Paciente*& ltpaciente, int* tamactual, int cantidad_aumentar);
Paciente* ArchPaciente_leer();
void ArchPaciente_agregar(Paciente p);
bool ArchPaciente_crear();
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
/*------------------*/

/*-----PACIENTE-----*/
void ltPaciente_agregar(Paciente*& ltpaciente, Paciente paciente, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Paciente* aux = new Paciente[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = ltpaciente[i];
		i++;
	}
	aux[i] = paciente;

	delete[] ltpaciente;
	ltpaciente = aux;

	return;
}
/*void ArchPaciente_resize(Paciente*& ltpaciente, int* tamactual, int cantidad_aumentar) {
	*tamactual = *tamactual + cantidad_aumentar;
	int i = 0;
	Paciente* aux = new Paciente[*tamactual];
	while (i < *tamactual - cantidad_aumentar) {
		aux[i] = ltpaciente[i];
		i++;
	}

	delete[] ltpaciente;
	ltpaciente = aux;

	return;
}*/
Paciente* ArchPaciente_leer() {
	Paciente* ltpaciente = new Paciente[0];
	Paciente aux;
	
	char coma;
	
	int tamact = 0;

	fstream arch;
	arch.open(ArchP, ios::in);
	

	if (!(arch.is_open()))
		return nullptr;

	string basura;
	arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
	
	while (arch) {
		
		arch >> aux.dni >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.sexo >> coma >> aux.natalicio.dia >> coma >> aux.natalicio.mes >> coma >> aux.natalicio.anio >> coma >> aux.estado >> coma >> aux.id_os.obra_social;

		ltPaciente_agregar(ltpaciente, aux, &tamact);
	}

	arch.close();
	

	return ltpaciente;
}
void ArchPaciente_agregar(Paciente p) {
	string coma = " , ";
	string barra = "/";
	fstream arch;

	arch.open(ArchP, ios::in);
	if (!(arch.is_open())) {
		
		bool ok = ArchPaciente_crear();
		if (ok == false) {
			arch.close();
			return;
		}
	}
	arch.close();
	arch.open(ArchP,  ios::app);
	if (arch.is_open()) {
		arch << endl << p.dni << coma << p.nombre << coma << p.apellido << coma << p.sexo << coma << p.natalicio.dia << barra << p.natalicio.mes << barra << p.natalicio.anio << coma << p.estado << coma << p.id_os.obra_social;
	}
	arch.close();
	

	return;
}
bool ArchPaciente_crear() {
	const char coma = ',';
	const char barra = '/';
	fstream arch;
	arch.open(ArchP, ios::out);

	if (arch.is_open()) {
		arch << "dni , nombre , apellido , sexo , natalicio , estado , id_os" << endl;	
		return true;
	}
	else { return false; }
}
/*-----O.SOCIAL-----*/
void ltOS_agregar(ObraSocial*& ltos, ObraSocial os, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	ObraSocial* aux = new ObraSocial[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = ltos[i];
		i++;
	}
	aux[i] = os;

	delete[] ltos;
	ltos = aux;

	return;
}
ObraSocial* ArchOS_leer() {
	ObraSocial* ltos = new ObraSocial[0];
	ObraSocial aux;

	char coma;

	int tamact = 0;

	fstream arch;
	arch.open(ArchOS, ios::in);


	if (!(arch.is_open()))
		return nullptr;

	string basura;
	arch >> basura >> coma >> basura ;

	while (arch) {

		arch >> aux.id >> coma >> aux.obra_social;

		ltOS_agregar(ltos, aux, &tamact);
	}

	arch.close();


	return ltos;
}
void ArchOS_agregar(ObraSocial os) {
	string coma = " , ";
	fstream arch;

	arch.open(ArchOS, ios::in);
	if (!(arch.is_open())) {

		bool ok = ArchOS_crear();
		if (ok == false) {
			arch.close();
			return;
		}
	}
	arch.close();
	arch.open(ArchOS, ios::app);
	if (arch.is_open()) {
		arch << endl << os.id << coma << os.obra_social;
	}
	arch.close();


	return;
}
bool ArchOS_crear() {
	const char coma = ',';
	fstream arch;
	arch.open(ArchOS, ios::out);

	if (arch.is_open()) {
		arch << "id , obra social" << endl;
		return true;
	}
	else { return false; }
}
/*------MEDICO------*/
void ltM_agregar(Medico*& ltmedico, Medico m, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Medico* aux = new Medico[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = ltmedico[i];
		i++;
	}
	aux[i] = m;

	delete[] ltmedico;
	ltmedico = aux;

	return;
}
Medico* ArchM_leer() {
	Medico* ltmedico = new Medico[0];
	Medico aux;

	char coma;

	int tamact = 0;

	fstream arch;
	arch.open(ArchM, ios::in);


	if (!(arch.is_open()))
		return nullptr;

	string basura;
	arch >> basura >> coma >> basura >>coma>> basura >> coma >> basura >>coma>> basura >> coma >> basura;

	while (arch) {

		arch >> aux.matricula >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.telefono >> coma >> aux.especialidad >> coma >> aux.activo;

		ltM_agregar(ltmedico, aux, &tamact);
	}

	arch.close();


	return ltmedico;
}
void ArchM_agregar(Medico m) {
	string coma = " , ";
	fstream arch;

	arch.open(ArchM, ios::in);
	if (!(arch.is_open())) {

		bool ok = ArchOS_crear();
		if (ok == false) {
			arch.close();
			return;
		}
	}
	arch.close();
	arch.open(ArchM, ios::app);
	if (arch.is_open()) {
		arch << endl << m.matricula << coma << m.nombre << coma << m.apellido << coma << m.telefono << coma << m.especialidad << coma << m.activo;
	}
	arch.close();


	return;
}
bool ArchM_crear() {
	const char coma = ',';
	fstream arch;
	arch.open(ArchM, ios::out);

	if (arch.is_open()) {
		arch << "matricula , nombre , apellido , telefono , especialidad , activo" << endl;
		return true;
	}
	else { return false; }
}
/*-----CONTACTO-----*/
void ltContac_agregar(Contacto*& ltcontac, Contacto contacto, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Contacto* aux = new Contacto[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = ltcontac[i];
		i++;
	}
	aux[i] = contacto;

	delete[] ltcontac;
	ltcontac= aux;

	return;
}
Contacto* ArchContac_leer() {
	Contacto* ltcontac = new Contacto[0];
	Contacto aux;

	char coma;

	int tamact = 0;

	fstream arch;
	arch.open(ArchContac, ios::in);


	if (!(arch.is_open()))
		return nullptr;

	string basura;
	arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura ;

	while (arch) {

		arch >> aux.dni_p.dni >> coma >> aux.telefono >> coma >> aux.celular >> coma >> aux.direccion >> coma >> aux.email;

		ltContac_agregar(ltcontac, aux, &tamact);
	}

	arch.close();


	return ltcontac;
}
void ArchContac_agregar(Contacto contacto) {
	string coma = " , ";
	fstream arch;

	arch.open(ArchContac, ios::in);
	if (!(arch.is_open())) {

		bool ok = ArchContac_crear();
		if (ok == false) {
			arch.close();
			return;
		}
	}
	arch.close();
	arch.open(ArchContac, ios::app);
	if (arch.is_open()) {
		arch << endl << contacto.dni_p.dni << coma << contacto.telefono << coma << contacto.celular << coma << contacto.direccion << coma << contacto.email ;
	}
	arch.close();


	return;
}
bool ArchContac_crear() {
	const char coma = ',';
	fstream arch;
	arch.open(ArchContac, ios::out);

	if (arch.is_open()) {
		arch << "dni_paciente , telefono , celular , direccion , mail" << endl;
		return true;
	}
	else { return false; }
}
/*-----CONSULTA-----*/
void ltConsul_agregar(Consulta*& ltconsul, Consulta consulta, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Consulta* aux = new Consulta[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = ltconsul[i];
		i++;
	}
	aux[i] = consulta;

	delete[] ltconsul;
	ltconsul = aux;

	return;
}
Consulta* ArchConsul_leer() {
	Consulta* ltconsul = new Consulta[0];
	Consulta aux;

	char coma;

	int tamact = 0;

	fstream arch;
	arch.open(ArchConsul, ios::in);


	if (!(arch.is_open()))
		return nullptr;

	string basura;
	arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;

	while (arch) {

		arch >> aux.dni_p.dni >> coma >> aux.solicitado.dia >> coma >> aux.solicitado.mes >> coma >> aux.solicitado.anio >> coma >> aux.turno.dia >> coma >> aux.turno.mes >> coma >> aux.turno.anio >> coma >> aux.presento >> coma >> aux.matricula_m.matricula;

		ltConsul_agregar(ltconsul, aux, &tamact);
	}

	arch.close();


	return ltconsul;
}
void ArchConsul_agregar(Consulta consulta) {
	string coma = " , ";
	string barra = "/";
	fstream arch;

	arch.open(ArchConsul, ios::in);
	if (!(arch.is_open())) {

		bool ok = ArchConsul_crear();
		if (ok == false) {
			arch.close();
			return;
		}
	}
	arch.close();
	arch.open(ArchConsul, ios::app);
	if (arch.is_open()) {
		arch << endl << consulta.dni_p.dni << coma << consulta.solicitado.dia << barra << consulta.solicitado.mes << barra << consulta.solicitado.anio << coma << consulta.turno.dia << barra << consulta.turno.mes << barra << consulta.turno.anio << coma << consulta.presento << coma << consulta.matricula_m.matricula;
	}
	arch.close();


	return;
}
bool ArchConsul_crear() {
	const char coma = ',';
	fstream arch;
	arch.open(ArchConsul, ios::out);

	if (arch.is_open()) {
		arch << "dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med" << endl;
		return true;
	}
	else { return false; }
}
/*------------------*/