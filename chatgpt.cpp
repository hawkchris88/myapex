#pragma once
#include <iostream>
#include "Utils.cpp"
#include "Memory.cpp"
#include "Offsets.cpp"

class ButtonController {
public:
    class KButton {
    public:
        int down[2];
        int state;
    };

    class InState {
    public:
        // The raw button state.
        KButton button;

        // True if the button is held down.
        bool state;
        // Set to true if the button should be overriden.
        bool force;
        // Force the button to be pressed.
        bool press;
        // Force the button to be released.
        bool release;

        void update(uint32_t address) {
            // Read the current button state from game memory.
            mem::Read(address, &button, sizeof(KButton));

            // Update the "state" field based on the "down" array.
            state = button.down[0] != 0 || button.down[1] != 0;

            // If the button should be overriden, set the "down" array and "state" field accordingly.
            if (force) {
                button.down[0] = press ? 1 : 0;
                button.down[1] = press ? 1 : 0;
                state = press;
            }

            // If the button should be released, set the "down" array and "state" field accordingly.
            if (release) {
                button.down[0] = 0;
                button.down[1] = 0;
                state = false;
            }
        }

        void post(uint32_t address) {
            // Write the updated button state to game memory.
            mem::Write(address + 8, &button.state, sizeof(int));
        }
    };

    ButtonController() {
        // Initialize the "forward" button state with default values.
        forward = InState{};
    }

    // The "forward" button state.
    InState forward;
};
