#ifndef MATHDEFS_H
#define MATHDEFS_H

//#include "Math/GenVector/LorentzVector.h"
//#include "DataFormats/Math/interface/LorentzVector.h"

#define M_PI    3.14159265358979323846f

#include <Math/LorentzVector.h>
#include <Math/PtEtaPhiM4D.h>

namespace ztop{
  typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVector;
  typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double> > PolarLorentzVector;




}


#endif
