#include <iostream>
#include <string>
using namespace std;

// Base Class
class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    // Default Constructor
    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    // Parameterized Constructor
    Vehicle(int id, string m, string mo, int y)
    {
        vehicleID = id;
        manufacturer = m;
        model = mo;
        year = y;
        totalVehicles++;
    }

    // Destructor
    virtual ~Vehicle()
    {
        totalVehicles--;
    }

    // Setters
    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    void setManufacturer(string m)
    {
        manufacturer = m;
    }

    void setModel(string mo)
    {
        model = mo;
    }

    void setYear(int y)
    {
        year = y;
    }

    // Getters
    int getVehicleID()
    {
        return vehicleID;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    // Display Function
    virtual void display()
    {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

// Single Inheritance
class Car : public Vehicle
{
private:
    string fuelType;

public:
    Car(int id, string m, string mo, int y, string fuel)
        : Vehicle(id, m, mo, y)
    {
        fuelType = fuel;
    }

    void setFuelType(string fuel)
    {
        fuelType = fuel;
    }

    string getFuelType()
    {
        return fuelType;
    }

    void display() override
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Multilevel Inheritance
class ElectricCar : public Car
{
private:
    int batteryCapacity;

public:
    ElectricCar(int id, string m, string mo, int y,
                string fuel, int battery)
        : Car(id, m, mo, y, fuel)
    {
        batteryCapacity = battery;
    }

    void setBatteryCapacity(int battery)
    {
        batteryCapacity = battery;
    }

    int getBatteryCapacity()
    {
        return batteryCapacity;
    }

    void display() override
    {
        Car::display();
        cout << "Battery Capacity: "
             << batteryCapacity << " kWh" << endl;
    }
};

// Multilevel Inheritance
class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar(int id, string m, string mo, int y,
              string fuel, int battery, int speed)
        : ElectricCar(id, m, mo, y, fuel, battery)
    {
        topSpeed = speed;
    }

    void setTopSpeed(int speed)
    {
        topSpeed = speed;
    }

    int getTopSpeed()
    {
        return topSpeed;
    }

    void display() override
    {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

// Hierarchical Inheritance
class Sedan : public Car
{
public:
    Sedan(int id, string m, string mo, int y, string fuel)
        : Car(id, m, mo, y, fuel)
    {
    }

    void display() override
    {
        cout << "Vehicle Type: Sedan" << endl;
        Car::display();
    }
};

class SUV : public Car
{
public:
    SUV(int id, string m, string mo, int y, string fuel)
        : Car(id, m, mo, y, fuel)
    {
    }

    void display() override
    {
        cout << "Vehicle Type: SUV" << endl;
        Car::display();
    }
};

// Second Base Class
class Aircraft
{
private:
    int flightRange;

public:
    Aircraft(int range)
    {
        flightRange = range;
    }

    void setFlightRange(int range)
    {
        flightRange = range;
    }

    int getFlightRange()
    {
        return flightRange;
    }

    void displayAircraft()
    {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

// Multiple Inheritance
class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id, string m, string mo, int y,
              string fuel, int range)
        : Car(id, m, mo, y, fuel), Aircraft(range)
    {
    }

    void display() override
    {
        cout << "Vehicle Type: Flying Car" << endl;
        Car::display();
        displayAircraft();
    }
};

// Static Member Definition
int Vehicle::totalVehicles = 0;

// Vehicle Registry Class
class VehicleRegistry
{
private:
    Vehicle *vehicles[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    // Destructor
    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete vehicles[i];
        }
    }

    // Add Vehicle Function
    void addVehicle()
    {
        if (count >= 100)
        {
            cout << "Registry is full!" << endl;
            return;
        }

        int choice, id, year;
        string manufacturer, model, fuel;

        cout << endl;
        cout << "----- ADD VEHICLE -----" << endl;
        cout << "1. Car" << endl;
        cout << "2. Electric Car" << endl;
        cout << "3. Sports Car" << endl;
        cout << "4. Sedan" << endl;
        cout << "5. SUV" << endl;
        cout << "6. Flying Car" << endl;
        cout << "Enter vehicle type: ";
        cin >> choice;

        if (choice < 1 || choice > 6)
        {
            cout << "Invalid vehicle type!" << endl;
            return;
        }

        cout << "Enter Vehicle ID: ";
        cin >> id;

        // Check Duplicate ID
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "Vehicle ID already exists!" << endl;
                return;
            }
        }

        cout << "Enter Manufacturer: ";
        cin >> ws;
        getline(cin, manufacturer);

        cout << "Enter Model: ";
        getline(cin, model);

        cout << "Enter Year: ";
        cin >> year;

        cout << "Enter Fuel Type: ";
        cin >> ws;
        getline(cin, fuel);

        switch (choice)
        {
        case 1:
            vehicles[count] =
                new Car(id, manufacturer, model, year, fuel);
            break;

        case 2:
        {
            int battery;

            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;

            vehicles[count] =
                new ElectricCar(id, manufacturer, model, year,
                                fuel, battery);
            break;
        }

        case 3:
        {
            int battery, speed;

            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;

            cout << "Enter Top Speed (km/h): ";
            cin >> speed;

            vehicles[count] =
                new SportsCar(id, manufacturer, model, year,
                              fuel, battery, speed);
            break;
        }

        case 4:
            vehicles[count] =
                new Sedan(id, manufacturer, model, year, fuel);
            break;

        case 5:
            vehicles[count] =
                new SUV(id, manufacturer, model, year, fuel);
            break;

        case 6:
        {
            int range;

            cout << "Enter Flight Range (km): ";
            cin >> range;

            vehicles[count] =
                new FlyingCar(id, manufacturer, model, year,
                              fuel, range);
            break;
        }
        }

        count++;
        cout << "Vehicle added successfully!" << endl;
    }

    // Display All Vehicles
    void displayVehicles()
    {
        if (count == 0)
        {
            cout << "No vehicles found!" << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << endl;
            cout << "-------------------------" << endl;
            vehicles[i]->display();
            cout << "-------------------------" << endl;
        }

        cout << "Total Vehicles: " << count << endl;
    }

    // Search Vehicle Function
    void searchVehicle()
    {
        int id;

        cout << "Enter Vehicle ID to search: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "Vehicle Found!" << endl;
                vehicles[i]->display();
                return;
            }
        }

        cout << "Vehicle not found!" << endl;
    }
};

// Main Function
int main()
{
    VehicleRegistry registry;
    int choice;

    do
    {
        cout << endl;
        cout << "===== VEHICLE REGISTRY SYSTEM =====" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. View All Vehicles" << endl;
        cout << "3. Search Vehicle by ID" << endl;
        cout << "4. Show Total Vehicles" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registry.addVehicle();
            break;

        case 2:
            registry.displayVehicles();
            break;

        case 3:
            registry.searchVehicle();
            break;

        case 4:
            cout << "Total Vehicles: "
                 << Vehicle::totalVehicles << endl;
            break;

        case 5:
            cout << "Thank you for using the system!" << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}