#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	int edad, sel, tamano, cont1, cont2, gen=0, esp=0, repetir=2;

	do {
		tamano = rand()%100 + 1;
		int n[100];
		cont1=0, cont2=0;

		for(int i = 0; i < tamano; i++) {
			edad = rand()% 82 + 18;
			n[i] = edad;
			if(edad < 60) {
				cont1+=1;
			} else {
				cont2+=1;
			}
		}

		int general[100], especial[100];
		cont1=0, cont2=0;
		for(int i = 0; i < tamano; i++) {
			if(n[i] < 60) {
				general[cont1] = n[i];
				cont1+=1;
			} else {
				especial[cont2] = n[i];
				cont2+=1;
			}
		}
		do {
		    repetir = 1;
			cout << "\n\t|BancaMex|" << endl
			     << "1. Mostrar fila inicial" << endl
			     << "2. Mostrar fila general" << endl
			     << "3. Mostrar fila especial" << endl
			     << "4. Atender" << endl
			     << "5. Salir" << endl;
			cin >> sel;
			switch(sel) {
			case 1:
				cout << tamano << " personas" << endl;
				cout << "[ ";
				for(int i = 0; i < tamano; i++) {
					cout << n[i] << " ";
				}
				cout << "]" << endl;
				break;
			case 2:
				cout << cont1 << " personas" << endl;
				cout << "[ ";
				for(int i = 0; i < cont1; i++) {
					cout << general[i] << " ";
				}
				cout << "]" << endl;
				break;
			case 3:
				cout << cont2 << " personas" << endl;
				cout << "[ ";
				for(int i = 0; i < cont2; i++) {
					cout << especial[i] << " ";
				}
				cout << "]" << endl;
				break;
			case 4:
				gen = 0, esp = 0;
				while(gen < cont1 or esp < cont2) {
					cout << "Atendiendo a personas con edad: ";
					
					if(esp < cont2) {
						cout << especial[esp] << " ";
						if(esp+1 < cont2) {
							cout << especial[esp+1] << " ";
						}
					}
					if(gen < cont1) {
						cout << general[gen] << " ";
					}
					gen+=1;
					esp+=2;
					cout << endl;
				}
				cout << "Repetir lista?" << endl;
				cout << "1. Si" << endl;
				cout << "2. No" << endl;
				cin >> repetir;
				break;
			case 5:
				cout << "Adios ;) !";
				repetir = 2;
				break;
			default:
				cout << "Opcion no valida";
				break;
			}
		} while(sel != 5 and repetir == 1);
	} while(sel!=5);

	return 0;
}