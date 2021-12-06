

class HSERelay
{
public:
    /**
     * @brief Set the Normal State Output object
     *
     * @param io Digital IO Number
     * @param blink Has blink feature (default false)
     * @param mode Output mode (default true) true=normal false=inverted
     */
    static void setNormalStateOutput(int io, bool blink = false, bool mode = false);

    /**
     * @brief Set the Warning State Output object
     *
     * @param io Digital IO Number
     * @param blink Has blink feature (default false)
     * @param mode Output mode (default true) true=normal false=inverted
     */
    static void setWarningStateOutput(int io, bool blink = false, bool mode = false);

    /**
     * @brief Set the Danger State Output object
     *
     * @param io Digital IO Number
     * @param blink Has blink feature (default false)
     * @param mode Output mode (default true) true=normal false=inverted
     */
    static void setDangerStateOutput(int io, bool blink = false, bool mode = false);

    /**
     * @brief Set the Buzzer Output object
     *
     * @param io Digital IO Number
     * @param blink Has blink feature (default false)
     * @param mode Output mode (default true) true=normal false=inverted
     */
    static void setBuzzerOutput(int io, bool blink = false, bool mode = false);

    /**
     * @brief Set the Toggle Duration object
     *
     * @param duration millisecond (default 500ms)
     */
    static void setToggleDuration(int duration = 500, bool async=false);

    static bool isNormalStateChanged();
    static bool isWarningStateChanged();
    static bool isDangerStateChanged();
    static bool isBuzzerStateChanged();

    static bool getNormalState();
    static bool getWarningState();
    static bool getDangerState();
    static bool getBuzzerState();
    static bool getToggleVal();

private:
    static unsigned long _last_change;
    static unsigned int _tooge_duration;
    static unsigned int _tooge_async_duration;
    static bool _toggle_val;

    static int _normal_state_out_pin;
    static int _warning_state_out_pin;
    static int _danger_state_out_pin;
    static int _buzzer_out_pin;

    static bool _is_normal_state_changed;
    static bool _is_warning_state_changed;
    static bool _is_danger_state_changed;
    static bool _is_buzzer_state_changed;

    static bool _normal_state_out_mode;
    static bool _warning_state_out_mode;
    static bool _danger_state_out_mode;
    static bool _buzzer_out_mode;
    static bool _is_toggle_async;

    /**
     * @brief Current Normal State Output Value
     *
     */
    static bool _normal_state_out;

    /**
     * @brief Current Warning State Output Value
     *
     */
    static bool _warning_state_out;

    /**
     * @brief Current Danger State Output Value
     *
     */
    static bool _danger_state_out;

    /**
     * @brief Current Buzzer State Output Value
     *
     */
    static bool _buzzer_state_out;

    static void _fixToggleValue(bool event);

    /**
     * @brief Checks if the output pin has a flashing feature.
     *
     * @param value Final value
     * @param blink Blink prop
     */
    static bool _isBlink(bool value, bool blink, bool mode);

    static void _resetLastChange();
    static void _setToggleValue(bool value);
    static unsigned int _getCurrentToggleDuration();

protected:
    static bool normal_state_blink;
    static bool warning_state_blink;
    static bool danger_state_blink;
    static bool buzzer_blink;

    static void resetEvents();
    static void normalRelay(bool value);
    static void warningRelay(bool value);
    static void dangerRelay(bool value);
    static void buzzerRelay(bool value);

    /**
     * @brief Calculate toggle value state
     *
     */
    static void checkToggle();
};