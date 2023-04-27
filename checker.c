#include <stdio.h>
#include <assert.h>

#define TEMPERATURE_MAX_THRESHOLD        45
#define TEMPERATURE_MIN_THRESHOLD        0

#define STATE_OF_CHARGE_MIN_THRESHOLD    20
#define STATE_OF_CHARGE_MAX_THRESHOLD    80

#define CHARGE_RATE_MAX_THRESHOLD        0.8f

int temperatureIsInRange(float temperature)
{
    int result = 1;
    if (temperature < TEMPERATURE_MIN_THRESHOLD)
    {
        printf("Temperature is low!\nTemperature: %f\n", temperature);
        result = 0;
    }
    else if (temperature > TEMPERATURE_MAX_THRESHOLD)
    {
        printf("Temperature is high!\nTemperature: %f\n", temperature);
        result = 0;
    }
    return result;
}

int stateOfChargeIsInRange(float soc)
{
    int result = 1;
    if (soc < STATE_OF_CHARGE_MIN_THRESHOLD)
    {
        printf("State of Charge is low!\nState of Charge: %f\n", soc);
        result = 0;
    }
    else if (soc > STATE_OF_CHARGE_MAX_THRESHOLD)
    {
        printf("State of Charge is high!\nState of Charge: %f\n", soc);
        result = 0;
    }
    return result;
}

int chargeRateIsAboveLimit(float chargeRate)
{
    int result = 1;
    if (chargeRate > CHARGE_RATE_MAX_THRESHOLD)
    {
        printf("Charge Rate is above its limit!\nCharge Rate: %f\n", chargeRate);
        result = 0;
    }
    return result;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int result = 0;
    if (temperatureIsInRange(temperature) && stateOfChargeIsInRange(soc) && chargeRateIsAboveLimit(chargeRate))
    {
        result = 1;
    }
    return result;
}

int main() {
    assert(!temperatureIsInRange(-0.1));
    assert(temperatureIsInRange(0));
    assert(temperatureIsInRange(0.1));
    assert(temperatureIsInRange(22));
    assert(temperatureIsInRange(44.9));
    assert(temperatureIsInRange(45));
    assert(!temperatureIsInRange(45.1));

    assert(!stateOfChargeIsInRange(19.9));
    assert(stateOfChargeIsInRange(20));
    assert(stateOfChargeIsInRange(20.1));
    assert(stateOfChargeIsInRange(50));
    assert(stateOfChargeIsInRange(79.9));
    assert(stateOfChargeIsInRange(80));
    assert(!stateOfChargeIsInRange(80.1));

    assert(chargeRateIsAboveLimit(0.7));
    assert(chargeRateIsAboveLimit(0.8));
    assert(!chargeRateIsAboveLimit(0.9));
    assert(chargeRateIsAboveLimit(0));
    assert(chargeRateIsAboveLimit(-1));

    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}
