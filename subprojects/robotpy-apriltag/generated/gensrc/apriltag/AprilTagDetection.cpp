
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/apriltag/AprilTagDetection.h>


#include <wpi_span_type_caster.h>













#include <pybind11/eigen.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_AprilTagDetection_initializer {


  

  












  py::class_<typename frc::AprilTagDetection> cls_AprilTagDetection;

    

    
    
    py::class_<typename frc::AprilTagDetection::Point> cls_Point;

    

    
    
    

  py::module &m;

  
  rpybuild_AprilTagDetection_initializer(py::module &m) :

  

  

  

  
    cls_AprilTagDetection(m, "AprilTagDetection", py::is_final()),

  

  
  
    cls_Point(cls_AprilTagDetection, "Point"),

  

  
  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  

    
    
  }

void finish() {





  {
  
  using Point [[maybe_unused]] = typename frc::AprilTagDetection::Point;
  
  
  


  

  cls_AprilTagDetection.doc() =
    "A detection of an AprilTag tag.";

  cls_AprilTagDetection
  
    
  .
def
("getFamily", &frc::AprilTagDetection::GetFamily, release_gil(), py::doc(
    "Gets the decoded tag's family name.\n"
"\n"
":returns: Decoded family name")
  )
  
  
  
    
  .
def
("getId", &frc::AprilTagDetection::GetId, release_gil(), py::doc(
    "Gets the decoded ID of the tag.\n"
"\n"
":returns: Decoded ID")
  )
  
  
  
    
  .
def
("getHamming", &frc::AprilTagDetection::GetHamming, release_gil(), py::doc(
    "Gets how many error bits were corrected. Note: accepting large numbers of\n"
"corrected errors leads to greatly increased false positive rates.\n"
"NOTE: As of this implementation, the detector cannot detect tags with\n"
"a hamming distance greater than 2.\n"
"\n"
":returns: Hamming distance (number of corrected error bits)")
  )
  
  
  
    
  .
def
("getDecisionMargin", &frc::AprilTagDetection::GetDecisionMargin, release_gil(), py::doc(
    "Gets a measure of the quality of the binary decoding process: the\n"
"average difference between the intensity of a data bit versus\n"
"the decision threshold. Higher numbers roughly indicate better\n"
"decodes. This is a reasonable measure of detection accuracy\n"
"only for very small tags-- not effective for larger tags (where\n"
"we could have sampled anywhere within a bit cell and still\n"
"gotten a good detection.)\n"
"\n"
":returns: Decision margin")
  )
  
  
  
    
  .
def
("getHomography", &frc::AprilTagDetection::GetHomography, release_gil(), py::doc(
    "Gets the 3x3 homography matrix describing the projection from an\n"
"\"ideal\" tag (with corners at (-1,1), (1,1), (1,-1), and (-1,\n"
"-1)) to pixels in the image.\n"
"\n"
":returns: Homography matrix data")
  )
  
  
  
    
  .
def
("getHomographyMatrix", &frc::AprilTagDetection::GetHomographyMatrix, release_gil(), py::doc(
    "Gets the 3x3 homography matrix describing the projection from an\n"
"\"ideal\" tag (with corners at (-1,1), (1,1), (1,-1), and (-1,\n"
"-1)) to pixels in the image.\n"
"\n"
":returns: Homography matrix")
  )
  
  
  
    
  .
def
("getCenter", &frc::AprilTagDetection::GetCenter, release_gil(), py::doc(
    "Gets the center of the detection in image pixel coordinates.\n"
"\n"
":returns: Center point")
  )
  
  
  
    
  .
def
("getCorner", &frc::AprilTagDetection::GetCorner,
      py::arg("ndx"), release_gil(), py::doc(
    "Gets a corner of the tag in image pixel coordinates. These always\n"
"wrap counter-clock wise around the tag. Index 0 is the bottom left corner.\n"
"\n"
":param ndx: Corner index (range is 0-3, inclusive)\n"
"\n"
":returns: Corner point")
  )
  
  
  
    
  .
def
("getCorners", &frc::AprilTagDetection::GetCorners,
      py::arg("cornersBuf"), release_gil(), py::doc(
    "Gets the corners of the tag in image pixel coordinates. These always\n"
"wrap counter-clock wise around the tag. The first set of corner coordinates\n"
"are the coordinates for the bottom left corner.\n"
"\n"
":param cornersBuf: Corner point array (X and Y for each corner in order)\n"
"\n"
":returns: Corner point array (copy of cornersBuf span)")
  )
  
  
  .def("__repr__", [](const AprilTagDetection &self) {
  return py::str("<AprilTagDetection tag_family={} tag_id={} hamming={} decision_margin={} center={}>")
    .format(self.GetFamily(), self.GetId(), self.GetHamming(), self.GetDecisionMargin(), self.GetCenter());
})
;

  


  

  cls_Point.doc() =
    "A point. Used for center and corner points.";

  cls_Point
  
    .def(py::init<>(), release_gil())
  
    .def_readwrite("x", &frc::AprilTagDetection::Point::x)
  
    .def_readwrite("y", &frc::AprilTagDetection::Point::y)
  .def(py::init([](double x, double y) {
  AprilTagDetection::Point pt{x, y};
  return std::make_unique<AprilTagDetection::Point>(std::move(pt));
}), py::arg("x"), py::arg("y"))
.def("__len__", [](const AprilTagDetection::Point &self) { return 2; })
.def("__getitem__", [](const AprilTagDetection::Point &self, int index) {
  switch (index) {
    case 0:
      return self.x;
    case 1:
      return self.y;
    default:
      throw std::out_of_range("AprilTagDetection.Point index out of range");
  }
})
.def("__repr__", [](const AprilTagDetection::Point &self) {
  return py::str("AprilTagDetection.Point(x={}, y={})").format(self.x, self.y);
})
;

  


  
  }






}

}; // struct rpybuild_AprilTagDetection_initializer

static std::unique_ptr<rpybuild_AprilTagDetection_initializer> cls;

void begin_init_AprilTagDetection(py::module &m) {
  cls = std::make_unique<rpybuild_AprilTagDetection_initializer>(m);
}

void finish_init_AprilTagDetection() {
  cls->finish();
  cls.reset();
}