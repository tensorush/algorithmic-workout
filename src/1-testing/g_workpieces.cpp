#include <iostream>

using namespace std;


int main() {
    unsigned alloyMass, billetMass, workpieceMass;
    cin >> alloyMass >> billetMass >> workpieceMass;

    unsigned totalNumWorkpieces = 0;
    if (alloyMass >= billetMass && billetMass >= workpieceMass) {
        unsigned numWorkpiecesPerBillet = billetMass / workpieceMass,
            leftoverMassPerBillet = billetMass - numWorkpiecesPerBillet * workpieceMass;
        for (unsigned numBillets = alloyMass / billetMass; numBillets > 0; numBillets = alloyMass / billetMass) {
            alloyMass -= numBillets * billetMass;
            alloyMass += numBillets * leftoverMassPerBillet;
            totalNumWorkpieces += numBillets * numWorkpiecesPerBillet;
        }
    }
    cout << totalNumWorkpieces << endl;

    return EXIT_SUCCESS;
}