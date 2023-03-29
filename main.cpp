/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */
#include <iostream>
/*
 copied UDT 1:
 */
struct VendingMachine
{

    int numCokes;
    int numMountainDews = 14;
    int numQuarters = 44;
    int numDimes = 22;
    int numNickels = 3;

    VendingMachine();

    void deliverSoda(int sodaCode);
    void makeChange(int sodaCode, int payment);
    void displayPrice(int sodaCode);
    void loadCokes(int howMany);
};


VendingMachine::VendingMachine() : numCokes(42)
{
    std::cout << "VendingMachine being constructed!" << std::endl;
    std::cout << numCokes << " Cokes and " << numMountainDews << " Mountain Dews" << std::endl;
}

void VendingMachine::loadCokes(int howMany)
{
    for (int i = 0; i < howMany; ++i)
    {
        std::cout << "now have " << ++numCokes << " cokes \n";
    }
}

void VendingMachine::deliverSoda( int sodaCode) 
{
    if (sodaCode == 1)
    {
        --numCokes;
        std::cout << "Delivering Coke" << std::endl;
    }
    else
    {
        --numMountainDews;    
        std::cout << "Delivering Mountain Dew" << std::endl;
    }
}

void VendingMachine::makeChange(int sodaCode, int payment)
{
    std::cout << "Sodacode:" << sodaCode << std::endl;
    std::cout << "Change:" << 1.5 - payment << std::endl;
}

void VendingMachine::displayPrice(int sodacode)
{
    std::cout << "Sodacode:" << sodacode << "Price: ";
    std::cout << 1.5  << std::endl;
}

/*
 copied UDT 2:
 */
struct DigitalCamera
{

    float lightLevel = 2.455f;
    int availableStorage = 234235;
    float zoomDegree = 2.5334f;
    int horizontalResolution;
    int verticalResolution;

    DigitalCamera();

    struct MemoryCard
    { 
        bool isFull = false;
        bool isLocked = false;
        std::string cardName;
        int capacity;
        int memoryAddress = 0;

        MemoryCard();

        bool storePicture(std::string Picture);
        void setLock(bool lock);
        std::string getPicture(int address);
        
    };

    MemoryCard mCard;
    void setZoom(float degree);
    void deletePicture(int pictNum, MemoryCard memCard);
    void gradualDezoom();
};

DigitalCamera::DigitalCamera() : horizontalResolution(1024), verticalResolution(768)
{
    std::cout << "Digital Camera being constructed!" << std::endl;
    std::cout << "Resolution :" << horizontalResolution << "x" << verticalResolution << std::endl;
}

void DigitalCamera::gradualDezoom()
{
    while (zoomDegree > 0.001f) 
    {
        zoomDegree *= .7f;
        std::cout << "zoom degree: " << zoomDegree << std::endl;
    }
}
DigitalCamera::MemoryCard::MemoryCard() : capacity(4340000)
{
    std::cout << "Digital Camera Memory Card being constructed!" << std::endl;
    std::cout << "Capacity :" << capacity << std::endl;
}

bool DigitalCamera::MemoryCard::storePicture(std::string Picture)
{
    if (Picture != "")
    {
        std::cout << "Storing picture: " << Picture << std::endl;
        return true;
    }
    return false;
}
void DigitalCamera::setZoom( float degree )
{
    zoomDegree = degree;
}

void DigitalCamera::deletePicture(int pictNum, MemoryCard memCard)
{
    memCard.memoryAddress = pictNum * 1024;
    memCard.storePicture("BLANK");
    std::cout << "Deleting picture" << std::endl;
}
/*
 copied UDT 3:
 */
struct Submarine
{
    float depth;
    float heading;
    float waterPressure = 22.44f;
    int numShipmen = 44;
    int numTorpedos = 55;

    Submarine();

    struct Motor 
    { 
        std::string manufacturer = "RollsRoyce";
        std::string model = "Submaster 3000";
        int rpm = 0;
        bool isReady = true;
        int voltage = 220;

