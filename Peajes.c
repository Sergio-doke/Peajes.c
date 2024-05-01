#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
/*Se desea efectuar un programa para una estaci�n de peaje.
El programa deber� solicitar al operador de la cabina de peaje la categor�a del veh�culo, el d�a de la 
semana, el horario, y el importe de dinero entregado por el conductor del veh�culo.
- Categor�as de veh�culo: moto, auto, camioneta y cami�n.
- D�as de la semana: 1 (lunes), 2 (martes), 3 (mi�rcoles), 4 (jueves), 5 (viernes), 6 (s�bado), 7 
(domingo).
- Horario: a (pico), b (no pico).
(ver tabla de valores)
El programa le deber� devolver al operador de la cabina de peaje el importe a cobrar (dependiendo 
de la categor�a del veh�culo, del d�a de la semana y del horario), y el vuelto a entregar al conductor 
del veh�culo (dependiendo del importe de dinero entregado por el conductor del veh�culo). 
Luego de cada venta, el programa debe preguntarle al operador si desea continuar vendiendo � no.
Notas:
- El importe a cobrar ser� obtenido por el programa principal a trav�s una funci�n que reciba 
el valor base del c�lculo, el d�a, y el horario.
- El vuelto ser� obtenido por el programa principal a trav�s de una funci�n que reciba el 
importe a cobrar y el importe de dinero entregado por el conductor del veh�culo.
- Para informar el importe a cobrar y el vuelto se debe efectuar mediante una funci�n que 
primero limpie la pantalla y luego los informe.
Todos los mensajes que se muestren por pantalla deben estar prolijamente ordenados y distribuidos.
Cuando el operador decida terminar de vender, el programa deber� informar lo siguiente: 
Cantidad de ventas de categor�a auto en horario pico.
Total de pases vendidos y total recaudado.
No se pide:
Validaci�n de entradas, asumimos que el operador ingresa todos los datos de forma correcta
*/
float cobro(float base, int dia_sem, char horario);
float vuelto(float importe, float cobrar);
void informe(float cobrar, float sobra);

char categoria[10], horario,r[3];
int dia_sem;
float importe, base = 0, cobrar = 0, sobra;

void main() 
{	do{

    printf("Ingrese la categoria del vehiculo: moto, auto, camioneta y camion:  ");
    scanf("%s", categoria);
    printf("Ingrese el dia de la semana: 1 (lunes), 2 (martes), 3 (mi�rcoles), 4 (jueves), 5 (viernes), 6 (s�bado), 7 (domingo): ");
    scanf("%d", &dia_sem);
    printf("Ingrese el Horario: a (pico), b (no pico): ");
    scanf(" %c", &horario);
    printf("Ingrese el importe recibido: ");
    scanf("%f", &importe);

    if (strcmp(categoria, "moto") == 0) {
        base = 5;
    } else if (strcmp(categoria, "auto") == 0) {
        base = 10;
    } else if (strcmp(categoria, "camioneta") == 0) {
        base = 15;
    } else if (strcmp(categoria, "camion") == 0) {
        base = 20;
    } else {
        printf("Ingreso una categoria no valida");
    }

    cobrar = cobro(base, dia_sem, horario);
    sobra = vuelto(importe, cobrar);
    informe(cobrar, sobra);
    printf("desea continuar vendiendo si/no.");
    scanf("%s", &r);
    }while(strcmp(r,"si")==0);
}

float cobro(float base, int dia_sem, char horario) {
    float importeCobro = 0;
    if (horario == 'a' && (dia_sem == 1 || dia_sem == 2 || dia_sem == 3 || dia_sem == 4 || dia_sem == 5)) {
        importeCobro = base * 1.20;
    } else {
        importeCobro = base - (base * 0.20);
    }
    return importeCobro;
}

float vuelto(float importe, float cobrar) {
    float vuelto = 0;
    if (importe < cobrar) {
        vuelto = 0;
        printf("El importe recibido no alcanza");
    } else {
        vuelto = importe - cobrar;
    }
    return vuelto;
}

void informe(float cobrar, float sobra) {
	system ("cls");
    printf("El importe a cobrar es: %.2f y el vuelto es %.2f\n", cobrar, sobra);
}
     

