#ifndef EVALUATION_H
#define EVALUATION_H

#include "expression.h"
#include "tensor.h"

#include <memory>
#include "eval_op.h"

class evaluation
{
    std::map<std::string, double> kwargs_;
    std::map<std::string, tensor> kwargs_tensor;
public:
    evaluation(const std::vector<expression> &exprs);
    //std::vector<expression> exprs_;
    //s
   

    
    std::map<int, tensor> variables_;
    
    void add_kwargs_double(
        const char *key,
        double value);

    void add_kwargs_ndarray(
        const char *key,
        int dim,
        size_t shape[],
        double data[]);

    // return 0 for success
    int execute();

    // return the variable computed by the last expression
    tensor &get_result();

private:
    tensor result_;
    std::vector<std::shared_ptr<eval_op>> ops_;
}; // class evaluation


#endif // EVALUATION_H
