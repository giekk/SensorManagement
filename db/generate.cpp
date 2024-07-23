#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

// Funzione per generare un valore casuale tra min e max
int generate_random_value(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() 
{
    srand(time(0)); // Inizializza il generatore di numeri casuali

    int temperature = 0, humidity = 0, microdust = 0;
    // Genera una data per ogni giorno tra il 01/01/2021 e il 31/12/2023
    for (int year = 2021; year <= 2023; ++year) {
        for (int month = 1; month <= 12; ++month) {
            for (int day = 1; day <= 31; ++day) 
            {
                // Ignora date non valide come il 30 febbraio
                if ((month == 2 && day > 28 + (year % 4 == 0)) || (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))) {
                    continue;
                }
                if (month < 3 || month == 12) {
                    temperature = generate_random_value(-10, 10);
                    humidity = generate_random_value(60, 95);
                }
                if (month == 3 || month == 11) {
                    temperature = generate_random_value(5, 15);
                    humidity = generate_random_value(60, 95);
                }
                if ((month >= 4 && month < 6) || (month >= 9 && month < 11)) {
                    temperature = generate_random_value(7, 22);
                    humidity = generate_random_value(60, 90);
                }
                if (month >= 6 && month < 9) {
                    temperature = generate_random_value(22, 40);
                    humidity = generate_random_value(50, 90);
                }

                microdust = generate_random_value(10, 90);

                if (day < 10 && month < 10) {
                    std::cout << "0" << day << "/" << "0" << month << "/" << year << "," << temperature << "," << humidity << "," << microdust << "\n";
                }
                if (day < 10 && month >= 10) {
                    std::cout << "0" << day << "/" << month << "/" << year << "," << temperature << "," << humidity << "," << microdust << "\n";
                }
                if (month < 10 && day >= 10) {
                    std::cout << day << "/" << "0" << month << "/" << year << "," << temperature << "," << humidity << "," << microdust << "\n";
                }
                if (day >= 10 && month >= 10) {
                    std::cout << day << "/" << month << "/" << year << "," << temperature << "," << humidity << "," << microdust << "\n";
                }
            }
        }
    }

    return 0;
}