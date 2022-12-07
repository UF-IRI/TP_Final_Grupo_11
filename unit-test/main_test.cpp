#include "gmock/gmock.h"
#include "dummy.h"

//testeo de tamanio del archivo y de creacion de archivos

namespace foobar::tests {
	TEST(TamArch_Paciente_Test, Test_Caso1) {
		int cant = 3;
		int* num = &cant;
		Paciente* test = new Paciente[*num];

		test[0].nombre = "Maitena";
		test[0].apellido = "Righetti";
		test[0].dni = 44481221;
		test[0].id_os.obra_social = "OSDE";
		test[0].id_os.id = 1;
		test[0].estado = INTERNADO;
		test[0].natalicio.dia = 5;
		test[0].natalicio.mes = 10;
		test[0].natalicio.anio = 2002;
		test[0].sexo = 'F';

		test[1].nombre = "Facundo";
		test[1].apellido = "Rimmele";
		test[1].dni = 40123445;
		test[1].id_os.obra_social = "INSTITUTO";
		test[1].id_os.id = 2;
		test[1].estado = FALLECIDO;
		test[1].natalicio.dia = 22;
		test[1].natalicio.mes = 9;
		test[1].natalicio.anio = 2000;
		test[1].sexo = 'M';

		test[2].nombre = "Bautista";
		test[2].apellido = "Rach";
		test[2].dni = 44223444;
		test[2].id_os.obra_social = "MEDICUS";
		test[2].id_os.id = 3;
		test[2].estado = INTERNADO;
		test[2].natalicio.dia = 10;
		test[2].natalicio.mes = 8;
		test[2].natalicio.anio = 2003;
		test[2].sexo = 'M';

		cant = TamanioArchPaciente();

		ASSERT_THAT(3, cant);
	}

	TEST(Crear_Paciente_Test, Test_Caso2) {

		int cant = 3;
		int* num = &cant;
		Paciente* test = new Paciente[*num];

		test[0].nombre = "Maitena";
		test[0].apellido = "Righetti";
		test[0].dni = 44481221;
		test[0].id_os.obra_social = "OSDE";
		test[0].id_os.id = 1;
		test[0].estado = INTERNADO;
		test[0].natalicio.dia = 5;
		test[0].natalicio.mes = 10;
		test[0].natalicio.anio = 2002;
		test[0].sexo = 'F';

		test[1].nombre = "Facundo";
		test[1].apellido = "Rimmele";
		test[1].dni = 40123445;
		test[1].id_os.obra_social = "INSTITUTO";
		test[1].id_os.id = 2;
		test[1].estado = FALLECIDO;
		test[1].natalicio.dia = 22;
		test[1].natalicio.mes = 9;
		test[1].natalicio.anio = 2000;
		test[1].sexo = 'M';

		test[2].nombre = "Bautista";
		test[2].apellido = "Rach";
		test[2].dni = 44223444;
		test[2].id_os.obra_social = "MEDICUS";
		test[2].id_os.id = 3;
		test[2].estado = INTERNADO;
		test[2].natalicio.dia = 10;
		test[2].natalicio.mes = 8;
		test[2].natalicio.anio = 2003;
		test[2].sexo = 'M';

		bool creado = ArchPaciente_crear(); //true: se creo bien

		ASSERT_THAT(test[0].dni, creado);
	}

	TEST(Crear_OS_Test, Test_Caso3) {

		int cant = 3;
		int* num = &cant;
		ObraSocial* test = new ObraSocial[*num];

		test[0].obra_social = "OSDE";
		test[0].id = 1;

		test[1].obra_social = "INSTITUTO";
		test[1].id = 2;

		test[2].obra_social = "MEDICUS";
		test[2].id = 3;

		bool creado = ArchOS_crear(); //true: se creo bien

		ASSERT_THAT(test[1].id, creado);
	}
}