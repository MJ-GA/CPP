#include <iostream>


using namespace std;

namespace  CST8219 {

    class Vehicule {
    private:
        int numWheels;
        int numDoors;
        

    public:
        Vehicule(int w, int d) {     // Constructor
          
            numWheels = w;
            numDoors = d;

        }
        Vehicule(int w) :Vehicule ( w, 4){     // Constructor
           
           
        }
        Vehicule() :Vehicule(4){     // Constructor
          
          
        }
        ~Vehicule() {
            cout << "previous vehicule object deleted" << endl;
        }
    };
}

int main()
{

    int d, w;
    using namespace CST8219;
    Vehicule veh1; // This calls constructor Vehicle()
    cout << "Vehicle 1 takes " << sizeof(veh1) << endl;
    Vehicule veh2(4); //This calls constructor Vehicle(int);
    cout << "Vehicle 2 takes " << sizeof(veh1) << endl;
    Vehicule veh3(4, 2); //This calls constructor Vehicle( int, int)
    cout << "Vehicle 3 takes " << sizeof(veh1) << endl;

   

 
    char input;

    do {
        Vehicule* pVehicule;
        cout << "enter number of doors" << endl;
        cin >> d;
        while (d <= 0) {
            cout << "enter a valid number of doors" << endl;
            cin >> d;
        }

        cout << "enter number of wheels" << endl;
        cin >> w;
        while (w <= 0) {
            cout << "enter a valid number of doors" << endl;
            cin >> w;
        }
        pVehicule = new Vehicule(w, d);
        cout << "do you want to repeat , press q to exit , and any other key to contunue" << endl;
        cin >> input;
        if (input != 'q')
            delete pVehicule;
       
    } while (input != 'q');

	return 0;
}

