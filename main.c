//****************** LIBRERIAS *******************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

//************** VARIABLES GLOBALES **************
int cedula;
int i,opc,n=0,continuar='Y',pos,opcion=1,clientes_registrados=0;

//************* FUNCIONES PROTOTIPO **************
int CargarDatos ();
void ImprimirLista();
int menu ();
void Busqueda();
void SetColor(int ForgC);
int error();
int modificar();

//************* COLOR DE TEXTO **************
void SetColor(int ForgC){
	
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
	}

//************* ESTRUCTURA DE DATOS **************
struct datos {
	char nombre [100];
	int CI;
	char telefono [20];
	char direccion [100];
	int eliminar;
} cliente[500]={ " ",0," "," ",0, };

//*************** FUNCION BUSCAR ******************
void Busqueda() {
	int pos1,j;
	system ("cls");
	SetColor(14);
	printf("\n\t\t ************************************\n");
	printf("\n\t\t %c BUSQUEDA DE CLIENTE %c \n",4,4);
	printf("\n\t\t ************************************\n");SetColor(11);
	printf ("\nINGRESE LA CEDULA DEL CLIENTE A BUSCAR: "); scanf("%d",&cedula);
	
	for (i=0; i<n;i++){
		if(cedula == cliente[i].CI){
			pos1=i;
			i=n;
		}
		else pos1=-1;
	}
	for (j=0; j<n;j++){
		if (pos1>=0 && cliente[j].eliminar == 1){
			printf(" \n\t EL CLIENTE HA SIDO ELIMINADO");
			j=n;
		}
		else if (pos1 >=0 && cliente[j].eliminar == 0){
			printf("\n\t\t NOMBRE: %s", cliente [pos1].nombre);
			printf("\n\t\t CEDULA: %d", cliente [pos1].CI);
			printf("\n\t\t TELEFONO: %s", cliente [pos1].telefono);
			printf("\n\t\t DIRECCION: %s", cliente [pos1].direccion);
			j=n;
		}
		else{
			printf(" \n\t EL CLIENTE NO HA SIDO REGISTRADO");
			j=n;
		}
	}
	getch();
}

//******************* FUNCION ELIMINAR ******************

void eliminar( ) {
	system ("cls");
	SetColor(14);
	printf("\n\t\t ************************************\n");
	printf("\n\t\t %c ELIMINAR REGISTRO %c \n",4,4);
	printf("\n\t\t ************************************\n");
	SetColor(11);
	
	if(clientes_registrados==0) printf("\n\n\n\n\n\n\n\n\t\tNO SE HA REGISTRADO NINGUN CLIENTE");
	else{
		printf ("\nIngrese La Cedula Del Cliente A Eliminar: ");
		scanf("%d",&cedula);
	for (i=0; i<n;i++){
		if(cedula == cliente[i].CI && cliente[i].eliminar==0){
			pos=i;i=n;
		}
		else pos=-1;
	}
	if (pos!=-1){
		printf("\n\t\t NOMBRE: %s", cliente [pos].nombre);
		printf("\n\t\t CEDULA: %d", cliente [pos].CI);
		printf("\n\t\t TELEFONO: %s", cliente [pos].telefono);
		printf("\n\t\t DIRECCION: %s", cliente [pos].direccion);
		printf("\n\n\n\t\t Desea Eliminar Registro (Y/N): ");
		scanf("%s",&opc);
		if (toupper(opc)=='Y'){
			cliente[pos].eliminar=1;
			printf("\n\n\t\tRegistro Eliminado...");
			clientes_registrados--;
		}
		else
		printf("\n\n\t\tNigun Registro Eliminado...");
	}
	else
	printf("\n\n\t\tRegistro No existe");
	}
	getch();
}

