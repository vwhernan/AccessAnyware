#include <iostream> 

class Microwave {
    int powerlevel;
    int cooktime;

public:
    Microwave() : powerlevel(1), cooktime(0) {}
  
    int getPowerLevel() { return powerlevel; }
    int getCookTime() { return cooktime; }

    void addThirty() { cooktime = cooktime + 30; }

    void powerToggle() {
        if (powerlevel == 1) { 
            powerlevel++; 
            return;
        }
        if (powerlevel == 2) {
            powerlevel--; 
            return;
        }
    }

    void resetSettings() {
        cooktime = 0;
        powerlevel = 1;
    }

    void Start() {
        std::cout << "Cooking for " << cooktime << " seconds, at level " << powerlevel << std::endl;

    }

};

int main()
{
    Microwave KitchenAid;
    
    //Display initial settings
    KitchenAid.Start();

    //toggle power level to two then display
    KitchenAid.powerToggle();
    KitchenAid.Start();

    //toggle power level to one add 90 seconds then display
    KitchenAid.powerToggle();
    KitchenAid.addThirty();
    KitchenAid.addThirty();
    KitchenAid.addThirty();
    KitchenAid.Start();

    //reset and display
    KitchenAid.resetSettings();
    KitchenAid.Start();
    
    return 0;
}

