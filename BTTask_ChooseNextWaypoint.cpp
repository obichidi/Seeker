// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolRoute.h"

#include "AIController.h"




EBTNodeResult::Type UBTTask_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) 
{


   

   //auto AIController =OwnerComp.GetAIOwner();

  // --------------------------------

   auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
  //------------------------------------


   //auto ControlledPawn = AIController->GetPawn();

  auto PatrolPoints = PatrolRoute->GetPatrolPoints();

  if (PatrolPoints.Num()==0)

  {
     UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
		return EBTNodeResult::Failed;
  }

   //PatrolPoints = PatrolRoute->PatrolPoints;

   

    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

   BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

   auto  NextIndex = (Index + 1) %  PatrolPoints.Num();
   BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
  
  
  
	
	  return EBTNodeResult::Succeeded;
}
