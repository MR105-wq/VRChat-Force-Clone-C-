#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

enum class CloningStatus {
    ENABLED,
    DISABLED,
    RESTRICTED
};

class Avatar {
private:
    std::string name;
    CloningStatus cloningStatus;
    int cloneCount;
    int maxClones;
    
public:
    Avatar(const std::string& name, int maxClones = 5)
        : name(name), cloningStatus(CloningStatus::DISABLED),
          cloneCount(0), maxClones(maxClones) {}
          
    void toggleClonePermission() {
        switch (cloningStatus) {
            case CloningStatus::ENABLED:
                cloningStatus = CloningStatus::DISABLED;
                break;
            case CloningStatus::DISABLED:
                cloningStatus = CloningStatus::ENABLED;
                break;
            case CloningStatus::RESTRICTED:
                std::cout << "Cannot change cloning permission - avatar is restricted." << std::endl;
                return;
        }
        std::cout << name << "'s cloning permission is now " 
                  << (cloningStatus == CloningStatus::ENABLED ? "ENABLED" : "DISABLED") << std::endl;
    }
    
    bool createClone() {
        if (cloningStatus != CloningStatus::ENABLED) {
            std::cout << "Cannot create clone - cloning is disabled or restricted." << std::endl;
            return false;
        }
        
        if (cloneCount >= maxClones) {
            std::cout << "Cannot create clone - maximum clone limit reached (" << maxClones << ")." << std::endl;
            return false;
        }
        
        cloneCount++;
        std::cout << "Created clone #" << cloneCount << " for " << name << std::endl;
        return true;
    }
    
    void restrictCloning() {
        cloningStatus = CloningStatus::RESTRICTED;
        std::cout << name << "'s cloning has been restricted." << std::endl;
    }
    
    void displayCloneInfo() {
        std::cout << "Avatar: " << name << std::endl;
        std::cout << "Cloning Status: ";
        switch (cloningStatus) {
            case CloningStatus::ENABLED: std::cout << "ENABLED"; break;
            case CloningStatus::DISABLED: std::cout << "DISABLED"; break;
            case CloningStatus::RESTRICTED: std::cout << "RESTRICTED"; break;
        }
        std::cout << std::endl;
        std::cout << "Current clones: " << cloneCount << "/" << maxClones << std::endl;
    }
};

int main() {
    Avatar avatar("DeepHat");
    
    avatar.displayCloneInfo();
    avatar.toggleClonePermission();
    avatar.createClone();
    avatar.createClone();
    avatar.restrictCloning();
    avatar.toggleClonePermission();
    avatar.createClone();
    
    return 0;
}