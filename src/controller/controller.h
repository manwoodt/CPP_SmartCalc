#ifndef CALC_CONTROLLER_H
#define CALC_CONTROLLER_H

#include <string>

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  //Controller();
  Controller(s21::CalcModel *C) : Calc_(C){};
  ~Controller();

 // void CalculateValue(view *view);

 private:
  s21::CalcModel *Calc_;
};

}  // namespace s21

#endif
