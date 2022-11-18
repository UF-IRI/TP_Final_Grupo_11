#include "dummy.h"

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
		arch << p.dni << coma << p.nombre << coma << p.apellido << coma << p.sexo << coma << p.natalicio.dia << barra << p.natalicio.mes << barra << p.natalicio.anio << coma << p.estado << coma << p.id_os.obra_social;
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
int TamanioArchPaciente() {

	char coma;
	fstream arch;
	arch.open(ArchP, ios::in);

	if (!(arch.is_open()))
		return 0;

	string basura;
	arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
	int i = 0;
	while (arch) {
		Paciente aux;
		arch >> aux.dni >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.sexo >> coma >> aux.natalicio.dia >> coma >> aux.natalicio.mes >> coma >> aux.natalicio.anio >> coma >> aux.estado >> coma >> aux.id_os.obra_social;
		i++;
	}

	arch.close();
	return i;
}
/*-----O.SOCIAL-----*/
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
		arch  << os.id << coma << os.obra_social;
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
		arch  << m.matricula << coma << m.nombre << coma << m.apellido << coma << m.telefono << coma << m.especialidad << coma << m.activo;
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
		arch  << contacto.dni_p.dni << coma << contacto.telefono << coma << contacto.celular << coma << contacto.direccion << coma << contacto.email ;
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
		arch  << consulta.dni_p.dni << coma << consulta.solicitado.dia << barra << consulta.solicitado.mes << barra << consulta.solicitado.anio << coma << consulta.turno.dia << barra << consulta.turno.mes << barra << consulta.turno.anio << coma << consulta.presento << coma << consulta.matricula_m.matricula;
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
int DiezAniosCosulta(int solicitado, string presento) {

	time_t t = time(NULL);
	struct tm* anio = localtime(&t);
	int diferencia;
	
		diferencia = anio->tm_year - (solicitado - 1900);
		if (diferencia > 10 && presento == "0") {
			return 1;
		}
		else if (diferencia < 10 && presento == "0") {
			return 2;
		}
	return 0;
}
void ArchConsul_RedireccionarEliminado() {

	char coma;
	int diferencia;
	
	Consulta aux;
	ifstream arch;
	arch.open(ArchConsul, ios::in);
	if (!(arch.is_open())) { return; }
	
	string basura;
	arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
	while (arch) {
		arch >> aux.dni_p.dni >> coma >> aux.solicitado.dia >> coma >> aux.solicitado.mes >> coma >> aux.solicitado.anio >> coma >> aux.turno.dia >> coma >> aux.turno.mes >> coma >> aux.turno.anio >> coma >> aux.presento >> coma >> aux.matricula_m.matricula;
		diferencia = DiezAniosCosulta(aux.solicitado.anio,aux.presento);
		if (diferencia == 1) {
			
			ArchConsul_eliminados(aux);
			ArchConsul_eliminar(aux);
		}
	}
	arch.close();
}
void ArchConsul_eliminar(Consulta consulta) {

	string coma = " , ";
	string barra = "/";
	fstream arch;
	int tamanio = TamanioArchConsul();
	Consulta* c = ArchConsul_leer();
	
	arch.open(ArchConsul, ios::out);
	if (!(arch.is_open())) { return; }
	while (int i = 0 < tamanio) {
		if (consulta.dni_p.dni == c[i].dni_p.dni) {
			for (int j = i; j < tamanio; j++) {
				c[i].dni_p.dni = c[i + 1].dni_p.dni;
				c[i].solicitado.dia = c[i + 1].solicitado.dia;
				c[i].solicitado.mes = c[i + 1].solicitado.mes;
				c[i].solicitado.anio = c[i + 1].solicitado.anio;
				c[i].turno.dia = c[i + 1].turno.dia;
				c[i].turno.mes = c[i + 1].turno.mes;
				c[i].turno.anio = c[i + 1].turno.anio;
				c[i].presento = c[i + 1].presento;
				c[i].matricula_m.matricula = c[i + 1].matricula_m.matricula;
			}
			break;
		}

	}
	arch << "dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med" << endl;
	while (int i = 0 < tamanio) {
		arch << c[i].dni_p.dni << coma << c[i].solicitado.dia << barra << c[i].solicitado.mes << barra << c[i].solicitado.anio << coma << c[i].turno.dia << barra << c[i].turno.mes << barra << c[i].turno.anio << coma << c[i].presento << coma << c[i].matricula_m.matricula << endl;
		i++;
	}
	arch.close();
}
void ArchConsul_eliminados( Consulta consulta) {
	const char coma = ',';
	const char barra = '/';

	fstream arch;

	arch.open(ArchCE, ios::in);
	if (!(arch.is_open())) {
		arch.close();

		arch.open(ArchCE, ios::out);
		if (arch.is_open()) {
			arch << "dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med" << endl;
		}
		else { cout << "No abrio el archivo 'consulta eliminados'."; return; }
		
	}
	arch.close();
	arch.open(ArchCE, ios::app);
	if (arch.is_open()) {
		arch << consulta.dni_p.dni << coma << consulta.solicitado.dia << barra << consulta.solicitado.mes << barra << consulta.solicitado.anio << coma << consulta.turno.dia << barra << consulta.turno.mes << barra << consulta.turno.anio << coma << consulta.presento << coma << consulta.matricula_m.matricula << endl;
	}
	arch.close();


	return;
}
int TamanioArchConsul() {

	char coma;
	fstream arch;
	arch.open(ArchConsul, ios::in);

	if (!(arch.is_open()))
		return 0;

	string basura;
	arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
	int i = 0;
	while (arch) {
		Consulta aux;
		arch >> aux.dni_p.dni >> coma >> aux.solicitado.dia >> coma >> aux.solicitado.mes >> coma >> aux.solicitado.anio >> coma >> aux.turno.dia >> coma >> aux.turno.mes >> coma >> aux.turno.anio >> coma >> aux.presento >> coma >> aux.matricula_m.matricula;
		i++;
	}

	arch.close();
	return i;
}
/*--------OTRAS FUNCIONES----------*/

