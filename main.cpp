// Include the libraries
#include <iostream>
#include <math.h>
// Define numbers useful/needed for planetary postioning
#define PI          3.14159265358979323846
#define RADEG       (180.0/PI)
#define DEGRAD      (PI/180.0)
#define sind(x)     sin((x)*DEGRAD)
#define cosd(x)     cos((x)*DEGRAD)
#define tand(x)     tan((x)*DEGRAD)
#define asind(x)    (RADEG*asin(x))
#define acosd(x)    (RADEG*acos(x))
#define atand(x)    (RADEG*atan(x))
#define atan2d(y,x) (RADEG*atan2((y),(x)))

//Some needed math functions:

    // Reduces an angle to between 0 and 360 degrees.
    double rev( double x )
    {
        return  x - floor(x/360.0)*360.0;
    }

    // Computes the cube root.
    double cbrt( double x )
    {
        if ( x > 0.0 )
            return exp( log(x) / 3.0 );
        else if ( x < 0.0 )
            return -cbrt(-x);
        else /* x == 0.0 */
            return 0.0;
    }

// Declaration of function PlanetPosition()
void CustomPlanetPosition()
{
    using namespace std;  // we need this in each function that uses cout and endl

    // The following line will harvest variales from the user for our caculation.

    // Get the static timepoint from which to calculate planet positions by asking the user for a standard gregorian date and converting to Julian Date.
    int t = -1;
    int day = -1;
    int month = -1;
    int year = -1;
    cout << "Before we go any further, space is safer when static. You may" << endl;
    cout << "find a lot of dead players on your game otherwise. In order to" << endl;
    cout << "facilitate the obital positioning of planets; we thereby need a" << endl;
    cout << "uninversal point of time from which to calculate this. Please" << endl;
    cout << "enter that time now...\n\n" << endl;
    cout << "Day: ";
    cin >> day;
    cout << endl << "Month: ";
    cin >> month;
    cout << endl << "Year: ";
    cin >> year;
    cout << "\n\n" << endl;
    t = 367*year - (7*(year + ((month+9)/12)))/4 + (275*month)/9 + day - 730530;
    cout << t << endl;

    cout << "Please input the numbers for the requested variables:" << endl;

    long double a = -1;
    cout << "a  Mean distance, or semi-major axis.\n" << endl;
    cout << "Your value for a: ";
    cin >> a;
    cout << "\n\n" << endl;

    long double e =-1;
    cout << "e  Eccentricity.\n" << endl;
    cout << "Your value for e: ";
    cin >> e;
    cout << "\n\n" << endl;

    int T = -1;
    int Day = -1;
    int Month = -1;
    int Year = -1;
    cout << "T Time at perihelion. This one is important and will be unique for" << endl;
    cout << "   each planet. This is any date at which the planet is at it's" << endl;
    cout << "   maximum distance from the star or body it orbits.\n" << endl;
    cout << "Your value for T:\n " << endl;
    cout << "Day: ";
    cin >> Day;
    cout << endl << "Month: ";
    cin >> Month;
    cout << endl << "Year: ";
    cin >> Year;
    cout << "\n\n" << endl;
    T = 367*Year - (7*(Year + ((Month+9)/12)))/4 + (275*Month)/9 + Day - 730530;

    cout << T << endl;

    long double i = -1;
    cout << "i  Inclination, i.e. the \"tilt\" of the orbit relative to the" << endl;
    cout << "   ecliptic.  The inclination varies from 0 to 180 degrees. If" << endl;
    cout << "   the inclination is larger than 90 degrees, the planet is in" << endl;
    cout << "   a retrogade orbit, i.e. it moves \"backwards\".  The most" << endl;
    cout << "   well-known celestial body with retrogade motion is Comet Halley.\n" << endl;
    cout << "Your value for i: ";
    cin >> i;
    cout << "\n\n" << endl;

    long double N = -1;
    cout << "N  (usually written as \"Capital Omega\") Longitude of Ascending" << endl;
    cout << "   Node. This is the angle, along the ecliptic, from the Vernal" << endl;
    cout << "   Point to the Ascending Node, which is the intersection between" << endl;
    cout << "   the orbit and the ecliptic, where the planet moves from south" << endl;
    cout << "   of to north of the ecliptic, i.e. from negative to positive" << endl;
    cout << "   latitudes.\n" << endl;
    cout << "Your value for N: ";
    cin >> N;
    cout << "\n\n" << endl;

    long double w = -1;
    cout << "w  (usually written as \"small Omega\") The angle from the Ascending" << endl;
    cout << "   node to the Perihelion, along the orbit.\n" << endl;
    cout << "Your value for w: ";
    cin >> w;
    cout << "\n\n" << endl;

    long double KG = -1;
    cout << "KG The weight of the star/planet/moon in true kilograms.\n" << endl;
    cout << "Your value for KG: ";
    cin >> KG;
    cout << "\n\n" << endl;

    long double SolKG = -1;
    SolKG = 1.9891e30;

    // Determing the planets solar mass.
    cout << "Calculating Solar Mass..." << endl;
    long double m = -1;
    m = KG/SolKG;
    cout << "Solar Mass: " << m << "solar mass(es)\n" << endl;

    // Determine the Perihelion distance.
    cout << "Calculating Perihelion distance.." << endl;
    long double q = -1;
    q = a * (1 - e);
    cout << "Perihelion distance: " << q << "au\n" << endl;

    // Determine the Aphelion distance.
    cout << "Calculating Aphelion distance..." << endl;
    long double Q = -1;
    Q = a * (1 + e);
    cout << "Aphelion distance: " << Q << "au\n" << endl;

    // Determine the orbital period in days.
    cout << "Calculating orbital period..." << endl;
    long double P = -1;
    P = 365.256898326 * a*1.5/sqrt(1+m);
    cout << "Orbital period: " << P << "earth days\n" << endl;

    // Determine the daily motion in degrees per day.
    cout << "Calculating daily motion..." << endl;
    long double n = -1;
    n = 360 / P;
    cout << "Daily motion: " << n << " degrees per day\n" << endl;

    // Define variable for Mean Anomaly.
    cout << "Calculating Mean Anomaly..." << endl;
    long double M = -1;
    M = n * (t - T);
    M = M/360;
    cout << "Mean Anomaly: " << M << " degrees\n" << endl;

    // Determine the mean longitude.
    cout << "Calculating mean longitude..." << endl;
    long double L = -1;
    L = M + w + N;
    cout << "Mean Longitude: " << L << "degrees\n" << endl;

    // Determine the Eccentric Anomaly determined by Kepler's equation. This must
    // be reestimated until the variance is less than 0.005.
    cout << "Calculating Eccentric Anomaly determined by Kepler's equation..." << endl;
    long double E = -1;
    long double E0 = -1;
    long double E1 = -1;
    long double EV = -1;

    E0 = M + (180/PI) * e * sin(M) * (1 + e * cos(M));
    cout << E0 << endl;
    cout << "Reducing variance to less than 0.005..." << endl;
    int attempt = 0;
    while ((EV > 0.005 || EV < -0.005 || attempt == 300)) {
        E1 = E0 - (E0 - (180/PI) * e * sin(E0) - M) / (1 - e * cos(E0));
        EV = E1 - E0;
        E0 = E1;
        cout << E1 << endl;
        attempt = attempt +1;
    }

    E = E1;

    cout << "Eccentric Anomaly: " << E << "\n" << endl;

    long double v = -1;
    cout << "Calculating True Anomaly..." << endl;
    v = atan2(sqrt(1+e)*sin(E/2),sqrt(1-e)*cos(E/2));
    cout << "True Anomaly: " << v << "\n" << endl;

    long double r = -1;
    cout << "Calculating radius..." << endl;
    r = a * (1-e * cos(E));
    cout << "Radius: " << r << "\n" << endl;

    long double X = -1;
    long double Y = -1;
    long double Z = -1;

    cout << "Calculating Coordinates..." << endl;
    X = r*(cos(N)*cos(w+v)-sin(N)*sin(w+v)*cos(i));
    Y = r*(sin(N)*cos(w+v)+cos(N)*sin(w+v)*cos(i));
    Z = r*(sin(i)*sin(w+v));
    cout << "Solar Coordinates: " << X << ", " << Y << ", " << Z << endl;

}

// Declaration of main()
int main()
{
    using namespace std;  // we need this in each function that uses cout and endl
    cout << "Welcome to the HSpace Wizard Calculator. The primary goal of this" << endl;
    cout << "application is to speed up math intensive or redundant tasks for" << endl;
    cout << "PennMUSH wizards on games using HSpace 5.0 \n\n" << endl;

    CustomPlanetPosition();
    cout << "Ending main()" << endl;
    return 0;
}
