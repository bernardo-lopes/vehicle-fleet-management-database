# Vehicle fleet management database

**C++** interface linked to a database using **SQL**.

The objective of this project done in the **Object-Oriented Programming and Database** course in my university was to create an interface to manage a company vehicle fleet. 

## Entities:
### Collaborators:
- **ID** (primary key): Number that identifies the collaborator
- **Name**: Name of the collaborator
- **Birth date**: Birth date of the collaborator
- **Contact**: Telephone number of the collaborator
- **Department**: Area of expertise where the collaborator works
- **Job**: Position that the collaborator occupies in the department

### Vehicles:
- **License plate** (primary key): Set of character that identifies the vehicle
- **Transmission**: Transmission of the motor
- **Consumption**: Consumption of the motor
- **Fuel**: Type of fuel that the motor runs on
- **Brand**: Manufacturer of the vehicle
- **Model**: Specific vehicle produced by manufacturer
- **Colour**: Colour of the vehicle
- **License plate date**: Date of emission of the vehicle

### Gas Station:
- **Name** (primary key): Name of the filling station
- **Coordinates**: location of the filling station

### Fuel Company:
- **Brand** (primary key): Brand of the fuel company
- **Discount**: Discounts that the fuel company offers

## Relations:
- **Attributions**: Indicates which collaborators used each vehicle at a certain year.
- **Refuel**: Indicates the expenses that are made to each vehicle.
- **Belongs to**: Associates the filling station with the fuel company.
