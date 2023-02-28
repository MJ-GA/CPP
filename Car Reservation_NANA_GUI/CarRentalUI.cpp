#include "CarRentalUI.h"
#include <sstream>

CarRentalUI::CarRentalUI(CarRentalSystem* rentalSystem)
{
    this->rentalSystem = rentalSystem;
    currDay = 0;
    form fm{ API::make_center(700,500) };
    fm.caption("");

    place plc(fm);
    std::vector<std::unique_ptr<button>> btns;
    // header label.
    label  header{ fm };
    header.format(true);
    header.caption("<size=20>Car Rental System</>");
    header.text_align(align::center);
    stringstream ss;
    ss << "<size=15>Day " << currDay << "</>";
    label  day{ fm };
    day.text_align(align::center);
    day.format(true);
    day.caption(ss.str());


    group  main_grp{ fm,  "", true };
    group grp_controls{ fm, "", true };

    plc.div("vert gap=10 margin=5 <header weight=50><day weight=40><all><control weight=65> ");
    plc["header"] << header;
    plc["day"] << day;
    plc["all"] << main_grp;
    plc["control"] << grp_controls;

    group grp_customers{ main_grp, ("Customers"), true };
    group grp_vehicles{ main_grp, ("Cars"), true };
    group grp_rentallocs{ main_grp, ("Rental Locations"), true };
    group grp_rentals{ main_grp, ("Rentals"), true };


    main_grp.div("vert gap=3 margin=20  <customers_field><vehicles_field><rentlocs_field><rentals_field> ");
    main_grp["customers_field"] << grp_customers;
    main_grp["vehicles_field"] << grp_vehicles;
    main_grp["rentlocs_field"] << grp_rentallocs;
    main_grp["rentals_field"] << grp_rentals;

    customers.create(grp_customers);
    btnAddCust.create(grp_customers);
    btnAddCust.caption("Add");
    btnRemoveCust.create(grp_customers);
    btnRemoveCust.caption("Remove");

    grp_customers.div(" margin=5 min=30 gap= 10 < <combo> | 30% <all>> ");
    grp_customers["combo"] << customers;
    grp_customers["all"] << btnAddCust << btnRemoveCust;

    vehicles.create(grp_vehicles);
    btnAddVehicle.create(grp_vehicles);
    btnAddVehicle.caption("Add");
    btnRemoveVehicle.create(grp_vehicles);
    btnRemoveVehicle.caption("Remove");

    grp_vehicles.div(" margin=5 min=30 gap= 10 < <combo> | 30% <all>> ");
    grp_vehicles["combo"] << vehicles;
    grp_vehicles["all"] << btnAddVehicle << btnRemoveVehicle;

    rentlocs.create(grp_rentallocs);
    btnAddRentalLoc.create(grp_rentallocs);
    btnAddRentalLoc.caption("Add");
    btnRemoveRentalLoc.create(grp_rentallocs);
    btnRemoveRentalLoc.caption("Remove");

    grp_rentallocs.div(" margin=5 min=30 gap= 10 < <combo> | 30% <all>> ");
    grp_rentallocs["combo"] << rentlocs;
    grp_rentallocs["all"] << btnAddRentalLoc << btnRemoveRentalLoc;


    rentals.create(grp_rentals);
    btnRentCar.create(grp_rentals);
    btnRentCar.caption("Rent a Car");
    btnReturnCar.create(grp_rentals);
    btnReturnCar.caption("Return a Car");

    grp_rentals.div(" margin=5 min=30 gap= 10 < <combo> | 30% <all>> ");
    grp_rentals["combo"] << rentals;
    grp_rentals["all"] << btnRentCar << btnReturnCar;

    btnNextDay.create(grp_controls);
    btnNextDay.caption("Next Day");

    btnExit.create(grp_controls);
    btnExit.caption("Exit");
    btnLateRentals.create(grp_controls);
    btnLateRentals.caption("Late Rentals");
    btnCustRenting.create(grp_controls);
    btnCustRenting.caption("Customers Renting a Car");
    btnCustPayment.create(grp_controls);
    btnCustPayment.caption("Customer Payment Due");

    grp_controls.div(" margin=5 min=50 gap= 10 < <nextday> | <laterental> | <custrenting> | <custpayment>> ");
    grp_controls["nextday"] << btnNextDay;
    grp_controls["laterental"] << btnLateRentals;
    grp_controls["custrenting"] << btnCustRenting;
    grp_controls["custpayment"] << btnCustPayment;

    btnNextDay.events().click([&day, this]
        {
            (this->currDay)++;
            stringstream ss;
            ss << "<size=15>Day " << this->currDay << "</>";
            day.caption(ss.str());
        });
    btnAddCust.events().click([&fm, this]
        {
            this->show_add_customer_form(fm);
        });
    btnRemoveCust.events().click([this]
        {
            this->remove_selected_customer();
        });
    btnAddVehicle.events().click([&fm, this]
        {
            //this->show_add_vehicle_form(fm);
        });
    btnAddRentalLoc.events().click([&fm, this]
        {
            this->show_add_location_form(fm);
        });
    btnExit.events().click(API::exit);

    plc.collocate();
    fm.show();
    exec();
}

CarRentalUI::~CarRentalUI()
{
}
