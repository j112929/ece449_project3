#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <string>
#include <map>

#include "tensor.h"
class evaluation;

class expression
{
    friend class evaluation;
    int expr_id_;
    std::string op_name_;
    std::string op_type_;
    std::vector<int> inputs_;
    std::map<std::string, double> op_params;
    std::map<std::string, tensor> op_params_tensor;
    
public:

    int get_id();
    std::string get_op_name();
    std::string get_op_type();
    std::map<std::string, double> get_op_params();
    std::map<std::string, tensor> expression::get_op_param();
   // int get_inputs();
    

    expression(
        int expr_id,
        const char *op_name,
        const char *op_type,
        int *inputs,
        int num_inputs);

    void add_op_param_double(
        const char *key,
        double value);

    void add_op_param_ndarray(
        const char *key,
        int dim,
        size_t shape[],
        double data[]);
}; // class expression

#endif // EXPRESSION_H
