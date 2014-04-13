#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <boost/lexical_cast.hpp>

#include "HiggsCSandWidth.cc"

using namespace std;

int main()
{

  ofstream fileOut;
  string fileName_[6] = {"Total_cs","GluGlu_cs","VBF_cs","WH_cs","ZH_cs","ttH_cs"};
  int sqrts_[3] = {7,8,14};

  HiggsCSandWidth *myCSW = new HiggsCSandWidth();

  for (int s = 0; s < 3; s++)
    {
      int sqrts = sqrts_[s];

      for( int i = 0; i < 6; i++)
	{
	  string energy = boost::lexical_cast<string>(sqrts);
	  string myFileName = fileName_[i]+"_"+energy+"TeV.txt";
	  
	  fileOut.open(myFileName.c_str());
	  fileOut << " mH      CS   CSErr Plus%   CSErr Plus   CSErr Minus%  CSErr Minus " << endl;
	  
	  double mH;
	  double CS;
	  double CSErrPlusPercent, CSErrMinusPercent;
	  double CSErrPlus, CSErrMinus;
	  
	  cout << sqrts <<"TeV  " << myFileName << endl;
	  for( int j = 80; j <= 1000; j += 1)
	    {
	      
    	      mH = j;
	      CS = myCSW->HiggsCS(i,mH,sqrts);
	      CSErrPlusPercent = myCSW->HiggsCSErrPlus(i,mH,sqrts)*100;
	      CSErrPlus = CS+myCSW->HiggsCSErrPlus(i,mH,sqrts)*CS;
	      CSErrMinusPercent = myCSW->HiggsCSErrMinus(i,mH,sqrts)*100;
	      CSErrMinus = CS+myCSW->HiggsCSErrMinus(i,mH,sqrts)*CS;
	      
	     
	      fileOut.width(6);
	      fileOut << mH << "  " << CS << "  " << CSErrPlusPercent << "      " << CSErrPlus 
		      << "        " << CSErrMinusPercent << "       " << CSErrMinus << endl;
	      
	    }
	  
	  fileOut.close();
	  
	}
      
    }



  return 0;

}
