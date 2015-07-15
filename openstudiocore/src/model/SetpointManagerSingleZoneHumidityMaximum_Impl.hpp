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

#ifndef MODEL_SETPOINTMANAGERSINGLEZONEHUMIDITYMAXIMUM_IMPL_HPP
#define MODEL_SETPOINTMANAGERSINGLEZONEHUMIDITYMAXIMUM_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/SetpointManager_Impl.hpp>

namespace openstudio {
namespace model {

// TODO: Check the following class names against object getters and setters.
class ThermalZone;
class Node;

namespace detail {

  /** SetpointManagerSingleZoneHumidityMaximum_Impl is a SetpointManager_Impl that is the implementation class for SetpointManagerSingleZoneHumidityMaximum.*/
  class MODEL_API SetpointManagerSingleZoneHumidityMaximum_Impl : public SetpointManager_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    SetpointManagerSingleZoneHumidityMaximum_Impl(const IdfObject& idfObject,
                                                  Model_Impl* model,
                                                  bool keepHandle);

    SetpointManagerSingleZoneHumidityMaximum_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                  Model_Impl* model,
                                                  bool keepHandle);

    SetpointManagerSingleZoneHumidityMaximum_Impl(const SetpointManagerSingleZoneHumidityMaximum_Impl& other,
                                                  Model_Impl* model,
                                                  bool keepHandle);

    virtual ~SetpointManagerSingleZoneHumidityMaximum_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    //@}
    /** @name Getters */
    //@{

    std::string controlVariable() const;

    // TODO: Check return type. From object lists, some candidates are: ThermalZone.
    boost::optional<ThermalZone> controlZone() const;

    // TODO: Check return type. From object lists, some candidates are: Node.
    boost::optional<Node> setpointNodeorNodeList() const;

    //@}
    /** @name Setters */
    //@{

    bool setControlVariable(std::string controlVariable);

    // TODO: Check argument type. From object lists, some candidates are: ThermalZone.
    bool setControlZone(const boost::optional<ThermalZone>& thermalZone);

    void resetControlZone();

    // TODO: Check argument type. From object lists, some candidates are: Node.
    bool setSetpointNodeorNodeList(const boost::optional<Node>& node);

    void resetSetpointNodeorNodeList();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.SetpointManagerSingleZoneHumidityMaximum");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_SETPOINTMANAGERSINGLEZONEHUMIDITYMAXIMUM_IMPL_HPP

