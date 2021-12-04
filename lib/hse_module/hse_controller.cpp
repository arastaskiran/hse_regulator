/**
 * @file hse_controller.cpp
 * @author Aras Taşkıran (aras.taskiran@argeloji.com)
 * @brief
 * @version 0.1
 * @date 2021-12-03
 *
 * @copyright Copyright (c) 2021 Argeloji Mühendislik
 *
 */

#include <hse_controller.h>
#include <Arduino.h>



int HseController::_inputs_numeric{0};
int HseController::_pre_alarm_input_pin{4};
int HseController::_crane_danger_input_pin{2};
int HseController::_crane_warning_input_pin{3};
int HseController::_sen_warning_input_pin{5};


bool HseController::pre_alarm_val{false};
bool HseController::crane_danger_val{false};
bool HseController::crane_warning_val{false};
bool HseController::sen_warning_val{false};

void HseController::setPreAlarmInput(int io, int mode)
{
    _pre_alarm_input_pin = io;
    pinMode(io, mode);
}

void HseController::setCraneDangerInput(int io, int mode)
{
    _crane_danger_input_pin = io;
    pinMode(io, mode);
}

void HseController::setCraneWarningInput(int io, int mode)
{
    _crane_warning_input_pin = io;
    pinMode(io, mode);
}

void HseController::setSenWarningInput(int io, int mode)
{
    _sen_warning_input_pin = io;
    pinMode(io, mode);
}

int HseController::updateInputStates()
{
    resetEvents();

    pre_alarm_val = !digitalRead(_pre_alarm_input_pin);
    crane_danger_val = !digitalRead(_crane_danger_input_pin);
    crane_warning_val = !digitalRead(_crane_warning_input_pin);
    sen_warning_val = !digitalRead(_sen_warning_input_pin);

    _inputs_numeric = 0;
    if (sen_warning_val)
        _inputs_numeric += 1;
    if (crane_warning_val)
        _inputs_numeric += 2;
    if (crane_danger_val)
        _inputs_numeric += 4;
    if (pre_alarm_val)
        _inputs_numeric += 8;

    return _inputs_numeric;
}


