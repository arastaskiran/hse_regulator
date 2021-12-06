/**
 * @file hse_relay.cpp
 * @author Aras Taşkıran (aras.taskiran@argeloji.com)
 * @brief
 * @version 0.1
 * @date 2021-12-03
 *
 * @copyright Copyright (c) 2021 Argeloji Mühendislik
 *
 */

#include <hse_relay.h>
#include <Arduino.h>

unsigned long HSERelay::_last_change{millis()};
unsigned int HSERelay::_tooge_duration{500};
unsigned int HSERelay::_tooge_async_duration{1000};

bool HSERelay::_normal_state_out{false};
bool HSERelay::_warning_state_out{false};
bool HSERelay::_danger_state_out{false};
bool HSERelay::_buzzer_state_out{false};

bool HSERelay::normal_state_blink{false};
bool HSERelay::warning_state_blink{false};
bool HSERelay::danger_state_blink{false};
bool HSERelay::buzzer_blink{false};

bool HSERelay::_toggle_val{false};

bool HSERelay::_is_normal_state_changed{false};
bool HSERelay::_is_warning_state_changed{false};
bool HSERelay::_is_danger_state_changed{false};
bool HSERelay::_is_buzzer_state_changed{false};
bool HSERelay::_normal_state_out_mode{false};
bool HSERelay::_warning_state_out_mode{false};
bool HSERelay::_danger_state_out_mode{false};
bool HSERelay::_buzzer_out_mode{false};
bool HSERelay::_is_toggle_async{false};

int HSERelay::_normal_state_out_pin{8};
int HSERelay::_warning_state_out_pin{9};
int HSERelay::_danger_state_out_pin{7};
int HSERelay::_buzzer_out_pin{6};

void HSERelay::setToggleDuration(int duration, bool async)
{
    _tooge_duration = duration;
    _is_toggle_async=async;
    _tooge_async_duration = async ? duration * 2 : duration;
}

void HSERelay::checkToggle()
{
    if ((millis() - _last_change) > _getCurrentToggleDuration())
    {
        _setToggleValue(!_toggle_val);
        _resetLastChange();
    }
}

unsigned int HSERelay::_getCurrentToggleDuration()
{
    if (_is_toggle_async && _toggle_val)
        return _tooge_async_duration;

    return _tooge_duration;
}

void HSERelay::setNormalStateOutput(int io, bool blink, bool mode)
{
    _normal_state_out_pin = io;
    normal_state_blink = blink;
    _normal_state_out_mode = mode;
    pinMode(io, OUTPUT);
}

void HSERelay::setWarningStateOutput(int io, bool blink, bool mode)
{
    _warning_state_out_pin = io;
    warning_state_blink = blink;
    _warning_state_out_mode = mode;
    pinMode(io, OUTPUT);
}

void HSERelay::setDangerStateOutput(int io, bool blink, bool mode)
{
    _danger_state_out_pin = io;
    danger_state_blink = blink;
    _danger_state_out_mode = mode;
    pinMode(io, OUTPUT);
}

void HSERelay::setBuzzerOutput(int io, bool blink, bool mode)
{
    _buzzer_out_pin = io;
    buzzer_blink = blink;
    _buzzer_out_mode = mode;
    pinMode(io, OUTPUT);
}

void HSERelay::normalRelay(bool value)
{
    _is_normal_state_changed = value != _normal_state_out;
    _fixToggleValue(_is_normal_state_changed);
    digitalWrite(
        _normal_state_out_pin,
        _isBlink(value, normal_state_blink, _normal_state_out_mode));

    _normal_state_out = value;
}

void HSERelay::warningRelay(bool value)
{
    _is_warning_state_changed = value != _warning_state_out;
    _fixToggleValue(_is_warning_state_changed);
    digitalWrite(
        _warning_state_out_pin,
        _isBlink(value, warning_state_blink, _warning_state_out_mode));

    _warning_state_out = value;
}

void HSERelay::dangerRelay(bool value)
{
    _is_danger_state_changed = value != _danger_state_out;
    _fixToggleValue(_is_danger_state_changed);
    digitalWrite(
        _danger_state_out_pin,
        _isBlink(value, danger_state_blink, _danger_state_out_mode));

    _danger_state_out = value;
}

void HSERelay::buzzerRelay(bool value)
{
    _is_buzzer_state_changed = value != _buzzer_state_out;
    _fixToggleValue(_is_buzzer_state_changed);
    digitalWrite(
        _buzzer_out_pin,
        _isBlink(value, buzzer_blink, _buzzer_out_mode));

    _buzzer_state_out = value;
}

void HSERelay::resetEvents()
{
    _is_normal_state_changed = false;
    _is_warning_state_changed = false;
    _is_danger_state_changed = false;
    _is_buzzer_state_changed = false;
}

bool HSERelay::isNormalStateChanged()
{
    return _is_normal_state_changed;
}

bool HSERelay::isWarningStateChanged()
{
    return _is_warning_state_changed;
}

bool HSERelay::isDangerStateChanged()
{
    return _is_danger_state_changed;
}

bool HSERelay::isBuzzerStateChanged()
{
    return _is_buzzer_state_changed;
}

void HSERelay::_fixToggleValue(bool event)
{
    if (event)
    {
        _setToggleValue(true);
        _resetLastChange();
    }
}

void HSERelay::_resetLastChange()
{
    _last_change = millis();
}

void HSERelay::_setToggleValue(bool value)
{
    _toggle_val = value;
}

bool HSERelay::_isBlink(bool value, bool blink, bool mode)
{
    bool val = value && blink ? _toggle_val : value;
    return mode ? val : !val;
}

bool HSERelay::getNormalState()
{
    return _normal_state_out;
}

bool HSERelay::getWarningState()
{
    return _warning_state_out;
}

bool HSERelay::getDangerState()
{
    return _danger_state_out;
}

bool HSERelay::getBuzzerState()
{
    return _buzzer_state_out;
}

bool HSERelay::getToggleVal()
{
    return _toggle_val;
}
