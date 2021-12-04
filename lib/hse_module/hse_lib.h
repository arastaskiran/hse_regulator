#include <hse_controller.h>

class HSELib: public HseController
{

public:
    /**
     * @brief Call this method in the loop method
     * 
     */
    static void update();

   

private:

    /**
     * @brief Set the green light output
     * 
     * @param inputs_numeric Inputs decimal state
     * @return bool state
     */
    static bool _getNormalState(int inputs_numeric);

    /**
     * @brief Set the yellow light output
     * 
     * @param inputs_numeric Inputs decimal state
     * @return bool state
     */
    static bool _getWarningState(int inputs_numeric);

    /**
     * @brief Set the red light output
     * 
     * @param inputs_numeric Inputs decimal state
     * @return bool state
     */
    static bool _getDangerState(int inputs_numeric);

    /**
     * @brief Set the buzzer output
     * 
     * @param inputs_numeric Inputs decimal state
     * @return bool state
     */
    static bool _getBuzzerState(int inputs_numeric);

    /**
     * @brief Set Outputs
     * 
     * @param inputs_numeric 
     */
    static void _updateOutputs(int numeric);

    


};