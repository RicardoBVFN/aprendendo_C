#include <stdio.h>

float temperaturaCelcius, temperaturaF;

void conversorTemperatura(){

    temperaturaF = ((temperaturaCelcius * 1.8) + 32);

}

void main(){

    printf("\ndigite a temepratura em °C: ");
    scanf("%f", &temperaturaCelcius);

    conversorTemperatura();

    printf("\na temperatura de %.2f°C corresponde à temperatura de %.2f°F", temperaturaCelcius, temperaturaF);

}