#include "eval_op.h"

eval_op::~eval_op(){

}

//const
eval_const::eval_const(const expression &expr):
eval_op(expr), value_(expr.get_op_param("value")){
}

void eval_const::eval(vars_type &variables, const kwargs_type &kwargs ){
    variables[expr_id_] = value_;
}

eval_input::eval_input(const expression &expr):
eval_op(expr), value_(){


}

void eval_input::eval(vars_type &variables, const kwargs_type &kwargs ){
  
}

eval_add::eval_add(const expression &expr):
eval_op(expr), value_(){

}

void eval_add::eval(vars_type &variables, const kwargs_type &kwargs ){
  
}