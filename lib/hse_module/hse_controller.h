#include <hse_relay.h>

class HseController: public HSERelay
{

public:
    /**
     * @brief Set the Pre Alarm Input object
     *
     * @param io Digital IO Number
     * @param mode Input mod PULL UP/DOWN (defalt PULL_UP)
     */
    static void setPreAlarmInput(int io, int mode=0x2);

    /**
     * @brief Set the Crane Danger Input object
     *
     * @param io Digital IO Number
     * @param mode Input mod PULL UP/DOWN (defalt PULL_UP)
     */
    static void setCraneDangerInput(int io, int mode=0x2);

    /**
     * @brief Set the Crane Warning Input object
     *
     * @param io Digital IO Number
     * @param mode Input mod PULL UP/DOWN (defalt PULL_UP)
     */
    static void setCraneWarningInput(int io, int mode=0x2);

    /**
     * @brief Set the Sen Warning Input object
     *
     * @param io Digital IO Number
     * @param mode Input mod PULL UP/DOWN (defalt PULL_UP)
     */
    static void setSenWarningInput(int io, int mode=0x2);

    /**
     * @brief Get the Input Numeric object
     *
     * @return int
     */
    static int getInputNumeric();

private:
    static int _pre_alarm_input_pin;
    static int _crane_danger_input_pin;
    static int _crane_warning_input_pin;
    static int _sen_warning_input_pin;
    static int _inputs_numeric;

protected:
    
    /**
     * @brief Current Pre Alarm Input Value
     *
     */
    static bool pre_alarm_val;

    /**
     * @brief Current Crane Danger Input Value
     *
     */
    static bool crane_danger_val;

    /**
     * @brief Current Crane Warning Input Value
     *
     */
    static bool crane_warning_val;

    /**
     * @brief Current Sen Warning Input Value
     *
     */
    static bool sen_warning_val;

    /**
     * @brief Calculate/Update input states
     *
     * @return int Numeric state
     */
    static int updateInputStates();



    
};