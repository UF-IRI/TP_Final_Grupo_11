#include "iri.cpp"
#include "dummy.cpp"
#include <iostream>

int main() {

    Fecha natalicio1 = { 6,9,2000 };
    Fecha natalicio2 = { 9,9,1995};

    ObraSocial os1 = { 9,"medife" };
    ObraSocial os2 = { 10,"osde" };

    Paciente p1 = { 42850107, "facundo", "rimmele", 'M',natalicio1, "grave", os1 };
    Medico m1 = { "12-345-1234", "sebastian", "rimmele", "+54(299)5808204", "cardiologo", "true"};

    Paciente* p;
    ObraSocial* os;
    Medico* m;
    Contacto* contac;
    Consulta* consul;


    //ArchPaciente_agregar(p2);
    //ArchM_agregar(m1);

    p = ArchPaciente_leer();
    os = ArchOS_leer();
    m = ArchM_leer();
    contac = ArchContac_leer();
    consul = ArchConsul_leer();
    
    int i = 0;
    string coma = " , ";
    string barra = "/";

    while (i < 10) {

        cout << p[i].dni << coma << p[i].nombre << coma << p[i].apellido << coma << p[i].sexo << coma << p[i].natalicio.dia << barra << p[i].natalicio.mes << barra << p[i].natalicio.anio << coma << p[i].estado << coma << p[i].id_os.obra_social << endl;
        i++;
    }
    cout << endl;
    i = 0;
    while (i < 5) {

        cout << os[i].id << coma << os[i].obra_social << endl;

        i++;
    }
    cout << endl;
    i = 0;
    
    while (i<5) {

        cout << contac[i].dni_p.dni << coma << contac[i].telefono << coma << contac[i].celular << coma << contac[i].direccion << coma << contac[i].email << endl;
        i++;
    }
    cout << endl;
    i = 0;

    while (i < 5) {

        cout << m[i].matricula << coma << m[i].nombre << coma << m[i].apellido << coma << m[i].telefono << coma << m[i].especialidad << coma << m[i].activo << endl;
        i++;
    }
    cout << endl;
    i = 0;
    while (i < 5) {
        cout << consul[i].dni_p.dni << coma << consul[i].solicitado.dia << barra << consul[i].solicitado.mes << barra << consul[i].solicitado.anio << coma << consul[i].turno.dia << barra << consul[i].turno.mes << barra << consul[i].turno.anio << coma << consul[i].presento << coma << consul[i].matricula_m.matricula << endl;
        i++;
    }

    delete[] p;
    delete[] os;
    delete[] m;
    delete[] contac;
    delete[] consul;
    
    
    return EXIT_SUCCESS;
}
