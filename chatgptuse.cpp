

//     // Update the "forward" button state.
        buttonController.forward.update(ptrLongForward);

        // if (!isOnGround())
        // {
        //     buttonController.forward.force = true;
        //     if (!buttonController.forward.release)
        //     {
        //         buttonController.forward.press = false;
        //         buttonController.forward.release = true;
        //     }
        //     else
        //     {
        //         buttonController.forward.release = false;
        //         buttonController.forward.press = true;
        //     }
        // }
        // else
        // { // prevent stopping when hit the ground
        //     if (buttonController.forward.release && buttonController.forward.button.down[0] != 0)
        //     {
        //         buttonController.forward.release = false;
        //         buttonController.forward.press = true;
        //     }
        //     else if (buttonController.forward.press && buttonController.forward.button.down[0] != 0)
        //     {
        //         buttonController.forward.force = false;
        //     }
        //     else if (buttonController.forward.press && buttonController.forward.button.down[0] == 0)
        //     {
        //         buttonController.forward.release = true;
        //         buttonController.forward.press = false;
        //     }
        //     else if (buttonController.forward.release && buttonController.forward.button.down[0] == 0)
        //     {
        //         buttonController.forward.force = false;
        //     }
        // }/


        ///////////////////////////////////////////////////////////////////////////////////////
        // Update and apply the changes to the "forward" button state.
        // buttonController.forward.update(ptrLongForward);
        // buttonController.forward.post(ptrLongForward);

// ButtonController buttonController;

// while (true) {
//     // Update the "forward" button state.
//     buttonController.forward.update(offsets.base + offsets.in_forward);

//     if (!player.isOnGround()) {
//         buttonController.forward.force = true;
//         if (!buttonController.forward.release) {
//             buttonController.forward.press = false;
//             buttonController.forward.release = true;
//         } else {
//             buttonController.forward.release = false;
//             buttonController.forward.press = true;
//         }
//     } else { // prevent stopping when hit the ground
//         if (buttonController.forward.release && buttonController.forward.button.down[0] != 0) {
//             buttonController.forward.release = false;
//             buttonController.forward.press = true;
//         } 
//         else if (buttonController.forward.press && buttonController.forward.button.down[0] != 0) {
//             buttonController.forward.force = false;
//         }
//          else if (buttonController.forward.press && buttonController.forward.button.down[0] == 0) {
//             buttonController.forward.release = true;
// buttonController.forward.press = false;
// } 
// else if (buttonController.forward.release && buttonController.forward.button.down[0] == 0) {
// buttonController.forward.force = false;
// }
// }
// // Update and apply the changes to the "forward" button state.
// buttonController.forward.update(offsets.base + offsets.in_forward);
// buttonController.forward.post(offsets.base + offsets.in_forward);
// }
