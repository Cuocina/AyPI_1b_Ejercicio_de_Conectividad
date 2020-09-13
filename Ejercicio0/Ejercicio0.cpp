// Ejercicio0.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
const int CantidadIngresos = 6;
const int TopeMatriz = 8;
const int Conectado = 1;
const int Desconectado = 0;


void BlanquearMatriz(int matriz[TopeMatriz]);
int ElementoValido();
bool Conectados(int c[TopeMatriz], int a, int b);
void Conectar(int c[TopeMatriz], int a, int b);
void MostrarMatriz(int matriz[TopeMatriz]);

int main() {
	int p, q, x[TopeMatriz];
	bool val = false;
	BlanquearMatriz(x);
	MostrarMatriz(x);
	for (int numeroIngreso = 0; numeroIngreso < CantidadIngresos; ++numeroIngreso)
	{
		p = ElementoValido();
		q = ElementoValido();

		if (Conectados(x, p, q) == true)
		{
			cout << "Estan Conectados Hilda" << endl;
		}
		else 
		{
			Conectar(x, p, q);
			cout << p << "-" << q << endl;
			cout << "No estaban conectados pero ahora si Mabel" << endl;
		}
	}
	return 0;
}

void BlanquearMatriz(int matriz[TopeMatriz])
{
	for (int i = 0; i < TopeMatriz; i++)
	{
		matriz[i] = i;
	}
}
int ElementoValido()
{
	int num = 0;
	do
	{
		cout << "Ingresar Numero" << endl;
		cin >> num;
	} while (num < 0 && num>7);

	return num;
}
bool Conectados(int c[TopeMatriz], int a, int b)
{
	bool aux = false;
	if (c[a] == c[b])
	{
		aux = true;
	}

	return aux;
}
void Conectar(int c[TopeMatriz], int a, int b)
{
	if (Conectados(c, a, b) == false)
	{
		int ConjuntoA = c[a];
		int ConjuntoB = c[b];
		for (int i = 0; i < TopeMatriz; i++)
		{
			if (c[i] == ConjuntoA)
			{
				c[i] = ConjuntoB;
			}
		}
	}
	
}
void MostrarMatriz(int matriz[TopeMatriz])
{
		for (int j = 0; j < TopeMatriz; j++)
		{
			cout << matriz[j] << "|";
		}
		cout << endl;
}