        Motor();

        void goOnline();
        void goOffline();
        bool setSpeed(int velocity);
    };

    void setDepth(float chosenDepth);
    void setDirection(float chosenHeading);
    bool fireTorpedo();
    void setVelocity(int velocity, Motor theMotor);
    void surface();
};

Submarine::Submarine() :depth(203.33f), heading(0.67f)
{
    std::cout << "Submarine being constructed!" << std::endl;
    std::cout << "Depth: " << depth << std::endl;
    std::cout << "Heading: " << heading << std::endl;
}

Submarine::Motor::Motor()
{
    std::cout << "Submarine Motor being constructed!" << std::endl;
}

void Submarine::surface()
{
    std::cout << "Surfacing...\n";
    while (depth > 0)
    {
        --depth;
        std::cout << "depth: " << depth << std::endl;
    }
}
void Submarine::setDepth(float chosenDepth)
{
    depth = chosenDepth;
    std::cout << "Depth set" << std::endl;
}

void Submarine::setDirection(float chosenHeading)
{
    heading = chosenHeading;
    std::cout << "Direction set" << std::endl;
}

bool Submarine::fireTorpedo()
{
    if (numTorpedos > 0)
    {       
        --numTorpedos;
        return true;
    }
    return false;
}

bool Submarine::Motor::setSpeed(int velocity)
{
    if (isReady && velocity>0)
    {
        return true;
    }
    return false;
}
void Submarine::setVelocity(int velocity, Motor theMotor)
{
    theMotor.setSpeed(velocity);
}

/*
 new UDT 4:
 with 2 member functions
 */
struct SodaSailor
{
    VendingMachine vendingMachine;
    Submarine submarine;
    void doCokeAndSubStuff();
    void deepChange();
    SodaSailor();
    ~SodaSailor();
};

SodaSailor::SodaSailor()
{
    std::cout << "Constructing SodaSailor\n";
}

SodaSailor::~SodaSailor()
{
    std::cout << "Destructing SodaSailor\n";
   
}
void SodaSailor::doCokeAndSubStuff()
{
    vendingMachine.loadCokes(33);
    submarine.surface();
}

void SodaSailor::deepChange()
{
    submarine.setDepth(400.f);
    vendingMachine.makeChange(1,20);
}
/*
 new UDT 5:
 with 2 member functions
 */
struct CameraManiac
{
    DigitalCamera nikon;
    DigitalCamera canon;
    void multiShot();
    void deZoomAll();
    CameraManiac();
    ~CameraManiac();
};

CameraManiac::CameraManiac()
{
    std::cout << "Constructing Camera Maniac\n";
}

CameraManiac::~CameraManiac()
{
    std::cout << "Destructing Camera Maniac\n";

}

void CameraManiac::multiShot()
{
    nikon.mCard.storePicture("Cat");
    canon.mCard.storePicture("Dog");
}

void CameraManiac::deZoomAll()
{
    nikon.gradualDezoom();
    canon.gradualDezoom();
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */





#include <iostream>
int main()
{

    
    VendingMachine vm;
    vm.deliverSoda(1);
    vm.makeChange(1,4);
    vm.displayPrice(1);


    DigitalCamera dc;
    DigitalCamera::MemoryCard mc;
    dc.setZoom(88.32f);
    dc.deletePicture(6, mc);

    Submarine sub;
    Submarine::Motor subMotor;
    sub.setDepth(99.4f);
    sub.setDirection(45.25);
    sub.fireTorpedo();
    sub.setVelocity(5, subMotor);

    vm.loadCokes(5);
    dc.gradualDezoom();
    sub.surface();

    SodaSailor ss;
    ss.doCokeAndSubStuff();
    ss.deepChange();

    CameraManiac cm;
    cm.multiShot();
    cm.deZoomAll();

    std::cout << "good to go!" << std::endl;
}
