/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

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
