#include "Model_DAC.h"

namespace libhamiltonian{

void DAC_Ham(double x, MATRIX* H, MATRIX* dH, MATRIX* d2H, vector<double>& params){ 
// DAC hamiltonian in diabatic representation

  if(H->num_of_elems!=4){ std::cout<<"Error in SAC_Ham: H matrix must be allocated\n"; exit(0);}
  if(dH->num_of_elems!=4){ std::cout<<"Error in SAC_Ham: dH matrix must be allocated\n"; exit(0);}
  if(d2H->num_of_elems!=4){ std::cout<<"Error in SAC_Ham: d2H matrix must be allocated\n"; exit(0);}

  // Default parameters
  double A = 0.100;  double B = 0.028;
  double C = 0.015;  double D = 0.06;
  double E = 0.05;

  if(params.size()>=5){
    A = params[0];    B = params[1];
    C = params[2];    D = params[3];
    E = params[4];
  }


  // H00
  H->M[0] = 0.0; 
  dH->M[0] = 0.0;
  d2H->M[0] = 0.0;

  // H00
  double e = A*exp(-B*x*x);
  H->M[3] = E - e; 
  dH->M[3] = 2.0*B*x*e;
  d2H->M[3] = (2.0*B*e - 2.0*B*x*dH->M[3]);

  // H01 and H10
  H->M[1] = H->M[2] = C*exp(-D*x*x);
  dH->M[1] = dH->M[2] = -2.0*D*x*H->M[1];
  d2H->M[1] = d2H->M[2] = (-2.0*D*H->M[1] - 2.0*D*x*dH->M[1]);


}

boost::python::list DAC_Ham(double x, boost::python::list params_){ 
// DAC hamiltonian in diabatic representation

  MATRIX H(2,2);
  MATRIX dH(2,2);
  MATRIX d2H(2,2);

  int sz = boost::python::len(params_);
  vector<double> params(sz,0.0);
  for(int i=0;i<sz;i++){ params[i] = boost::python::extract<double>(params_[i]);  }

  DAC_Ham(x,&H,&dH,&d2H,params);

  boost::python::list res;
  res.append(x);
  res.append(H);
  res.append(dH);
  res.append(d2H);
 
  return res;

}

}// namespace libhamiltonian
