#include "Utils.cpp"
#include "Memory.cpp"
#include "ButtonController.cpp"

class Movement
{
private:

    long ptrLongForward;
    long ptrLongFlags;
    long m_basePointer = 0;
    long getUnresolvedBasePointer()
    {
        long unresolvedBasePointer = offsets::REGION + offsets::LOCAL_PLAYER;
        return unresolvedBasePointer;
    }
    long getBasePointer()
    {
        if (m_basePointer == 0)
            m_basePointer = mem::ReadLong(getUnresolvedBasePointer());
        return m_basePointer;
    }
    ButtonController buttonController;
     const long OFFSET_FLAG= 0x0098;
    const u_int32_t OFFSET_IN_FORWARD =0x07642ca8;

public:
    Movement()
    {   long basePointer = getBasePointer();
        ptrLongForward = offsets::REGION  + offsets::OFFSET_IN_FORWARD;
        // ptrLongFlags = offsets::REGION + offsets::OFFSET_FLAGS;
    }

    

    bool isOnGround()
    {
       long basePointer = getBasePointer();
        long ptrLong = basePointer + offsets::OFFSET_FLAGS;
        int result = mem::ReadInt(ptrLong);
         return (result & 0x1) != 0;
    }

    void update()
    {
       

        //     // Update the "forward" button state.
        buttonController.forward.update(ptrLongForward);

        if (!isOnGround())
        {
            buttonController.forward.force = true;
            if (!buttonController.forward.release)
            {
                buttonController.forward.press = false;
                buttonController.forward.release = true;
            }
            else
            {
                buttonController.forward.release = false;
                buttonController.forward.press = true;
            }
        }
        else
        { // prevent stopping when hit the ground
            if (buttonController.forward.release && buttonController.forward.button.down[0] != 0)
            {
                buttonController.forward.release = false;
                buttonController.forward.press = true;
            }
            else if (buttonController.forward.press && buttonController.forward.button.down[0] != 0)
            {
                buttonController.forward.force = false;
            }
            else if (buttonController.forward.press && buttonController.forward.button.down[0] == 0)
            {
                buttonController.forward.release = true;
                buttonController.forward.press = false;
            }
            else if (buttonController.forward.release && buttonController.forward.button.down[0] == 0)
            {
                buttonController.forward.force = false;
            }
        }
        // Update and apply the changes to the "forward" button state.
        // buttonController.forward.update(ptrLongForward);
        buttonController.forward.post(ptrLongForward);
    }
};