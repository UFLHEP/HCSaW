#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "HiggsCSandWidth.cc"

using namespace std;

int main()
{

  ofstream fileOut;
  string fileName_[25] = {"Hbb.txt","Htautau.txt","Hmumu.txt","Hss.txt","Hcc.txt","Htt.txt","Hgg.txt","Hgamgam.txt","HgammaZ.txt","HWW.txt","HZZ.txt",
			"HZZ4e.txt","HZZ2e2mu.txt","HZZ4lep(emu).txt","HZZ4lep(emutau).txt","HWW2e2nu.txt","HWWeNuMuNu.txt","HZZ2l2nu(emu).txt",
			 "HZZ2l2nu(emutau).txt","HZZ2l2q(emu).txt","HZZ2l2q(emutau).txt","HWWlnuqq(emu).txt","HZZ2nu2q.txt","H4q.txt","H4f.txt"};
  string channel[25] = {"H->bb","H->tautau","H->mumu","H->ss","H->cc","H->tt","H->gg","H->gamgam","H->gammaZ","H->WW","H->ZZ",
			 "H->ZZ->4e","H->ZZ->2e2mu","H->ZZ->4lep(emu)","H->ZZ->4lep(emutau)","H->WW->2e2nu","H->WW->eNuMuNu","H->ZZ->2l2nu(emu)",
			"H->ZZ->2l2nu(emutau)","H->ZZ->2l2q(emu)","H->ZZ->2l2q(emutau)","H->WW->lnuqq(emu)","H->ZZ->2nu2q","H->4q","H->4f"};

  HiggsCSandWidth *myCSW = new HiggsCSandWidth("YR3","../txtFiles");


  for( int i = 0; i < 25; i++)
    {
      
      fileOut.open(fileName_[i].c_str());
      fileOut << " mH     Width  BR("+channel[i]+")  BRErrUp%   BRErrUp   BRErrDn%   BRErrDn     " << endl;

      double mH, Width, BRChan, BRErrUpPer, BRErrDnPer, BRErrUp, BRErrDn;

      for( int j = 80; j <= 1000; j++)
	{

	  mH = j;
	  Width = myCSW->HiggsWidth(0,mH);
	  BRChan = myCSW->HiggsBR(i+1,mH);
	  BRErrUpPer = myCSW->HiggsBRerrPlus(i+1,mH)*100;
	  BRErrUp = BRErrUpPer*BRChan+BRChan;
	  BRErrDnPer = myCSW->HiggsBRerrMinus(i+1,mH)*100;
	  BRErrDn = BRErrDnPer*BRChan+BRChan;
	 

	  fileOut.width(7);
	  fileOut << mH << " " 
		  << Width      << "   " << BRChan << "   " 
		  << BRErrUpPer << "   " << BRErrUp << "   "  
		  << BRErrDnPer << "   " << BRErrDn << "   "
		  << endl;

	}


      fileOut.close();

    }




  return 0;

}
