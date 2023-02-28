#ifndef CARRENTALUI_H
#define CARRENTALUI_H

#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/group.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/msgbox.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <vector>
#include <iostream>

#include "CarRentalSystem.h"

using namespace nana;

// This class implements the UI of the car rental system
class CarRentalUI
{
public:
    CarRentalUI(CarRentalSystem* rentalSystem);
    virtual ~CarRentalUI();

protected:

private:
    // Update the combo list of customers
    void update_customers_combo()
    {
        customers.clear();
        vector<Customer*> custList = rentalSystem->getCustomers();
        for (int i = 0; i < custList.size(); i++)
        {
            Customer* c = custList[i];
            char tmp[100];
            string name = c->getFirstName() + " " + c->getLastName();
            string addr = c->getStreetAddress();
            string pf = (c->isPreferred()) ? "yes" : "no";
            sprintf(tmp, "%s (Age=%d, Address=%s, Preferred=%s)", name.c_str(), c->getAge(), addr.c_str(), pf.c_str());
            customers.push_back(tmp);
        }
        customers.option(0);
    }
    // Update the combo list of vehicles
    void update_vehicles_combo()
    {
        vehicles.clear();
        vector<Vehicle*> vList = rentalSystem->getVehicles();
        for (int i = 0; i < vList.size(); i++)
        {
            Vehicle* v = vList[i];
            char tmp[50];
            const char* loc = (v->getRentalLocation() == nullptr) ? "None" : v->getRentalLocation()->getAddress().c_str();
            sprintf(tmp, "%s (ID=%d, Location=%s, #Seats=%d, RentalCost=%f)", v->getModel().c_str(), v->getId(), loc, v->getNumSeats(), v->getDailyRentalCost());
            vehicles.push_back(tmp);
        }
        vehicles.option(0);
    }
    // Update the combo list of rental locations
    void update_rentallocs_combo()
    {
        rentlocs.clear();
        vector<RentalLocation*> rlList = rentalSystem->getRentalLocations();
        for (int i = 0; i < rlList.size(); i++)
        {
            RentalLocation* rl = rlList[i];
            char tmp[50];
            sprintf(tmp, "%d - %s", rl->getId(), rl->getAddress().c_str());
            rentlocs.push_back(tmp);
        }
        rentlocs.option(0);
    }
    // Show input form for adding a new customer
    void show_add_customer_form(form& fm)
    {
        inputbox ibox(fm, "Enter customer details:", "Add Customer");
        inputbox::text fn{ "First Name:" };
        inputbox::text ln{ "Last Name:" };
        inputbox::text addr{ "Street Address:" };
        inputbox::integer age{ "Age:", 15, -10, 100, 1 };
        std::vector<string> yesno;
        yesno.push_back("Yes");
        yesno.push_back("No");
        inputbox::text pf("Preferred: ", yesno);

        auto firstName = fn.value();
        auto lastName = ln.value();
        auto stAddr = addr.value();
        auto cAge = age.value();
        auto preferred = (pf.value() == "Yes") ? true : false;
        Customer* cust = new Customer(100, cAge, firstName, lastName, stAddr, preferred);
        rentalSystem->addCustomer(cust);
        update_customers_combo();


    }
    // Show input form for adding a new vehicle
    void show_add_vehicle_form(form& fm)
    {
        inputbox ibox(fm, "Enter vehicle details:", "Add Vehicle");
        inputbox::text model{ "Model:" };
        inputbox::integer id{ "ID:", 100, 100, 500, 1 };
        inputbox::integer seats{ "#Seats:", 2, 2, 6, 1 };
        inputbox::real cost{ "Rental Cost (per day):", 10, 10, 50, 1 };
        std::vector<string> locations;
        locations.push_back("None");
        vector<RentalLocation*> rlList = rentalSystem->getRentalLocations();
        for (int i = 0; i < rlList.size(); i++)
        {
            RentalLocation* rl = rlList[i];
            char tmp[50];
            sprintf(tmp, "%d - %s", rl->getId(), rl->getAddress().c_str());
            locations.push_back(tmp);
        }
        inputbox::text loc("Rental Location: ", locations);

        auto vid = id.value();
        auto vmodel = model.value();
        auto vLoc = loc.value();
        auto vSeats = seats.value();
        auto vCost = cost.value();

        RentalLocation* rl = nullptr;
        if (vLoc != "None") {
            stringstream ss(vLoc);
            int locId;
            ss >> locId;
            rl = rentalSystem->findRentalLocation(locId);

            Vehicle* v = new Vehicle(vid, vmodel, vSeats, vCost, rl);
            rentalSystem->addVehicle(v);
            update_vehicles_combo();
        }
    }

    // Show input form for adding a new rental location
    void show_add_location_form(form& fm)
    {
        inputbox ibox(fm, "Enter location details:", "Add Rental Location");
        inputbox::text addr{ "Address:" };
        inputbox::integer id{ "ID:", 100, 100, 500, 1 };

        auto lid = id.value();
        auto laddr = addr.value();
        RentalLocation* rentLoc = new RentalLocation(lid, laddr);
        rentalSystem->addRentalLocation(rentLoc);
        update_rentallocs_combo();

    }
    void remove_selected_customer() {
        msgbox msg{ "Info" };
        if (customers.the_number_of_options() == 0) {
            msg << "Customers list is empty !";
        }
        else {
            int index = customers.option();

            msg << "Please select a customer from list.";
        }
        msg.show();
    }

    // reference to car rental system
    CarRentalSystem* rentalSystem;


    // drop down list of customers
    combox customers;
    // drop down list of vehicles
    combox vehicles;
    // drop down list of rental locations
    combox rentlocs;
    // drop down list of rentals
    combox rentals;

    // add/remove customer buttons
    button btnAddCust, btnRemoveCust;
    // add/remove vehicles buttons
    button btnAddVehicle, btnRemoveVehicle;
    // add/remove rental location buttons
    button btnAddRentalLoc, btnRemoveRentalLoc;


    button btnNextDay;
    button btnRentCar, btnReturnCar;
    button btnShowAllRent, btnShowCustPayment;
    button btnLateRentals;
    button btnCustRenting, btnCustPayment;
    button btnExit;

    // current day number
    int currDay;

};

#endif // CARRENTALUI_H
