﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/ec2/model/PrefixListId.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace EC2
{
namespace Model
{

PrefixListId::PrefixListId() : 
    m_descriptionHasBeenSet(false),
    m_prefixListIdHasBeenSet(false),
    m_securityGroupRuleIdHasBeenSet(false)
{
}

PrefixListId::PrefixListId(const XmlNode& xmlNode) : 
    m_descriptionHasBeenSet(false),
    m_prefixListIdHasBeenSet(false),
    m_securityGroupRuleIdHasBeenSet(false)
{
  *this = xmlNode;
}

PrefixListId& PrefixListId::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode descriptionNode = resultNode.FirstChild("description");
    if(!descriptionNode.IsNull())
    {
      m_description = Aws::Utils::Xml::DecodeEscapedXmlText(descriptionNode.GetText());
      m_descriptionHasBeenSet = true;
    }
    XmlNode prefixListIdNode = resultNode.FirstChild("prefixListId");
    if(!prefixListIdNode.IsNull())
    {
      m_prefixListId = Aws::Utils::Xml::DecodeEscapedXmlText(prefixListIdNode.GetText());
      m_prefixListIdHasBeenSet = true;
    }
    XmlNode securityGroupRuleIdNode = resultNode.FirstChild("securityGroupRuleId");
    if(!securityGroupRuleIdNode.IsNull())
    {
      m_securityGroupRuleId = Aws::Utils::Xml::DecodeEscapedXmlText(securityGroupRuleIdNode.GetText());
      m_securityGroupRuleIdHasBeenSet = true;
    }
  }

  return *this;
}

void PrefixListId::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_descriptionHasBeenSet)
  {
      oStream << location << index << locationValue << ".Description=" << StringUtils::URLEncode(m_description.c_str()) << "&";
  }

  if(m_prefixListIdHasBeenSet)
  {
      oStream << location << index << locationValue << ".PrefixListId=" << StringUtils::URLEncode(m_prefixListId.c_str()) << "&";
  }

  if(m_securityGroupRuleIdHasBeenSet)
  {
      oStream << location << index << locationValue << ".SecurityGroupRuleId=" << StringUtils::URLEncode(m_securityGroupRuleId.c_str()) << "&";
  }

}

void PrefixListId::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_descriptionHasBeenSet)
  {
      oStream << location << ".Description=" << StringUtils::URLEncode(m_description.c_str()) << "&";
  }
  if(m_prefixListIdHasBeenSet)
  {
      oStream << location << ".PrefixListId=" << StringUtils::URLEncode(m_prefixListId.c_str()) << "&";
  }
  if(m_securityGroupRuleIdHasBeenSet)
  {
      oStream << location << ".SecurityGroupRuleId=" << StringUtils::URLEncode(m_securityGroupRuleId.c_str()) << "&";
  }
}

} // namespace Model
} // namespace EC2
} // namespace Aws
