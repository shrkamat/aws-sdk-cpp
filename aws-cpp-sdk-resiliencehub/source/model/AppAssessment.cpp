﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/resiliencehub/model/AppAssessment.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace ResilienceHub
{
namespace Model
{

AppAssessment::AppAssessment() : 
    m_appArnHasBeenSet(false),
    m_appVersionHasBeenSet(false),
    m_assessmentArnHasBeenSet(false),
    m_assessmentNameHasBeenSet(false),
    m_assessmentStatus(AssessmentStatus::NOT_SET),
    m_assessmentStatusHasBeenSet(false),
    m_complianceHasBeenSet(false),
    m_complianceStatus(ComplianceStatus::NOT_SET),
    m_complianceStatusHasBeenSet(false),
    m_costHasBeenSet(false),
    m_endTimeHasBeenSet(false),
    m_invoker(AssessmentInvoker::NOT_SET),
    m_invokerHasBeenSet(false),
    m_messageHasBeenSet(false),
    m_policyHasBeenSet(false),
    m_resiliencyScoreHasBeenSet(false),
    m_startTimeHasBeenSet(false),
    m_tagsHasBeenSet(false)
{
}

AppAssessment::AppAssessment(JsonView jsonValue) : 
    m_appArnHasBeenSet(false),
    m_appVersionHasBeenSet(false),
    m_assessmentArnHasBeenSet(false),
    m_assessmentNameHasBeenSet(false),
    m_assessmentStatus(AssessmentStatus::NOT_SET),
    m_assessmentStatusHasBeenSet(false),
    m_complianceHasBeenSet(false),
    m_complianceStatus(ComplianceStatus::NOT_SET),
    m_complianceStatusHasBeenSet(false),
    m_costHasBeenSet(false),
    m_endTimeHasBeenSet(false),
    m_invoker(AssessmentInvoker::NOT_SET),
    m_invokerHasBeenSet(false),
    m_messageHasBeenSet(false),
    m_policyHasBeenSet(false),
    m_resiliencyScoreHasBeenSet(false),
    m_startTimeHasBeenSet(false),
    m_tagsHasBeenSet(false)
{
  *this = jsonValue;
}

AppAssessment& AppAssessment::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("appArn"))
  {
    m_appArn = jsonValue.GetString("appArn");

    m_appArnHasBeenSet = true;
  }

  if(jsonValue.ValueExists("appVersion"))
  {
    m_appVersion = jsonValue.GetString("appVersion");

    m_appVersionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("assessmentArn"))
  {
    m_assessmentArn = jsonValue.GetString("assessmentArn");

    m_assessmentArnHasBeenSet = true;
  }

  if(jsonValue.ValueExists("assessmentName"))
  {
    m_assessmentName = jsonValue.GetString("assessmentName");

    m_assessmentNameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("assessmentStatus"))
  {
    m_assessmentStatus = AssessmentStatusMapper::GetAssessmentStatusForName(jsonValue.GetString("assessmentStatus"));

    m_assessmentStatusHasBeenSet = true;
  }

  if(jsonValue.ValueExists("compliance"))
  {
    Aws::Map<Aws::String, JsonView> complianceJsonMap = jsonValue.GetObject("compliance").GetAllObjects();
    for(auto& complianceItem : complianceJsonMap)
    {
      m_compliance[DisruptionTypeMapper::GetDisruptionTypeForName(complianceItem.first)] = complianceItem.second.AsObject();
    }
    m_complianceHasBeenSet = true;
  }

  if(jsonValue.ValueExists("complianceStatus"))
  {
    m_complianceStatus = ComplianceStatusMapper::GetComplianceStatusForName(jsonValue.GetString("complianceStatus"));

    m_complianceStatusHasBeenSet = true;
  }

  if(jsonValue.ValueExists("cost"))
  {
    m_cost = jsonValue.GetObject("cost");

    m_costHasBeenSet = true;
  }

  if(jsonValue.ValueExists("endTime"))
  {
    m_endTime = jsonValue.GetDouble("endTime");

    m_endTimeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("invoker"))
  {
    m_invoker = AssessmentInvokerMapper::GetAssessmentInvokerForName(jsonValue.GetString("invoker"));

    m_invokerHasBeenSet = true;
  }

  if(jsonValue.ValueExists("message"))
  {
    m_message = jsonValue.GetString("message");

    m_messageHasBeenSet = true;
  }

  if(jsonValue.ValueExists("policy"))
  {
    m_policy = jsonValue.GetObject("policy");

    m_policyHasBeenSet = true;
  }

  if(jsonValue.ValueExists("resiliencyScore"))
  {
    m_resiliencyScore = jsonValue.GetObject("resiliencyScore");

    m_resiliencyScoreHasBeenSet = true;
  }

  if(jsonValue.ValueExists("startTime"))
  {
    m_startTime = jsonValue.GetDouble("startTime");

    m_startTimeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("tags"))
  {
    Aws::Map<Aws::String, JsonView> tagsJsonMap = jsonValue.GetObject("tags").GetAllObjects();
    for(auto& tagsItem : tagsJsonMap)
    {
      m_tags[tagsItem.first] = tagsItem.second.AsString();
    }
    m_tagsHasBeenSet = true;
  }

  return *this;
}

