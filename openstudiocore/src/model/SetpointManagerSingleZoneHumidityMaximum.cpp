/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include <model/SetpointManagerSingleZoneHumidityMaximum.hpp>
#include <model/SetpointManagerSingleZoneHumidityMaximum_Impl.hpp>

// TODO: Check the following class names against object getters and setters.
#include <model/ThermalZone.hpp>
#include <model/ThermalZone_Impl.hpp>
#include <model/Node.hpp>
#include <model/Node_Impl.hpp>

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_SetpointManager_SingleZone_Humidity_Maximum_FieldEnums.hxx>

#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

namespace detail {

  SetpointManagerSingleZoneHumidityMaximum_Impl::SetpointManagerSingleZoneHumidityMaximum_Impl(const IdfObject& idfObject,
                                                                                               Model_Impl* model,
                                                                                               bool keepHandle)
    : SetpointManager_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == SetpointManagerSingleZoneHumidityMaximum::iddObjectType());
  }

  SetpointManagerSingleZoneHumidityMaximum_Impl::SetpointManagerSingleZoneHumidityMaximum_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                               Model_Impl* model,
                                                                                               bool keepHandle)
    : SetpointManager_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == SetpointManagerSingleZoneHumidityMaximum::iddObjectType());
  }

  SetpointManagerSingleZoneHumidityMaximum_Impl::SetpointManagerSingleZoneHumidityMaximum_Impl(const SetpointManagerSingleZoneHumidityMaximum_Impl& other,
                                                                                               Model_Impl* model,
                                                                                               bool keepHandle)
    : SetpointManager_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& SetpointManagerSingleZoneHumidityMaximum_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType SetpointManagerSingleZoneHumidityMaximum_Impl::iddObjectType() const {
    return SetpointManagerSingleZoneHumidityMaximum::iddObjectType();
  }

  std::string SetpointManagerSingleZoneHumidityMaximum_Impl::controlVariable() const {
    boost::optional<std::string> value = getString(OS_SetpointManager_SingleZone_Humidity_MaximumFields::ControlVariable,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<ThermalZone> SetpointManagerSingleZoneHumidityMaximum_Impl::controlZone() const {
    return getObject<ModelObject>().getModelObjectTarget<ThermalZone>(OS_SetpointManager_SingleZone_Humidity_MaximumFields::ControlZoneName);
  }

  boost::optional<Node> SetpointManagerSingleZoneHumidityMaximum_Impl::setpointNodeorNodeList() const {
    return getObject<ModelObject>().getModelObjectTarget<Node>(OS_SetpointManager_SingleZone_Humidity_MaximumFields::SetpointNodeorNodeListName);
  }

  bool SetpointManagerSingleZoneHumidityMaximum_Impl::setControlVariable(std::string controlVariable) {
    bool result = setString(OS_SetpointManager_SingleZone_Humidity_MaximumFields::ControlVariable, controlVariable);
    return result;
  }

  bool SetpointManagerSingleZoneHumidityMaximum_Impl::setControlZone(const boost::optional<ThermalZone>& thermalZone) {
    bool result(false);
    if (thermalZone) {
      result = setPointer(OS_SetpointManager_SingleZone_Humidity_MaximumFields::ControlZoneName, thermalZone.get().handle());
    }
    else {
      resetControlZone();
      result = true;
    }
    return result;
  }

  void SetpointManagerSingleZoneHumidityMaximum_Impl::resetControlZone() {
    bool result = setString(OS_SetpointManager_SingleZone_Humidity_MaximumFields::ControlZoneName, "");
    OS_ASSERT(result);
  }

  bool SetpointManagerSingleZoneHumidityMaximum_Impl::setSetpointNodeorNodeList(const boost::optional<Node>& node) {
    bool result(false);
    if (node) {
      result = setPointer(OS_SetpointManager_SingleZone_Humidity_MaximumFields::SetpointNodeorNodeListName, node.get().handle());
    }
    else {
      resetSetpointNodeorNodeList();
      result = true;
    }
    return result;
  }

  void SetpointManagerSingleZoneHumidityMaximum_Impl::resetSetpointNodeorNodeList() {
    bool result = setString(OS_SetpointManager_SingleZone_Humidity_MaximumFields::SetpointNodeorNodeListName, "");
    OS_ASSERT(result);
  }

} // detail

SetpointManagerSingleZoneHumidityMaximum::SetpointManagerSingleZoneHumidityMaximum(const Model& model)
  : SetpointManager(SetpointManagerSingleZoneHumidityMaximum::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::SetpointManagerSingleZoneHumidityMaximum_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  bool ok = true;
  // ok = setHandle();
  OS_ASSERT(ok);
  // ok = setControlVariable();
  OS_ASSERT(ok);
}

IddObjectType SetpointManagerSingleZoneHumidityMaximum::iddObjectType() {
  return IddObjectType(IddObjectType::OS_SetpointManager_SingleZone_Humidity_Maximum);
}

std::vector<std::string> SetpointManagerSingleZoneHumidityMaximum::controlVariableValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SetpointManager_SingleZone_Humidity_MaximumFields::ControlVariable);
}

std::string SetpointManagerSingleZoneHumidityMaximum::controlVariable() const {
  return getImpl<detail::SetpointManagerSingleZoneHumidityMaximum_Impl>()->controlVariable();
}

boost::optional<ThermalZone> SetpointManagerSingleZoneHumidityMaximum::controlZone() const {
  return getImpl<detail::SetpointManagerSingleZoneHumidityMaximum_Impl>()->controlZone();
}

boost::optional<Node> SetpointManagerSingleZoneHumidityMaximum::setpointNodeorNodeList() const {
  return getImpl<detail::SetpointManagerSingleZoneHumidityMaximum_Impl>()->setpointNodeorNodeList();
}

bool SetpointManagerSingleZoneHumidityMaximum::setControlVariable(std::string controlVariable) {
  return getImpl<detail::SetpointManagerSingleZoneHumidityMaximum_Impl>()->setControlVariable(controlVariable);
}

bool SetpointManagerSingleZoneHumidityMaximum::setControlZone(const ThermalZone& thermalZone) {
  return getImpl<detail::SetpointManagerSingleZoneHumidityMaximum_Impl>()->setControlZone(thermalZone);
}

void SetpointManagerSingleZoneHumidityMaximum::resetControlZone() {
  getImpl<detail::SetpointManagerSingleZoneHumidityMaximum_Impl>()->resetControlZone();
}

bool SetpointManagerSingleZoneHumidityMaximum::setSetpointNodeorNodeList(const Node& node) {
  return getImpl<detail::SetpointManagerSingleZoneHumidityMaximum_Impl>()->setSetpointNodeorNodeList(node);
}

void SetpointManagerSingleZoneHumidityMaximum::resetSetpointNodeorNodeList() {
  getImpl<detail::SetpointManagerSingleZoneHumidityMaximum_Impl>()->resetSetpointNodeorNodeList();
}

/// @cond
SetpointManagerSingleZoneHumidityMaximum::SetpointManagerSingleZoneHumidityMaximum(std::shared_ptr<detail::SetpointManagerSingleZoneHumidityMaximum_Impl> impl)
  : SetpointManager(impl)
{}
/// @endcond

} // model
} // openstudio

