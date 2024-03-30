#include <iostream>
#include <iomanip>
#include "stdlib.h"

const int player_none = -1;
const int player_x = 1;
const int player_o = 2;

const int gameOnline = 1;
const int history = 2;
const int exitGame = 3;
const int backMenu = 1;

int main() {

    int currentPlayer = player_x;
    int lastWinner = -1;
    int optionSelected = -1;
    bool gameInProgress = true;
    char player = 'O';

    int round = 0;

    int l1c1 = -1;
    int l1c2 = -1;
    int l1c3 = -1;
    int l2c1 = -1;
    int l2c2 = -1;
    int l2c3 = -1;
    int l3c1 = -1;
    int l3c2 = -1;
    int l3c3 = -1;

    std::cout << "Bem vindo ao jogo da velha do Lucas..." << std::endl;

    while (gameInProgress) {
        if (optionSelected != gameOnline) {
            round = 0;
            std::cout << "Escolha uma opção: " << std::endl;
            std::cout << " [1] - Novo Jogo" << std::endl;
            std::cout << " [2] - Ultimo ganhador " << std::endl;
            std::cout << " [3] - Sair do jogo " << std::endl;
            std::cout << std::endl << " Digite: ";

            std::cin >> optionSelected;
            system("clear");
            switch (optionSelected) {
                case gameOnline:
                    currentPlayer = player_x;
                    break;
                case history:
                    if (lastWinner == player_none) {
                        std::cout << "Nenhum vencedor ainda" << std::endl;
                    } else {
                        char winner = 'O';
                        if (lastWinner == player_x) winner = 'X';
                        std::cout << "O ultimo vencedor foi: " << winner << std::endl;
                    }

                    std::cout << "Deseja voltar ao menu ?" << std::endl;
                    std::cout << " [1] - Voltar ao menu" << std::endl;
                    std::cout << " [2] - Sair do jogo" << std::endl << " Digite: ";
                    std::cin >> optionSelected;
                    system("clear");
                    switch (optionSelected) {
                        case backMenu: optionSelected = -1;break;
                        case exitGame - 1: gameInProgress = false; break;
                        default: optionSelected = 2; std::cout << "Opção inválida" << std::endl;
                    }
                    break;
                case exitGame: gameInProgress = false; break;
                default: std::cout << "Opção inválida" << std::endl; break;
            }
        } else {
            if (currentPlayer == player_x) currentPlayer = player_o; else currentPlayer = player_x;
            int number = -1;
            round += 1;

            while (number == -1) {
                system("clear");
                if (currentPlayer == player_x) player = 'X'; else player = 'O';
                std::cout << "Vez do jogador: " << player << std::endl;
                std::cout << "Digite uma posição livre: " << std::endl;
                std::cout << "Rodada: " << round << std::endl;

                for (int i = 0; i < 9; i++) {
                    if (i % 3 == 0) std::cout << std::endl;

                    int contentPosition = player_none;
                    switch (i) {
                        case 0: if (l1c1 != -1) contentPosition = l1c1; break;
                        case 1: if (l1c2 != -1) contentPosition = l1c2; break;
                        case 2: if (l1c3 != -1) contentPosition = l1c3; break;
                        case 3: if (l2c1 != -1) contentPosition = l2c1; break;
                        case 4: if (l2c2 != -1) contentPosition = l2c2; break;
                        case 5: if (l2c3 != -1) contentPosition = l2c3 ; break;
                        case 6: if (l3c1 != -1) contentPosition = l3c1 ; break;
                        case 7: if (l3c2 != -1) contentPosition = l3c2 ; break;
                        case 8: if (l3c3 != -1) contentPosition = l3c3; break;
                    }

                    switch (contentPosition) {
                        case player_x:  std::cout << std::setw(3) << "X"; break;
                        case player_o:  std::cout << std::setw(3) << "@"; break;
                        default: std::cout << std::setw(3) << i;
                    }
                }

                std::cout << std::endl << " Digite: ";
                std::cin >> number;
                system("clear");
                bool enabledWarning = false;

                switch (number) {
                    case 0: if (l1c1 == -1) l1c1 = currentPlayer; else enabledWarning = true; break;
                    case 1: if (l1c2 == -1) l1c2 = currentPlayer; else enabledWarning = true; break;
                    case 2: if (l1c3 == -1) l1c3 = currentPlayer; else enabledWarning = true; break;
                    case 3: if (l2c1 == -1) l2c1 = currentPlayer; else enabledWarning = true; break;
                    case 4: if (l2c2 == -1) l2c2 = currentPlayer;else enabledWarning = true; break;
                    case 5: if (l2c3 == -1) l2c3 = currentPlayer; else enabledWarning = true; break;
                    case 6: if (l3c1 == -1) l3c1 = currentPlayer; else enabledWarning = true; break;
                    case 7: if (l3c2 == -1) l3c2 = currentPlayer; else enabledWarning = true; break;
                    case 8: if (l3c3 == -1) l3c3 = currentPlayer; else enabledWarning = true; break;
                    default:
                        number = -1;
                        std::cout << std::endl << "\nPosição inválida, digite somente as existentes" << std::endl;
                }

                if (enabledWarning) {
                    number = -1;
                    std::cout  << std::endl << "Posição ocupada, digite uma posição livre de 0 a 9" << std::endl;
                }
            }

            if ((l1c1 == l1c2 && l1c3 == l1c2) && l1c1 != player_none) {
                optionSelected = -1;
                lastWinner = l1c1;
            } else if (l2c1 == l2c2 && l2c3 == l2c2 && l2c1 != player_none) {
                optionSelected = -1;
                lastWinner = l2c1;
            } else if (l3c1 == l3c2 && l3c3 == l3c2 && l3c1 != player_none) {
                optionSelected = -1;
                lastWinner = l3c1;
            } else if (l2c1 == l2c2 == l2c3 == l2c2 && l2c1 != player_none) {
                optionSelected = -1;
                lastWinner = l3c1;
            } else if (l3c1 == l3c2 == l3c3 == l3c2 && l3c1 != player_none) {
                optionSelected = -1;
                lastWinner = l3c1;
            } else if (l1c1 == l2c1  && l3c1 == l2c1 && l1c1 != player_none) {
                optionSelected = -1;
                lastWinner = l1c1;
            } else if (l1c2 == l2c2 && l3c2 == l2c2 && l1c2 != player_none) {
                optionSelected = -1;
                lastWinner = l1c2;
            } else if (l1c3 == l2c3 && l3c3 == l2c3 && l1c3 != player_none) {
                optionSelected = -1;
                lastWinner = l1c3;
            } else if (l1c1 == l2c2 && l3c3 == l2c2 && l1c1 != player_none) {
                optionSelected = -1;
                lastWinner = l1c1;
            } else if (l1c3 == l2c2 && l3c1 == l2c2 && l1c3 != player_none) {
                optionSelected = -1;
                lastWinner = l1c3;
            }

            if (l1c1 != -1 && l1c2 != -1 && l1c3 != -1 &&
                l2c1 != -1 && l2c2 != -1 && l2c3 != -1 &&
                l3c1 != -1 && l3c2 != -1 &&l3c3 != -1 ) {
                optionSelected = -1;
                lastWinner = player_none;
            }
            std::cout << std::endl;
            if (optionSelected == -1) {
                if (lastWinner == player_none) {
                    std::cout << "Deu velha =( em " << round << " rodadas!" << std::endl;
                } else if (currentPlayer == lastWinner) {
                    std::cout << "Você fez a última tacada, jogador " << player << " venceu =) em " << round << " rodadas!" << std::endl;
                } else {
                    std::cout << "O jogador " << lastWinner << " venceu =)" << std::endl;
                }

                l1c1 = -1; l1c2 = -1; l1c3 = -1; l2c1 = -1; l2c2 = -1; l2c3 = -1; l3c1 = -1; l3c2 = -1; l3c3 = -1;
            }
        }
    }
    return 0;
}
