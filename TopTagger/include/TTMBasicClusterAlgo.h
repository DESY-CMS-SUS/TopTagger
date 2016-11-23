#ifndef TTMBASICCLUSTERALGO_H
#define TTMBASICCLUSTERALGO_H

#include "TopTagger/TopTagger/include/TTModule.h"

class TopTaggerResults;
class Constituent;

class TTMBasicClusterAlgo : public TTModule
{
private:
    //mino-jet variables
    double minAK8TopMass_, maxAK8TopMass_, maxTopTau32_, minAK8TopPt_;
    bool doMonojet_;

    //dijet variables
    double minAK8WMass_, maxAK8WMass_, maxWTau21_, minAK8WPt_;
    bool doDijet_;

    //trijet variables
    double minTopCandMass_, maxTopCandMass_, dRMax_;
    bool doTrijet_;

    //Implement the requirements to be tagged as an AK8 W
    bool passAK8WReqs(const Constituent& constituent) const;

    //Implement the requirements to be tagged as an AK8 top
    bool passAK8TopReqs(const Constituent& constituent) const;

public:
    void getParameters(const cfg::CfgDocument*);
    void run(TopTaggerResults&);
};
REGISTER_TTMODULE(TTMBasicClusterAlgo);

#endif
