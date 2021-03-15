#include <iostream>
using std::cout;
using std::endl;
#include "TRandom.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TMatrix.h"
#include "TVector.h"
#include "TCanvas.h"

// TASK 1: Make this code compile under CMake against some installation of ROOT

Double_t smear (Double_t xt){
  Double_t xsmear= gRandom->Gaus(-2.5,0.2);     // bias and smear
  return xt+xsmear;
}

void RooUnfoldGSOC()
{
  TH2D response = TH2D("response","response",4, -10.0, 10.0,4, -10.0, 10.0);
  TH1D truth = TH1D("truth","truth",4,-10.,10.);
  TH1D reco = TH1D("reco","reco",4,-10.,10.);

  cout << "==================================== TEST =====================================" << endl;

  // Train with a Breit-Wigner, mean 0.3 and width 2.5.
  for (Int_t i= 0; i<100000; i++) {
    Double_t xt= gRandom->BreitWigner (0.3, 2.5);
    truth.Fill(xt);
    Double_t x= smear (xt);
    response.Fill (x, xt);
    reco.Fill(x);
  }
  // We have three objects now. A distribution, an approximation of how that distribution
  // would look in our detector, and the response of how the detector affects it.
  
  // now one would think that for given distribution we can use this response to
  // predict how that distribution would look in our detector by multiplying through
  TH1D prediction = TH1D("prediction","prediction",4,-10.,10.);
  for (Int_t i= 0; i<reco.GetNbinsX(); i++){
    for (Int_t j= 0; j<truth.GetNbinsX(); j++){
        auto current = prediction.GetBinContent(i+1);
        auto contribution = response.GetBinContent(i+1,j+1); 
        prediction.SetBinContent(i+1,current+contribution);
    }
  }
  cout << "=============================== PREDICT (With Normalization) =====================================" << endl;

  // in this case the prediction and reco should line up exactly.
  cout<<"reco bins"<<endl;
  for (Int_t i=0; i<reco.GetNbinsX(); i++){
    cout<<reco.GetBinContent(i+1)<<", ";
  }
  cout<<endl;

  cout<<"prediciton"<<endl;
  for (Int_t i=0; i<prediction.GetNbinsX(); i++){
    cout<<prediction.GetBinContent(i+1)<<", ";
  }
  
  cout<<endl;
  // TASK 2 (Optional): the predictions don't line up. This is because the response needs to be normalised
  // by the number of events measured in truth. Loop over the bins of the response to normalise
  // each element to be the probability of reconstructing the event in each bin given the bin it
  // truthfully came from. (divide each by truth). Ensure the prediction now lines up with reco.

  // TASK 3 (Optional): here we perform the operation reco = Response.dot(truth). replace the loops with
  // matrix operations using the built in ROOT TMatrix objects and operations. Test that it gives the same
  // predictions as the loop method.

  cout << "===================== PREDICT (With Normalization and Matrix Operation) =====================================" << endl;


  TMatrix normalisedResponse = TMatrix(4,4);
  TVector truth_mat = TVector(4);
  for (Int_t i= 0; i<4; i++) {
    truth_mat[i] = truth.GetBinContent(i+1);;
  }

  for (Int_t i= 0; i<reco.GetNbinsX(); i++){
    for (Int_t j= 0; j<truth.GetNbinsX(); j++){
        normalisedResponse[i][j] = response.GetBinContent(i+1,j+1)/truth.GetBinContent(j+1);
    }
  }

  cout<<"reco bins"<<endl;
  for (Int_t i=0; i<reco.GetNbinsX(); i++){
    cout<<reco.GetBinContent(i+1)<<", ";
  }
  cout<<endl;


  TVector predicted = normalisedResponse*truth_mat;
  cout<<"prediciton"<<endl;
  for (Int_t i= 0; i<predicted.GetNoElements(); i++) {
    cout<<predicted[i]<<", ";
  }
  cout<<endl;
  // TASK 4 (Optional): Setup a Series of CTests to verify that different operations give the same results.
  
}

#ifndef __CINT__
int main () { RooUnfoldGSOC(); return 0; }  // Main program when run stand-alone
#endif
