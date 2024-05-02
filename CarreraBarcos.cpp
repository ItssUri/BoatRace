#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Barco.h"

HANDLE hConsole;
bool play_again;

static const int TURNOS = 5;
//void menu(); void singleplayer(); void boatArt(Barco barco1, Barco barco2); turno(Barco barco1, Barco barco2, int gamemode, int turnNum);
void enter() {
    std::cout<<"+---------------------------------+\n| Presiona Enter per continuar... |\n+---------------------------------+";
    std::cin.ignore();

}
void boatArt(Barco &barco1, Barco &barco2) {
    if (barco1.getDistancia() > barco2.getDistancia())
    {
        std::cout << std::endl << barco1.getName() << " || (" << barco1.getVelocidad() << "km/h" << "   " << barco1.getDistancia() << "m)" << std::endl;
        std::cout << "                                        ~." << std::endl; std::cout << "                                        /|" << std::endl; std::cout << "                                       / |" << std::endl; std::cout << "                                      /__|__" << std::endl; std::cout << "                                    \\--------/" << std::endl; std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`~~~~~~'~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl << barco2.getName() << " || (" << barco2.getVelocidad() << "km/h" << "   " << barco2.getDistancia() << "m)" << std::endl;
        std::cout << "                  ~." << std::endl; std::cout << "                  /|" << std::endl; std::cout << "                 / |" << std::endl; std::cout << "                /__|__" << std::endl; std::cout << "                /__|__" << std::endl; std::cout << "              \\--------/" << std::endl; std::cout << "~~~~~~~~~~~~~~~`~~~~~~'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    }
    else if (barco1.getDistancia() < barco2.getDistancia()) {
        std::cout << std::endl << barco1.getName() << " || (" << barco1.getVelocidad() << "km/h" << "   " << barco1.getDistancia() << "m)" << std::endl;
        std::cout << "                  ~." << std::endl; std::cout << "                  /|" << std::endl; std::cout << "                 / |" << std::endl; std::cout << "                /__|__" << std::endl; std::cout << "                /__|__" << std::endl; std::cout << "              \\--------/" << std::endl; std::cout << "~~~~~~~~~~~~~~~`~~~~~~'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl << barco2.getName() << " || (" << barco2.getVelocidad() << "km/h" << "   " << barco2.getDistancia() << "m)" << std::endl;
        std::cout << "                                        ~." << std::endl; std::cout << "                                        /|" << std::endl; std::cout << "                                       / |" << std::endl; std::cout << "                                      /__|__" << std::endl; std::cout << "                                    \\--------/" << std::endl; std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`~~~~~~'~~~~~~~~~~~~~~~~~~" << std::endl;
    }
    else {
        std::cout << std::endl << barco1.getName() << " || (" << barco1.getVelocidad() << "km/h" << "   " << barco1.getDistancia() << "m)" << std::endl;
        std::cout << "                  ~." << std::endl; std::cout << "                  /|" << std::endl; std::cout << "                 / |" << std::endl; std::cout << "                /__|__" << std::endl; std::cout << "                /__|__" << std::endl; std::cout << "              \\--------/" << std::endl; std::cout << "~~~~~~~~~~~~~~~`~~~~~~'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl << barco2.getName() << " || (" << barco2.getVelocidad() << "km/h" << "   " << barco2.getDistancia() << "m)" << std::endl;
        std::cout << "                  ~." << std::endl; std::cout << "                  /|" << std::endl; std::cout << "                 / |" << std::endl; std::cout << "                /__|__" << std::endl; std::cout << "                /__|__" << std::endl; std::cout << "              \\--------/" << std::endl; std::cout << "~~~~~~~~~~~~~~~`~~~~~~'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    }
    std::cout << std::setw(0);
}
void turno(Barco &barco1, Barco &barco2, int gamemode, int turnNum) {
    std::cout << "\nO=========O\n| TURNO "<< turnNum<<" | \nO=========O\n";
    boatArt(barco1, barco2);
    int diceResult = barco1.rollDice();
    std::cout << std::endl << "El jugador " << barco1.getName() << " tira el dado. || Obtiene un " << diceResult << std::endl;
    barco1.setVelocidad(barco1.getVelocidad() + diceResult);
    if (barco1.getNitro()) {
        std::string nitroOption = "";
        while (nitroOption != "y" && nitroOption != "n") {
            std::cout << std::endl << barco1.getName() << " | Quieres usar nitro? (y/n) : ";
            std::cin >> nitroOption;
        }
        if (nitroOption == "y") {
            barco1.useNitro();
        }
    }
    std::cout << std::endl;
    diceResult = barco2.rollDice();
    std::cout << std::endl << "El jugador " << barco2.getName() << " tira el dado. || Obtiene un " << diceResult << std::endl;
    barco2.setVelocidad(barco2.getVelocidad() + diceResult);
    if (gamemode == 2) {
        //Multiplayer
        if (barco2.getNitro()) {
            std::string nitroOption = "";
            while (nitroOption != "y" && nitroOption != "n") {
                std::cout << std::endl << barco2.getName() << " | Quieres usar nitro? (y/n) : ";
                std::cin >> nitroOption;
            }
            if (nitroOption == "y") {
                barco2.useNitro();
            }
        }
    }
    else {
        if (diceResult >= 4) {
            barco2.useNitro();
        }
    }
    //distancia recorrida = distancia recorrida + velocidad*100
    barco1.setDistancia(barco1.getDistancia() + barco1.getVelocidad() * 100);
    barco2.setDistancia(barco2.getDistancia() + barco2.getVelocidad() * 100);
    std::cout << std::endl;
    enter();
    std::cin.ignore();
    system("CLS");
}
void singleplayer() {
    std::string boatName;
    std::cout << "Participante, Elige tu nombre! : ";
    std::getline(std::cin, boatName);
    system("CLS");
    Barco participante1 = Barco(0, 0, 1);
    Barco participanteAi = Barco(0, 0, 1); 
    participante1.setName(boatName);
    participanteAi.setName(participanteAi.randomName());
    for (int i = 1; i <= TURNOS; i++)
    {
        turno(participante1, participanteAi, 1, i);
    }
    if (participante1.getDistancia() > participanteAi.getDistancia()) {
        std::cout << std::endl << "\tPLAYER " << participante1.getName() << " WINS!" << std::endl;
    }
    else {
        std::cout << std::endl << "\tPLAYER " << participanteAi.getName() << " WINS!" << std::endl;
    }
    std::string playAgainOption = "";
    while (playAgainOption != "y" || playAgainOption != "n") {
        std::cout << "Quieres jugar otra vez? (y/n) : ";
        std::getline(std::cin, playAgainOption);
        std::cout << playAgainOption;
        if (playAgainOption == "y")
        {
            play_again = true;
            break;
        }
        else if (playAgainOption == "n") {
            play_again = false;
            break;
        }
    }
}
void multiplayer() {
    std::string boat1Name;
    std::cout << "Participante 1, Elige tu nombre! : ";
    std::getline(std::cin, boat1Name);
    std::string boat2Name;
    std::cout << "\nParticipante 2, Elige tu nombre! : ";
    std::getline(std::cin, boat2Name);
    system("CLS");
    Barco participante1 = Barco(0, 0, 1);
    Barco participante2 = Barco(0, 0, 1);
    participante1.setName(boat1Name);
    participante2.setName(boat2Name);
    for (int i = 1; i <= TURNOS; i++)
    {
        turno(participante1, participante2, 2, i);
    }
    if (participante1.getDistancia() > participante2.getDistancia()) {
        std::cout << std::endl << "\tPLAYER " << participante1.getName() << " WINS!" << std::endl;
    }
    else {
        std::cout << std::endl << "\tPLAYER " << participante2.getName() << " WINS!" << std::endl;
    }
    std::string playAgainOption = "";
    while (playAgainOption != "y" || playAgainOption != "n") {
        std::cout << "Quieres jugar otra vez? (y/n) : ";
        std::getline(std::cin, playAgainOption);
        std::cout << playAgainOption;
        if (playAgainOption == "y")
        {
            play_again = true;
            break;
        }
        else if (playAgainOption == "n") {
            play_again = false;
            break;
        }
    }
}

void menu() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    #define SPACE 32
    #define ARROWDOWN 80
    #define ARROWUP 72

    bool enteredOption = false;
    int selected_option = 1;
    int keyboardInput = 0;
    while (!enteredOption)
    {
        system("CLS");
        std::cout << std::endl << "\tWelcome / Bienvenido / Benvingut" << std::endl;SetConsoleTextAttribute(hConsole, 2); ; std::cout << "\t\tBoatSim Racing ++\n\n"; SetConsoleTextAttribute(hConsole, 15);
        std::cout << " +====================+\n | GAMEMODE SELECTION |\n +====================+\n |    "; if (selected_option == 1) { SetConsoleTextAttribute(hConsole, 15 * 16); } std::cout << "Singleplayer"; SetConsoleTextAttribute(hConsole, 15); std::cout << "    | \n |     ";if (selected_option == 2) { SetConsoleTextAttribute(hConsole, 15 * 16); } std::cout << "Multiplayer";SetConsoleTextAttribute(hConsole, 15); std::cout << "    | \n +====================+";
        switch ((keyboardInput = _getch())) {
        case ARROWDOWN:
            if (selected_option == 1) selected_option = 2;
            break;
        case ARROWUP:
            if (selected_option == 2) selected_option = 1;
            break;
        case SPACE:
            enteredOption = true;
        }
    }
    system("CLS");
    if (selected_option == 1) {
        singleplayer();
    }
    else if (selected_option == 2) {
        multiplayer();
    }
}

int main()
{
    srand(time(NULL));
    play_again = true;
    while (play_again) {
        menu();
    }

}