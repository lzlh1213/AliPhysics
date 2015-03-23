/**
 * \file AliEMCalTriggerClusterAnalysisComponent.h
 * \brief Analysis component for EMCAL clusters.
 *
 * Analysis component for EMCal clusters. Loops over calibrated and uncalibrated clusters
 *
 * \author Markus Fasel <markus.fasel@cern.ch>, Lawrence Berkeley National Laboratory
 * \date Dec 12, 2014
 */
#ifndef ALIEMCALTRIGGERCLUSTERANALYSISCOMPONENT_H
#define ALIEMCALTRIGGERCLUSTERANALYSISCOMPONENT_H
/* Copyright(c) 1998-2014, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

#include "AliCutValueRange.h"
#include "AliEMCalTriggerTracksAnalysisComponent.h"
#include "AliEMCalTriggerAnaTriggerDecision.h"

class TString;
class AliVCluster;
class AliVEvent;

/**
 * \namespace EMCalTriggerPtAnalysis
 * \brief Analysis of high-p_{t} tracks in triggered events
 *
 * This namespace contains classes for the analysis of high-p_{t} tracks in
 * triggered events.
 */
namespace EMCalTriggerPtAnalysis {

class AliEMCalTriggerEventData;

/**
 * \class AliEMCalTriggerClusterAnalysisComponent
 * \brief Analysis component for EMCAL clusters in events.
 *
 * Analysis component for EMCal clusters. Loops over calibrated and uncalibrated clusters and fills cluster-based
 * histograms for each trigger class the event is selected by.
 */
class AliEMCalTriggerClusterAnalysisComponent : public AliEMCalTriggerTracksAnalysisComponent {
public:
  AliEMCalTriggerClusterAnalysisComponent();
  AliEMCalTriggerClusterAnalysisComponent(const char *name);
  virtual ~AliEMCalTriggerClusterAnalysisComponent() {}

  virtual void CreateHistos();
  virtual void Process(const AliEMCalTriggerEventData * const data);

  /**
   * Define method used to select triggered events.
   * \param method The method which is used by this component
   */
  void SetTriggerMethod(ETriggerMethod_t method) { fTriggerMethod = method; }

  /**
   * Set the range of the energy in which clusters are accepted
   * \param min Minimum energy of the cluster
   * \param max Maximum energy of the cluster
   */
  void SetEnergyRange(double min, double max) { fEnergyRange.SetLimits(min, max); }

protected:
  void FillHistogram(const TString &histname, const AliVCluster *clust, AliVEvent *ev, Bool_t inMB);

  AliCutValueRange<double>    fEnergyRange;               ///< Allowed energy range for the cluster
  ETriggerMethod_t            fTriggerMethod;             ///< Method used for the trigger decision

  /// \cond CLASSIMP
  ClassDef(AliEMCalTriggerClusterAnalysisComponent, 1);       // Analysis component for EMCal cluster
  /// \endcond
};

} /* namespace EMCalTriggerPtAnalysis */

#endif /* ALIEMCALTRIGGERCLUSTERANALYSISCOMPONENT_H */