//******************* FUNCION DIBUJAR ******************
int dibujar(int opcion){
	switch (opcion){
		case 1: system ("cls");
			SetColor(14);
			printf("\n\t\t******************************************\n");
			printf("\n\t\t %c REGISTRO DE CLIENTES %c \n",4,4);
			printf("\n\t\t******************************************\n\n");
			SetColor(11);
			printf(" \t%c 1) Registrar Cliente\n\n",16);
			SetColor(14);
			printf(" 2) Buscar Cliente\n\n");
			printf(" 3) Imprimir Listado\n\n");
			printf(" 4) Eliminar Cliente\n\n");
			printf(" 5) Modificar Cliente\n\n");
			printf(" 6) Salir del Registro\n\n\n");
			SetColor(11);
			printf(" Seleccione Una Opcion: ");
			break;
		case 2: system ("cls");
			SetColor(14);
			printf("\n\t\t******************************************\n");
			printf("\n\t\t %c REGISTRO DE CLIENTES %c \n",4,4);
			printf("\n\t\t******************************************\n\n");
			printf(" 1) Registrar Cliente\n\n");SetColor(11);
			printf(" \t%c 2) Buscar Cliente\n\n",16);
			SetColor(14);
			printf(" 3) Imprimir Listado\n\n");
			printf(" 4) Eliminar Cliente\n\n");
			printf(" 5) Modificar Cliente\n\n");
			printf(" 6) Salir del Registro\n\n\n");
			SetColor(11);
			printf(" Seleccione Una Opcion: ");
			break;
		case 3: system ("cls");
			SetColor(14);
			printf("\n\t\t******************************************\n");
			printf("\n\t\t %c REGISTRO DE CLIENTES %c \n",4,4);
			printf("\n\t\t******************************************\n\n");
			printf(" 1) Registrar Cliente\n\n");
			printf(" 2) Buscar Cliente\n\n");
			SetColor(11);
			printf(" \t%c 3) Imprimir Listado\n\n",16);
			SetColor(14);
			printf(" 4) Eliminar Cliente\n\n");
			printf(" 5) Modificar Cliente\n\n");
			printf(" 6) Salir del Registro\n\n\n");
			SetColor(11);
			printf(" Seleccione Una Opcion: ");
			break;
		case 4: system ("cls");
			SetColor(14);
			printf("\n\t\t******************************************\n");
			printf("\n\t\t %c REGISTRO DE CLIENTES %c \n",4,4);
			printf("\n\t\t******************************************\n\n");
			printf(" 1) Registrar Cliente\n\n");
			printf(" 2) Buscar Cliente\n\n");
			printf(" 3) Imprimir Listado\n\n");
			SetColor(11);
			printf(" \t%c 4) Eliminar Cliente\n\n",16);
			SetColor(14);
			printf(" 5) Modificar Cliente\n\n");
			printf(" 6) Salir del Registro\n\n\n");
			SetColor(11);
			printf(" Seleccione Una Opcion: ");
			break;
		case 5: system ("cls");
			SetColor(14);
			printf("\n\t\t******************************************\n");
			printf("\n\t\t %c REGISTRO DE CLIENTES %c \n",4,4);
			printf("\n\t\t******************************************\n\n");
			printf(" 1) Registrar Cliente\n\n");
			printf(" 2) Buscar Cliente\n\n");
			printf(" 3) Imprimir Listado\n\n");
			printf(" 4) Eliminar Cliente\n\n");
			SetColor(11);
			printf(" \t%c 5) Modificar Cliente\n\n",16);
			SetColor(14);
			printf(" 6) Salir del Registro\n\n\n");
			SetColor(11);
			printf(" Seleccione Una Opcion: ");
			break;
		case 6: system ("cls");
			SetColor(14);
			printf("\n\t\t******************************************\n");
			printf("\n\t\t %c REGISTRO DE CLIENTES %c \n",4,4);
			printf("\n\t\t******************************************\n\n");
			printf(" 1) Registrar Cliente\n\n");
			printf(" 2) Buscar Cliente\n\n");
			printf(" 3) Imprimir Listado\n\n");
			printf(" 4) Eliminar Cliente\n\n");
			printf(" 5) Modificar Cliente\n\n");
			SetColor(12);
			printf(" \t%c 6) Salir del Registro\n\n\n",16);
			SetColor(11);
			printf(" Seleccione Una Opcion: ");
			break;
	}
}

//******************* FUNCION MODIFICAR ******************
int modificar (){
	
	bool cliente_no_registrado=false;
	int a;
	system("cls");
	SetColor(14);
	printf("\n\t\t ************************************\n");
	printf("\n\t\t %c MODIFICAR LOS DATOS DEL CLIENTE %c \n",4,4);
	printf("\n\t\t ************************************\n");
	SetColor(11);
	
	if(clientes_registrados==0)
		printf("\n\n\n\n\n\n\n\n\t\tNO SE HA REGISTRADO NINGUN CLIENTE");
	else{
		printf ("\nINGRESE LA CEDULA DEL CLIENTE A MODIFICAR: ");
		scanf("%d",&cedula);
		for (i=0; i<n;i++){
			if(cedula == cliente[i].CI){
				system("cls");
				SetColor(14);
				printf("\n\t\t ************************************\n");
				printf("\n\t\t %c MODIFICAR LOS DATOS DEL CLIENTE %c\n",4,4);
				printf("\n\t\t ************************************\n");
				SetColor(11);
				printf("\n\t\t NOMBRE: %s", cliente [i].nombre);
				printf("\n\t\t CEDULA: %d", cliente [i].CI);
				printf("\n\t\t TELEFONO: %s", cliente [i].telefono);
				printf("\n\t\t DIRECCION: %s", cliente [i].direccion);
				printf("\n\n\tDATOS A MODIFICAR\n");
				printf("\n\t\t NOMBRE: ");
				scanf("%s",&cliente[400].nombre);
				printf("\n\t\t CEDULA: "); scanf("%d",&cliente[400].CI);
				//---------------------------REVISAR QUE NO EXISTA--------------------------
				for (a=0; a<n-1; a++){
					if(cliente[400].CI == cliente[a].CI){
						error();
						a=n;
						return 0;
					}
				}
				//---------------------------------------------------------------------------
				continuar:
				printf("\n\t\t TELEFONO: ");
				scanf("%s",&cliente[400].telefono);
				printf("\n\t\t DIRECCION: ");
				scanf("%s",&cliente[400].direccion );
				strcpy(cliente[i].nombre, cliente[400].nombre);
				cliente[i].CI = cliente[400].CI;
				strcpy(cliente[i].telefono, cliente[400].telefono);
				strcpy(cliente[i].direccion, cliente[400].direccion);
				printf("\n\t\tDATOS MODIFICADOS EXITOSAMENTE!\n");
				cliente[i].eliminar=0;
				cliente_no_registrado=false;
				i=n;
			}
			else cliente_no_registrado=true;
		}
	}
	if(cliente_no_registrado == true) printf("\n\t\t\tCLIENTE NO REGISTRADO\n");
	getch();
}


