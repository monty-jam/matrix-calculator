#ifndef SEMESTRAL_CMATRIX_H
#define SEMESTRAL_CMATRIX_H


#include <memory>
#include <vector>

class CMatrix {
public:
    CMatrix(unsigned width, unsigned height, unsigned zeroes);
    virtual ~CMatrix();

    virtual double at(unsigned int x, unsigned int y) const = 0;

//    std::shared_ptr<CMatrix> operator+(const CMatrix &rhs) const;
//    std::shared_ptr<CMatrix> operator-(const CMatrix &rhs) const;
//    std::shared_ptr<CMatrix> operator*(const CMatrix &rhs) const;

    //virtual std::shared_ptr<CMatrix> Transpose() const = 0;
    //virtual std::shared_ptr<CMatrix> Merge(const CMatrix &rhs) const = 0;

    virtual void print(std::ostream &os) const;
    friend std::ostream& operator<<(std::ostream &os, const CMatrix& mtx);

protected:
    unsigned m_Width;
    unsigned m_Height;
    unsigned m_Zeroes;

    std::shared_ptr<CMatrix> decider(unsigned int width, unsigned int height, unsigned int zeroes,
                                     const std::vector<std::vector<double>>& mtx) const;
};


#endif //SEMESTRAL_CMATRIX_H
