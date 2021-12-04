/**
 * @file hse_lib.cpp
 * @author Aras Taşkıran (aras.taskiran@argeloji.com)
 * @brief
 * @version 0.1
 * @date 2021-12-03
 *
 * @copyright Copyright (c) 2021 Argeloji Mühendislik
 *
 */

#include <hse_lib.h>
#include <Arduino.h>

void HSELib::update()
{
    checkToggle();
    _updateOutputs(updateInputStates());
}

void HSELib::_updateOutputs(int numeric)
{
    normalRelay(_getNormalState(numeric));
    warningRelay(_getWarningState(numeric));
    dangerRelay(_getDangerState(numeric));
    buzzerRelay(_getBuzzerState(numeric));
}

bool HSELib::_getNormalState(int inputs_numeric)
{
    return (inputs_numeric < 3 || inputs_numeric == 10);
}

bool HSELib::_getWarningState(int inputs_numeric)
{
    return (inputs_numeric == 8 || inputs_numeric == 9);
}

bool HSELib::_getDangerState(int inputs_numeric)
{
    return (inputs_numeric >= 3 && inputs_numeric <= 7) ||
           inputs_numeric >= 11;
}

bool HSELib::_getBuzzerState(int inputs_numeric)
{
    return (inputs_numeric >= 3 && inputs_numeric <= 7) ||
           inputs_numeric >= 11 ||
           inputs_numeric == 9;
}