//******************* FUNCION MENU ******************

int menu() {
	while (opc!='6'){
		dibujar(opcion);
		opc=getch();
		switch (opc){
			case 13 : 
				if (opcion==1) { CargarDatos(); break; }
				else if (opcion==2) { Busqueda(); break; }
				else if (opcion==3) { ImprimirLista(); break; }
				else if (opcion==4) { eliminar(); break; }
				else if (opcion==5) { modificar(); break; }
				else { return 0; break; }
			case 80 : 
				if(opcion<6)opcion++; //abajo
				else opcion=1; break;
			case 72 : 
				if(opcion>1)opcion--; //arriba
				else opcion=6; break;
			case '1': { opcion=1; CargarDatos(); break; }
			case '2': { opcion=2; Busqueda(); break; }case '3': { opcion=3; ImprimirLista(); break; }
			case '4': { opcion=4; eliminar(); break; }
			case '5': { opcion=5; modificar(); break; }
			case '6': { opcion=6; return 0; break; }
			default : break;
		}
	}
}

//******************* FUNCION IMPRIMIR ******************
void ImprimirLista(){
	
	SetColor(14);
	system ("cls");
	printf(" \n\t\t %c L i s t a d o d e C l i e n t e s %c",4,4);
	SetColor(11);
	if(clientes_registrados==0) printf("\n\n\n\n\n\n\n\n\n\n\t\t\tNO SE HA REGISTRADO NINGUN CLIENTE");
	for (i=0; i<n;i++){
		if (cliente[i].eliminar==0 && n>0){
			printf("\n\t__________________________________________________________________\n\n");
			printf("\n\tNOMBRE\t\tCEDULA\t\tTELEFONO\t\tDIRECCION\n\n ");
			printf("\n %-20s %-13d %-15s %-15s \n\n" , cliente[i].nombre, cliente[i].CI,cliente[i].telefono, cliente[i].direccion);
		}
	}
	getch();
}

//******************* FUNCION ERROR ******************
int error(){
	
	system("cls");
	SetColor(11);
	int j;
	char reg;
	for (j=0; j<n; j++){
		if(cliente[j].eliminar == 1){
			printf("\n\n ESTE USUARIO YA HABIA SIDO REGISTRADO, DESEA VOLVER A REGISTRARLO (Y/N): \n\n");
			reg=getch();
			reg=toupper(reg);
			if(reg=='Y'){
				printf("\n\n USUARIO REGISTRADO DE NUEVO!\n\n");
				cliente[j].eliminar=0;
				clientes_registrados++;
				j=n;
			}
		}
		else{
			printf("\n\n\t\tUSUARIO REGISTRADO\n\n");
			j=n;
		}
	}
	system("PAUSE");
	menu();
}

//******************* FUNCION REGISTRAR ******************
int CargarDatos() {
	int a;
	do {
		system ("cls");
		SetColor(14);
		printf("\n\t\t ************************************\n");
		printf("\n\t\t %c INTRODUZCA LOS DATOS DEL CLIENTE %C \n",4,4);
		printf("\n\t\t ************************************\n");
		SetColor(11);
		printf("\n\tNOMBRE: "); scanf("%s",&cliente[i].nombre);
		printf("\n\tCEDULA: "); scanf("%d",&cliente[i].CI);
		//---------------------------REVISAR QUE NO EXISTA--------------------------
		for (a=0; a<n; a++){
			if(cliente[i].CI == cliente[a].CI){
				error();
				a=n;
				return 0;
			}
		}
		//---------------------------------------------------------------------------
		printf("\n\tTELEFONO: "); scanf("%s",&cliente[i].telefono);
		printf("\n\tDIRECCION: "); scanf("%s",&cliente[i].direccion );
		cliente[i].eliminar=0;
		n++;
		i++;
		clientes_registrados++;
		printf("\n\n\t\tDesea continuar(Y/N): ");
		continuar=getch();
	}while(toupper(continuar)!='N');
}

//------------------------- FUNCION PRINCIPAL --------------------------------
int main () { 
	system("color 2F");
	menu(); 
	return 0;
}
