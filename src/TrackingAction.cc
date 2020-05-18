#include "TrackingAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "G4RunManager.hh"
#include "G4String.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "Analysis.hh"
using namespace CLHEP;
TrackingAction *TrackingAction::theTrackingAction=NULL;
TrackingAction::~TrackingAction(){theTrackingAction=NULL;}
TrackingAction::TrackingAction():G4UserTrackingAction()
{
  theAnalysis = Analysis::GetInstance();
  theStepping = SteppingAction::GetInstance();
  theTrackingAction=this;
}

void TrackingAction::PreUserTrackingAction(const G4Track* aTrack)
{
  if(aTrack->GetCreatorProcess()==0){ Primary = 1;}
    
}


void TrackingAction::PostUserTrackingAction(const G4Track* aTrack)
{
  //cout<<"----====----====----====----====----====----====----====----===="<<endl;
  if(aTrack->GetCreatorProcess()==0 && Primary){

    //  cout<<aTrack->GetDynamicParticle()->GetDefinition()->GetParticleName()<<endl;
    //G4TrackVector* secondaryTracks   = fpTrackingManager->GimmeSecondaries();  
    //for(int i =0; i<secondaryTracks->size(); i++){
    //G4String secondaryName = secondaryTracks->at(i)->GetDynamicParticle()->GetDefinition()->GetParticleName();
    /*if(!secondaryName.contains("e-")) primary =0;
      else{
      double e = aTrack->GetKineticEnergy();
      //if(e>0) cout<<e<<endl;
      }*/
    //cout<<"Counted as a primary!!"<<endl;
      NPrimary++;
    }
  
}

  //G4ProcessManager* processManager = aTrack->GetDefinition()->GetProcessManager();
  //G4ProcessVector* processVector   = processManager->GetProcessList();

  //G4SteppingManager* steppingManager = fpTrackingManager->GetSteppingManager();
  //G4ProcessVector* processVector   =  steppingManager->GetfAtRestDoItVector();
  //G4ProcessVector* processVector   =  steppingManager->GetfPostStepDoItVector();
  //G4ProcessVector* processVector   =  steppingManager->GetfAlongStepDoItVector();

  /*if(processVector->size()>0){
    G4VProcess* lastprocess = processVector->removeLast();
    processVector->insert(lastprocess);
    cout<<lastprocess->GetProcessName()<<endl;
    }*/
  /*
  if(secondaryTracks){

   
    }*/
  
//}


