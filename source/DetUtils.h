
#ifndef DetUtils_h
#define DetUtils_h

// helper fuctions for detectors

#include <Geant4/globals.hh>
#include <TTree.h>

//_____________________________________________________________________________
class DetUtils {

  public:

    //_____________________________________________________________________________
    DetUtils(G4String nam="", TTree *t=0x0): fNam(nam), fTree(t) {}

    //_____________________________________________________________________________
    template<class par> void AddBranch(std::string nam, par *addr, std::string type) {

      //add branch for variable of type 'par' to the tree

      std::string name = fNam + nam; // branch name from detector name and variable name
      std::string leaf = name + "/" + type; // leaflist for the variable

      fTree->Branch(name.c_str(), addr, leaf.c_str()); // create the branch

      //G4cout << name << " " << leaf << G4endl;

    }//AddBranch

  private:

    G4String fNam; // detector name
    TTree *fTree; // tree for output functions

};

#endif