JsonValue AppAssessment::Jsonize() const
{
  JsonValue payload;

  if(m_appArnHasBeenSet)
  {
   payload.WithString("appArn", m_appArn);

  }

  if(m_appVersionHasBeenSet)
  {
   payload.WithString("appVersion", m_appVersion);

  }

  if(m_assessmentArnHasBeenSet)
  {
   payload.WithString("assessmentArn", m_assessmentArn);

  }

  if(m_assessmentNameHasBeenSet)
  {
   payload.WithString("assessmentName", m_assessmentName);

  }

  if(m_assessmentStatusHasBeenSet)
  {
   payload.WithString("assessmentStatus", AssessmentStatusMapper::GetNameForAssessmentStatus(m_assessmentStatus));
  }

  if(m_complianceHasBeenSet)
  {
   JsonValue complianceJsonMap;
   for(auto& complianceItem : m_compliance)
   {
     complianceJsonMap.WithObject(DisruptionTypeMapper::GetNameForDisruptionType(complianceItem.first), complianceItem.second.Jsonize());
   }
   payload.WithObject("compliance", std::move(complianceJsonMap));

  }

  if(m_complianceStatusHasBeenSet)
  {
   payload.WithString("complianceStatus", ComplianceStatusMapper::GetNameForComplianceStatus(m_complianceStatus));
  }

  if(m_costHasBeenSet)
  {
   payload.WithObject("cost", m_cost.Jsonize());

  }

  if(m_endTimeHasBeenSet)
  {
   payload.WithDouble("endTime", m_endTime.SecondsWithMSPrecision());
  }

  if(m_invokerHasBeenSet)
  {
   payload.WithString("invoker", AssessmentInvokerMapper::GetNameForAssessmentInvoker(m_invoker));
  }

  if(m_messageHasBeenSet)
  {
   payload.WithString("message", m_message);

  }

  if(m_policyHasBeenSet)
  {
   payload.WithObject("policy", m_policy.Jsonize());

  }

  if(m_resiliencyScoreHasBeenSet)
  {
   payload.WithObject("resiliencyScore", m_resiliencyScore.Jsonize());

  }

  if(m_startTimeHasBeenSet)
  {
   payload.WithDouble("startTime", m_startTime.SecondsWithMSPrecision());
  }

  if(m_tagsHasBeenSet)
  {
   JsonValue tagsJsonMap;
   for(auto& tagsItem : m_tags)
   {
     tagsJsonMap.WithString(tagsItem.first, tagsItem.second);
   }
   payload.WithObject("tags", std::move(tagsJsonMap));

  }

  return payload;
}

} // namespace Model
} // namespace ResilienceHub
} // namespace Aws
