#include <iostream>
#include "CVars.h"

CVars::CVars(std::map<std::string, std::shared_ptr<CMatrix>> &matrices)
        : CCommand("vars",
                   "vars",
                   "print all variables with stored matrices"), m_Matrices(matrices) {}

void CVars::validate(const std::vector<std::string> &args) const {
    if (args.size() != 1)
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CVars::execute(const std::vector<std::string> &args) {
    if (m_Matrices.empty()) {
        std::cout << "No stored variables." << std::endl;
        return;
    }

    for (const auto& matrix : m_Matrices)
        std::cout << matrix.first << "  ";
    std::cout << std::endl;
}