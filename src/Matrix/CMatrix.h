#ifndef SEMESTRAL_CMATRIX_H
#define SEMESTRAL_CMATRIX_H


#include <memory>
#include <vector>

class CMatrix {
public:
    CMatrix(unsigned width, unsigned height, unsigned zeroes);

    virtual ~CMatrix();

    static std::shared_ptr<CMatrix> create(unsigned int width, unsigned int height, unsigned int zeroes,
                                           const std::vector<std::vector<double>> &mtx);

    virtual void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const CMatrix &mtx);

    virtual void save(std::string fileName) const = 0;

    virtual double at(unsigned int x, unsigned int y) const = 0;

    unsigned getWidth() const;

    unsigned getHeight() const;

    unsigned getZeroes() const;

    virtual std::shared_ptr<CMatrix> transpose() const = 0;

protected:
    unsigned m_Width;
    unsigned m_Height;
    unsigned m_Zeroes;
};


#endif //SEMESTRAL_CMATRIX_H
