//#include "iri.cpp"
#include "dummy.h"


int main() {

    

    Fecha natalicio1 = { 6,9,2000 };
    Fecha natalicio2 = { 9,9,1995 };
    Fecha solicitado = { 5,7,2021 };
    Fecha turno = { 9,7,2021 };

    ObraSocial os1 = { 9,"medife" };
    ObraSocial os2 = { 10,"osde" };

    Paciente p1 = { 42850107, "Facundo", "Rimmele", 'M',natalicio1, "Grave", os1 };

    Medico m1 = { "12-345-1234", "Sebastian", "Rimmele", "+54(299)5808204", "Cardiologo", "true" };

    //Contacto contac1 = { 42850107, "+54(299)5808204", "+54(299)5808205", "Charcas", "facurimmele@gmail.com" };

    //Consulta consul1 = { 42850107,solicitado,turno,"S","12-345-1234" };

    Paciente* p;
    ObraSocial* os;
    Medico* m;
    Contacto* contac;
    Consulta* consul;


    ArchPaciente_agregar(p1);
    //ArchOS_agregar(os1);
    //ArchM_agregar(m1);
    //ArchContac_agregar(contac1);
    //ArchConsul_agregar(consul1);

    p = ArchPaciente_leer();
    os = ArchOS_leer();
    m = ArchM_leer();
    contac = ArchContac_leer();
    consul = ArchConsul_leer();
    
    //ArchConsul_RedireccionarEliminado(); //busca los que fueron citados para hace más de diez años y no concurrieron a la consulta, los guarda en un nuevo archivo y los elimina del actual

    int i = 0;
    string coma = " , ";
    string barra = "/";
/*
    //imprimo personas
    while (i < 10) {

        cout << p[i].dni << coma << p[i].nombre << coma << p[i].apellido << coma << p[i].sexo << coma << p[i].natalicio.dia << barra << p[i].natalicio.mes << barra << p[i].natalicio.anio << coma << p[i].estado << coma << p[i].id_os.obra_social << endl;
        i++;
    } 
    cout << endl;
    i = 0;
    //imprimo obra social
    while (i < 5) {

        cout << os[i].id << coma << os[i].obra_social << endl;

        i++;
    }
    cout << endl;
    i = 0;
    //imprimo contactos
    while (i<5) {

        cout << contac[i].dni_p.dni << coma << contac[i].telefono << coma << contac[i].celular << coma << contac[i].direccion << coma << contac[i].email << endl;
        i++;
    }
    cout << endl;
    i = 0;
    //imprimo medicos
    while (i < 5) {

        cout << m[i].matricula << coma << m[i].nombre << coma << m[i].apellido << coma << m[i].telefono << coma << m[i].especialidad << coma << m[i].activo << endl;
        i++;
    }
 */   cout << endl;
    i = 0;
    //imprimo consultas
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
