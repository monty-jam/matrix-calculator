#include "CDel.h"

CDel::CDel(std::map<std::string, std::shared_ptr<CMatrix>> &matrices)
        : CCommand("del",
                   "del [VARIABLE]",
                   "delete variable with stored matrix"), m_Matrices(matrices) {}

void CDel::validate(const std::vector<std::string> &args) const {
    if (args.size() != 2)
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CDel::execute(const std::vector<std::string> &args) {
    m_Matrices.at(args[1]);
    m_Matrices.erase(args[1]);
}
