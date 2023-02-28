
cmake_minimum_required (VERSION 3.8)

add_definitions( -D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
# Add source to this project's executable.
add_executable (FinalProject "main.cpp" "CarRentalUI.h" "CarRentalUI.cpp"  "CarRentalSystem.cpp" "CarRentalSystem.h" "Customer.cpp" "Customer.h" "Rental.cpp" "Rental.h" "RentalLocation.cpp" "RentalLocation.h" "Vehicle.cpp" "Vehicle.h" "CarRentalSystem.cpp" "CarRentalSystem.h" "CarRentalUI.cpp" "CarRentalUI.h" "Customer.cpp" "Customer.h" "main.cpp" "Rental.cpp" "Rental.h" "RentalLocation.cpp" "RentalLocation.h" "Vehicle.cpp" "Vehicle.h")


target_include_directories(FinalProject PUBLIC "C:\\Users\\16138\\Desktop\\nana\\include")
target_link_libraries(FinalProject "nana_v143_Debug_x64")
target_link_directories(FinalProject PUBLIC "C:\\Users\\16138\\Desktop\\nana\\build\\bin")

# TODO: Add tests and install targets if needed.
