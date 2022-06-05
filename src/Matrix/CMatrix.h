#ifndef SEMESTRAL_CMATRIX_H
#define SEMESTRAL_CMATRIX_H


#include <memory>
#include <vector>

class CMatrix {
public:
    CMatrix(unsigned width, unsigned height, unsigned zeroes);
    virtual ~CMatrix();

    //virtual double at(unsigned int x, unsigned int y) const = 0;
    //virtual std::shared_ptr<CMatrix> create(std::vector<double> values) const = 0;

//    std::shared_ptr<CMatrix> operator+(const CMatrix &rhs) const;
//    std::shared_ptr<CMatrix> operator-(const CMatrix &rhs) const;
//    std::shared_ptr<CMatrix> operator*(const CMatrix &rhs) const;

    //virtual std::shared_ptr<CMatrix> Transpose() const = 0;
    //virtual std::shared_ptr<CMatrix> Merge(const CMatrix &rhs) const = 0;

    //virtual void print(std::ostream &os) = 0;
    friend std::ostream& operator<<(std::ostream &os, const CMatrix& mtx);

protected:
    unsigned m_Width{};
    unsigned m_Height{};
    unsigned m_Zeroes{};
};


#endif //SEMESTRAL_CMATRIX_H
