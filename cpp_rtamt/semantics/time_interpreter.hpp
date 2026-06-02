#pragma once

#include <map>
#include <vector>
#include <string>
#include <utility>

namespace stl_library {

    typedef std::map<std::string, double> DataSet;

    class AbstractTimeInterpreter {
    private:

    public:
        AbstractTimeInterpreter() {}
        virtual bool dataset_check(const DataSet& p_dataset) = 0;
        virtual void set_variable_to_ast_from_dataset(const DataSet& p_dataset) = 0;
    };

}