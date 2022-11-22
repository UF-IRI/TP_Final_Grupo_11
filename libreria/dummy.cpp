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
		string auxestado;
		arch >> aux.dni >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.sexo >> coma >> aux.natalicio.dia >> coma >> aux.natalicio.mes >> coma >> aux.natalicio.anio >> coma >> auxestado >> coma >> aux.id_os.obra_social;
		if (auxestado == "internado") {
			aux.estado = INTERNADO;
		}
		else { aux.estado = FALLECIDO; }
		ltPaciente_agregar(ltpaciente, aux, &tamact);
	}

	arch.close();
	

	return ltpaciente;
}
void ArchPaciente_agregar() {
	string coma = " , ";
	string barra = "/";
	fstream arch;

	Paciente p;
	string auxestado;
	cout << "Nombre: "; cin >> p.nombre;
	cout << "Apellido: "; cin >> p.apellido;
	cout << "DNI: "; cin >> p.dni;
	cout << "Sexo (M/F): "; cin >> p.sexo;
	cout << "Natalicio:" << "\tDia: "; cin >> p.natalicio.dia; cout << "\t\tMes: "; cin >> p.natalicio.mes; cout << "\t\tAño: "; cin >> p.natalicio.anio;
	cout << "Estado (fallecido/internado): "; cin >> auxestado;
	while (auxestado != "fallecido" && auxestado != "internado") {
		cout << "Vuelva a intentarlo." << endl;
		cout << "Estado (fallecido/internado): "; cin >> auxestado;
	}
	cout << "Obra Social: "; cin >> p.id_os.obra_social;
	

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
		arch <<endl<< p.dni << coma << p.nombre << coma << p.apellido << coma << p.sexo << coma << p.natalicio.dia << barra << p.natalicio.mes << barra << p.natalicio.anio << coma << auxestado << coma << p.id_os.obra_social;
	}
	arch.close();
	
	ArchContac_agregar(p.dni);

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
		//arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
		arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
		i++;
	}
	
	arch.close();
	return i;
}
void ImpPacientes() {
	//imprimo personas
	string coma = " , ";
	string barra = "/";
	string guion = "-";
	string mas = "+";
	string parenA = "(";
	string parenC = ")";
	Paciente* p = ArchPaciente_leer();
	int tam = TamanioArchPaciente();
	int i = 0;
	cout << "dni , nombre , apellido , sexo , natalicio , estado , id_os" << endl;
	while (i < tam-1) {
		string auxestado;
		if (p[i].estado == INTERNADO) {
			auxestado = "internado";
		}
		else { auxestado = "fallecido"; }
		cout << p[i].dni << coma << p[i].nombre << coma << p[i].apellido << coma << p[i].sexo << coma << p[i].natalicio.dia << barra << p[i].natalicio.mes << barra << p[i].natalicio.anio << coma << auxestado << coma << p[i].id_os.obra_social << endl;
		i++;
	}
	delete[]p;
	system("pause");
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
int TamanioArchOS() {

	char coma;
	fstream arch;
	arch.open(ArchOS, ios::in);

	if (!(arch.is_open()))
		return 0;

	string basura;
	arch >> basura >> coma >> basura;
	int i = 0;
	while (arch) {
		arch >> basura >> coma >> basura;
		i++;
	}
	
	arch.close();
	return i;
}
void ImpOS() {
	// imprimo obra social
	string coma = " , ";
	string barra = "/";
	string guion = "-";
	string mas = "+";
	string parenA = "(";
	string parenC = ")";
	ObraSocial* os = ArchOS_leer();
	int tam = TamanioArchOS();
	int i = 0;
	cout << "id , obra social" << endl;
	while (i < tam-1) {

		cout << os[i].id << coma << os[i].obra_social << endl;

		i++;
	}
	delete[]os;
	system("pause");
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
		string auxespecialidad, auxactivo;
		int cont = 0;
		arch >> aux.matricula.p1 >> coma >> aux.matricula.p2 >> coma >> aux.matricula.p3 >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> coma >> aux.telefono.pais >> coma >> aux.telefono.area >> coma >> aux.telefono.num >> coma >> auxespecialidad >> coma >> auxactivo;
		
		if (auxespecialidad == "neurologia") {
			aux.especialidad = NEUROLOGIA;
		}
		else if (auxespecialidad == "cardiologia") {
			aux.especialidad = CARDIOLOGIA;
		}
		else { aux.especialidad = PEDIATRIA; }
		if (auxactivo == "true") {
			aux.activo = true;
		}
		else { aux.activo = false; }
			

		ltM_agregar(ltmedico, aux, &tamact);
	}

	arch.close();


	return ltmedico;
}
void ArchM_agregar() {
	string coma = " , ";
	string guion = "-";
	string mas = "+";
	string parenA = "(";
	string parenC = ")";

	fstream arch;

	Medico m;
	string auxmatricula, auxespecialidad, auxactivo;
	cout << "Matricula medico (xx-xxx-xxxx): "; cin >> auxmatricula;
	while (auxmatricula[2]!='-' || auxmatricula[6]!='-' || auxmatricula[11] != NULL) {
		cout << "intente nuevamente." << endl;
		cout << "Matricula medico (xx-xxx-xxxx): "; cin >> auxmatricula;
	}
	cout << "Nombre: "; cin >> m.nombre;
	cout << "Apellido: "; cin >> m.apellido;
	cout << "Telefono: " << "\tcod. Pais: "; cin >> m.telefono.pais; cout << "\t\tcod. Area: "; cin >> m.telefono.area; cout << "\t\tNumero (sin 15): "; cin >> m.telefono.num;
	cout << "Especialidad (neurologia/pediatria/cardiologia): "; cin >> auxespecialidad;
	while (auxespecialidad != "neurologia" && auxespecialidad != "pediatria" && auxespecialidad != "cardiologia") {
		cout << "intente nuevamente." << endl;
		cout << "Especialidad (neurologia/pediatria/cardiologia): "; cin >> auxespecialidad;
	}
	cout << "Activo (true/false): "; cin >> auxactivo;
	while (auxactivo != "true" && auxactivo != "false") {
		cout << "intente nuevamente." << endl;
		cout << "Activo(true / false) : "; cin >> auxactivo;
	}

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
		arch << auxmatricula << coma << m.nombre << coma << m.apellido << coma << mas << m.telefono.pais << parenA << m.telefono.area << parenC << m.telefono.num << coma << auxespecialidad << coma << auxactivo;
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
int TamanioArchMedico() {

	char coma;
	fstream arch;
	arch.open(ArchM, ios::in);

	if (!(arch.is_open()))
		return 0;

	string basura;
	arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
	int i = 0;
	while (arch) {
		//arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
		arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
		i++;
	}
	
	arch.close();
	return i;
}
void ImpMedicos() {
	string coma = " , ";
	string barra = "/";
	string guion = "-";
	string mas = "+";
	string parenA = "(";
	string parenC = ")";
	Medico* m = ArchM_leer();
	//imprimo medicos
	int tam = TamanioArchMedico();
	int i = 0;
	cout << "matricula , nombre , apellido , telefono , especialidad , activo" << endl;
	while (i < tam-1) {
		string auxespecialidad;
		if (m[i].especialidad == NEUROLOGIA) {
			auxespecialidad = "neurologia";
		}
		else if (m[i].especialidad == PEDIATRIA) {
			auxespecialidad = "pediatria";
		}
		else { auxespecialidad = "cardiologia"; }
		string activo;
		if (m[i].activo == true) {
			activo = "true";
		}
		else { activo = "false"; }
		cout << m[i].matricula.p1 << guion << m[i].matricula.p2 << guion << m[i].matricula.p3 << coma << m[i].nombre << coma << m[i].apellido << coma << mas << m[i].telefono.pais << parenA << m[i].telefono.area << parenC << m[i].telefono.num << coma << auxespecialidad << coma << activo << endl;
		i++;
	}
	delete[]m;
	system("pause");
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

		arch >> aux.dni_p.dni >> coma >> coma >> aux.telefono.pais >> coma >> aux.telefono.area >> coma >> aux.telefono.num >> coma >> coma >> aux.celular.pais >> coma >> aux.celular.area >> coma >> aux.celular.num >> coma >> aux.direccion >> coma >> aux.email;

		ltContac_agregar(ltcontac, aux, &tamact);
	}

	arch.close();


	return ltcontac;
}
void ArchContac_agregar(int dni) {
	string coma = " , ";
	string mas = "+";
	string parenA = "(";
	string parenC = ")";

	fstream arch;

	Contacto contacto;
	contacto.dni_p.dni = dni;
	cout << "Telefono: " << "\tcod. Pais: "; cin >> contacto.telefono.pais; cout << "\t\tcod. Area: "; cin >> contacto.telefono.area; cout << "\t\tNumero (sin 15): "; cin >> contacto.telefono.num;
	cout << "Celular: " << "\tcod.Pais: "; cin >> contacto.celular.pais; cout << "\t\tcod.Area: "; cin >> contacto.celular.area; cout << "\t\tNumero(sin 15) : "; cin >> contacto.celular.num;
	cout << "Direccion: "; cin >> contacto.direccion;
	cout << "Email: "; cin >> contacto.email;

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
		arch << contacto.dni_p.dni << coma << mas << contacto.telefono.pais << parenA << contacto.telefono.area << parenC << contacto.telefono.num << coma << mas << contacto.celular.pais << parenA << contacto.celular.area << parenC << contacto.celular.num << coma << contacto.direccion << coma << contacto.email;
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
int TamanioArchContac() {

	char coma;
	fstream arch;
	arch.open(ArchContac, ios::in);

	if (!(arch.is_open()))
		return 0;

	string basura;
	arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
	int i = 0;
	while (arch) {
		//arch >> basura >> coma >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
		arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
		i++;
	}
	
	arch.close();
	return i;
}
void ImpContactos() {
	//imprimo contactos
	string coma = " , ";
	string barra = "/";
	string guion = "-";
	string mas = "+";
	string parenA = "(";
	string parenC = ")";
	Contacto* contac = ArchContac_leer();
	int tam = TamanioArchContac();
	int i = 0;
	cout << "dni_paciente , telefono , celular , direccion , mail" << endl;
	while (i < tam-1) {

		cout << contac[i].dni_p.dni << coma << mas << contac[i].telefono.pais << parenA << contac[i].telefono.area << parenC << contac[i].telefono.num << coma << mas << contac[i].celular.pais << parenA << contac[i].celular.area << parenC << contac[i].celular.num << coma << contac[i].direccion << coma << contac[i].email << endl;
		i++;
	}
	delete[]contac;
	system("pause");
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

		arch >> aux.dni_p.dni >> coma >> aux.solicitado.dia >> coma >> aux.solicitado.mes >> coma >> aux.solicitado.anio >> coma >> aux.turno.dia >> coma >> aux.turno.mes >> coma >> aux.turno.anio >> coma >> aux.presento >> coma >> aux.matricula_m.matricula.p1 >> coma >> aux.matricula_m.matricula.p2 >> coma >> aux.matricula_m.matricula.p3;

		ltConsul_agregar(ltconsul, aux, &tamact);
	}

	arch.close();


	return ltconsul;
}
void ArchConsul_agregar(Consulta consulta) {
	string coma = " , ";
	string barra = "/";
	string guion = "-";
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
		arch << consulta.dni_p.dni << coma << consulta.solicitado.dia << barra << consulta.solicitado.mes << barra << consulta.solicitado.anio << coma << consulta.turno.dia << barra << consulta.turno.mes << barra << consulta.turno.anio << coma << consulta.presento << coma << consulta.matricula_m.matricula.p1 << guion << consulta.matricula_m.matricula.p2 << guion << consulta.matricula_m.matricula.p3;
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
		//arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura >>coma>> basura>>coma>> basura;
		arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
		i++;
	}
	
	arch.close();
	return i;
}
void ImpConsultas() {
	string coma = " , ";
	string barra = "/";
	string guion = "-";
	string mas = "+";
	string parenA = "(";
	string parenC = ")";
	Consulta* consul = ArchConsul_leer();
	//imprimo consultas
	int tam = TamanioArchConsul();
	int i = 0;
	cout << "dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med" << endl;
	while (i < tam-1) {
		cout << consul[i].dni_p.dni << coma << consul[i].solicitado.dia << barra << consul[i].solicitado.mes << barra << consul[i].solicitado.anio << coma << consul[i].turno.dia << barra << consul[i].turno.mes << barra << consul[i].turno.anio << coma << consul[i].presento << coma << consul[i].matricula_m.matricula.p1 << guion << consul[i].matricula_m.matricula.p2 << guion << consul[i].matricula_m.matricula.p3 << endl;
		i++;
	}
	delete[]consul;
	system("pause");
}
int DiezAniosCosulta(int solicitado, int presento) {

	time_t t = time(NULL);
	struct tm* anio = localtime(&t);
	int diferencia;
	
		diferencia = anio->tm_year - (solicitado - 1900);
		if (diferencia > 10 && presento == 0) {
			return 1;
		}
		else if (diferencia < 10 && presento == 0) {
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
		arch >> aux.dni_p.dni >> coma >> aux.solicitado.dia >> coma >> aux.solicitado.mes >> coma >> aux.solicitado.anio >> coma >> aux.turno.dia >> coma >> aux.turno.mes >> coma >> aux.turno.anio >> coma >> aux.presento >> coma >> aux.matricula_m.matricula.p1 >> coma >> aux.matricula_m.matricula.p2 >> coma >> aux.matricula_m.matricula.p3;
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
	string guion = "-";
	fstream arch;
	int tamanio = TamanioArchConsul();
	Consulta* c = ArchConsul_leer();
	int i = 0;
	int cont = 0;
	while (i < tamanio) {
		if (consulta.dni_p.dni == c[i].dni_p.dni) {
			cont++;
			for (int j = i; j < tamanio; j++) {
				c[j].dni_p.dni = c[j + 1].dni_p.dni;
				c[j].solicitado.dia = c[j + 1].solicitado.dia;
				c[j].solicitado.mes = c[j + 1].solicitado.mes;
				c[j].solicitado.anio = c[j + 1].solicitado.anio;
				c[j].turno.dia = c[j + 1].turno.dia;
				c[j].turno.mes = c[j + 1].turno.mes;
				c[j].turno.anio = c[j + 1].turno.anio;
				c[j].presento = c[j + 1].presento;
				c[j].matricula_m.matricula = c[j + 1].matricula_m.matricula;
			}
			break;
		}
		i++;
	}
	i = 0;
	arch.open(ArchConsul, ios::out);
	//if (!(arch.is_open())) { return; }
	arch << "dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med" << endl;
	while (i < tamanio - cont) {
		arch << c[i].dni_p.dni << coma << c[i].solicitado.dia << barra << c[i].solicitado.mes << barra << c[i].solicitado.anio << coma << c[i].turno.dia << barra << c[i].turno.mes << barra << c[i].turno.anio << coma << c[i].presento << coma << c[i].matricula_m.matricula.p1 << guion << c[i].matricula_m.matricula.p2 << guion << c[i].matricula_m.matricula.p3 << endl;
		i++;
	}
	arch.close();
}
void ArchConsul_eliminados( Consulta consulta) {
	const char coma = ',';
	const char barra = '/';
	const char guion = '-';

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
		arch << consulta.dni_p.dni << coma << consulta.solicitado.dia << barra << consulta.solicitado.mes << barra << consulta.solicitado.anio << coma << consulta.turno.dia << barra << consulta.turno.mes << barra << consulta.turno.anio << coma << consulta.presento << coma << consulta.matricula_m.matricula.p1 << guion << consulta.matricula_m.matricula.p2 << guion << consulta.matricula_m.matricula.p3 << endl;
	}
	arch.close();


	return;
}

