#define EVAL_OP_H

#include "tensor.h"
#include <map>
#include <vector>


typedef std::map<int, tensor> vars_type;
typedef std::map<std::string, tensor> kwargs_type;


class eval_op{
    protected:
        int expr_id_;
        std::string op_name_;
        std::vector<int> inputs_;
    public:
        eval_op(const expression &expr);
        virtual ~eval_op();
        virtual void eval(vars_type &variables, const kwargs_type &kwargs) = 0;
};

class eval_const: public eval_op{
        tensor value_;
    public:
        eval_const(const expression &expr);
        void eval(vars_type &variables , const kwargs_type &kwargs);

};

class eval_input: public eval_op{
          tensor value_;
    public:
        eval_input(const expression &expr);
        void eval(vars_type &variables , const kwargs_type &kwargs);
};

class eval_add: public eval_op{
    tensor value_;
    public:
        eval_add(const expression &expr);
        void eval(vars_type &variables , const kwargs_type &kwargs);
    };


