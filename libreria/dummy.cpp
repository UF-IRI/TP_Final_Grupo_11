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
	cout << "Natalicio:" << "\tDia: "; cin >> p.natalicio.dia; cout << "\t\tMes: "; cin >> p.natalicio.mes; cout << "\t\tA�o: "; cin >> p.natalicio.anio;
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
void ArchUMxP_agregar(Medico m, Paciente p, Contacto c) {
	string coma = " , ";
	string mas = " + ";
	string parenA = "(";
	string parenC = ")";
	string barra = "/";
	string guion = "-";
	string tab = "\t";
	fstream arch;

	arch.open(ArchUMxP, ios::in);
	if (!(arch.is_open())) {

		bool ok = ArchUMxP_crear();
		if (ok == false) {
			arch.close();
			return;
		}
	}
	arch.close();

	string auxespecialidad;
	if (m.especialidad == NEUROLOGIA) {
		auxespecialidad = "neurologia";
	}
	else if (m.especialidad == CARDIOLOGIA) {
		auxespecialidad = "cardiologia";
	}
	else { auxespecialidad = "pediatria"; }
	string auxactivo;
	if (m.activo == true) {
		auxactivo = "true";
	}
	else { auxactivo = "false"; }

	arch.open(ArchUMxP, ios::app);
	if (arch.is_open()) {
		arch << tab << tab << p.dni << coma << p.nombre << coma << p.apellido << coma << mas << c.telefono.pais << parenA << c.telefono.area << parenC << c.telefono.num << coma << p.id_os.obra_social << tab << tab << tab << m.matricula.p1 << guion << m.matricula.p2 << guion << m.matricula.p3 << coma << m.nombre << coma << m.apellido << coma << mas << m.telefono.pais << parenA << m.telefono.area << parenC << m.telefono.num << coma << auxespecialidad << coma << auxactivo << endl;
	}
	arch.close();



}
bool ArchUMxP_crear() {
	const char coma = ',';
	fstream arch;
	arch.open(ArchUMxP, ios::out);

	if (arch.is_open()) {
		arch << "PACIENTE: dni_pac , nombre , apellido ,   telefono   , obra social ,  MEDICO: matricula , nombre , apellido ,   telefono   , especialidad , activo" << endl;
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
	bool archivo;
	
	Consulta aux;
	ifstream arch;
	arch.open(ArchConsul, ios::in);
	if (!(arch.is_open())) { return; }
	
	string basura;
	arch >> basura >> coma >> basura >> coma >> basura >> coma >> basura >> coma >> basura;
	cout << "Este proceso puede tardar unos segundos..." << endl;
	while (arch) {
		arch >> aux.dni_p.dni >> coma >> aux.solicitado.dia >> coma >> aux.solicitado.mes >> coma >> aux.solicitado.anio >> coma >> aux.turno.dia >> coma >> aux.turno.mes >> coma >> aux.turno.anio >> coma >> aux.presento >> coma >> aux.matricula_m.matricula.p1 >> coma >> aux.matricula_m.matricula.p2 >> coma >> aux.matricula_m.matricula.p3;
		diferencia = DiezAniosCosulta(aux.solicitado.anio,aux.presento);
		if (diferencia == 1) {
			
			archivo = ArchConsul_eliminados(aux);
			if (archivo == false) { cout << "no se pudo archivar 'consulta eliminados'."; return; }
			ArchConsul_eliminar(aux);
			
		}
	}
	arch.close();
	system("cls");
	cout << "Se ARCHIVO correctmante." << endl;
	system("pause");

}
void ArchConsul_eliminar(Consulta consulta) {

	string coma = " , ";
	string barra = "/";
	string guion = "-";
	fstream arch;
	int tamanio = TamanioArchConsul();
	Consulta* c = ArchConsul_leer();
	int i = 0;
	while (i < tamanio) {
		if (consulta.dni_p.dni == c[i].dni_p.dni) {
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
	c[tamanio].dni_p.dni =NULL;
	c[tamanio].solicitado.dia = NULL;
	c[tamanio].solicitado.mes = NULL;
	c[tamanio].solicitado.anio = NULL;
	c[tamanio].turno.dia = NULL;
	c[tamanio].turno.mes = NULL;
	c[tamanio].turno.anio = NULL;
	c[tamanio].presento = NULL;
	c[tamanio].matricula_m.matricula.p1 = NULL;
	c[tamanio].matricula_m.matricula.p2 = NULL;
	c[tamanio].matricula_m.matricula.p3 = NULL;

	arch.open(ArchConsul, ios::out);
	//if (!(arch.is_open())) { return; }
	arch << "dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med" << endl;
	i = 0;
	tamanio--;
	while (i < tamanio) {
		arch << c[i].dni_p.dni << coma << c[i].solicitado.dia << barra << c[i].solicitado.mes << barra << c[i].solicitado.anio << coma << c[i].turno.dia << barra << c[i].turno.mes << barra << c[i].turno.anio << coma << c[i].presento << coma << c[i].matricula_m.matricula.p1 << guion << c[i].matricula_m.matricula.p2 << guion << c[i].matricula_m.matricula.p3 << endl;
		i++;
	}
	arch.close();
}
bool ArchConsul_eliminados( Consulta consulta) {
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
		else { cout << "No abrio el archivo 'consulta eliminados'."; return false; }
		
	}
	arch.close();
	arch.open(ArchCE, ios::app);
	if (arch.is_open()) {
		arch << consulta.dni_p.dni << coma << consulta.solicitado.dia << barra << consulta.solicitado.mes << barra << consulta.solicitado.anio << coma << consulta.turno.dia << barra << consulta.turno.mes << barra << consulta.turno.anio << coma << consulta.presento << coma << consulta.matricula_m.matricula.p1 << guion << consulta.matricula_m.matricula.p2 << guion << consulta.matricula_m.matricula.p3 << endl;
	}
	arch.close();


	return true;
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
				cout << "1) Imprimir Pacientes." << endl; //listo
				cout << "2) Imprimir Contactos de pacientes." << endl; //listo
				cout << "3) Agregar nuevo Paciente y Contacto." << endl; //listo
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
				case 3:
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
				cout << "1) Imprimir Medicos." << endl; //listo
				cout << "2) Agregar nuevo Medico." << endl; //listo
				cout << "3) Ordenar archivo con Pacientes y ultimos Medicos." << endl; //no se que error tiene pero andaba
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
				case 3:
					system("cls");
					PacienteXMedico();
					break;
				}
			}opc = 0;
			break;
		case 3:
			while (opc != 9) {
				system("cls");
				cout << "----MENU-H.CLINICAS----" << endl;
				cout << "1) Imprimir Consultas." << endl; //listo
				cout << "2) Actualizar archivo (elimina los que fueron citados para hace m�s de diez a�os y no concurrieron a la consulta)." << endl; //a terminar
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
void PacienteXMedico() {
	Paciente* p = ArchPaciente_leer();
	Contacto* contac = ArchContac_leer();
	Medico* m = ArchM_leer();
	Consulta* consul = ArchConsul_leer();

	Fecha basurafecha, guardofecha;
	guardofecha.dia = 0;
	guardofecha.mes = 0;
	guardofecha.anio = 0;

	int tam_p = TamanioArchPaciente();
	int tam_consul = TamanioArchConsul();
	int tam_contac = TamanioArchContac();
	int tam_m = TamanioArchMedico();
	int pos_p = -1, pos_consul = -1, pos_m = -1, pos_contac = -1;
	int np, nconsul, ncontac, nm;

	//Paciente* aux_p = new Paciente[tam_p];
	cout << "Este proceso puede tardar unos segundos..." << endl;
	for (np = 0; np < tam_p; np++) {
		basurafecha.dia = 0;
		basurafecha.mes = 0;
		basurafecha.anio = 0;

		for (nconsul = 0; nconsul < tam_consul; nconsul++) {
			if (p[np].dni == consul[nconsul].dni_p.dni) {
				basurafecha.dia = consul[nconsul].turno.dia;
				basurafecha.mes = consul[nconsul].turno.mes;
				basurafecha.anio = consul[nconsul].turno.anio;
				pos_p = np;
				if (basurafecha.anio >= guardofecha.anio && basurafecha.mes >= guardofecha.mes && basurafecha.dia > guardofecha.dia) {
					guardofecha.dia = basurafecha.dia;
					guardofecha.mes = basurafecha.mes;
					guardofecha.anio = basurafecha.anio;
					pos_consul = nconsul;
				}
			}
		}
		for (nm = 0; nm < tam_m; nm++) {
			if (m[nm].matricula.p1 == consul[pos_consul].matricula_m.matricula.p1 && m[nm].matricula.p2 == consul[pos_consul].matricula_m.matricula.p2 && m[nm].matricula.p3 == consul[pos_consul].matricula_m.matricula.p3) {
				pos_m = nm;
				break;
			}
		}
		for (ncontac = 0; ncontac < tam_contac; ncontac++) {
			if (contac[ncontac].dni_p.dni == p[pos_p].dni) {
				pos_contac = ncontac;
				break;
			}
		}
		if(pos_p != -1){
			ArchUMxP_agregar(m[pos_m], p[pos_p], contac[pos_contac]);
		}
		
		pos_p = -1, pos_consul = -1, pos_m = -1, pos_contac = -1;
		guardofecha.dia = 0;
		guardofecha.mes = 0;
		guardofecha.anio = 0;
	}
	system("cls");
	cout << "Se ARCHIVO correctmante." << endl;
	system("pause");

	//delete[] aux_p;
}
void Secretaria()
{
	Paciente* P = ArchPaciente_leer();
	bool respuesta;

	int tam = TamanioArchPaciente();

	Paciente aux;

	cout << "Desea volver?" << endl;
	cin >> respuesta;

	if (respuesta == true)
	{
		//desea volver
		cout << "RETORNA" << endl;
		cout << "Indique obra social: " << endl;
		cin >> aux.id_os.obra_social;
		for (int i = 0; i < tam; i++) //recorre pacientes
		{
			if (P[i].id_os.obra_social != aux)
			{
				//informa nueva cobertura
				if (P[i].id_os.obra_social == "OSDE")
				{
					P[i].id_os.id = 1;
				}
				if (P[i]id_os.obra_social == "INSTITUTO")
				{
					P[i].id_os.id = 2;
				}
				if (P[i].id_os.obra_social == "MEDICUS")
				{
					P[i].id_os.id = 3;
				}
				if (P[i].id_os.obra_social == "SWISS MEDICAL")
				{
					P[i].id_os.id = 4;
				}
			}
		}
	}
	else {
		cout << "La obra social sigue siendo la misma que en la ultima consulta" << endl;
	}
}