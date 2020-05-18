#ifndef TrackingAction_h
#define TrackingAction_h 1
#include "globals.hh"
#include "G4UserTrackingAction.hh"
#include "SteppingAction.hh"
class PrimaryGeneratorAction;
class Analysis;
class SteppingAction;

class TrackingAction : public G4UserTrackingAction {
  
public:  
  TrackingAction();
  ~TrackingAction();
  
  virtual void  PreUserTrackingAction(const G4Track*);
  virtual void PostUserTrackingAction(const G4Track*);
  static inline TrackingAction* GetInstance() { return theTrackingAction; }
  G4int NPrimary = 0;
  G4bool Primary = 1;
private:
  static TrackingAction*  theTrackingAction;
  PrimaryGeneratorAction* theGenerator;
  Analysis*               theAnalysis;
  SteppingAction*         theStepping;
};



#endif
