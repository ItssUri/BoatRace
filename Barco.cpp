#include "Barco.h"
int Barco::getVelocidad() {
	return Velocidad;
}

void Barco::setVelocidad(int _velocidad) {
	Velocidad = _velocidad;
	std::cout << "La velocidad del barco " << Name << " cambia a " << Velocidad;
}

int Barco::getDistancia()
{
	return Distancia;
}

void Barco::setDistancia(int _distancia)
{
	Distancia = _distancia;
}

std::string Barco::getName()
{
	return Name;
}

void Barco::setName(std::string _name)
{
	Name = _name;
}

bool Barco::getNitro()
{
	if (Nitro == 1) {
		return true;
	}
	else { return false; }
}

void Barco::setNitro(int _nitro)
{
	Nitro = _nitro;
}

void Barco::getParams() {
	std::cout << "El barco " << Name << " esta a una distancia de " << Distancia << " a una velocidad de " << Velocidad << " y con un estatus de nitro de " << Nitro;
}

Barco::Barco() {

}
Barco::Barco(int _distancia, int _velocidad, int _nitro, std::string _name) {
	Distancia = _distancia;
	Velocidad = _velocidad;
	Nitro = _nitro;
	Name = _name;
}

Barco::Barco(int _distancia, int _velocidad, int _nitro)
{
	Distancia = _distancia;
	Velocidad = _velocidad;
	Nitro = _nitro;
}

int Barco::rollDice()
{
	return rand() % 6 + 1;
}

std::string Barco::randomName()
{
	std::string nombres[12] = { "Titanic","Queen Mary","USS Enterprise","HMS Victory","Black Pearl","Andrea Doria","Santa Maria","Queen Elizabeth","Nautilus","Cutty Sark","USS Constitution","Bismarck" };
	return nombres[rand() % 12];
}

void Barco::useNitro()
{
	if (getNitro() == true)
	{
		std::cout << "\n\n\t!!! NITRO !!!";
		int failure = rand() % 2;
		if (failure == 1)
		{
			std::cout << std::endl << "\t!! Exito !! Velocidad Duplicada !!\n" << std::endl;
			setVelocidad(getVelocidad() * 2);
		}
		else {
			std::cout << std::endl << "\tFallo critico del motor. Velocidad Terriblemente afectada\n" << std::endl;
			setVelocidad(getVelocidad() / 2);
		}
		Nitro = 0;
	}
	else {
		std::cout << "No queda nitro.";
	}
}
