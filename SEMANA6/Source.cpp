#include <conio.h>
#include <iostream>
using namespace std;
using namespace System;



class Circulo
{
protected:
	double r;
public:
	Circulo(double R);
	~Circulo();
	double AreaDelCirculo();
	double Longitud();
};
Circulo::Circulo(double R)
{
	r = R;
}
double Circulo::AreaDelCirculo()
{
	return (3.1416*r*r);
}
double Circulo::Longitud()
{
	return (2*3.1416*r);
}

Circulo::~Circulo()
{

}


class Cilindro:public Circulo
{
protected:
	double h;

public:
	Cilindro(double R,double H);
	~Cilindro();
	double AreaDelCilindro();
	double VolumenDelCilindro();
};
Cilindro::Cilindro(double R, double H) :Circulo(r)
{
	h = H;
}
double Cilindro::AreaDelCilindro()
{
	return (Longitud()*h+2*AreaDelCirculo());
}
double Cilindro::VolumenDelCilindro()
{
	return (AreaDelCirculo()*h);
}
Cilindro::~Cilindro()
{

}


class CilindroHueco: public Cilindro
{
private:
	double i;//radio menor
public:
	CilindroHueco(double R, double I, double H);
	double AreaDelCilindroH();
	double VolumenDelCilindroH();
	~CilindroHueco();
};

CilindroHueco::CilindroHueco(double R, double I, double H): Cilindro(r,h)
{
	i = I;
}
double CilindroHueco::AreaDelCilindroH()
{
	return (AreaDelCilindro() + 2 * 3.1416*h*i - 2 * 3.1416*i*i);
}
double CilindroHueco::VolumenDelCilindroH()
{
	return (VolumenDelCilindro() - 3.1416*i*i*h);
}
CilindroHueco::~CilindroHueco()
{

}



int main()
{
	Circulo *unCirculo;
	Cilindro *unCilindro;
	CilindroHueco *unCilindroHueco;

	double r, i, h;
	cout << "EJEMPLO DE HERENCIA" << endl;
	cout << "Ingrese radio: "<<endl;
	cin >> r;
	cout << "Ingrese altura: "<<endl;
	cin >> h;
	cout << "Ingrese radio menor: " << endl;
	cin >> i;

	unCirculo = new Circulo(r);
	cout << "DATOS DEL CURCULO" << endl;
	cout << "Radio: " << r<<endl;
	cout << "Area del circulo: " << unCirculo->AreaDelCirculo() << endl;
	cout << "Longitud de la circunferencia: " << unCirculo->Longitud()<<endl;

	unCilindro = new Cilindro(r,h);
	cout << "DATOS DEL CILINDRO" << endl;
	cout << "Radio: " << r<<endl;
	cout << "Altura: " << h<<endl;
	cout << "Area del cilindro: " << unCilindro->AreaDelCilindro()<<endl;
	cout << "Volumen del cilindro: " << unCilindro->VolumenDelCilindro()<<endl;

	unCilindroHueco = new CilindroHueco(r,i,h);
	cout << "DATOS DEL CILINDRO HUECO" << endl;
	cout << "Radio: " << r<<endl;
	cout << "Altura: " << h<<endl;
	cout << "Radio menor: " << i<<endl;
	cout << "Area del cilindro hueco: " << unCilindroHueco->AreaDelCilindroH()<<endl;
	cout << "Volumen del cilindro hueco: " << unCilindroHueco->VolumenDelCilindroH() << endl;
	delete unCilindro;
	delete unCirculo;
	delete unCilindroHueco;

	_getch();
}


