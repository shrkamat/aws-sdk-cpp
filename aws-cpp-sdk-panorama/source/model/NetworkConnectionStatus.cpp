﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/panorama/model/NetworkConnectionStatus.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace Panorama
  {
    namespace Model
    {
      namespace NetworkConnectionStatusMapper
      {

        static const int CONNECTED_HASH = HashingUtils::HashString("CONNECTED");
        static const int NOT_CONNECTED_HASH = HashingUtils::HashString("NOT_CONNECTED");


        NetworkConnectionStatus GetNetworkConnectionStatusForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == CONNECTED_HASH)
          {
            return NetworkConnectionStatus::CONNECTED;
          }
          else if (hashCode == NOT_CONNECTED_HASH)
          {
            return NetworkConnectionStatus::NOT_CONNECTED;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<NetworkConnectionStatus>(hashCode);
          }

          return NetworkConnectionStatus::NOT_SET;
        }

        Aws::String GetNameForNetworkConnectionStatus(NetworkConnectionStatus enumValue)
        {
          switch(enumValue)
          {
          case NetworkConnectionStatus::CONNECTED:
            return "CONNECTED";
          case NetworkConnectionStatus::NOT_CONNECTED:
            return "NOT_CONNECTED";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace NetworkConnectionStatusMapper
    } // namespace Model
  } // namespace Panorama
} // namespace Aws
