/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _SECONDARY_TABLE_CONTROLLER_H
#define _SECONDARY_TABLE_CONTROLLER_H

#include <sysutils/FrameworkListener.h>

static const unsigned int MAX_IFACE_LENGTH = 10;
static const int INTERFACES_TRACKED = 10;
static const int BASE_TABLE_NUMBER = 60;
static int MAX_TABLE_NUMBER = BASE_TABLE_NUMBER + INTERFACES_TRACKED;

class SecondaryTableController {

public:
    SecondaryTableController();
    virtual ~SecondaryTableController();

    int addRoute(SocketClient *cli, char *iface, char *dest, int prefixLen, char *gateway);
    int removeRoute(SocketClient *cli, char *iface, char *dest, int prefixLen, char *gateway);
    int findTableNumber(const char *iface);

private:
    char mInterfaceTable[INTERFACES_TRACKED][MAX_IFACE_LENGTH];
    int mInterfaceRuleCount[INTERFACES_TRACKED];

    int runAndFree(SocketClient *cli, char *cmd);
};

#endif
