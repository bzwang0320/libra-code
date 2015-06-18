#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "libnuclear.h"

using namespace boost::python;
//using namespace libdyn::libnuclear;


namespace libdyn{
namespace libnuclear{


void export_Nuclear_objects(){

//  def("SAC_Ham", expt_SAC_Ham1);
  void (Nuclear::*expt_propagate_p_v1)(int, double) = &Nuclear::propagate_p;
  void (Nuclear::*expt_propagate_p_v2)(double) = &Nuclear::propagate_p;
  void (Nuclear::*expt_propagate_p_v3)(double, vector<int>&) = &Nuclear::propagate_p;

  void (Nuclear::*expt_propagate_q_v1)(int, double) = &Nuclear::propagate_q;
  void (Nuclear::*expt_propagate_q_v2)(double) = &Nuclear::propagate_q;
  void (Nuclear::*expt_propagate_q_v3)(double, vector<int>&) = &Nuclear::propagate_q;

  void (Nuclear::*expt_scale_p_v1)(int, double) = &Nuclear::scale_p;
  void (Nuclear::*expt_scale_p_v2)(double) = &Nuclear::scale_p;
  void (Nuclear::*expt_scale_p_v3)(double, vector<int>&) = &Nuclear::scale_p;

  void (Nuclear::*expt_scale_q_v1)(int, double) = &Nuclear::scale_q;
  void (Nuclear::*expt_scale_q_v2)(double) = &Nuclear::scale_q;
  void (Nuclear::*expt_scale_q_v3)(double, vector<int>&) = &Nuclear::scale_q;



  class_<Nuclear>("Nuclear",init<>())
      .def(init<int>())
      .def(init<const Nuclear&>())
      .def("__copy__", &generic__copy__<Nuclear>)
      .def("__deepcopy__", &generic__deepcopy__<Nuclear>)

      .def_readwrite("nnucl", &Nuclear::nnucl)
      .def_readwrite("mass", &Nuclear::mass)
      .def_readwrite("q", &Nuclear::q)
      .def_readwrite("p", &Nuclear::p)
      .def_readwrite("f", &Nuclear::f)
      .def_readwrite("ctyp", &Nuclear::ctyp)


      .def("propagate_p",expt_propagate_p_v1) 
      .def("propagate_p",expt_propagate_p_v2) 
      .def("propagate_p",expt_propagate_p_v3) 

      .def("propagate_q",expt_propagate_q_v1) 
      .def("propagate_q",expt_propagate_q_v2) 
      .def("propagate_q",expt_propagate_q_v3) 

      .def("scale_p",expt_scale_p_v1) 
      .def("scale_p",expt_scale_p_v2) 
      .def("scale_p",expt_scale_p_v3) 

      .def("scale_q",expt_scale_q_v1) 
      .def("scale_q",expt_scale_q_v2) 
      .def("scale_q",expt_scale_q_v3) 



  ;



}


#ifdef CYGWIN
BOOST_PYTHON_MODULE(cygnuclear){
#else
BOOST_PYTHON_MODULE(libnuclear){
#endif

  // Register converters:
  // See here: https://misspent.wordpress.com/2009/09/27/how-to-write-boost-python-converters/
  //to_python_converter<std::vector<DATA>, VecToList<DATA> >();

//  export_Mathematics_objects();
  export_Nuclear_objects();

}


}// namespace libdyn
}// namespace libnuclear


