#include "iri.cpp"
#include "dummy.cpp"
#include <iostream>

int main() {

    Fecha natalicio1 = { 6,9,2000 };
    Fecha natalicio2 = { 19,6,2001 };

    ObraSocial os1 = { 9,"medife" };
    ObraSocial os2 = { 10,"osde" };

    Paciente* p1 = new Paciente{ 42850107, "facundo", "rimmele", 'M',natalicio1, "grave", os1 };
    Paciente* p2 = new Paciente{ 39999999, "sebastian", "rimmele", 'M', natalicio2, "espera",os2 };

    Archpaciente_In();

    system("pause");
    return EXIT_SUCCESS;
}
