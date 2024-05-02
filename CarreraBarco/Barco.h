#pragma once
#include <iostream>
class Barco
{
private:
	int Velocidad;
	int Distancia;
	std::string Name;
	int Nitro;

public:
	int getVelocidad();
	void setVelocidad(int _velocidad);
	int getDistancia();
	void setDistancia(int _distancia);
	std::string getName();
	void setName(std::string _name);
	bool getNitro();
	void setNitro(int _nitro);
	void getParams();
	Barco();
	Barco(int _distancia, int _velocidad, int _nitro, std::string _name);
	Barco(int _distancia, int _velocidad, int _nitro);
	int rollDice();
	std::string randomName();
	void useNitro();
};
