#include <iostream>
#include "Matrix.hpp"
#include <cstring>
using namespace std;

namespace zich {

    Matrix Matrix::operator + (Matrix const &obj)const {
        if(obj.col!=col || obj.row!=row){
            throw("Illegal num of col/rows");
        }
        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(this->vec[i]+obj.vec[i]);
        }
        Matrix m(matr,obj.row,obj.col);
        return m;
    }

    Matrix Matrix::operator += (Matrix const &obj)  {
        if(obj.col!=col || obj.row!=row){
            throw("Illegal num of col/rows");
        }
        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(this->vec[i]+obj.vec[i]);
        }
        Matrix m(matr,obj.row,obj.col);
        return m;
    }

    Matrix Matrix::operator + () const{

        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(this->vec[i]);
        }
        Matrix m(matr,this->row,this->col);
        return m;
    }

    //    //the '-' operators
    Matrix Matrix::operator - (Matrix const &obj) const{
        if(obj.col!=col || obj.row!=row){
            throw("Illegal num of col/rows");
        }
        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(this->vec[i]-obj.vec[i]);
        }
        Matrix m(matr,obj.row,obj.col);
        return m;
    }
    Matrix Matrix::operator - () const {
        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(-1*this->vec[i]);
        }
        Matrix m(matr,this->row,this->col);
        return m;
    }
    Matrix Matrix::operator -= (Matrix const &obj) {
        if(obj.col!=col || obj.row!=row){
            throw("Illegal num of col/rows");
        }
        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(this->vec[i]-obj.vec[i]);
        }
        Matrix m(matr,obj.row,obj.col);
        return m;
    }

    //the equals operators
    bool operator == (Matrix const &obj,Matrix const &obj2) {
        if(obj.col!=obj2.col || obj.row!=obj2.row){
            throw("Illegal num of col/rows");
        }
        for (size_t i = 0; i < obj2.vec.size(); ++i) {
            if(obj2.vec[i]!=obj.vec[i]){
                return false;
            }
        }
        return true;
    }

    bool operator > (Matrix const &obj,Matrix const &obj2) {
        if(obj.col!=obj2.col || obj.row!=obj2.row){
            throw("Illegal num of col/rows");
        }
        int sum1;
        int sum2;
        for (size_t i = 0; i < obj2.vec.size(); ++i) {
            sum2 += obj2.vec[i];
            sum1 += obj.vec[i];
        }
        if(sum1<sum2){
            return true;
        }
        else
            return false;

    }
    bool operator >= (Matrix const &obj,Matrix const &obj2) {
        if(obj.col!=obj2.col || obj.row!=obj2.row){
            throw("Illegal num of col/rows");
        }
        int sum1;
        int sum2;
        for (size_t i = 0; i < obj2.vec.size(); ++i) {
            sum2 += obj2.vec[i];
            sum1 += obj.vec[i];
        }
        if(sum1>=sum2){
            return true;
        }
        else
            return false;
    }
    bool operator != (Matrix const &obj,Matrix const &obj2) {
        if(obj.col!=obj2.col || obj.row!=obj2.row){
            throw("Illegal num of col/rows");
        }
        for (size_t i = 0; i < obj2.vec.size(); ++i) {
            if(obj2.vec[i]!=obj.vec[i]){
                return true;
            }
        }
        return false;
    }
    bool operator <= (Matrix const &obj,Matrix const &obj2) {
        if(obj.col!=obj2.col || obj.row!=obj2.row){
            throw("Illegal num of col/rows");
        }
        int sum1=0;
        int sum2=0;
        for (size_t i = 0; i < obj2.vec.size(); ++i) {
            sum2 += obj2.vec[i];
            sum1 += obj.vec[i];
        }
        if(sum1<=sum2){
            return true;
        }
        else
            return false;
    }
    bool operator < (Matrix const &obj,Matrix const &obj2) {
        if(obj.col!=obj2.col || obj.row!=obj2.row){
            throw("Illegal num of col/rows");
        }
        int sum1=0;
        int sum2=0;
        for (size_t i = 0; i < obj2.vec.size(); ++i) {
            sum2 += obj2.vec[i];
            sum1 += obj.vec[i];
        }
        if(sum1<sum2){
            return true;
        }
        else
            return false;
    }

    //the increment/decrement functions
    //prefix
    Matrix& Matrix::operator ++ () {
//        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            this->vec.at(i)++;
        }
        return *this;
    }
    //postfix
    Matrix Matrix::operator ++ (int dummy_flag_for_postfix_increment) {
        Matrix copy = *this;
        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(this->vec[i]+1);
        }
        this->vec=matr;
        return copy;
    }

//    // prefix increment:
//    Complex& operator++() {
//        _re++;
//        return *this;
//    }
//
//    // postfix increment:
//    Complex operator++(int dummy_flag_for_postfix_increment) {
//        Complex copy = *this;
//        _re++;
//        return copy;
//    }
    //prefix
    Matrix& Matrix::operator -- () {
        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(this->vec[i]-1);
        }
        this->vec=matr;
        return *this;
    }
    //postfix
    Matrix Matrix::operator -- (int dummy_flag_for_postfix_increment) {
        Matrix copy = *this;
        vector<double> matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(this->vec[i] + 1);
        }
        this->vec = matr;
        return copy;
    }
    //multiplying with scalar
    Matrix Matrix::operator * (double scalar) {
        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(this->vec[i]*scalar);
        }
        Matrix m(matr,this->row,this->col);
        return m;
    }
    Matrix Matrix::operator *= (double scalar) {
        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            matr.push_back(this->vec[i]*scalar);
        }
        Matrix m(matr,this->row,this->col);
        return m;
    }
    // matrix muliplying
    Matrix Matrix::operator * (Matrix const &obj) {
        if(obj.row!=this->col){
            throw("Illegal num of col/rows");
        }
        vector<double>  matr;
        for (size_t i = 0; i < this->row; i++) {
            for (size_t j = 0; j < obj.col; j++) {
                double sum=0;
                for (size_t k = 0; k < this->col; k++) {
                    sum += this->vec[i*this->col+k] * obj.vec[k*obj.col+j];
                }
                matr.push_back(sum);
            }
        }
        Matrix m(matr,this->row,obj.col);
        return m;
    }

    Matrix Matrix::operator *= (Matrix const &obj) {
        if(obj.row!=this->col){
            throw("Illegal num of col/rows");
        }
        vector<double>  matr;
        for (size_t i = 0; i < this->row; i++) {
            for (size_t j = 0; j < obj.col; j++) {
                double sum=0;
                for (size_t k = 0; k < this->col; k++) {
                    sum += this->vec[i*this->col+k] * obj.vec[k*obj.col+j];
                }
                matr.push_back(sum);
            }
        }
        Matrix m(matr,this->row,this->col);
        return m;
    }

    //operators for istream and ostream
    std::ostream& operator<< (std::ostream& output, const Matrix& c){
        string str="";
        for (size_t i = 0; i < c.vec.size(); ++i) {
            if(i%c.col==0){
                str+="[";
            }
            str+= to_string(c.vec[i])+" ";
            if(i% c.col==c.col-1){
                str+="]\n";
            }

        }
        return (output<<str<<endl);
    }
    std::istream& operator>> (std::istream& input , Matrix& c){
        return input;
    }

    Matrix operator * (const double scalar, Matrix &m){
        vector<double>  matr;
        for (size_t i = 0; i < m.vec.size(); ++i) {
            matr.push_back(m.vec[i]*scalar);
        }
        Matrix mat2(matr,m.row,m.col);
        return mat2;
    }



}
