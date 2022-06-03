#include <Stepper.h>

Stepper moteur_PaP(2048, 9, 11, 10, 8);

int nombreDePasParTour_moteur_PaP = 2048;

void setup() {
  moteur_PaP.setSpeed(5);
}

void loop() {
  moteur_PaP.step(1* nombreDePasParTour_moteur_PaP);

}
