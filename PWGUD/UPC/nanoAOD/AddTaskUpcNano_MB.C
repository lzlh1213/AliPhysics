AliAnalysisTaskUpcNano_MB *AddTaskUpcNano_MB(Bool_t cutEta = kFALSE){

  
  //--- get the current analysis manager ---//
  AliAnalysisManager *mgr = AliAnalysisManager::GetAnalysisManager();
  if (!mgr) {
      Error("AddTask_UpcNano", "No analysis manager found.");
      return 0;
   }
  
  // Check the analysis type using the event handlers connected to the analysis manager.
  //==============================================================================
  if (!mgr->GetInputEventHandler()) {
    Error("AddTask_UpcNano", "This task requires an input event handler");
    return 0;
  }
	
  TString inputDataType = mgr->GetInputEventHandler()->GetDataType(); // can be "ESD" or "AOD"
  Bool_t isMC;
  if(mgr->GetMCtruthEventHandler()) isMC = kTRUE;
  
  // Create tasks
  AliAnalysisTaskUpcNano_MB *task = new AliAnalysisTaskUpcNano_MB(inputDataType.Data());
  task->SetIsMC(isMC);
  task->SetCutEta(cutEta);
  mgr->AddTask(task);


   // Create containers for input/output
  AliAnalysisDataContainer *cinput = mgr->GetCommonInputContainer();
  AliAnalysisDataContainer *coutput = mgr->CreateContainer("ListHist", TList::Class(), AliAnalysisManager::kOutputContainer, Form("%s:Upc", AliAnalysisManager::GetCommonFileName()));  

  // Connect input/output
  mgr->ConnectInput(task, 0, cinput);
  mgr->ConnectOutput(task, 1, coutput);

return task;
}
