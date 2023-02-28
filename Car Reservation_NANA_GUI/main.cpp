#include "CarRentalSystem.h"
#include "CarRentalUI.h"

int main()
{
    CarRentalSystem* rentalSystem = new CarRentalSystem();
    CarRentalUI* rentalUI = new CarRentalUI(rentalSystem);
}