void IoF() //internado o fallecido
{
	Paciente* aux = ArchPaciente_leer();
	int tam = TamanioArchPaciente();

	Consulta* aux1 = ArchConsul_leer();
	//si es 1: hace mas de 10 anios saco el turno y no se presento. cuando retorna 2: fueron citados hace menos de diez anios y no se presento 

	for (int i = 0; i < tam; i++)
	{

		int DiezAnios = DiezAniosCosulta(aux1[i].solicitado.anio, aux1[i].presento);
		if (DiezAnios == 2 && aux[i].estado == "fallecido")
		{
			cout << "FALLECIDO" << endl;
		}
		else if (DiezAnios == 2 && aux[i].estado == "internado")
		{
			cout << "INTERNADO" << endl;
		}
	}
}

void UltimoMedico()
{
	fstream archivo, arch;
	Medico* aux;
	Paciente* auxx;
	Consulta* aux1 = ArchConsul_leer();

	int i = 0;
	int tam = TamanioArchConsul();
	

	arch.open(ArchConsul, ios::in);
	if (!(arch.is_open())) { return; }

	while (arch)
	{
		int DiezAnios = DiezAniosCosulta(aux1[i].solicitado.anio, aux1[i].presento);
		if (DiezAnios == 2)
		{
			//se tendria que fijar cual medico fue el ultimo en atenderlo
		}
	}

	arch.close();

	archivo.open(ArchUM, ios::out);

	if (!(archivo.is_open())) { return; }

	while (i < tam)
	{
		if (DiezAnios == 2)
		{
			archivo << aux[i].matricula << coma << aux[i].nombre << coma << aux[i].apellido << coma << aux[i].telefono << aux[i].especialidad << coma << aux[i].activo << endl;
			archivo << auxx[i].dni << coma << auxx[i].id_os.obra_social << endl;
		}
	}

	archivo.close();

}

void Secretaria()
{
	fstream archivo;
	fstream arch;
	Paciente* aux;
	Paciente paciente;
	int tam = TamanioArchConsul();

	archivo.open(ArchP, ios::in); //primero lo leo, lo guardo adentro de un puntero
	arch.open(ArchConsul, ios::in)


	if (!(archivo.is_open())) { return; }
	if (!(arch.is_open())) { return; }

	while (archivo)
	{
		//guardo en un puntero el archivo 
		Paciente* aux1 = new Paciente[tam];

	}

	while (arch)
	{
		Consulta* aux2 = new Consulta[tam];
	}

	archivo.close();
	arch.close();

	int DiezAnios = DiezAniosCosulta();

	archivo.open(ArchP, ios::out);
	archivo.open(ArchConsul, ios::out);

	if (!(archivo.is_open())) { return; }
	if (!(arch.is_open())) { return; }

	while (i < tam)
	{
		ArchPaciente_agregar(paciente);
		if (aux[i].id_os != aux1[i].id_os && DiezAnios == 2)
		{

			archivo << aux[i].id_os << endl;
		}
		else
			return;

	}
	archivo.close();
	arch.close();

}
