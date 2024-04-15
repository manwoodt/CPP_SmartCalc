#ifdef CALC_CONTROLLER_H
#define CALC_CONTROLLER_H

#include <string>

namespace s21
{
    class Controller
    {
    private:
    public:
        Controller();
        ~Controller();

        void CalculateValue(MainWindow *main_window);
    };

    Controller::Controller();
    Controller::~Controller();

#endif CALC_CONTROLLER_H