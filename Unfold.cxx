#include "Unfold.h"

Unfold::Unfold(int nb, double xlo, double xhi){

  response_SliceID_Int.Reset();
  response_SliceID_Int.Setup(nb, xlo, xhi);

  response_SliceID_Inc.Reset();
  response_SliceID_Inc.Setup(nb, xlo, xhi);

  eff_num_Int = new TH1D("eff_num_Int", "eff_num_Int", nb, xlo, xhi);
  eff_den_Int = new TH1D("eff_den_Int", "eff_den_Int", nb, xlo, xhi);
  eff_num_Inc = new TH1D("eff_num_Inc", "eff_num_Inc", nb, xlo, xhi);
  eff_den_Inc = new TH1D("eff_den_Inc", "eff_den_Inc", nb, xlo, xhi);
  pur_num_Int = new TH1D("pur_num_Int", "pur_num_Int", nb, xlo, xhi);
  pur_num_Inc = new TH1D("pur_num_Inc", "pur_num_Inc", nb, xlo, xhi);
  pur_den     = new TH1D("pur_den",     "pur_den",     nb, xlo, xhi);

  eff_num_Int->Sumw2();
  eff_den_Int->Sumw2();
  eff_num_Inc->Sumw2();
  eff_den_Inc->Sumw2();
  pur_num_Int->Sumw2();
  pur_num_Inc->Sumw2();
  pur_den->Sumw2();

}  

void Unfold::SaveHistograms(){

  eff_num_Int->Write("eff_num_Int");
  eff_den_Int->Write("eff_den_Int");
  eff_num_Inc->Write("eff_num_Inc");
  eff_den_Inc->Write("eff_den_Inc");
  pur_num_Int->Write("pur_num_Int");
  pur_num_Inc->Write("pur_num_Inc");
  pur_den->Write("pur_den");

  TH2D *hint = (TH2D*)response_SliceID_Int.Hresponse();
  hint->SetTitle("Pion Inelastic Scatterings;Reco Slice ID;True Slice ID");
  hint->Write("response_SliceID_Int");
  TH2D *hinc = (TH2D*)response_SliceID_Inc.Hresponse();
  hinc->SetTitle("All Pions; Reco Slice ID; True Slice ID");
  hinc->Write("response_SliceID_Inc");
}