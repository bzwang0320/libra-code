/*********************************************************************************
* Copyright (C) 2015 Alexey V. Akimov
*
* This file is distributed under the terms of the GNU General Public License
* as published by the Free Software Foundation, either version 2 of
* the License, or (at your option) any later version.
* See the file LICENSE in the root directory of this distribution
* or <http://www.gnu.org/licenses/>.
*
*********************************************************************************/

#ifndef MMATH_EIGEN_H
#define MMATH_EIGEN_H

#include "../linalg/liblinalg.h"

/// libmmath namespace
namespace libmmath{

using namespace liblinalg; 

/// libmeigen namespace
namespace libmeigen{


double det(MATRIX&);
complex<double> det(CMATRIX&);

void solve_eigen(int, MATRIX*, MATRIX*, MATRIX*, MATRIX*);
void solve_eigen(int, MATRIX&, MATRIX&, MATRIX&, MATRIX&);
void solve_eigen_gen(int, MATRIX*, MATRIX*, MATRIX*, MATRIX*);
void solve_eigen_gen(int, MATRIX&, MATRIX&, MATRIX&, MATRIX&);


void solve_eigen(int Norb, MATRIX* H, MATRIX* S, CMATRIX* E, CMATRIX* C);
void solve_eigen(int Norb, MATRIX& H, MATRIX& S, CMATRIX& E, CMATRIX& C);
void solve_eigen_gen(int Norb, MATRIX* H, MATRIX* S, CMATRIX* E, CMATRIX* C);
void solve_eigen_gen(int Norb, MATRIX& H, MATRIX& S, CMATRIX& E, CMATRIX& C);


void solve_eigen(int Norb, CMATRIX* H, CMATRIX* S, CMATRIX* E, CMATRIX* C);
void solve_eigen(int Norb, CMATRIX& H, CMATRIX& S, CMATRIX& E, CMATRIX& C);
void solve_eigen_gen(int Norb, CMATRIX* H, CMATRIX* S, CMATRIX* E, CMATRIX* C);
void solve_eigen_gen(int Norb, CMATRIX& H, CMATRIX& S, CMATRIX& E, CMATRIX& C);




void solve_eigen(int, MATRIX*, MATRIX*, MATRIX*);


}// namespace libmeigen
}// namespace libmmath


#endif
