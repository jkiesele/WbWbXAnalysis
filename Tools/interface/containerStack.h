#ifndef containerStack_h
#define containerStack_h

#include "container.h"
#include <iostream>
#include "TString.h"
#include <vector>
#include "THStack.h"
#include "TLegend.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLine.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TGaxis.h"

namespace top{

  class container1DStack{
    
  public:
    container1DStack(){};
    container1DStack(TString name) : name_(name), dataleg_("data") {}

    void push_back(top::container1D, TString, int, double);
    
    void setDataLegend(TString leg="data"){dataleg_=leg;}
    void mergeSameLegends();
    top::container1D getContribution(TString);   //! does not ignore data
    top::container1D getContributionsBut(TString);  //!does not ignore data
    top::container1D getContributionsBut(std::vector<TString>);  //!does not ignore data
    TString getName(){return name_;}
    unsigned int size(){return colors_.size();}
    TString getLegend(unsigned int i){return legends_[i];}
    int & getColor (unsigned int i){return colors_[i];};
    double & getNorm  (unsigned int i){return norms_[i];}
    container1D & getContainer(unsigned int i){return containers_[i];}
    container1D & getContainer(TString);
    container1D getFullMCContainer();           //! gets the sum of all MC containers (normalized with their stored norm) including error handling
    void multiplyNorm(TString , double);
    void addGlobalRelMCError(TString,double);   //! adds a global systematic variation to the systematics stored (e.g. lumi)
    void addMCErrorStack(TString,container1DStack,bool ignoreMCStat=true);  //! calls container1D::addErrorContainer for each same named member container
    void addRelSystematicsFrom(top::container1DStack);
    void removeError(TString);

    void clear(){containers_.clear();legends_.clear();colors_.clear();norms_.clear();}
    
    void setName(TString name){name_=name;}
    
    THStack * makeTHStack(TString stackname = "");
    TLegend * makeTLegend();
    void drawControlPlot(TString name="", bool drawxaxislabels=true, double resizelabels=1); // the extra axis is in both... sorry for that!
    TGraphAsymmErrors * makeMCErrors();
    void drawRatioPlot(TString name="",double resizelabels=1);

    TCanvas * makeTCanvas(bool drawratioplot=true);


    //define operators (propagate from containers) for easy handling

    container1DStack operator + ( container1DStack );
    container1DStack operator - ( container1DStack );
    container1DStack operator / ( container1DStack );
    container1DStack operator * ( container1DStack );
    container1DStack operator * (double);
    container1DStack operator * (float);
    container1DStack operator * (int);
    
    
  private:
    TString name_;
    std::vector<top::container1D> containers_;
    std::vector<TString> legends_;
    std::vector<int> colors_;
    std::vector<double> norms_;
    TString dataleg_;

    
};

 
  

}
#endif