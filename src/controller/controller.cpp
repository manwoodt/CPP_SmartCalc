#include "controller.h"

void s21::Controller::CalculateValue(std::string input_str, std::string x){
    Calc_->CalculateAnswer(input_str, x);

}

double s21::Controller::GetAnswer(){
   return Calc_->GetAnswer();
}
