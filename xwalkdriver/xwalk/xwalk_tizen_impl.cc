// Copyright (c) 2014 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file

#include "xwalk/test/xwalkdriver/xwalk/xwalk_tizen_impl.h"

#include "xwalk/test/xwalkdriver/net/port_server.h"
#include "xwalk/test/xwalkdriver/xwalk/device.h"
#include "xwalk/test/xwalkdriver/xwalk/device_manager.h"
#include "xwalk/test/xwalkdriver/xwalk/devtools_http_client.h"
#include "xwalk/test/xwalkdriver/xwalk/status.h"
#include "xwalk/test/xwalkdriver/xwalk/tizen_device.h"

XwalkTizenImpl::XwalkTizenImpl(
    scoped_ptr<DevToolsHttpClient> client,
    ScopedVector<DevToolsEventListener>& devtools_event_listeners,
    scoped_ptr<PortReservation> port_reservation,
    scoped_ptr<Device> device)
    : XwalkImpl(client.Pass(),
                 devtools_event_listeners,
                 port_reservation.Pass()),
      device_(device.Pass()) {}

XwalkTizenImpl::~XwalkTizenImpl() {}

std::string XwalkTizenImpl::GetOperatingSystemName() {
  return "Tizen";
}

Status XwalkTizenImpl::QuitImpl() {
  return device_->TearDown();
}

