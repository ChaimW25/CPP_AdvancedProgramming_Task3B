#include "string"
#include <iostream>
#include <vector>

using namespace std;

namespace zich {

    class Matrix {
    public:
        size_t row;
        size_t col;
        vector<double> vec;
//        vector<vector<double> > mat;

//        std::vector<std::vector<double>> matrix<row,std::vector<double>(col));
        Matrix(){
            this->row=1;
            this->col=1;
            this->vec={1};
        }
        Matrix(vector<double> v, int ro, int co) {
            if(co<1 || ro<1 || co*ro!=v.size()){
                throw("Illegal num of col/rows");
            }
            this->row=(size_t)ro;
            this->col=(size_t)co;
            this->vec=v;
//            vec=v;
//            vector<vector<int> > matrix(ro);
//            vector<vector<double> > matrix;
//            vector<double> mat;

//            for (int i = 0; i < ro; i++) {
//                for (int j = 0; j < co; j++) {
//                    vec[i][j] = (v[ro * co + co]);
//                }
//            }
        }
//            int curr=0;
//
//
//                    if(i==0){
//                        curr==j;
//                    }
//                    else{
//                        curr= i*co + j;
//                    }
//                    matrix[i][j]= vec[curr];
//                }

//        vector<vector<double>> a;
//        (row,vector<double>(col));

//        Matrix(vector<double> v, int ro, int co){
//
////            std::vector<std::vector<double>> matrix<ro,std::vector<double>(co));
//
//}

        // '+' operators
        Matrix operator + (Matrix const &obj) const ;
        Matrix operator + () const ;
        Matrix operator += (Matrix const &obj)  ;
        //the '-' operators
        Matrix operator - (Matrix const &obj) const;
        Matrix operator - () const;
        Matrix operator -= (Matrix const &obj) ;
        //the equals operators
        friend bool operator == (Matrix const &obj,Matrix const &obj2)  ;
        friend bool operator > (Matrix const &obj,Matrix const &obj2) ;
        friend bool operator >= (Matrix const &obj,Matrix const &obj2);
        friend bool operator != (Matrix const &obj,Matrix const &obj2) ;
        friend bool operator <= (Matrix const &obj,Matrix const &obj2) ;
        friend bool operator < (Matrix const &obj,Matrix const &obj2) ;
        //the increment/decrement functions
        Matrix& operator ++ () ;
        Matrix& operator -- () ;
        Matrix operator ++ (int dummy_flag_for_postfix_increment);
        Matrix operator -- (int dummy_flag_for_postfix_increment);
//        string  stri();


            //multiplying with scalar
        Matrix operator * (double scalar);
        Matrix operator *= (double scalar);

        // matrix muliplying
        Matrix operator * (Matrix const &obj) ;
        Matrix operator *= (Matrix const &obj) ;


        friend std::ostream& operator<< (std::ostream& output, const Matrix& c);

        friend std::istream& operator>> (std::istream& input , Matrix& c);

    };
    Matrix operator * (const double scalar, Matrix &m);


    };
//        int main(){
//
//            vector<double> vec= {1.0,3.0};
//            Matrix m = (2,1,vec);
////            for(int i=0; i<2; i++){
////            m
////        }
//            return 0;
//    }


