// ----------------------------------------------------------------------------
// jctool.cpp — Added vJoy integration to send Joy-Con gyro data to a virtual joystick
// ----------------------------------------------------------------------------

#include "jctool.h"
#include "hidapi.h"

// Include vJoy SDK
#include "vJoyInterface.h"
#define VJOY_ID 1

int main(int argc, char* argv[])
{
    // ... existing initialization and Joy-Con setup code ...

    // Initialize vJoy
    if (!vJoyEnabled()) {
        fprintf(stderr, "Error: vJoy driver not enabled or not installed.\n");
        return -1;
    }
    if (!AcquireVJD(VJOY_ID)) {
        fprintf(stderr, "Error: Failed to acquire vJoy device %d.\n", VJOY_ID);
        return -1;
    }

    // Query axis range for normalization
    LONG axisMin = GetVJDAxisMin(VJOY_ID, HID_USAGE_X);
    LONG axisMax = GetVJDAxisMax(VJOY_ID, HID_USAGE_X);

    // Main read-loop: read gyro, map to vJoy axes, and send
    bool running = true;
    while (running) {
        // ... code that reads a HID report into 'buf' ...

        // Parse raw gyro data from joy-con report (example offsets)
        // Note: replace 0x?? with the actual offsets where gyro X/Y live
        int16_t rawGyroX = *(int16_t*)&buf[0x20]; // example
        int16_t rawGyroY = *(int16_t*)&buf[0x22]; // example

        // Convert raw gyro to degrees (driver already does any scaling)
        float degPerSecX = rawGyroX; 
        float degPerSecY = rawGyroY;

        // Map from [-maxDeg, +maxDeg] to [axisMin, axisMax]
        const float maxDeg = 2000.0f; // Joy-Con gyro full-scale ±2000°/s
        LONG vjoyX = (LONG)((degPerSecX + maxDeg) / (2 * maxDeg) * (axisMax - axisMin) + axisMin);
        LONG vjoyY = (LONG)((degPerSecY + maxDeg) / (2 * maxDeg) * (axisMax - axisMin) + axisMin);

        // Clamp
        vjoyX = (vjoyX < axisMin) ? axisMin : (vjoyX > axisMax) ? axisMax : vjoyX;
        vjoyY = (vjoyY < axisMin) ? axisMin : (vjoyY > axisMax) ? axisMax : vjoyY;

        // Send to vJoy device
        SetAxis(vjoyX, VJOY_ID, HID_USAGE_X);
        SetAxis(vjoyY, VJOY_ID, HID_USAGE_Y);

        // ... any other processing, exit conditions ...
    }

    // Clean up vJoy
    RelinquishVJD(VJOY_ID);

    // ... existing shutdown code ...

    return 0;
}