/*--------OTRAS FUNCIONES----------*/
void menu() {//falta titulo de cada imprimir

	int opc = 0;
	while (opc != 9) {
		system("cls");
		cout << "---------MENU-HOSPITAL--------" << endl;
		cout << "1) Menu Pacientes." << endl;
		cout << "2) Menu Medicos." << endl;
		cout << "3) Menu Historias Clinicas." << endl;
		cout << "9) Salir." << endl;
		cout << "->";
		cin >> opc;

		switch (opc) {
		case 1:
			while (opc != 9) {
				system("cls");
				cout << "------------MENU-PACIENTES------------" << endl;
				cout << "1) Imprimir Pacientes." << endl;
				cout << "2) Imprimir Contactos de pacientes." << endl;
				cout << "3) Buscar e imprimir paciente." << endl;
				cout << "4) Agregar nuevo Paciente y Contacto." << endl;
				cout << "9) Volver al menu." << endl;
				cout << "->";
				cin >> opc;
				switch (opc) {
				case 1:
					system("cls");
					ImpPacientes();
					break;
				case 2:
					system("cls");
					ImpContactos();
					break;
				case 3://falta
					break;
				case 4:
					system("cls");
					ArchPaciente_agregar();
					break;
				}
			}opc = 0;
			break;
		case 2:
			while (opc != 9) {
				system("cls");
				cout << "------MENU-MEDICOS------" << endl;
				cout << "1) Imprimir Medicos." << endl;
				cout << "2) Agregar nuevo Medico." << endl;
				cout << "9) Volver al menu." << endl;
				cout << "->";
				cin >> opc;
				switch (opc) {
				case 1:
					system("cls");
					ImpMedicos();
					break;
				case 2:
					system("cls");
					ArchM_agregar();
					break;
				}
			}opc = 0;
			break;
		case 3:
			while (opc != 9) {
				system("cls");
				cout << "----MENU-H.CLINICAS----" << endl;
				cout << "1) Imprimir Consultas." << endl;
				cout << "2) Actualizar archivo (elimina los que fueron citados para hace más de diez años y no concurrieron a la consulta)." << endl;
				cout << "9) Volver al menu." << endl;
				cout << "->";
				cin >> opc;
				switch (opc) {
				case 1:
					system("cls");
					ImpConsultas();
					break;
				case 2:
					system("cls");
					ArchConsul_RedireccionarEliminado();
					break;
				}
			}opc = 0;
			break;
		}
	}
}
void IoF() //internado o fallecido
{
	Paciente* aux = ArchPaciente_leer();
	int tam = TamanioArchPaciente();

	Consulta* aux1 = ArchConsul_leer();
	//si es 1: hace mas de 10 anios saco el turno y no se presento. cuando retorna 2: fueron citados hace menos de diez anios y no se presento 

	for (int i = 0; i < tam; i++)
	{

		int DiezAnios = DiezAniosCosulta(aux1[i].solicitado.anio, aux1[i].presento);
		if (DiezAnios == 2 && aux[i].estado == FALLECIDO)
		{
			cout << "FALLECIDO" << endl;
		}
		else if (DiezAnios == 2 && aux[i].estado == INTERNADO)
		{
			cout << "INTERNADO" << endl;
		}
	}
}

/*void UltimoMedico()
{
	fstream archivo, arch;
	Medico* aux;
	Paciente* auxx;
	Consulta* aux1 = ArchConsul_leer();

	int i = 0;
	int tam = TamanioArchConsul();
	int DiezAnios;

	arch.open(ArchConsul, ios::in);
	if (!(arch.is_open())) { return; }

	while (arch)
	{
		DiezAnios = DiezAniosCosulta(aux1[i].solicitado.anio, aux1[i].presento);
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

}*/

/*void Secretaria()
{
	fstream archivo;
	fstream arch;
	Paciente* aux;
	Paciente paciente;
	int tam = TamanioArchConsul();

	archivo.open(ArchP, ios::in); //primero lo leo, lo guardo adentro de un puntero
	arch.open(ArchConsul, ios::in);


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

}*/
