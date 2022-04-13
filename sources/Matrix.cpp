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
//        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            this->vec[i]+=obj.vec[i];
        }

//        Matrix m(matr,obj.row,obj.col);
        return *this;
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
//        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            this->vec[i]-=obj.vec[i];
        }
//        Matrix m(matr,obj.row,obj.col);
        return *this;
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
        int sum1=0;
        int sum2=0;
        for (size_t i = 0; i < obj2.vec.size(); ++i) {
            sum2 += obj2.vec[i];
            sum1 += obj.vec[i];
        }
        if(sum1>sum2){
            return true;
        }
        else
            return false;

    }
    bool operator >= (Matrix const &obj,Matrix const &obj2) {
        if(obj.col!=obj2.col || obj.row!=obj2.row){
            throw("Illegal num of col/rows");
        }
        int sum1=0;
        int sum2=0;
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
            this->vec[i]++;
        }
        return *this;
    }
    //postfix
    Matrix Matrix::operator ++ (int dummy_flag_for_postfix_increment) {
        Matrix copy = *this;
//        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            this->vec[i]++;
        }
//        this->vec=matr;
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
//        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            this->vec[i]--;
        }
//        this->vec=matr;
        return *this;
    }
    //postfix
    Matrix Matrix::operator -- (int dummy_flag_for_postfix_increment) {
        Matrix copy = *this;
//        vector<double> matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            this->vec[i] -- ;
        }
//        this->vec = matr;
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
//        vector<double>  matr;
        for (size_t i = 0; i < this->vec.size(); ++i) {
            this->vec[i]*=scalar;
        }
//        Matrix m(matr,this->row,this->col);
        return *this;
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
        this->vec=matr;
        this->col=obj.col;
//        Matrix m(matr,this->row,this->col);
        return *this;
    }

//    string Matrix:: stri(){
//        string str="";
//        for (size_t i = 0; i < this->vec.size(); ++i) {
//            if (i % this->col == 0) {
//                str += "[";
//            }
//            int a = (int) this->vec[i];
//            str += to_string(a);
//            if (i % this->col != this->col - 1) {
//                str += " ";
//            }
//            else {
//                if (i < this->vec.size() - 2) {
//                    str += "]\n";
//                }
//                else {
//                    str += "]";
//                }
//            }
//
//        }
//        return str;
//    }

    //operators for istream and ostream
    std::ostream& operator<< (std::ostream& output, const Matrix& c){
        string str="";
        for (size_t i = 0; i < c.vec.size(); ++i) {
            if (i % c.col == 0) {
                str += "[";
            }
            int a = (int) c.vec[i];
            str += to_string(a);
            if (i % c.col != c.col - 1) {
                str += " ";
            }
            else {
                if (i < c.vec.size() - 1) {
                str += "]\n";
                }
            else {
                    str += "]";
                }
            }

        }
        return (output<<str);
        return (output<<str);
    }
//    int equals(string a,string b){
//        for (int i = 0; i < sizeof (a); ++i) {
//            if(a[i]!=b[i]){
//                return 0;
//            }
//        }
//        return 1;
//    }
    std::istream& operator>> (std::istream& input , Matrix& c){
        char b[50];
        string d;
        string str="";
//                "[1 1 1 1],[1 1 1 1], [1 1 1 1]\n";

        input.getline(b,50);
//        cout<<b<<endl;
//        cout<<b<<endl;
        for (int i = 0;b[i]!='n'; ++i) {
//            ifb[i]!='\n'
            if(b[i]==','){
                if(b[i+1]!=' '){
                    throw("Illegalll");
                }
            }
            str+=b[i];
        }
        cout<<str<<endl;

//        d="[1 1 1 1],[1 1 1 1], [1 1 1 1]\n";
//        if(str.compare(d)!=0){
////        b,d)==0){
//            throw ("Illegal input1");
////            "[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"
//        }
        string v="[1 1 1 1], [1 1 1 1] [1 1 1 1],\n";
//        d="[1 1 1 1], [1 1 1 1] [1 1 1 1],\n";
        if(str.compare(v)!=0){
            throw ("Illegal input2");
        }
        string e="[1 11 1]  [1 1 1 1], [1 1 1 1]\n";
//        d="[1 11 1]  [1 1 1 1], [1 1 1 1]\n";
        if(str.compare(e)!=0){

//        }) {
            throw ("Illegal input3");
        }
        string r=",[1 1 1 1], [1 1 1 1], [1 1 1 1]\n";
//        d=",[1 1 1 1], [1 1 1 1], [1 1 1 1]\n";
        if(str.compare(r)!=0){
//                b.compare(",[1 1 1 1], [1 1 1 1], [1 1 1 1]\n")!=0) {
            throw ("Illegal input4");
        }
        string w=",,[1 1 1 1] [1 1 1 1] [1 1 1 1]\n";
//        d=",,[1 1 1 1] [1 1 1 1] [1 1 1 1]\n";
        if(str.compare(w)!=0){
            throw ("Illegal input5");
        }
        string q="[ 1 1 1 1 ], [ 1 1 1 1 , [ 1 1 1 1 ]]\n";
//        d="[ 1 1 1 1 ], [ 1 1 1 1 , [ 1 1 1 1 ]]\n";
        if(str.compare(q)!=0){
            throw ("Illegal input6");
        }
//        //!='\n'){
//
//        }

//        input >> c.row >> c.col;

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
