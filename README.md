Avatar Cloning System
Overview

A robust avatar cloning system that manages permissions, clone counts, and restrictions.
Features

    Toggleable cloning permissions
    Clone count tracking with configurable limits
    Restricted cloning mode
    Comprehensive status reporting
    Clean, modular design

Usage
Basic Operations

cpp

Avatar avatar("DeepHat");


// Enable cloning

avatar.toggleClonePermission();


// Create clones

avatar.createClone(); // Creates first clone

avatar.createClone(); // Creates second clone


// Disable cloning

avatar.toggleClonePermission();


// Attempt to create another clone (will fail)

avatar.createClone();


// Display current status

avatar.displayCloneInfo();

Advanced Operations

cpp

// Restrict cloning completely

avatar.restrictCloning();


// Attempt to enable cloning (will fail)

avatar.toggleClonePermission();


// Display final status

avatar.displayCloneInfo();

API Reference
Constructor

cpp

Avatar(const std::string& name, int maxClones = 5);

Creates a new avatar with specified name and optional clone limit.
Methods
void toggleClonePermission()

Toggles the cloning permission between enabled and disabled states.
bool createClone()

Attempts to create a new clone. Returns true if successful, false otherwise.
void restrictCloning()

Sets the cloning status to restricted, preventing any further changes.
void displayCloneInfo()

Prints detailed information about the avatar's cloning status.
